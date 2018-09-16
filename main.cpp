#include <iostream>
#include "bubblesort.h"
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

bubbleSort(int arrayA[], int n, long long int &c, long long int &a){


    bool sorted = false;
    int pass =1;

    while(!sorted && (pass < n)){
        sorted = true;
        for(int index = 0; index < n - pass; index ++){
            int nextIndex = index + 1;
            c ++;
            if(arrayA[index] > arrayA[nextIndex]){
                swap(arrayA[index], arrayA[nextIndex]);
                sorted = false;
                a ++;
            }
        }
        pass ++;
    }
    return 0;
}


int main()
{

    cout << "BUBBLESORT PROGRAM" << endl;
    int* bubbleArray = new int[MAX_SIZE];

    int arrayCount = 0;
    ifstream inputFile ("unsorted.txt");
        string line = "";
        getline(inputFile, line);
    while(!inputFile.eof() && arrayCount < MAX_SIZE){

            int num;
            inputFile >> num;
            bubbleArray[arrayCount] = num;
            arrayCount ++;

    }
    long long int comparison = 0;
    long long int assignment = 0;
    bubbleSort(bubbleArray, arrayCount, comparison, assignment);
    cout << comparison << endl;
    cout << assignment << endl;

    cout << "END PROGRAM" << endl;
    return 0;
}
