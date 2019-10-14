/*************************************************************************
	> File Name: at.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月29日 星期日 14时38分53秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec(10);
	for(int i=0; i<5; i+=2)
	{
		vec.insert(vec.begin()+i,i);
	}
	cout << "size: " << vec.size()<<endl;
	for(int i =0;i<vec.size(); i++)
	{
		int k = vec.at(i);
		cout << k <<endl;
	}
}
