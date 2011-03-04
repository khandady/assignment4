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
	string *word;			//pointers to lists
	string *phrs;
	string *sent;
	int wordl;			//list lengths
	int phrsl;
	int sentl;

	public:
	Dict(string f);			//constructor
	string lookup(int, int) const;	//finds element of type
	int getlength(int) const;		//returns a list length
	void print(int);	
	~Dict();
};
#endif
