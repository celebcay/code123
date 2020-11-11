/*
 * File Name: pthread_argv.cpp
 * Author: calebcay
 * Mail: calebcay@163.com 
 * Created Time: 2020年11月11日 星期三 04时17分24秒
 */

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

namespace {
	const int NUM_PTHREAD = 5;
}

void* PrintText(void* threadId)
{
	int curTid = *((int*)threadId);
	cout << "Hello pthreadid = " << curTid <<endl;
	pthread_exit(nullptr);
}

int main()
{
	pthread_t tids[NUM_PTHREAD];
	int index[NUM_PTHREAD] = { -1 };
	for (register int count = 0; count < NUM_PTHREAD; count++) {
		cout << "Create pthead id : " << count << " in main." << endl;
		index[count] = count * 2;
		int result = pthread_create(&tids[count], nullptr, PrintText, (void*)&(index[count]));
		if (result != 0) {
			cout << "Pthread not create, " << result << endl;
			pthread_exit(nullptr);
			exit(-1);
		}
	}
	pthread_exit(nullptr);
	return 0;
}
