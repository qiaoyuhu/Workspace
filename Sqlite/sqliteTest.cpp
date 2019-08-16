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

void InsertInto()
{

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

	sql = "INSERT INTO Company Values(2, 'liu', 18, 'shanghai', 25000);";
	
	res = sqlite3_exec(db, sql, callback,0, &zErrMsg);
	if(res !=SQLITE_OK)
	{
		cout << "SQL Insert ERR: "<<zErrMsg<<endl;
	}
	else
		cout << "SQL Insert Successfully"<<endl;

	sqlite3_close(db);
	return 0;
}
