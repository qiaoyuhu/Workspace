/*************************************************************************
	> File Name: vector.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年10月14日 星期一 13时33分46秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
void PrintVector(const vector<T> &v)
{
	typename vector<T>::const_iterator i;
	for(i = v.begin(); i!=v.end(); ++i)
		cout << *i <<"  ";
	cout <<endl;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	vector<int> v(a,a+5); //将数组a的前五个(全部)放入v
	vector<int>::iterator p2 =v.end();//p2指向最后一个元素5的后面一位
	vector<int>::iterator p1 =v.begin();
	//cout <<"begin: "<< *p1 <<endl;	//第一位的值
	//cout <<"end: "<< *(p2-1) <<endl;//最后一位的值

	cout <<"1> "<< p2 -p1<<endl;//5  p2所指向元素和 p1 所指向元素的序号之差()
	cout << "2> ";
	PrintVector(v);

	v.insert(v.begin()+2, 13);
	cout << "3> ";PrintVector(v);
	sort(v.begin(), v.end());//从小到大排序sort(),再algorithm头文件中
	cout << "3> ";PrintVector(v);
	
	v.erase(v.begin()+2);
	cout << "4> ";PrintVector(v);

	vector<int> v2(4,100);//4个元素，都是100
	v2.insert(v2.begin(),v.begin(),v.begin()+2);//将v的一段插入v2的开头
	cout << "5> ";PrintVector(v2);

	v.erase(v.begin()+1 , v.begin()+3 );
	cout << "6> ";PrintVector(v);




	

}
