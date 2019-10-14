/*************************************************************************
	> File Name: sort.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年10月14日 星期一 13时21分50秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int a[4] = {3,4,2,5};
	sort(a, a+4);
	for(int i=0; i<4; ++i)
	{
		cout << a[i] <<"  ";
	}
	cout <<endl;
}
