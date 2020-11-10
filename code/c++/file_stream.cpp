#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	string buffer = "";
	ofstream outFile;

	outFile.open("afile.dat");
	cout << "Writing to the file" << endl;
	cout << "Enter your name: ";
	cin.getline((char*)buffer.c_str(), 100);

	outFile << buffer <<endl;

	cout << "Enter your age: ";
	cin >> buffer;
	cin.ignore();

	outFile << buffer <<endl;
	outFile.close();

	ifstream inFile;
	inFile.open("afile.dat");

	cout << "Reading from the file" << endl;
	inFile >> buffer;
	cout << buffer;

	inFile >> buffer;
	cout << buffer << endl;
	inFile.close();

	return 0;
}
