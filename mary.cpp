#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
int
main(void)
{
	ifstream text("mary.txt");
	char buffer[255];
	string stgbuf;
	text.getline(buffer, 255, '.');
	cout << "using c style string" << endl;
	cout << buffer << endl;
	stgbuf.assign(buffer);
	cout << stgbuf<< endl;
	//stgbuf.assign(text.getline(buffer,255,'.'));
	//cout << "attempting string assignment" << endl;
	//cout << stgbuf << endl;
	return 0;
}
