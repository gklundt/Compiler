#ifndef StandardTypes_h 
#define StandardTypes_h 1
//-----------------------------------------------------------------------------
//File StandardTypes.h makes Standard Types available to the Symbol Table. 
//-----------------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//April 2015
//-----------------------------------------------------------------------------
//Copyright April, 2015 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//-----------------------------------------------------------------------------
//C++ include files and namespace std
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
//-----------------------------------------------------------------------------
//Application include files
//-----------------------------------------------------------------------------
#include "Typ.h"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SetTVoid(Typ* tv);
void SetTAddress(Typ* ta);
void SetTBoolean(Typ* tb);
void SetTChar(Typ* tc);
void SetTInteger(Typ* ti);
void SetTReal(Typ* tr);
Typ* GetTVoid(void);
Typ* GetTAddress(void);
Typ* GetTBoolean(void);
Typ* GetTChar(void);
Typ* GetTInteger(void);
Typ* GetTReal(void);
#endif

