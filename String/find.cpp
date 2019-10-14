/*************************************************************************
  > File Name: find.cpp
  > Author: qiaoyuhu
  > Mail: yuhuqiao@163.com 
  > Created Time: 2019年10月14日 星期一 17时20分38秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define SUBWAY_LINE_FLAG "地铁"
#define SUBWAY_NAME_FLAG "到达"
#define SUBWAY_FOOT_FLAG "步行"
#define FLAG_SIZE strlen("到达")

string function(string str)
{
	string address , line ,test;
	string::size_type  position_line = 0, position_name=0 ,position_foot;
	position_line=str.rfind(SUBWAY_LINE_FLAG);
	if(position_line == str.npos)
	{
		cout << "not found "<<SUBWAY_LINE_FLAG<<endl;
		return address;
	}
	position_name =str.find(SUBWAY_NAME_FLAG,position_line);
	if(position_name == str.npos)
	{
		cout << "not found "<<SUBWAY_NAME_FLAG<<endl;
		return address;
	}
	test = str.substr(position_name+FLAG_SIZE);
	position_foot = test.find(SUBWAY_FOOT_FLAG);
	cout << "foot : "<<position_foot<<endl;

	address = test.substr(0,position_foot);

	return address;



}


int main()
{
	string str;
	cin >>str;
	cout << "final address :" <<function(str) <<endl;
}
