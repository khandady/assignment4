#ifndef PHRASE_H
#define PHRASE_H
#include <iostream>
#include <string>
#include "element.h"
using namespace std;
class Phrase
{
	public:
		Phrase();
		void complete(string , const Dict&);
		void correction(string , const Dict&);
		void show();
		void check(string input);
		~Phrase();
	private:
		string input2;
		int counter;
		};
#endif