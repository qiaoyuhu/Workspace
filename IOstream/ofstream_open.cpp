/*************************************************************************
	> File Name: ofstream_open.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年08月27日 星期二 15时47分40秒
 ************************************************************************/

#include <fstream>
using namespace std;

int main()
{
	ofstream ofs;
	ofs.open("test.txt",ios::out|ios::app);
	ofs << "123";
	ofs.close();
	return 0;
}

