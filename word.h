#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>
#include "element.h"
using namespace std;
class Word
{
	public:
		Word(string);
		virtual void complete(const Dict&);
        //void correction(const Dict&);
        virtual void show();
        virtual void check(const Dict &);
		~Word();
	private:
		string input;
		string input2;
		int counter;
		};
#endif