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
	word = NULL;
	//phrs = NULL;
	//sent = NULL;
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
	word = new string [i];
	i = 0;
	source.clear();
	source.seekg(0);
	while (source.eof() == 0)
	{
		char buffer[250];
		source >> buffer;
		//word[i] = NULL;
		word[i].assign(buffer);
		cout << word[i] << endl;
		i++;
	}
	source.clear();
	source.seekg(0);
	i = 0;
/*	
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

	sent = new string*[i];
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
	i = 0;*/
}

void Dict::print(int i)
{
	cout << word[i] << endl;
}

