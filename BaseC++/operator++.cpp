/*************************************************************************
	> File Name: operator++.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月09日 星期一 10时34分30秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Time
{
	public:
		Time()
		{
			hour = 0;
			minutes = 0;
		}
		Time(int h, int m)
		{
			hour = h;
			minutes = m;
		}
		void operator ++(int)//t1++
		{
			minutes +=2;
			if(minutes >=60)
			{
				hour ++;
				minutes -=60;
			}
		}
		void operator ++()//++t1
		{
			minutes ++;
			if(minutes >=60)
			{
				hour ++;
				minutes -=60;
			}
		}

		void display()
		{
		cout << this->hour <<" : "<<this->minutes<<endl;

		}
	private:
		int hour;
		int minutes;
};

int main()
{
	Time t1(10,60);
	t1++;
	t1.display();
	t1++;
	t1.display();

	Time t2(11,10);
	++t2;
	t2.display();
	++t2;
	t2.display();
}
