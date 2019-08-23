/*************************************************************************
	> File Name: 1.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年08月23日 星期五 15时07分56秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


int main()
{
	ifstream in("2.html");
	ostringstream tmp;
	tmp <<in.rdbuf();
	string str = tmp.str();
	cout << str <<endl;
}
