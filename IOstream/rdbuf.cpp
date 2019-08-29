/*************************************************************************
	> File Name: rdbuf.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年08月27日 星期二 16时46分09秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	ifstream is("text.json",ios::in);;
	filebuf *fb = is.rdbuf();
	ostringstream tmp;
	tmp << is.rdbuf();
	string str = tmp.str();
	cout << "str :\n"<<str <<endl;
	cout << "str.size(): "<<str.size()<<endl;
	
	fb->open("1.txt",ios::out | ios::app);
	

	fb->close();
	return 0;
}
