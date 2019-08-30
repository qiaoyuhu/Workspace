/*************************************************************************
  > File Name: select.cpp
  > Author: qiaoyuhu
  > Mail: yuhuqiao@163.com 
  > Created Time: 2019年08月29日 星期四 17时41分04秒
 ************************************************************************/

#include <iostream>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;



int main()
{
	struct timeval timeout;
	int fd; 
	int ret;
	char value[52]= {0};
	fd_set readfd;
	fd = open("transit.html",O_RDONLY);
	while(1)
	{
		timeout.tv_sec =2;		//时间需要重新赋值
		timeout.tv_usec = 0;
		cout << "timeout "<<endl;
		FD_ZERO(&readfd);
		FD_SET(fd,&readfd);
		ret = select(fd+1, &readfd, NULL, NULL, &timeout);
		if(FD_ISSET(fd, &readfd))
		{
			read(fd,value,sizeof(value)-1);
			cout << value << endl;
		}

	}
}
