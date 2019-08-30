/*************************************************************************
  > File Name: sem_init.cpp
  > Author: yuhuqiao
  > Mail: yuhuqiao@163.com 
  > Created Time: 2019年07月22日 星期一 14时49分25秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define WORD_SIZE 1024
using namespace std;

string work_area ;
void *thread_function(void *arg);
sem_t bin_sem;
/**
*线程接收到信号，打印work_area。
*
*/



int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;
	res = sem_init(&bin_sem,0,0);
	if(res!=0)
	{
		perror("初始化信号量失败");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread,NULL,thread_function,NULL);
	if(res !=0)
	{
		perror("线程创建失败");
		exit(EXIT_FAILURE);
	}
	cout <<"请输入要发送的信息，end结束"<<endl;
	while(work_area != "end")
	{
		cin >>work_area;
		sem_post(&bin_sem);
	}

	cout << "等待线程结束"<<endl;
	res = pthread_join(a_thread,&thread_result);
	if(res !=0)
	{
		perror("等待线程创建失败");
		exit(EXIT_FAILURE);
	}
	cout << "线程结束"<<endl;
	sem_destroy(&bin_sem);
	exit(EXIT_SUCCESS);

}

void show()
{
	cout << "Received Msg："<<work_area<<endl;
	cout << "Test Merge Again"<<endl;
}


void *thread_function(void *arg)
{
	sem_wait(&bin_sem);
	while(work_area !="end")
	{
		show();
		sem_wait(&bin_sem);
	}
}



