/* Michael Riedlin
   Karthik Handady
   Class definitions for Sentence */

#include <iostream>
#include <string>
#include <fstream>
#include "sentence.h"

Sentence::Sentence(string in, const Dict *dictionary) : Element
{
	input =  in;
	d = dictionary;
	sent = NULL;
	chck = NULL;
	distance = 0;
	for (int i=0; i<10;i++)
	{diststore[i] = 10000;}
}

void Sentence::complete(const Dict &d)
{
	sent = new string[10];
	string test = d.lookup_sent();
	//If input and string have same length, check to see if they're the same
	if (test.length() == input.length)
	{
		//If same, store string
		if (test.compare(input) == 0)
		{
			sent[0] = test;
		}
	}
	//If input is shorter than string
	if (test.length() > input.length)
	{
		//If substrings are the same
		if (input.compare(test.substr(0,input.length())) == 0)
		{
			//Check distance and store as appropriate
			distance = test.length() - input.length;
			int count = 0;
			while (count < 10)
			{
				if (distance < diststore[count])
				{
