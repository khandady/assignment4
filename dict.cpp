/* Michael Riedlin
   Karthik Handady
   Function definitions for Dict class */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "dict.h"

using namespace std;

//Constructor
Dict::Dict(string f)
{
	const char BLANK = ' ',
		   ENDST = '.';
	char ch;
	ifstream source(f.c_str());
	if ( !source)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	//Create word list
	int i = 0;
	while (source.eof() == 0 )
	{
		source.get(ch);
		//cout << ch << endl;
		if ((ch == BLANK) || (ch == ENDST))
		{
			cout << i << endl;
			i++;
		}
	}
	cout << "Declare memory" << endl;
	word = new string[i];
	i = 0;
	source.clear();
	source.seekg(0);
	cout << "Storage loop" << endl;
	while (source.eof() == 0)
	{
		cout << "in loop" << endl;
		void *ptr = &word[i];
		source.get((char *) ptr,250, BLANK);
		i++;
	}
	cout << "clear source" << endl;
	source.clear();
	source.seekg(0);
	i = 0;
	
	//Create sentence list
	while (source.eof() == 0)
	{
		cout << "checking sentence size" << endl;
		source.get(ch);
		if (ch == ENDST)
		{
			i++;
		}
	}

	sent = new string[i];
	i=0;
	source.clear();
	source.seekg(0);
	while (source.eof() == 0)
	{
		void *ptr = &sent[i];
		source.get((char *) ptr,250,46);
		i++;
	}
	source.clear();
	source.seekg(0);
	i = 0;
}

void Dict::print(int i)
{
	cout << *word << endl;
}

