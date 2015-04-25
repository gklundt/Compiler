//-------------------------------------------------------------------------
//File optional_statements.cpp contains implementations for the following 
//productions: 
//optional_statements -> empty
//optional_statements -> statement_list
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
//Function prototypes are given in file optional_statements.h
//-------------------------------------------------------------------------
#include "optional_statements.h"
//-------------------------------------------------------------------------
//Function optional_statements implements the rule
//optional_statements -> empty
//-------------------------------------------------------------------------
List<Exp*>* Optional_statements(void)
{  return new List<Exp*>;
}
//--------------------------------------------------------------------
//optional_statements -> statement_list
//--------------------------------------------------------------------
List<Exp*>* Optional_statements(List<Exp*>* sl)
{  return sl;
}
