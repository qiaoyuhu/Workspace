/*************************************************************************
  > File Name: ifstream_open.cpp
  > Author: qiaoyuhu
  > Mail: yuhuqiao@163.com 
  > Created Time: 2019年08月27日 星期二 16时04分05秒
 ************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("text.json",ios::in);
	string str;
	cout << "ifs.rdbuf(): \t" <<ifs.rdbuf()<<endl;
	for(;!ifs.eof();)
	{
		string tmp ;
		ifs >> tmp;
		str.append(tmp);
	}
	cout <<"str: " <<str<<endl;
}
