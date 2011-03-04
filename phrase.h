#ifndef PHRASE_H
#define PHRASE_H
#include <iostream>
#include <string>
#include "element.h"
using namespace std;
class Phrase
{
	public:
		Phrase(string);
		 virtual void complete(const Dict&);
       //void correction(const Dict&);
         virtual void show();
         virtual void check(const Dict &);
		~Phrase();
	private:
		string input;
		string input2;
		int counter;
		};
#endif