#ifndef PHRASE_H
#define PHRASE_H
#include <iostream>
#include <string>
#include "element.h"
using namespace std;
class Phrase : Element
{
	public:
		Phrase(string);
		 virtual void complete(const Dict&);
       //void correction(const Dict&);
         virtual void show() const;
         virtual void check(const Dict &);
		~Phrase();
	private:
		string input;
		string input2;
		int counter;
		};
#endif
