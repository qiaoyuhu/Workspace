/*************************************************************************
	> File Name: find.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年10月14日 星期一 11时23分58秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a[10] = {10,20,30,40};
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator p;
	p = find(v.begin(),v.end(),4);
	// [first,last)这是一个左闭右开的区间，即last指向的元素其实不在此区间内，指向4后面的位置
	if(p !=v.end())
	{
		cout << "1: "<<*p <<endl;
	}

	p = find(v.begin(), v.end(),9);//查找9
	if(p == v.end())	//没找到
	{
		cout << "not found" <<endl; // 
	}

	p = find(v.begin()+1, v.end()-1, 20);
	cout << "2: " << *p <<endl;	//4  没找到20，p指向最后一个
}
