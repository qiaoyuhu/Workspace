/*************************************************************************
	> File Name: templateclass.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月23日 星期一 13时42分31秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

template <class T>
class Stack
{
	private:
		vector<T> elems;

	public:
		void push (T const&);//入栈
		void pop();		//出栈
		T top()const;		//返回栈顶元素
		bool empty() const
		{ return elems.empty(); }//如果为空则返回真
};


template <class T>
void Stack<T>::push(T const &elem)
{
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if(elems.empty())
	{
		throw "Stack<>::pop():empty stack";
	}
	elems.pop_back();
}


template <class T>
T Stack<T>::top() const
{
	if(elems.empty())
	{
		throw out_of_range("Stack<>::pop():empty stack");
	}
	return elems.back();
}




int main()
{
	try
	{
		Stack<int> intStack;//int类型的栈
		Stack<string> stringStack;//string类型的栈

		intStack.push(7);
		cout << intStack.top() <<endl;

		stringStack.push("hello");
		cout << stringStack.top()<<endl;
		stringStack.pop();
		stringStack.pop();//elems为空，抛出异常

	}catch(const char* ex)
	{
		cout<<"Exception: "<<ex <<endl;
		return -1;
	}
}































