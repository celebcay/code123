/*
 * File Name: pthread_join.cpp
 * Author: calebcay
 * Mail: calebcay@163.com 
 * Created Time: 2020年11月11日 星期三 04时48分30秒
 */

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

namespace {
	const int NUM_THREAD = 5;
}

void* Wait(void* data) 
{
	long tid = *((long*)data);
	sleep(1);
	cout << "Sleeping in thread!" << endl;
	cout << "Thread with id : " << tid << "...exiting!" <<endl;
	pthread_exit(nullptr);
}

int main()
{
	pthread_t tids[NUM_THREAD];
	pthread_attr_t attr;
	void* status = nullptr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for (register int i = 0; i < NUM_THREAD; i++) {
		cout << "Ctreat : " << i << endl;
		int result = pthread_create(&tids[i], nullptr, Wait, (void*)&i);
		if (result != 0) {
			cout << "Eorror : " << result << endl;
			pthread_exit(nullptr);
			exit(-1);
		}
	}

	pthread_attr_destroy(&attr);

	for (register int i = 0; i < NUM_THREAD; i++) {
		int result = pthread_join(tids[i], &status);
		if (result != 0) {
			cout << "Error : join " << result << endl;
		}
		cout << "main completed " << i << "exiting status : " << status <<endl;
	}
	cout << "exiting!" << endl;
	pthread_exit(nullptr);
}
