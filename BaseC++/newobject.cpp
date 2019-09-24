/*************************************************************************
	> File Name: newobject.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月23日 星期一 10时48分16秒
 ************************************************************************/

#include <iostream>
#include <unistd.h>
using namespace std;


class Box
{
	public:
		Box()
		{cout << "构造函数" <<endl;}
		~Box()
		{cout << "析构函数" <<endl;}
};


int main()
{
	while(1)
	{
	Box *box;
	box = new Box[4];//将会调用四次构造函数

	delete []box;//将会调用四次析构函数
	sleep(5);
}
}
