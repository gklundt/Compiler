#ifndef Label_h
#define Label_h 1
//-------------------------------------------------------------------
//Class Label manages PCode Labels
//-------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//February, 2012
//-------------------------------------------------------------------
//C++ include files
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
//-------------------------------------------------------------------
//-------------------------------------------------------------------
class Label {
   int label;
   int width;
   char fillchar;
public:
   Label(int w=5,char f='0');
   string New(void);
};
#endif
