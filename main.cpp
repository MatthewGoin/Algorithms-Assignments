#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <list>
#include <cctype>
#include "matrix.h"


using namespace std;

string characters[6487];
string comics[12943];
bool edgesMatrix[6485][12942];
int collabMatrix[6485][6485] = {};
int identityMatrix[6487][6487] = {};
int spiderManMatrix[6485][6485] = {};
int collabMatrix2[6485][6485];


vector<bool> getedgeVector(int x){

    vector<bool>returnVec;

    for (int i = 1; i < 12943; i ++){
        bool tempBool;
        tempBool = edgesMatrix[x][i];
        returnVec.push_back(tempBool);
    }

return returnVec;

}


int spiderMan(int x){
    int spiderManNumber = -1;
    if(x == 5305){
        spiderManNumber = 0;
    }
    /*else if (collabMatrix[5306][x] > 0){
        spiderManNumber = 1;
    }*/
    else{
        for(int i = 0; i < 6485; i ++){
            for(int j =0; j < 6485; j++){
                if(i == j){
                    spiderManMatrix[i][j] == 1;
                }
            }
        }

        for(int i = 1; i < 4; i++){
            if(spiderManMatrix[5305][x] > 0){
                spiderManNumber = i;
            }
            else{
                for(int i = 0; i < 6485; i ++){
                    for(int j = 0; j < 6485; j++){
                        for(int k = 1; k < 6485; k++){

                            spiderManMatrix[i][j] = spiderManMatrix[i][j] + spiderManMatrix[i][k] * collabMatrix[k][j];
                        }
                    }

                }
            }
            //here is where I would add “i” to an array at position: spiderManMatrix[5305][x] > 0;
            //that way we have O(1) lookup for any marvel character.

        }

    }

return spiderManNumber;

}

int spiderMan2(int x){

    int spiderManNumber = -1;

    if(x == 5305){
        spiderManNumber = 0;
    }
    else if (collabMatrix[5305][x] > 0){
        spiderManNumber = 1;
    }
    else{
            int counter = 1;
            //spiderManNumber = 1;
            vector<int>spiderVec;
            vector<int>spiderVec2;
            for(int j = 1; j < 6485; j++){
                //cout << collabMatrix[5306][j] << endl;
                if(collabMatrix[5305][j] > 0){
                    spiderVec.push_back(j);
                }
            }
            cout << "SPIDERVEC SIZE IS " << spiderVec.size() << endl;
            for(int k =0; k < spiderVec.size(); k++){
                //cout << "HELLO" << endl;
                if(collabMatrix[spiderVec[k]][x] > 0){
                    counter++;
                    goto endFunction;
                }
            }
            counter = 2;
            for(int it = 0; it < spiderVec.size(); it++){
                for (int itt = 0; itt < 6487; itt ++){
                    if(collabMatrix[spiderVec[it]][itt] > 0){
                        spiderVec2.push_back(itt);
                    }
                }
            }
            for(int l = 0; l < spiderVec2.size(); l++){
                if(collabMatrix[spiderVec2[l]][x] > 0){
                    counter++;
                    goto endFunction;
                }
            }
            counter = 3;

        //}
        endFunction:
        spiderManNumber = counter;
    }


return spiderManNumber;


}

