//listed libraries for unincluded versions, delete unnecessary libraries before compilation
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include "binarySearch.h"

using namespace std;

bool sortWords(Node &left,Node &right){ //function to overload the vector sort //could have used bubble-works well for almost sorted arrays.

    return(left.getWord() < right.getWord());

}
//recursive binary search function, accepts a vector of nodes, a target string, an int for comparisons and a first and last marker
int binarySearch(vector<Node>& wordList, string Target, long long int& comparisons, int first, int last){

    bool found;
    //int index;
    comparisons++;
    if(first > last){ //if it is not in the array
        found = false; //found = false
    }
    else{

        int mid = first + (last - first) / 2; //set the midpoint
        comparisons ++;
        if(Target == wordList[mid].getWord()){
            wordList[mid].number ++;
            //index = mid;
            found = true;
        }
        else if (Target < wordList[mid].getWord()){
            found = binarySearch(wordList, Target, comparisons, first, mid-1);
        }
        else{
            found = binarySearch(wordList, Target, comparisons, mid+1, last);
        }
    }
    return found;
}

int main()
{
    cout << "BINARY SEARCH PROGRAM " << endl;
    vector<Node> wordList;
    //int counter1 =0;
    int counter2 =0;
    int beginVec =0;
    long long int comparisons = 0;
    long long int assignments = 0;
    long int numUnique =0;
    ifstream inputFile ("wordlist.txt");

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


    while(!inputFile.eof()&& counter2 < 1000000){

        //counter1 ++;
        int sizeVec = 0;
        string readString = "";
        getline(inputFile, readString); //get a line of the input file
        if(isalpha(readString[0])){ //check if the character is alphabetic
            counter2 ++;
            transform(readString.begin(), readString.end(), readString.begin(), ::tolower); //transform to all lowercase
            sizeVec = wordList.size(); //get the current size of the vector
            bool present = binarySearch(wordList, readString, comparisons, beginVec, sizeVec -1); //send to binary search function
            if(present == false){ //if it i not present
                Node tempNode;
                tempNode.setWord(readString);
                tempNode.setNumber(1); //create a temp node and fill its data members
                wordList.push_back(tempNode); //push the tempnode into the vector
                sort(wordList.begin(), wordList.end(),sortWords); //sort the vector
                assignments ++; //increment assignments
            }

        }

    }

    for(unsigned int i = 0; i < wordList.size(); i++){ //get the number of unique numbers
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
    for(unsigned int i = wordList.size() - 10; i < wordList.size(); i ++){ //loop through last 10 elements
        cout << wordList[i].getWord() << ":" << wordList[i].getNumber() << endl;
    }
    cout << "==================================================" << endl;
    cout << "comparisons: " << comparisons << endl;
    cout << "assignments: " << assignments << endl;
    cout << "==================================================" << endl;
    cout << "END PROGRAM" << endl;
    return 0;
}
