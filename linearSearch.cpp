//certain libraries present for unincluded versions of this implementation
// make sure to delete unnecessary libraries before compilation.
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include "linearSearch.h"

using namespace std;

bool sortWords(Node &left,Node &right){ //function to overload vector sort

    return(left.getWord() < right.getWord());

}
//simple linear search function.accepts a vector of nodes, a target string, and an int for comparisons. returns a bool indicating if found or not
bool linearSearch(vector<Node>& wordList, string Target, long long int& comparisons){

    bool found = false;
    for(unsigned int i = 0; i < wordList.size(); i++){  //iterate through the vector and check if the target matches anything
        comparisons ++;
        if(wordList[i].getWord() == Target){ //if the target is found
            wordList[i].number ++; //increment the numbers found member
            found = true;
        }
    }
    return found;
}

int main()
{
    cout << "LINEAR SEARCH PROGRAM " << endl;
    vector<Node> wordList;
    //int counter1 =0;
    int counter2 =0;
    long long int comparisons = 0;
    long long int assignments = 0;
    long int numUnique =0;
    ifstream inputFile ("wordlist.txt"); //open the text file

    /*string practice = "ABCDEfGtGFD";
    cout << practice << endl;
    transform(practice.begin(), practice.end(), practice.begin(), ::tolower);
    cout << practice << endl;
    for(string::size_type i =0; i < practice.size(); ++i){
        practice[i] = tolower(practice[i]);
    }
    cout << practice << endl;
    for(string::size_type i =0; i < readString.size(); ++i){

            }*/

    //while not end of file
    while(!inputFile.eof()){//} && counter2 < 100){

        //counter1 ++;
        string readString = "";
        getline(inputFile, readString); //grab a line of code
        if(isalpha(readString[0])){ //check if first element is alphabetic
            counter2 ++;
            transform(readString.begin(), readString.end(), readString.begin(), ::tolower); //transform to all lowercase
            bool present = linearSearch(wordList, readString, comparisons); //send to the linear search function
            if(present == false){ //if it is not found
                Node tempNode;
                tempNode.setWord(readString);
                tempNode.setNumber(1); //create a temp node and fill its data elements
                wordList.push_back(tempNode); //place elemet at the end of the vector
                assignments ++; //increment assignments
            }

        }

    }
    sort(wordList.begin(), wordList.end(),sortWords); //sort the vector
    for(unsigned int i = 0; i < wordList.size(); i++){ //loop through and get the number of unique numbers
        if(wordList[i].getNumber() == 1){
            numUnique ++;
        }
    }

    cout << numUnique << endl;
    cout << "==================================================" << endl;
    for(unsigned int i = 0; i < 10; i ++){ //loop through first ten elements
        cout << wordList[i].getWord() << ":" << wordList[i].getNumber() << endl;

    }
    cout << "==================================================" << endl;
    for(unsigned int i = wordList.size() - 10; i < wordList.size(); i ++){ //loop through ast ten elements
        cout << wordList[i].getWord() << ":" << wordList[i].getNumber() << endl;
    }
    cout << "==================================================" << endl;
    cout << "comparisons: " << comparisons << endl;
    cout << "assignments: " << assignments << endl;
    cout << "==================================================" << endl;
    cout << "END PROGRAM" << endl;
    return 0;
}
