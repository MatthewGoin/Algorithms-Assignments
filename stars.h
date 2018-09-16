#ifndef STARS_
#define STARS_
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
using namespace std;

class Stars{


private:
    int StarID;
    string properName;
    double distance;
    double xCoord;
    double yCoord;
    double zCoord;
    bool Visited = false;


public:

    int getStarID(){return StarID;} //getter and setter functions to retrieve and set data
    void setStarID(int _StarID){StarID = _StarID;}
    string getproperName(){return properName;}
    void setproperName(string _properName){properName = _properName;}
    double getDistance(){return distance;}
    void setDistance(double _distance){distance = _distance;}

    double getXcoord(){return xCoord;}
    void setXcoord(double _xCoord){xCoord = _xCoord;}

    double getYcoord(){return yCoord;}
    void setYcoord(double _yCoord){yCoord = _yCoord;}

    double getZcoord(){return zCoord;}
    void setZcoord(double _zCoord){zCoord = _zCoord;}

    bool getVisited(){return Visited;}
    void setVisited(bool _Visited){Visited = _Visited;}


};


#endif
