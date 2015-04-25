#ifndef yyerror_h
#define yyerror_h 1
//---------------------------------------------------------------------
//File yyerror.h contains the definition of yyerror.  
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     February, 2012
//---------------------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//C++ inlcude files
//---------------------------------------------------------------------
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
void yyerror(string m);
#endif
