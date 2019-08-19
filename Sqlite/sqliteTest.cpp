#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sqlite3.h>
using namespace std;


static int callback(void *NotUsed, int argc ,char **argv ,char **azColName)
{
	int i ;
	for(i=0; i<argc; i++)
	{
		printf("%s = %s\n",azColName[i], argv[i] ?argv[i] : "NULL");
	}
	return 0;
}

void InsertInto(sqlite3 *db)
{
	char *zErrMsg =0;
	int result;
	char *sql ; 
	sql = new char[100];
	string name ;
	int age ;
	int salary ;
	cout << "your name:";
	cin >>name;
	cout << "your age:";
	cin >>age;
	cout << "your salary:";
	cin >> salary;
	sprintf(sql,"INSERT INTO Company(NAME,AGE,ADDRESS,SALARY) values('%s',%d,'shanghai',%d)",name.c_str(),age,salary);
//	const char *sql = "INSERT INTO Company Values(3, 'wang', 18, 'shanghai', 25000);";
	sqlite3_stmt *stmt = NULL;
	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);//检查语句的合法性
	if(result == SQLITE_OK)
	{
		cout << "插入语句语法正确" <<endl;
		int value = sqlite3_step(stmt);//执行语句
		cout << "value : "<<value <<endl;
		
	}
	else
	{
		cout << "插入语句语法错误" <<endl;
	}
	free(sql);
	sqlite3_finalize(stmt);
	

}

void Find(sqlite3 *db)
{
	const char *sql = "SELECT NAME,SALARY,AGE FROM COMPANY;";
	sqlite3_stmt *stmt = NULL;
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt,NULL);
	if(result == SQLITE_OK)
	{
		cout << "查询语句语法正确" <<endl;
		while(sqlite3_step(stmt) == SQLITE_ROW)
		{
			const unsigned char *name = sqlite3_column_text(stmt,0);
			int salary = sqlite3_column_int(stmt,1);
			int age = sqlite3_column_int(stmt,2);
			cout << "name = "<<name <<" ,age = "<<age <<" ,salary: "<<salary<<endl;
		}

	}
	else
	{
		cout << "查询语句语法错误" <<endl;
	}

	sqlite3_finalize(stmt);
}




int main()
{
	sqlite3 *db;
	int res ;
	char *sql;
	char *zErrMsg =0;
	res = sqlite3_open("test.db",&db);
	if(res)
	{
		fprintf(stderr,"Can't Open database:%s\n",sqlite3_errmsg(db));
		exit(0);
	}
	else
	{
		fprintf(stderr,"Open database successfully\n");
	}

	InsertInto(db);

	Find(db);

	sqlite3_close(db);
	return 0;
}
