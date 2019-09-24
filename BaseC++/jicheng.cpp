/*************************************************************************
	> File Name: jicheng.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月09日 星期一 09时29分13秒
 ************************************************************************/

#include <iostream>
using namespace std;

//基类
class Shape
{
	public:
		void setWidth(int w)
		{
			width = w;
		}
		void setHeight(int h)
		{
			height = h;
		}
	protected:
		int width;
		int height;
};

//基类
class PaintCost
{
	public:
		int getCost(int area)
		{
			return (area * 70);
		}
};

//派生类
class Rectangle:public Shape,public PaintCost
{
	public:
		int getArea()
		{
			return (width * height);
		}
};

int main()
{
	Rectangle Rect;
	Rect.setWidth(4);
	Rect.setHeight(5);
	
	int area = Rect.getArea();//继承自Shape
	cout << "area : " << area <<endl;
	cout << "Cost :"<<Rect.getCost(area) <<endl; //继承自PainCost




}
