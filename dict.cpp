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
	sort(word,word +ref);
	sort(sent,sent +limit);
	sort(phrs,phrs +((4*ref)-10));

	//filtering
	i=1;
	int newsize = 1;
	string test = word[0];
	while(i<ref)
	{
		if(test.compare(word[i]) == 0)
		{i++;}
		else
		{i++;newsize++;test=word[i];}
	}
	string *ptr = new string[newsize];
	test = word[0];
	ptr[0].assign(test);
	i=1;
	int newcount = 0;
	while(i<ref)
	{
		if(ptr[newcount].compare(word[i]) == 0)
		{i++;}
		else
		{i++;newcount++;ptr[newcount].assign(word[i]);}
	}
	delete [] word;
	word = ptr;
	//sentence filter
	cout << "sentence filter" << endl;
        i=1;
        newsize = 1;
        test = sent[0];
	cout << "first sent loop" << endl;
	cout << limit << endl;
        while(i<limit)
        {
		cout << i << endl;
                if(test.compare(sent[i]) == 0)
                {i++;}
                else
                {newsize++;test=sent[i];i++;}
        }
	cout << "out of loop" << endl;
        ptr = new string[newsize];
        test = sent[0];
        ptr[0].assign(test);
        i=1;
        newcount = 0;
	cout << "second sent loop" << endl;
        while(i<limit)
        {
                if(ptr[newcount].compare(sent[i]) == 0)
                {i++;}
                else
                {newcount++;ptr[newcount].assign(sent[i]);i++;}
        }
        delete [] sent;
        sent = ptr;
	//phrase filter
	cout << "phrase filter" << endl;
        i=1;
        newsize = 1;
        test = phrs[0];
        while(i<((4*ref)-10))
        {
                if(test.compare(phrs[i]) == 0)
                {i++;}
                else
                {newsize++;test=phrs[i];i++;}
        }
        ptr = new string[newsize];
        test = phrs[0];
        ptr[0].assign(test);
        i=1;
        newcount = 0;
        while(i<((4*ref)-10))
        {
                if(ptr[newcount].compare(phrs[i]) == 0)
                {i++;}
                else
                {newcount++;ptr[newcount].assign(phrs[i]);i++;}
        }
        delete [] phrs;
        phrs = ptr;

	//set lengths
	wordl = ref;
	phrsl = (4*ref)+10;
	sentl = limit;

}

const string Dict::lookup(int type, int i)
{
	if (type = 1) {return word[i];}
	if (type = 2) {return phrs[i];}
	if (type = 3) {return sent[i];}
}

const int Dict::getlength(int i)
{
	if (i = 1) {return wordl;}
	if (i = 2) {return phrsl;}
	if (i = 3) {return sentl;}
}
void Dict::print(int i)
{
	cout << word[i] << endl;
}

Dict::~Dict()
{
	cout << "Deleting dictionary" << endl;
	delete [] sent;
	delete [] word;
	delete [] phrs;
}
