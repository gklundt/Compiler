#ifndef procedure_statement_h
#define procedure_statement_h 1
//-------------------------------------------------------------------------
//File procedure_statement.h contains prototytpes for the 
//following productions: 
//procedure_statement: procedure_statement -> ID
//procedure_statement: procedure_statement -> ID ( expression_list )
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
//C++ include files
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
//P-Code and Statement Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
#include "String.h"
//-------------------------------------------------------------------------
//Function procedure_statement implements the rule
//procedure_statement: procedure_statement -> ID
//-------------------------------------------------------------------------
Exp* procedure_statement(string* id);
//-------------------------------------------------------------------------
//Function procedure_statement implements the rule
//procedure_statement: procedure_statement -> ID ( expression_list )
//-------------------------------------------------------------------------
Exp* procedure_statement(string* id, List<Exp*>* EL);
#endif