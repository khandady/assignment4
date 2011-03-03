/* Michael Riedlin
   Karthik Handady
   Sentence class for hw4 */

#ifndef SENTENCE_H
#define SENTENCE_H
#include "element.h"
class Sentence : Element
{
	private:
	string input;
	const Dict *d; //pointer to dictionary
	string *sent; //pointer to complete container
	string *chck; //pointer to correct containecorrect container
	int distance;
	int diststore[10];

	public:
	Sentence();
	virtual void complete(const Dict &d);
	virtual void check(const Dict &d);
	virtual void show() const;
	~Sentence();
}
#endif
