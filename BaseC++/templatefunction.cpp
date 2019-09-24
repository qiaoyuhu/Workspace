/*************************************************************************
	> File Name: templatefunction.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月23日 星期一 11时16分32秒
 ************************************************************************/

#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
	T t =a;
	a = b;
	b = t;
}

int main()
{
	int i =2,j=3;
	Swap(i,j);
	cout << "i: "<<i <<endl;
	cout << "j: "<<j <<endl;


	float a = 1.5, b= 2.3;
	Swap(a,b);
	cout << "a: "<<a <<endl;
	cout << "b: "<<b <<endl;

}
