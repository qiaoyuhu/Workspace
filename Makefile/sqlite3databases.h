/*************************************************************************
	> File Name: sqlite3databases.h
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年10月21日 星期一 15时36分48秒
 ************************************************************************/

#include <iostream>
#include <sqlite3.h>
#include <cstdio>
#include <cstdlib>
#include <string.h>


struct DataBases_Format
{
	char orderNo[30];
	int price;

};

enum TABLES_NAME
{
	COMPANY=0,
};
class DataBases
{
	public:
		explicit DataBases();
		virtual ~DataBases();
		void insert_into_table();	

		int is_table_exist(const std::string tb_name);
//	private:
		void sqlite3_initialize();
		bool is_sql_prepare(const std::string );
		bool run_sql(const std::string );
		void create_table();
		void IntoData(const DataBases_Format );
	private:
		const std::string DATABASES_NAME = "WxFacePay.db";
//		const std::string DATABASES_NAME = "test.db";
		const std::string TABLE_FacePay="Transaction_Record";
		sqlite3 *db;

};

