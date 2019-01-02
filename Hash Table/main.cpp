//several libraries for unincluded versions of this implementation
//delete unnecessary libraries before compilation.
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <list>
#include <cctype>
#include "hashTable.h"

using namespace std;

static const int CAPACITY = 2678;// 4937//2678*** //7919 //88079 //65267 //1373
list<Node> hashTable[CAPACITY]; //create an array of linked lists in heap memory

bool sortWords(Node &left,Node &right){ //function to overload the vector sort function

    return(left.getWord() < right.getWord());

}

unsigned int hashFunction(string hashString){ //SDBM HASH function

    unsigned int hash = 0;
	//unsigned int i = 0;
	unsigned int len = hashString.length();

	for (unsigned int i = 0; i < len; i++)
	{
		hash = (hashString[i]) + (hash << 6) + (hash << 16) - hash;
	}

	return hash;
}


int main()
{
    cout << "HASH TABLE PROGRAM " << endl;

    vector<Node> wordList;
    long long int comparisons = 0;
    long long int assignments = 0;
    long int numUnique =0;
    ifstream inputFile ("wordlist.txt"); //open wordlist.txt

    while(!inputFile.eof()){//while not end of file

        //counter1 ++;
        long long int hashNum = 0;
        string readString = "";
        getline(inputFile, readString); //get a line from the input file
        if(isalpha(readString[0])){ //check if the first element is alphabetical. if it is then....
            //counter2 ++;
            transform(readString.begin(), readString.end(), readString.begin(), ::tolower); //transform everything to lowercase
            //bool present = linearSearch(wordList, readString, comparisons);
            hashNum = ((hashFunction(readString)* 5000) % CAPACITY); //send the string the hash function and get and get the hash number
            if(hashTable[hashNum].empty()){ //if the spot in the hash table is empty
                Node tempNode;
                tempNode.setWord(readString);
                tempNode.setNumber(1); //create a node and set the data elements
                hashTable[hashNum].push_back(tempNode); //place it in the hash table
                assignments ++; //increment assignments
            }
            if(!hashTable[hashNum].empty()){ //if the space in the hash table is not empty
                bool found = false;
                for(list<Node>::iterator it = hashTable[hashNum].begin(); it != hashTable[hashNum].end(); ++it){
                    comparisons ++; //iterate through the linked list and see if a word matches
                    if(it->getWord() == readString){ //if a aword matches
                        //foundWord ++;
                        found = true; //set found = true
                        //break;
                        it->number ++; //iterate its count
                    }
                }
                if(found == false){ //if you looped through the entire list and nothing was found
                        Node tempNode;
                        tempNode.setWord(readString);
                        tempNode.setNumber(1); //create a node and set the data elements
                        hashTable[hashNum].push_back(tempNode); //place it in the list
                        assignments ++; //increment assignments
                }

            }

        }

    }

    for(int i = 0; i < CAPACITY; i ++){ //loop through the hash table
        if(!hashTable[i].empty()){ //if an array spot is not empty
            for(list<Node>::iterator it = hashTable[i].begin(); it != hashTable[i].end(); ++it){
                    Node tempNode; //iterate through that spots linked list
                    tempNode.setWord(it->getWord());
                    tempNode.setNumber(it->getNumber()); //create a node from the data in the linked list
                    wordList.push_back(tempNode); //push that node into the vector
                }
            }
        }
    sort(wordList.begin(), wordList.end(),sortWords); //sort the new vector
    for(unsigned int i = 0; i < wordList.size(); i++){ //loop through the vector
        if(wordList[i].getNumber() == 1){ //get the elements that only have a 1 count
            numUnique ++;
        }
    }

    cout << numUnique << endl;
    cout << "==================================================" << endl;
    for(unsigned int i = 0; i < 10; i ++){ //display the first ten elements
        cout << wordList[i].getWord() << ":" << wordList[i].getNumber() << endl;

    }
    cout << "==================================================" << endl;
    for(unsigned int i = wordList.size() - 10; i < wordList.size(); i ++){
        cout << wordList[i].getWord() << ":" << wordList[i].getNumber() << endl; //display the last 10 elements
    }
    cout << "==================================================" << endl;
    cout << "comparisons: " << comparisons << endl;
    cout << "assignments: " << assignments << endl;
    cout << "==================================================" << endl;

    cout << "END PROGRAM " << endl;
    return 0;
}
