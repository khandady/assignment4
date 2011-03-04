#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <string>
using namespace std;
class element
{
	public:
		virtual void complete(const Dict &d) = 0;
		virtual void check(const Dict &d) = 0;
		virtual void show() const = 0;
	private:
		
};
#endif