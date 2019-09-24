/*************************************************************************
	> File Name: signalHandle.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月23日 星期一 15时59分55秒
 ************************************************************************/

#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;

void signalhandler(int signum)
{
	cout << "Interrupt signal : "<<signum << " received!"<<endl;
}


int main()
{
	signal(SIGINT,signalhandler);
	while(1)
	{
		cout << "Going to sleep..."<<endl;
		sleep(1);
	}
	return 0;
}

