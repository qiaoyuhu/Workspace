#include <iostream>
#include <sqlite3.h>
#include <cstdio>
#include <cstdlib>

using namespace std;	

/*
   int sqlite3_get_table(sqlite3*, const char *sql, char ***resultp, int *nrow, int *ncolumn, char **errmsg); 
1 :句柄
2 :sql语句
3 :查询结果,一维数据
4 :多少条记录(多少行)
5 :多少字段(多少列)
6 :错误信息
 */

int main()
{
	sqlite3 *db;
	int nrow;
	int ncolumn;
	int result;
	char *ErrMsg;
	string sql = "SELECT * FROM COMPANY;";
	result = sqlite3_open("test.db",&db);
	if(result !=SQLITE_OK)
	{
		cout << "Open test.db FAILED!" <<endl;
		exit(0);
	}
	else
		cout << "open test.db success" <<endl;

	char **pResult;
	result = sqlite3_get_table(db,sql.c_str(),&pResult,&nrow,&ncolumn,&ErrMsg);
	if(result == SQLITE_OK)
	{
		int num = 0;
		cout << "get_table SUCCESS" <<endl;
		for(int i=0;i <nrow; i++)
		{
			for(int j=0; j<ncolumn; j++)
			{
				cout << pResult[num] << "   ";
				num ++;
			}
			cout << "\n"<<endl;
		}

	}
	else
	{
		cout << "result: "<<result <<endl;
		cout << "get_table ERROR"<<endl;
	}



	sqlite3_free_table(pResult);
	sqlite3_close(db);
	return 0;

}
