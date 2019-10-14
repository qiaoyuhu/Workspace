/*************************************************************************
	> File Name: list.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年10月14日 星期一 15时20分40秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class A
{
	private:
		int n  ;
	public:
		A(int n){this->n = n;}
		friend bool operator <(const A& a1, const A& a2);
		friend bool operator ==(const A& a1, const A& a2);
		friend ostream & operator <<(ostream &o, const A&a);
};

bool operator <(const A& a1, const A& a2)
{
	return a1.n <a2.n;
}

bool operator ==(const A& a1, const A&a2)
{
	return a1.n == a2.n;
}

ostream & operator <<(ostream &o, const A&a)
{
	o << a.n;
	return o;
}

template <typename T>
void Print(T first ,T last)
{
	for(T i=first; i!=last; ++i)
	{
		cout << *i << "  ";
	}
	cout << endl;
}
int main()
{
	A a[5]= {1,3,6,2,3};
	A b[7]= {10,30,20,20,40,30,40};
	list <A> lst1(a, a+5);
	list <A> lst2(b, b+7);
	lst1.sort();//从小到大排序
	Print(lst1.begin(), lst1.end());
	
	
	lst2.sort();
	Print(lst2.begin(), lst2.end());

	lst1.remove(2);//删除所有值为2的元素
	Print(lst1.begin(), lst1.end());

	lst2.pop_front();//删除链表最前面的元素
	Print(lst2.begin(), lst2.end());


	lst2.unique();//删除所有和前面一个元素相等的元素
	Print(lst2.begin(), lst2.end());

	lst1.merge(lst2);//合并lst2到lst1，并清空lst2

	cout << "1> ";Print(lst1.begin(), lst1.end());
	cout << "2> ";Print(lst2.begin(), lst2.end());


	lst1.reverse();//将lst1前后颠倒
	cout << "3> ";Print(lst1.begin(), lst1.end());

	lst2.insert(lst2.begin(), a+1, a+4);//插入3,6,2
	cout << "4> ";Print(lst2.begin(), lst2.end());

	list <A>::iterator p1,p2,p3;
	p1 = find(lst1.begin(),lst1.end(), 30);
	p2 = find(lst2.begin(),lst2.end(), 3);
	p3 = find(lst2.begin(),lst2.end(), 2);

	lst1.splice(p1, lst2, p2,p3);//将[p2,p3)插入p1之前，并在lst2中删除[p2,p3)左闭右开，包含p2,不包含p3
	
	cout << "5> ";Print(lst1.begin(), lst1.end());
	cout << "6> ";Print(lst2.begin(), lst2.end());
}






