int main()
{
    cout << "MARVEL UNIVERSE PROGRAM" << endl;
    cout << "=======================" << endl;
    //cout << edgesMatrix[1][1] << endl;
    long int counter = 1;
    long int counter2 = 1;
    const int MAX_SIZE1 = 6486;

    /*for(int i = 0; i < 6487; i ++){
        for(int j =0; j < 6487; i ++){
            if(i == j){
                identityMatrix[i][j] = 1;
            }
        }
    }*/


    ifstream inputFile ("porgat.txt"); //open wordlist.txt
    string throwAway = "";
    getline(inputFile, throwAway);
    vector<NODE>nodeVec;
    //string practice = "hello";
    //cout << practice.length() << endl;
    long int position = 1;
    long int position2 =1;
    while(!inputFile.eof() && counter < 6487){//while not end of file
        //cout << counter << endl;
        //cout << "BEGINNING " << endl;
        string addString = "";
        string readString = "";
        //char search_char = '"';
        getline(inputFile, readString);
        size_t found = readString.find_first_of('"');
        for(unsigned int i = found + 1; i < readString.length() - 1; ++i){
            addString.push_back(readString[i]);
        }
        //cout << addString << endl;
        characters[position] = addString;

        //cout << position << endl;

        //cout << characters[position] << endl;
        position ++;
        counter ++;

    }

     //cout << "does it get here? " << endl;

    while(!inputFile.eof() && counter2 <  12943){

        string addString = "";
        string readString = "";
        //char search_char = '"';
        getline(inputFile, readString);
        size_t found = readString.find_first_of('"');
        for(unsigned int i = found + 1; i < readString.length() - 1; ++i){
            addString.push_back(readString[i]);
        }
        //cout << addString << endl;
        comics[position2] = addString;

        //cout << position << endl;

        //cout << characters[position] << endl;
        position2 ++;
        counter2 ++;
    }
    string throwAway2 = "";
    getline(inputFile, throwAway2);
    cout << throwAway2 << endl;
    int counter3 = 1;

    int counted = 0;
    int prevRow = 0;
    while(!inputFile.eof()){

        int row;
        vector<long int> cols;
        string matrixNums = "";
        stringstream ss;
        getline(inputFile, matrixNums);
        ss << matrixNums;
        ss >> row;
        while(!ss.eof()){
            long int tempCol =0;
            ss >> tempCol;
            cols.push_back(tempCol);
        }
        counter3 ++;
        /*cout << "ROW " << row << "===" << "COLS ";
        for(int i =0; i < cols.size(); i ++){
            cout << cols[i] << " ";
        }*/
        for(unsigned int i = 0; i < cols.size(); i ++){
            int tempPlace;
            tempPlace = cols[i];
            edgesMatrix[row][tempPlace - 6486] = true;
        }

        /*NODE tempNode;
            tempNode.row = row;
            tempNode.columns = cols;
            nodeVec.push_back(tempNode);*/

        if(prevRow == row ){
            //cout << "HELLO " << endl;
            nodeVec[counted - 1].columns.insert(nodeVec[counted -1].columns.end(), cols.begin(), cols.end());

            }
        else{
            NODE tempNode;
            tempNode.row = row;
            /*for(int i =0; i < cols.size(); i++){
                tempNode.columns[i] = cols[i];
            }*/
            tempNode.columns = cols;
            nodeVec.push_back(tempNode);
            counted ++;
        }
        prevRow = row;



        //cout << endl;

    }

    //cout << edgesMatrix[1][1] << endl;
    //bool hopefully = edgesMatrix[1][1];
    //cout << hopefully << endl;
    //cout << edgesMatrix[1][1] << endl;
    int letsSee =0;
    //cout << "Lets See: " << endl;
    //cout << nodeVec[1].columns.size() << endl;
    /*for(int i = 0; i < nodeVec[1].columns.size(); i ++){
        for(int j = 0; j < nodeVec[5305].columns.size(); j++){
            if(nodeVec[1].columns[i] == nodeVec[5305].columns[j])
                letsSee ++;
        }
    }*/
    //cout << "Here is lets see: " << letsSee << endl;



    cout << "==================================" << endl;
    for(int i =1; i < 11; i++){
        //cout << i << endl;
        cout << i << ": " <<characters[i] << endl;
    }
    cout << "==================================" << endl;
    for(int i =12933; i < 12943; i++){
        //cout << i << endl;
        cout << i << ": " << comics[i] << endl;
    }

    cout << nodeVec.size() << endl;

    for(int i = 0; i < nodeVec.size(); i ++){

        for(int j = 0; j < nodeVec.size(); j++){
            int tempInt =0;
            for(int k = 0; k < nodeVec[i].columns.size(); k ++){
                    for(int l = 0; l < nodeVec[j].columns.size(); l++){
                        if(nodeVec[i].columns[k] == nodeVec[j].columns[l]){
                            tempInt ++;
                        }
                    }
            }
            //cout << tempInt << endl;
            collabMatrix[i][j] = tempInt;

        }
    }

    /*for(int i =1; i < 6487; i ++){
        cout << collabMatrix[5306][i] << endl;
    }*/
    cout << nodeVec[5305].columns.size() << endl;


    /*for(int i = 1; i < 1000; i++){
        vector<bool>tempVec1;
        tempVec1 = getedgeVector(i);
        for(int j = 1; j < 1000; j++){
            int tempCount = 0;
            vector<bool>tempVec2;
            tempVec2 = getedgeVector(j);
            for(unsigned int i = 0; i < tempVec1.size(); i ++){
                if(tempVec2[i] == true && tempVec1[i] == true){
                    tempCount ++;
                }
            }
            //cout << tempCount << endl;
            collabMatrix[i][j] = tempCount;
            //cout << collabMatrix[i][j] << endl;
        }
    }*/
    int numChars;
    cout << "how many spider man numbers would you like to compute? " << endl;
    cin >> numChars;

    for(int i =0; i < numChars; i++){
        int MarvelCharacter;
        int finalNum;
        int finalNum2;
        cout << "please enter the character number for me to compute the spiderMan number of that character " << endl;
        cin >> MarvelCharacter;
        finalNum2 = MarvelCharacter - 1;
        finalNum = spiderMan2(finalNum2);
        //cout << nodeVec[MarvelCharacter].row;
        cout << "character : " << characters[MarvelCharacter] << "'s Spider Man number is: " << finalNum << endl;
    }

    int character1;
    //int finalNum2;
    int numChars2;
    cout << "how many spider man numbers would you like to compute? [for spiderMan function1] " << endl;
    cin >> numChars2;
    for(int i =0; i < numChars; i++){
        int MarvelCharacter;
        int finalNum;
        int finalNum2;
        cout << "please enter the character number for me to compute the spiderMan number of that character " << endl;
        cin >> MarvelCharacter;
        finalNum2 = MarvelCharacter - 1;
        finalNum = spiderMan(finalNum2);
        //cout << nodeVec[MarvelCharacter].row;
        cout << "character : " << characters[MarvelCharacter] << "'s Spider Man number is: " << finalNum << endl;
    }
    //cout << "enter a character number for me to check in  spiderMan1 function: " << endl;
    //cin >> character1;
    //finalNum2 = spiderMan(character1);
    //cout << "character : " << character1 << "'s Spider Man number [in function1] is: " << finalNum2 << endl;




    cout << "END PROGRAM" << endl;
    return 0;
}
