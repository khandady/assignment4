#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>
using namespace std;
class Word
{
	public:
		Word();
		void complete(string , const Dict&);
		void correction(string , const Dict&);
		void show();
		void check(string input);
		~Word();
	private:
		string input1;
		string input2;
		int counter;
		};
#endif