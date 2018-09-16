#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;
long long int comparison = 0;
long long int assignment = 0;

finalMerge(int arrayA[], int first, int mid, int last){


    int* tempA = new int[MAX_SIZE];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = first1;
    while((first1 <= last1) && (first2 <= last2)){

        comparison ++;
        if(arrayA[first1] <= arrayA[first2]){
            assignment ++;
            tempA[index] = arrayA[first1];
            first1 ++;
        }
        else{
            assignment ++;
            tempA[index] = arrayA[first2];
            first2 ++;
        }
        index ++;
    }
    while(first1 <= last1){

        assignment ++;
        tempA[index] = arrayA[first2];
        first1 ++;
        index ++;
    }
    while(first2 <= last2){

        assignment ++;
        tempA[index] = arrayA[first2];
        first2 ++;
        index ++;
    }
    for(index = first; index <= last; index ++){
        assignment ++;
        arrayA[index] = tempA[index];
    }
    delete []tempA;

}


mergeSort(int arrayA[], int first, int last){

    if(first < last){
        int mid = first + (last - first)/2;
        mergeSort(arrayA, first, mid);
        mergeSort(arrayA, mid + 1, last);
        finalMerge(arrayA, first, mid, last);
    }

}


int main()
{

    cout << "MERGE SORT PROGRAM " << endl;
    int* mergeArray = new int[MAX_SIZE];

    int arrayCount = 0;
    ifstream inputFile ("unsorted.txt");
        string line = "";
        string line2 = "";
        getline(inputFile, line);
        getline(inputFile, line2);
    while(!inputFile.eof() && arrayCount < MAX_SIZE){

            int num;
            inputFile >> num;
            mergeArray[arrayCount] = num;
            arrayCount ++;

    }
    mergeSort(mergeArray, 0, arrayCount - 1);

    cout << comparison << endl;
    cout << assignment << endl;


    cout << "END PROGRAM" << endl;
    return 0;
}
