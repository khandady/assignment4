//#include "element.h"
#include "word.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
int i=0;
int flag=0;
Word word;
string input;
cout<<"Enter a partial word, phrase, or sentence: ";
getline(cin, input);
for(i=0; i < input.length(); i++)
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
word.complete(input);
word.correction(input);
}