#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <cctype>
#include <math.h>
#include "stars.h"
#include <iomanip>

using namespace std;

int main()
{
    cout << "STAR TRAVELLER PROGRAM " << endl;
    cout << "=======================" << endl;
    int counter = 0;
    //double practiceNum = 5.87695;
    //cout << practiceNum << endl;
    vector<Stars> starVec;
    cout << "Reading file: hygxyz.csv....." << endl;
    ifstream inputFile("hygxyz.csv"); //load the actor-actress.csv file
    string string1; //, string2, string3, string4, string5;
    getline(inputFile, string1); //get the first line and throw it away
    while(inputFile.good()){ //while the file is good

        string tempString;
        string get1, get2, get3, get4, get5; //, get6, get7;

        Stars tempStar; //create a tempNode
        int tempStarID =0; //fill it with info
        string tempProperName = "";
        double tempDistance =0;
        double tempX =0;
        double tempY =0;
        double tempZ =0;


        getline(inputFile, get1, ','); //read line until comma
        if ( ! (istringstream(get1) >> tempStarID) );
        tempStar.setStarID(tempStarID); //read line until comma


        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');

        getline(inputFile, tempProperName, ',');
        tempStar.setproperName(tempProperName);

        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        getline(inputFile, get2, ','); //read line until comma
        if ( ! (istringstream(get2) >> tempDistance) );
        //std::size_t sz =0;
        //tempDistance = stod(get2, &sz);
        //inputFile >> tempDistance;
        //stringstream ss(get2);
        //ss >> tempDistance;
        tempStar.setDistance(tempDistance); //read line until comma
        //getline(inputFile, get2, ','); //read line until comma
///////////////////////////////////////////////////////////////////////////////////////////////////////////

        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
        getline(inputFile, get3, ','); //read line until comma
        if ( ! (istringstream(get3) >> tempX) );
        //std::size_t sz3=0;
        //tempX = stod(get3, &sz3);
        //inputFile >> tempX;
        //stringstream ss2(get3);
        //ss2 >> tempX;
        tempStar.setXcoord(tempX); //read line until comma
        //getline(inputFile, get3, ','); //read line until comma
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

        getline(inputFile, get4, ','); //read line until comma
        if ( ! (istringstream(get4) >> tempY) );
        //std::size_t sz4 = 0;
        //tempY = stod(get4, &sz4);
        //inputFile >> tempY;
        //stringstream ss3(get4);
        //ss3 >> tempY;
        tempStar.setYcoord(tempY); //read line until comma
        //getline(inputFile, get4, ','); //read line until comma
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        getline(inputFile, get5, ','); //read line until comma
        if ( ! (istringstream(get5) >> tempZ) );
        //std::size_t sz5 = 0;
        //tempZ = stod(get5, &sz5);
        //inputFile >> tempZ;
        //stringstream ss4(get5);
        // ss4 >> tempZ;
        tempStar.setZcoord(tempZ); //read line until comma
        //getline(inputFile, get5, ','); //read line until comma
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        getline(inputFile, tempString, ',');
        getline(inputFile, tempString, ',');
        getline(inputFile, tempString);

        if(tempStar.getDistance() <= 10.0){
            starVec.push_back(tempStar);
        }
        //counter ++;


    }

    cout << "==============================================================================================" << endl;
    cout << starVec.size() << endl;

    //for(int i = 0; i < 10; i++){
    //cout << starVec[i].getStarID() << "=====" << starVec[i].getDistance() << "=======" << starVec[i].getVisited() << endl;
    //}
    cout << "==============================================================================================" << endl;

    int count2 = 0;
    int currentPosition = 0;
    //double smallestDistance = 10.0;
    double nextsmallestDistance = 0;
    int foundPosition = 0;
    double totalDistance = 0;
    //starVec.size() -1
    for(int i = 0; i < starVec.size()-1; i ++){
        double smallestDistance = 100.0;
        starVec[currentPosition].setVisited(true);
        cout << "STAR: [" <<  starVec[currentPosition].getStarID() << "|" << starVec[currentPosition].getproperName() << "] ======>";
        for(int j = 0; j < starVec.size(); j++){
            if(starVec[j].getVisited() == false){
                double firstElement = pow((starVec[j].getXcoord() - starVec[currentPosition].getXcoord()), 2);
                double secondElement = pow((starVec[j].getYcoord()-starVec[currentPosition].getYcoord()), 2);
                double thirdElement = pow((starVec[j].getZcoord()-starVec[currentPosition].getZcoord()), 2);
                nextsmallestDistance = sqrt(firstElement + secondElement + thirdElement);
                //cout << firstElement << "  " << secondElement << "  " << thirdElement << "   "<<nextsmallestDistance << endl;
                if(nextsmallestDistance < smallestDistance){
                    smallestDistance = nextsmallestDistance;
                    foundPosition = j;
                    //cout << foundPosition << endl;
                }

            }
        }
        currentPosition = foundPosition;
        totalDistance = totalDistance + smallestDistance;
        cout << " STAR: [" <<  starVec[currentPosition].getStarID() << "|" << starVec[currentPosition].getproperName() << "] ===";
        cout << " Distance: " << smallestDistance << " ===" << " Total Distance: " << totalDistance << endl;
        count2 ++;
    }

    cout << "Total distance traversed is: " << totalDistance << " Parsecs" << endl;
    //cout << count2 << endl;
    //int count3 = 0;
    //for(int i = 0; i < starVec.size(); i++){
        //if(starVec[i].getVisited() == false){
            //count3 ++;
        //}
    //}
    //cout << count3;
    cout << "==============================================================================================" << endl;
    cout << "==============================================================================================" << endl;
    cout << "==============================================================================================" << endl;

    //for(int i = 0; i < starVec.size(); i ++){
      //  cout << starVec[i].getStarID() << " = " << starVec[i].getproperName() << " = " << starVec[i].getDistance() << " = " << starVec[i].getXcoord() << " = " << starVec[i].getVisited() << endl;
    //}

    cout << "END STAR PROGRAM" << endl;
    return 0;
}
