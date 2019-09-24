/*************************************************************************
  > File Name: duotai.cpp
  > Author: qiaoyuhu
  > Mail: yuhuqiao@163.com 
  > Created Time: 2019年09月20日 星期五 15时14分42秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Shape
{
	protected:
		int width,height;
	public:
		Shape(int a=0,int b=0)
		{
			width = a ;
			height = b;
		}
		virtual int area()=0;
		/*
		{
			cout << "parent class area" <<endl;
			return 0;
		}*/
};

class Rectangle:public Shape
{
	public:
		Rectangle(int a=0, int b=0):Shape(a,b){}
		int area()
		{
			cout << "Rectangle class area" <<endl;
			return (width * height);
		}

};

class Triangle:public Shape
{
	public:
		Triangle(int a=0, int b=0):Shape(a,b){}
		/*
		int area()
		{
			cout << "Triangle class area" <<endl;
			return (width * height / 2);
		
		}
		*/

};

int main()
{
	Shape *shape;
//	Shape s1;//Shape 中含有纯虚函数,所以Shape为抽象类，抽象类不能进行实例化，只能作为基类使用。其派生类必须实现此纯虚函数之后才能被实例化
	Rectangle rec(10,7);
	Triangle  tri(10,5);	//没有实现area()函数，无法实例化

	// 存储矩形的地址
	shape = &rec;
	// 调用矩形的求面积函数 area
	shape->area();

	// 存储三角形的地址
	shape = &tri;
	// 调用三角形的求面积函数 area
	shape->area();

	return 0;

/*

	Shape *shape;
	Rectangle rectangle(10,7);
	Triangle triangle(10,5);
	shape = &rectangle;
	shape->area();

	shape = &triangle;
	shape->area();
	*/
}















