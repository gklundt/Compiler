//---------------------------------------------------------------------
//File yyerror.cpp contains the implementation of yyerror.  
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     April, 2015
//---------------------------------------------------------------------
//Copyright April, 2015 by Thomas R. Turner.
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
void yyerror(string m){cout << m << endl;}
