/*************************************************************************
	> File Name: operator.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月09日 星期一 10时09分10秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Box
{
	public:
		double getVolume()
		{
			return length * breadth * height;
		}
		void setLength(double len)
		{
			length = len;
		}
		void setBreath(double bre)
		{
			breadth = bre;
		}
		void setHeight(double hei)
		{
			height = hei;
		}
		Box operator+(const Box& b)//重载＋运算符
		{
			Box box;
			box.length  = this->length + b.length;
			box.breadth = this->breadth + b.breadth;
			box.height  = this->height + b.height;
			return box;
		}

	private:
		double length;	//长度
		double breadth; //宽度
		double height;	//高度
};


int main()
{
	Box box1, box2, box3;
	double volume = 0.0;

	box1.setLength(6.0);
	box1.setBreath(7.0);
	box1.setHeight(5.0);

	box2.setLength(6.0);
	box2.setBreath(7.0);
	box2.setHeight(5.0);

	volume = box1.getVolume();
	cout << "volume of box1 : "<<volume <<endl;


	volume = box2.getVolume();
	cout << "volume of box2 : "<<volume <<endl;


	//两个对象相加
	box3 = box1 + box2;
	volume = box3.getVolume();
	cout << "volume of box3 : "<<volume <<endl;
	return 0;
	
	
}






















