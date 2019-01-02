#ifndef WORDS_
#define WORDS_
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <vector>

using namespace std;

struct Node{
public:
    string word;
    int number;
    void setWord(string _word){word = _word;};
    void setNumber(int _number){number = _number;};
    string getWord(){return word;};
    int getNumber(){return number;};

};

#endif
