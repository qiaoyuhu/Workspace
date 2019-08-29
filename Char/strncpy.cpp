/*************************************************************************
	> File Name: strncpy.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年08月29日 星期四 15时03分14秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char str[4]  = {0};
	char *p = "a\0bcdefghijklmn";
//	strcpy(str,p);
	strncpy(str,p,sizeof(str)-1);
	cout << str <<endl;
}
