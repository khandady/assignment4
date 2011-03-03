/* Michael Riedlin
   Karthik Handady
   Function definitions for Dict class */

#include <algorithm>
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
	int limit = i; //used to avoid segmentation fault
	int ref = i; //used to construct phrase list
	i = 0;
	file->clear();
	file->seekg(0);
	while (file->eof() == 0)
	{
		if (i<limit){
		string test;
		getline(*file, test, ' ');
		//word[i] = NULL;
		word[i].assign(test);
		//cout << word[i] << endl;
		i++;}
	}
	i = 0;
	while (i < ref)
	{
		int pos = word[i].find('.');
		if (pos > -1)
		{
			word[i].erase(pos, pos + 1);
		}
		i++;
	}
	file->clear();
	file->seekg(0);
	i = 0;
	
	//Create sentence list
	while (file->eof() == 0)
	{
		file->get(ch);
		if (ch == ENDST)
		{
			i++;
		}
	}

	sent = new string [i];
	limit = i;
	i=0;
	file->clear();
	file->seekg(0);
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
	//remove leading whitespace
	while (i < limit)
	{
		int pos = sent[i].find(" ");
		if (pos == 0)
		{
			sent[i].erase(0,1);
		}
		else{ i++;}
	}
	i = 0;
	while (i < limit)
	{
		int pos = sent[i].find("\n");
		if (pos != -1)
		{
			sent[i].replace(pos,1," ");
		}
		else {i++;}
	}
	i=0;
	cout << "starting phrase list" << endl;
	//create phrase list from word list
	phrs = new string[(4*ref)-10];
	string buff;
	string *buffer = &buff;
	int iref; //a counter to help
	cout << "first while loop" << endl;
	while (i < (ref-1))
	{
		buffer->assign(word[i]);
		buffer->append(" ").append(word[i+1]);
		phrs[i].assign(*buffer);
		i++;
	}
	iref = i - (ref-1);
	cout << "second while loop" << endl;
	while (i < ((2*ref)-3))
	{
		buffer->assign(word[iref]);
		buffer->append(" ").append(word[iref+1]).append(" ").append(word[iref+2]);
		phrs[i].assign(*buffer);
		i++;
		iref++;
	}
	iref = i - ((2*ref) -3);
	cout << "third while loop" << endl;
	while (i < ((3*ref)-6))
	{
		buffer->assign(word[iref]);
		buffer->append(" ").append(word[iref+1]).append(" ").append(word[iref+2]).append(" ").append(word[iref+3]);
		phrs[i].assign(*buffer);
		i++;
		iref++;
	}
	iref = i - ((3*ref)-6);
	cout << "last while loop" << endl;
	while (i < ((4*ref)-10))
	{
		buffer->assign(word[iref]);
		buffer->append(" ").append(word[iref+1]).append(" ").append(word[iref+2]).append(" ").append(word[iref+3]).append(" ").append(word[iref+4]);
		phrs[i].assign(*buffer);
		i++;
		iref++;
	}

	//sort
	//sort(word,word +ref);
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
	delete [] phrs;
}
