/*************************************************************************
	> File Name: new_delete.cpp
	> Author: calebcay
	> Mail: calebcay@163.com 
	> Created Time: 2020年11月10日 星期二 07时07分42秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int i, j, k;
	int*** p = nullptr;

	p = new int** [2];
	for (i = 0; i < 2; i++) {
		p[i] = new int* [3];
		for (j = 0; j < 3; j++) {
			p[i][j] = new int[4];
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 4; k++) {
				p[i][j][k] = i + j + k;
				cout << p[i][j][k] << " * ";
			}
			cout << endl;
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			delete[] p[i][j];
		}
	}

	for (i = 0; i < 2; i++) {
		delete[] p[i];
	}

	delete[] p;

	return 0;
}
