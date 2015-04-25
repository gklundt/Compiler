//-----------------------------------------------------------------------------
//File StandardTypes.cpp makes Standard Types available to the Symbol Table. 
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
#include "StandardTypes.h"
//-----------------------------------------------------------------------------
//Externals
//-----------------------------------------------------------------------------
Typ* TypeVoid;
Typ* TypeAddress;
Typ* TypeBoolean;
Typ* TypeChar;
Typ* TypeInteger;
Typ* TypeReal;
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SetTVoid(Typ* tv){TypeVoid=tv;}
void SetTAddress(Typ* ta){TypeAddress=ta;}
void SetTBoolean(Typ* tb){TypeBoolean=tb;}
void SetTChar(Typ* tc){TypeChar=tc;}
void SetTInteger(Typ* ti){TypeInteger=ti;}
void SetTReal(Typ* tr){TypeReal=tr;}
Typ* GetTVoid(void){return TypeVoid;}
Typ* GetTAddress(void){return TypeAddress;}
Typ* GetTBoolean(void){return TypeBoolean;}
Typ* GetTChar(void){return TypeChar;}
Typ* GetTInteger(void){return TypeInteger;}
Typ* GetTReal(void){return TypeReal;}

