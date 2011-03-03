#include "word.h"
//#include "element.h"
#include <iostream>
#include <string>
using namespace std;
Word::Word(){

}

void Word::complete(string input){
size_t position;
string input1;
int counter = 1;
cout<<"Enter a word: ";
getline(cin, input2);

for(int i=0; i < input.length()-1; i++){
	if(input[i] != input2[i]){
		counter = 0;
		break;
	}
}

cout<<"Word completion for: "<<input<<"\n";
cout<<"--------------------------------"<<"\n";
if(counter == 0){
	cout<<"no completion \n";
}
else if(counter == 1){
	cout<<input2<<"\n";
}

}

void Word::check(string input){


}

void Word::correction(string input){

int counter = 0;
cout<<"Enter a word: ";
getline(cin, input2);
//Hamming distance calculator
for(int i=0; i < input.length()-1; i++){
	if(input[i] != input2[i]){
		counter++;
	}
}
cout<<"Hamming distance is "<<counter<<"\n";
}

void Word::show(){



}

Word::~Word(){

}
