/*************************************************************************
	> File Name: cur_system_time.cpp
	> Author: calebcay
	> Mail: calebcay@163.com 
	> Created Time: 2020年11月09日 星期一 05时59分20秒
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class CurSystemTime {
public:
	string ShowLocalSystemTime ();
	string ShowUTCSystemTime ();
	string ShowStructSystemTime ();
};

string CurSystemTime::ShowLocalSystemTime()
{
	time_t nowSystemTime = time(0);
	return ctime(&nowSystemTime);
}

string CurSystemTime::ShowUTCSystemTime()
{
	time_t nowSystemTime = time(0);

	tm* changeUTCTime = gmtime(&nowSystemTime);
    return asctime(changeUTCTime);
}

string CurSystemTime::ShowStructSystemTime ()
{	
	time_t nowSystemTime = time(0);
	char tempTime[1024] = { 0 };

	tm* localStructTime = localtime(&nowSystemTime);
	sprintf(tempTime, "%ld\n%d.%d.%d %d:%d:%d", nowSystemTime,
			1900 + localStructTime->tm_year, 1 + localStructTime->tm_mon,
			localStructTime->tm_mday, localStructTime->tm_hour,
			localStructTime->tm_min, localStructTime->tm_sec);
	return tempTime;
}

int main()
{
	CurSystemTime* localTime = nullptr;

	cout << "SystemTime: " << localTime->ShowLocalSystemTime() << endl;
	cout << "ChangeUTCTime: " << localTime->ShowUTCSystemTime() << endl;
	cout << "StructTime: " << localTime->ShowStructSystemTime() << endl;
	return 0;
}
