//---------------------------------------------------------
//File type.cpp defines semantics for the production
//type->standard_type
//type->ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type
//---------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//Date:   February, 2012
//---------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner
//Do not reproduce without permission from Thomas R. Turner
//---------------------------------------------------------
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
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Application inlcude files
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Symbol Table
//---------------------------------------------------------------------
#include "List.h"
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//---------------------------------------------------------------------
//Semantic include files
//---------------------------------------------------------------------
#include "type.h"
//---------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;
extern int line;
extern int col;
extern Label L;
//---------------------------------------------------------------------
//Global variables defined in paspar.y
//---------------------------------------------------------------------
extern SymbolTable ST;        //The SymbolTable
//---------------------------------------------------------------------
//type->standard_type
//---------------------------------------------------------------------
Typ* type(Typ* T){return T;}
//---------------------------------------------------------------------
//type->ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type
//---------------------------------------------------------------------
Array* type(string lo,string hi,Typ* T)
{   Range* I=new Range(ST.TInteger(),lo,hi);
    return new Array(I,T);

}
