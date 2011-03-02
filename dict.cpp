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
	sent = NULL;
	const char BLANK = ' ',
		   ENDST = '.';
	char ch;
	ifstream source(f.c_str());
	ifstream *file = &source;
	if ( !source)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	//Create word list
	int i = 0;
	while (file->eof() == 0 )
	{
		file->get(ch);
		//cout << ch << endl;
		if ((ch == BLANK) || (ch == ENDST))
		{
			//cout << i << endl;
			i++;
		}
	}
	word = new string [i];
	i = 0;
	file->clear();
	file->seekg(0);
	while (file->eof() == 0)
	{
		string test;
		//char buffer[250];
		(*file) >> test;
		//word[i] = NULL;
		word[i].assign(test);
		//cout << word[i] << endl;
		i++;
	}
	file->clear();
	file->seekg(0);
	i = 0;
	
	//Create sentence list
	while (file->eof() == 0)
	{
		cout << "checking sentence size" << endl;
		file->get(ch);
		if (ch == ENDST)
		{
			i++;
		}
		cout << i << endl;
	}

	sent = new string [i];
	int limit = i;
	cout << "Memory Allocated" << endl;
	i=0;
	file->clear();
	file->seekg(0);
	cout << "Entering while loop" << endl;
	while (file->eof() == 0 && i < limit)
	{
		if (i < limit){
		string buffer;
		getline(*file, buffer,'.');
		sent[i].assign(buffer);
		i++;}
	}
	file->clear();
	file->seekg(0);
	i = 0;
	cout << limit << endl;
}

void Dict::print(int i)
{
	cout << sent[i] << endl;
}

Dict::~Dict()
{
	cout << "Deleting dictionary" << endl;
	delete [] sent;
	delete [] word;
}
