/*************************************************************************
  > File Name: read.cpp
  > Author: qiaoyuhu
  > Mail: yuhuqiao@163.com 
  > Created Time: 2019年08月23日 星期五 13时57分34秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;
const string BAIDU_SEARCH = "\nlocal.search(\"search_temp\");\n</script>";
const string SEARCH_VALUE = "search_temp";
int Search(string address)
{
	ifstream in("2.html",ios::binary);
	ostringstream tmp;
	tmp << in.rdbuf();
	ofstream out ;
	string search = tmp.str();
	out.open("Search.html");
	
	string search_value = BAIDU_SEARCH;
	int pos = search_value.find(SEARCH_VALUE);
	int len = SEARCH_VALUE.size();
	search_value.replace(pos,len,address);
	search += search_value;
	out.write(search.c_str(),search.size());
}

int main()
{
	string address;
	cout << "输入要搜索的地点: ";
	cin >>address;
	Search(address);

}
