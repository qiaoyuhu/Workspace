/*************************************************************************
  > File Name: strncpy.cpp
  > Author: qiaoyuhu
  > Mail: yuhuqiao@163.com 
  > Created Time: 2019年08月29日 星期四 15时03分14秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

void myStrncpy()
{
	char str[4] = {'w', 'x', 'y', 'z'};
	char *p = "a\0bcdefg";
	strncpy(str, p, sizeof(str) - 1);

	cout << int(str[0]) << endl; // 'a'
	cout << int(str[1]) << endl; // '\0'
	cout << int(str[2]) << endl; // '\0'   //确实要注意这个值， 不是'b'   why?

	cout << int(str[3]) << endl; // 'z'

}


int main()
{
	myStrncpy();
	return 0;

	char str[4] = {0};


	char *p = "abc";
	//strcpy(str,p);
	strncpy(str,"abcdefg",sizeof(str)-1);
	cout << str <<endl;
}
