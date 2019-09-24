/************************************************************************* > File Name: const.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月23日 星期一 14时39分16秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Test
{
	public:
	void swap(int a)const//只读函数，无法会成员变量进行修改
	{
	//	test =a;//报错
		cout <<"Test.swap()"<<endl;
	}
	int test;
};



void swap(int const &a)
{
//	a =1;//报错，a是const，无法修改
	cout << "--" <<endl;
}

//const int & min( int& a, int& b)//返回值不可变
int & min( int& a, int& b)
{
	if(a>=b)
		return b;
	else
		return a;
}




int main()
{
	/*
	int a = 2;
	swap(a);
	cout << a <<endl;

	Test t1;
	t1.swap(a);
//	cout << t1.test<<endl;
*/
	int a =2,b =20;
	 min(a,b) =30;
	 cout << "a: "<<a<<"  b: "<<b <<endl;





}
