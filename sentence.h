#ifndef SENTENCE_H
#define SENTENCE_H
#include "element.h"
#include <iostream>
#include <string>

using namespace std;

class Sentence : Element
{
        public:
                Sentence(string);
                virtual void complete(const Dict&);
                //void correction(const Dict&);
                virtual void show() const;
                virtual void check(const Dict &);
                ~Sentence();
        private:
                string input;
                string input2;
                int counter;
 };
#endif

