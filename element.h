/* Michael Riedlin
   Karthik Handady
   Element abstract class */

#ifndef ELEMENT_H
#define ELEMENT_H
class Element
{
	public:
	virtual void complete(const Dist &d) = 0;
	virtual void check(const Dict &d) = 0;
	virtual void show() = 0;
};
#endif 
