/*************************************************************************
	> File Name: new.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月23日 星期一 09时39分53秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int **p;
	int i,j;//p[4][8]
	//开始分配四行八列的二位数组
	p = new int *[4];	
	for(i=0; i<4; i++)
	{
		p[i] = new int[8];
	}

	for(i=0 ; i<4; i++)
	{
		for(j=0; j<8; j++)
		{
			p[i][j]= i*j;
		}
	}

	for(i=0 ; i<4; i++)
	{
		for(j=0; j<8; j++)
		{
			cout <<p[i][j]<<" ";
		}
	}

	//开始释放申请的堆
	for(i=0; i<4; i++)
	{
		delete [] p[i];//删除p[i]所指向的数组
	}
	delete []p;	//删除ｐ所指向的数组
	return 0;




}
