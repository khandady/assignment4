/* Michael Riedlin
   Karthik Handady
   A dictionary class for hw4 */

#include <string>
#ifndef DICT_H
#define DICT_H

using namespace std;
class Dict
{
	private:
	string *word;
	string *phrs;
	string *sent;

	public:
	Dict(string f);
	//~Dict();
	//tring lookup_word(int);
	//string lookup_phrs(int);
	//string lookup_sent(int);
	void print(int);
	~Dict();
};
#endif
