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
//Application include files
//-------------------------------------------------------------------
#include "Label.h"
//-------------------------------------------------------------------
//-------------------------------------------------------------------
Label::Label(int w,char f):label(1),width(w),fillchar(f){}
string Label::New(void)
{   ostringstream o;
    o << setw(width) << setfill(fillchar) << label++;
    return "L" + o.str();
}
