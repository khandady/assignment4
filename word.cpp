#include "word.h"
//#include "element.h"
#include <iostream>
#include <string>
using namespace std;
Word::Word(){

}

void Word::complete(string input, const Dict& book){
int a =0;
int b=0;
int max;
max = book.getlength(1);
cout<<"Word completion for: "<<input<<"\n";
cout<<"--------------------------------"<<"\n";
while(a < max){
int counter = 1;
input2 = book.lookup(1, a);
for(int i=0; i < input.length()-1; i++){	//for loop that flags counter as zero if beginning is not the same
	if(input[i] != input2[i]){
		counter = 0;
		break;
	}
}
if(counter == 1){
	cout<<input2<<"\n";
	b++;
}
a++;
}

if(b == 0){
	cout<<"no completion found \n";
}

}

void Word::check(string input){


}

void Word::correction(string input, const Dict& book){
int a =0;
int b=0;
int max;
max = book.getlength(1);
int n[max];
string m[max];
cout<<"Word correction for: "<<input<<"\n";
cout<<"--------------------------------"<<"\n";
while( a < max){
int counter = 0;
int num=0;
input2 = book.lookup(1, a);
if(input2.length() > input.length()-1){
	num=input2.length();
}
else {
	num=input.length()-1;
}
//Hamming distance calculator
for(int i=0; i < num; i++){
	if(input[i] != input2[i]){
		counter++;
	}
}


if(a<10){
m[a] = input2;
n[a] = counter;
}
else{
for(int L=0; L<10;L++){
	if(counter < n[L]){
		for(int x=11; x>L; x--){
		n[x] = n[x-1];
		m[x]= m[x-1];
		}
		m[L] = input2;
		n[L] = counter;
		break;
	}	
}
}

a++;
}

for(int w=0; w<10; w++){
cout<<m[w]<<"  "<<n[w]<<"\n";
}

}

void Word::show(){



}

Word::~Word(){

}
