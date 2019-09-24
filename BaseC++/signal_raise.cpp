/*************************************************************************
	> File Name: signal_raise.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月23日 星期一 16时37分57秒
 ************************************************************************/

#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;

void signalhandler(int signum)
{
	cout << "signum : "<< signum<<endl;
	
}


int main()
{
	int i=0;
	signal(SIGINT, signalhandler);

	while(++i)
	{
		cout << "Going to sleep..."<<endl;
		if(3 ==i)
		{
			raise(SIGINT);//i==3时，会主动发送SIGINT信号
		}
		sleep(1);
	}
	return 0;
}

