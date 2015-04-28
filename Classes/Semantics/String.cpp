//-------------------------------------------------------------------------
//File String.cpp contains utility String that converts an integer to an
//equivalent string 
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     February, 2012
//---------------------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//C++ include files
//---------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
//-------------------------------------------------------------------------
//Application include files
//-------------------------------------------------------------------------
#include "String.h"
//-------------------------------------------------------------------------
//Function String is a utility that converts integers to strings.
//-------------------------------------------------------------------------
string String(int i) {
	ostringstream o;
	o << i;
	return o.str();
}

