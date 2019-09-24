/*************************************************************************
	> File Name: thread.cpp
	> Author: qiaoyuhu
	> Mail: yuhuqiao@163.com 
	> Created Time: 2019年09月23日 星期一 17时13分28秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5



void *PrintHello(void *threadid)
{
	int tid = *((int *)threadid);
	cout << "Hello Runoob! 线程ID:"<<tid <<endl;
	pthread_exit(NULL);
}


int main()
{
	pthread_t threads[NUM_THREADS];
	int indexs[NUM_THREADS];
	int rc;
	int i;
	for(i=0; i<NUM_THREADS; i++)
	{
		cout << "main(): 创建线程 "<<i <<endl;
		indexs[i] =i;
		rc = pthread_create(&threads[i],NULL,PrintHello,(void*)&indexs[i]);
	}
	pthread_exit(NULL);
}

