/* Michael Riedlin
   Karthik Handady
   Main for hw4 */

//include statements
#include "dict.cpp"
#include "word.cpp"
#include "element.h"
#include "phrase.cpp"
#include "sentence.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const Dict book("new-data.txt");
	string quit = "n";
	while(quit != "y")						//main loop
	{
		int i=0;
		int flag=0;
		string input;
		cout<<"Enter a partial word, phrase, or sentence: ";
		getline(cin, input);					//get input
		for(i=0; i < input.length(); i++)			//determine input type
		{
			if(input[i] == '.'){							
				flag = 3;
			}
			else if(input[i] == '\t'){
				flag = 1;
			}
			else
				flag = 2;
		}
		if(flag == 1){               				//if input was flagged as word
			Word *word = new Word(input);
			word->complete(book);
			word->check(book);
			word->show();
		}
		if(flag == 2){
			Phrase *phrase = new Phrase(input);
			phrase->complete(book);
			phrase->check(book);
			phrase->show();
		}
		if(flag == 3){
			Sentence *sent = new Sentence(input);
			sent->complete(book);
			sent->check(book);
			sent->show();
		}
		cout << "Enter y to quit" << endl;
		getline(cin, quit);
		cout<<"\n";
	}
}
