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
	const string lookup(int, int);	//finds element of type
	const int getlength(int);		//returns a list length
	void print(int);	
	~Dict();
};
#endif
