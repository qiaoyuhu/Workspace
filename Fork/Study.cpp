/*************************************************************************
  > File Name: Study.cpp
  > Author: qiaoyuhu
  > Mail: yuhuqiao@163.com 
  > Created Time: 2019年08月29日 星期四 16时40分40秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;

string Msg ;
sem_t bin_sem;
void *thread_function(void *argu);
int main()
{
	pthread_t thread_id;
	void * thread_result;

	int res =-1;
	res = sem_init(&bin_sem,0,0);
	if(res !=0)
	{
		cout << "信号量初始化失败" <<endl;
		exit(1);
	}
	res = pthread_create(&thread_id,NULL,thread_function,NULL);
	if(res !=0)
	{
		cout << "线程创建失败" <<endl;
		exit(1);
	}
	while(Msg !="end")
	{
	cout << "Enter the message what you want to Send: ";
		cin >> Msg;
		sem_post(&bin_sem);
		sleep(1);
	}
	pthread_join(thread_id,&thread_result);
	sem_destroy(&bin_sem);




}


void *thread_function(void * argu)
{
	sem_wait(&bin_sem);
	while(Msg !="end")
	{
		cout << "Receive Msg: " << Msg<<endl;
		sem_wait(&bin_sem);
	}

}
