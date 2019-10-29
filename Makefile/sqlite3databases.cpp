/*************************************************************************
	> File Name: sqlite3databases.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年10月21日 星期一 15时41分34秒
 ************************************************************************/

#include "sqlite3databases.h"
using namespace std;

DataBases::DataBases()
{
}

/*
 *@brief   初始化
 */
void DataBases::sqlite3_initialize()
{
	int nRet = sqlite3_open(DATABASES_NAME.c_str(),&db);	
	if(nRet !=SQLITE_OK)
	{
		const char* szError = sqlite3_errmsg(0);
		cout << "szError :" <<szError <<endl;

	}
	cout << "Open DataBases Successful"<<endl;
}

/*
 *@brief: 创建表结构
 */
void DataBases::create_table()
{
	if(is_table_exist(TABLE_FacePay))
	{
		cout << "已存在表:"<<TABLE_FacePay<<endl;
		return ;
	}
	char * sql = nullptr;
	sql = new char[200];
	sprintf(sql,"CREATE TABLE %s (ID INTEGER PRIMARY KEY AUTOINCREMENT,ORDER_NO CHAR(30)NOT NULL,PRICE INT NOT NULL, TRANSACTION_TIME CHAR(15) NOT NULL);",TABLE_FacePay.c_str());
	cout << sql <<endl;
	if(is_sql_prepare((string)sql))//语法正确
	{
		char * errmsg;
		int result = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
		if(result ==SQLITE_OK)
		{
			cout << "成功创建表结构"<<endl;
		}
		else
			cout << "创建表结构失败" <<endl;


	}

	delete(sql);
}

/*
 *@brief: 插入数据
 *
 */

void DataBases::IntoData(const DataBases_Format dt)
{
	char *sql = new char[200];
	string timestamp = "20191029101000";
	sprintf(sql,"INSERT INTO %s (ORDER_NO,PRICE,TRANSACTION_TIME) VALUES(%s,%d,%s);",TABLE_FacePay.c_str(),dt.orderNo,dt.price,timestamp.c_str());
	cout << sql <<endl;
	if(is_sql_prepare(sql))//查询语句合法性
	{
		char *errmsg= nullptr;
		int result = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
		if(result !=SQLITE_OK)
		{
			throw("INSET DATA FAILED!");
		}
		else
			cout << "插入数据成功!" <<endl;
		sqlite3_free(errmsg);
	}


	delete sql;
}










/*

   int sqlite3_exec(

      sqlite3*,                                 // 一个打开的数据库实例

       constchar *sql,                          // 需要执行的SQL语句

       int(*callback)(void*,int,char**,char**),  // SQL语句执行完毕后的回调

       void*,                                   // 回调函数的第1个参数

       char**errmsg                             // 错误信息

   );
*/
bool DataBases::run_sql(const string sql)
{

	char* errmsg = nullptr;
	int ret = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errmsg);
	cout << "errmsg : "<<errmsg<<endl;
	cout <<"ret : " << ret <<endl;
	sqlite3_free(errmsg);
}



/*
 *@brief  :判断表是否存在  
 *@param  :
 *@return :存在表返回True,否则返回false
 */
int DataBases::is_table_exist(const string tb_name)
{
	int RetVal = 0;	
	char * sql = new char[100];
	sprintf(sql,"SELECT COUNT(*) FROM sqlite_master WHERE type='table' AND name='%s';",tb_name.c_str());
//	const string sql = "SELECT * FROM ";
	if(is_sql_prepare(sql))
	{
		char **pResult =nullptr;
		int nRow=0,ncolumn=0;
		char *errmsg = nullptr;
		int result = sqlite3_get_table(db,sql,&pResult,&nRow,&ncolumn,&errmsg);

		if(result == SQLITE_OK)
		{
			RetVal = atoi(pResult[ncolumn]);//第一行(0~ncolumn)为列名
			cout << "RetVal: "<<RetVal<<endl;

		}
		else
			cout << "sqlite3_get_table run error" <<endl;
		delete sql;
		sqlite3_free_table(pResult);
		return RetVal;
	}


}

/*
 *@brief: 语句的合法性检查
 */
bool DataBases::is_sql_prepare(const string sql)
{
	bool tf= false;
	sqlite3_stmt *pStmt;
	int result = sqlite3_prepare_v2(db,sql.c_str(),-1,&pStmt,NULL);
	if(result == SQLITE_OK)
	{
		cout << "语法正确" <<endl;
		tf = true;
	}
	cout <<"语法:" <<boolalpha<< tf<<endl;
	return tf;
}











DataBases::~DataBases()
{
	sqlite3_close(db);
}
int main()
{
	DataBases_Format df;
	strcpy(df.orderNo,"201910101019");
	df.price = 200;
	DataBases *databases;
	databases = new DataBases();
	databases->sqlite3_initialize();
//	databases->count_tables();
	databases->create_table();
	try
	{
	databases->IntoData(df);
	}catch(const char *errmsg)
	{
		cout << "Catch Error :"<<errmsg <<endl;
	}
}
