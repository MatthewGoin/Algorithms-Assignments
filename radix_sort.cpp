#include <iostream>
#include <fstream>
#include <list>

using namespace std;
const int MAX_SIZE = 100; //set the size of the array
long long int comparison = 0; //set the size of the comparisons
long long int assignment = 0; //set the size of assignments

radixSort(int arrayA[], int n, int d){ //radix sort procedure-accepts an array, number of integers in the array, and the max number of digits in the numbers

        //list<int> list0;



    for(int j = d; j >= 1; --j){ //
        list<int > list0,list1, list2, list3, list4, list5, list6, list7, list8, list9, list10; //declare 10 lists to put the integers in
        list<int>::iterator it; //declare an iterator

        for(int i =0; i < n; i++){
            assignment ++; //increment assignment
            int k;
            int Num;
            if(j == 2){
                k = arrayA[i] % 10; //grab the value of the least significant digit
                Num = arrayA[i]; //set the vlue of num
                //cout << k << "====" << Num << endl;

            }
            else if(j==1){
                k = arrayA[i] / 10; //grab the value of the most significant digit
                Num = arrayA[i]; //set the vlaue of num
                //cout << k << "====" << Num << endl;
            }
            //if statements; store the value of num in the list depending on the value of k
            if(k == 0){
                list0.push_back(Num);
                //cout << "zero" << endl;


            }
            else if(k == 1){
                list1.push_back(Num);
                //cout << "one" << endl;

            }
            else if(k == 2){
                list2.push_back(Num);
                //cout << "two" << endl;

            }
            else if(k ==3){
                list3.push_back(Num);
                //cout << "Three" << endl;

            }
            else if(k == 4){
                list4.push_back(Num);
                //cout << "four" << endl;

            }
            else if(k == 5){
                list5.push_back(Num);
                //cout << "five" << endl;

            }
            else if(k == 6){
                list6.push_back(Num);
                //cout << "six" << endl;

            }
            else if(k == 7){
                list7.push_back(Num);
                //cout << "seven" << endl;

            }
            else if(k == 8){
                list8.push_back(Num);
                //cout << "eight" << endl;

            }
            else if(k == 9){
                list9.push_back(Num);
                //cout << "nine" << endl;

            }


        }
        //splice the lists to form one
        it = list0.end();
        list0.splice(it, list1);
        it = list0.end();
        list0.splice(it, list2);
        it = list0.end();
        list0.splice(it, list3);
        it = list0.end();
        list0.splice(it, list4);
        it = list0.end();
        list0.splice(it, list5);
        it = list0.end();
        list0.splice(it, list6);
        it = list0.end();
        list0.splice(it, list7);
        it = list0.end();
        list0.splice(it, list8);
        it = list0.end();
        list0.splice(it, list9);
        int counter = 0;
        assignment ++; //increment assignment
        //reset the elements in arrayA with the values in list0
        for(list<int>::iterator it = list0.begin(); it != list0.end(); ++it){
                //cout << *it << endl;
                arrayA[counter] = *it;
                counter ++;
                //cout << counter << endl;

        }

        list0.clear(); //now clear the list for the next iteration

    }

}


int main()
{
    cout << "RADIX SORT PROGRAM" << endl;
    int* radixArray = new int[MAX_SIZE]; //create an array of max size

    int arrayCount = 0;
    ifstream inputFile ("unsorted.txt"); //create an ifstream and open the file
        string line = "";
        string line2 = "";
        getline(inputFile, line);
        getline(inputFile, line2);
    while(!inputFile.eof() && arrayCount < MAX_SIZE){
            //read the numbers in the file into the array
            int num;
            inputFile >> num;
            radixArray[arrayCount] = num;
            arrayCount ++;

    }

    cout << "====================================" << endl;
    radixSort(radixArray, arrayCount, 2); //call the radix sort function
    cout << "====================================" << endl;


    cout << comparison << endl;
    cout << assignment << endl;

    cout << "END PROGRAM " << endl;


    return 0;
}
