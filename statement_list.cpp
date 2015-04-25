//-------------------------------------------------------------------------
//File statement_list.cpp contains implementations for the following 
//productions: 
//statement_list: statement_list -> statement
//statement_list: statement_list -> statement_list ; statement
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     March, 2012
//---------------------------------------------------------------------
//Copyright March, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//C++ inlcude files
//---------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//---------------------------------------------------------------------
//Supporting utilities
//---------------------------------------------------------------------
#include "List.h"
#include "yyerror.h"
//---------------------------------------------------------------------
//Symbol Table
//---------------------------------------------------------------------
#include "Label.h"
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//---------------------------------------------------------------------
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
#include "String.h"
//-------------------------------------------------------------------------
//Function prototypes are given in file statement_list.h
//-------------------------------------------------------------------------
#include "statement_list.h"
//-------------------------------------------------------------------------
//Function statement_list implements the rule
//statement_list -> statement 
//-------------------------------------------------------------------------
List<Exp*>* Statement_list(List<Exp*>* s)
{   List<Exp*>* sl=new List<Exp*>;
    sl->Append(s);
    return sl;
}
//--------------------------------------------------------------------
//statement_list -> statement_list ; statement
//--------------------------------------------------------------------
List<Exp*>* Statement_list(List<Exp*>* sl,List<Exp*>* s)
{   sl->Append(s);
    return sl;
}
