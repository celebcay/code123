/*************************************************************************
 * File Name: pthread_create.cpp
 * Author: calebcay
 * Mail: calebcay@163.com 
 * Created Time: 2020年11月11日 星期三 03时57分02秒
 ************************************************************************/

#include <iostream>
#include <pthread.h>

using namespace std;

namespace {
	const int NUM_THREADS = 5;
}

void* RunningThread(void* argv)
{
	cout << "Hello Runoob!" << endl;
	return nullptr;
}

int main()
{
	pthread_t tids[NUM_THREADS];
	for (register int count = 0; count < NUM_THREADS; count++) {
		int result = pthread_create(&tids[count], nullptr, RunningThread, nullptr);
		if (result != 0) {
			cout << "Pthread create error : error_code = " << result <<endl;
		}
	}
	pthread_exit(nullptr);
}
