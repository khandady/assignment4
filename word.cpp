#include "word.h"
//#include "element.h"
#include <iostream>
#include <string>
using namespace std;
Word::Word(){

}

void Word::complete(string input, const Dict& book){
int max;
max = book.getlength(1);
cout<<"Max is : "<<max<<"\n";
int counter = 1;
cout<<"Enter a word: ";
getline(cin, input2);
for(int i=0; i < input.length()-1; i++){	//for loop that flags counter as zero if beginning is not the same
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

void Word::correction(string input, const Dict&){
int num = input.length();
int counter = 0;
cout<<"Enter a word: ";
getline(cin, input2);
if(input2.length() >= input.length()){
num = input2.length();
}

//Hamming distance calculator
for(int i=0; i < num; i++){
	if(input[i] != input2[i]){
		counter++;
	}
}
cout<<"Hamming distance is "<<counter<<"\n";
// overarching while loop that sorts the array 

}

void Word::show(){



}

Word::~Word(){

}
