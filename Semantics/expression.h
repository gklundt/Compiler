#ifndef expression_h
#define expression_h 1
//-------------------------------------------------------------------------
//File expression.h contains prototypes for the following productions: 
//expression -> simple_expression 
//expression -> simple_expression relop simple_expression 
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
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//---------------------------------------------------------------------
//P-Code and expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
//-------------------------------------------------------------------------
//Function expression_1 implements the rule
//expression -> simple_expression
//-------------------------------------------------------------------------
Exp* expression(Exp* simple_expression);
//--------------------------------------------------------------------
//expression_2: expression -> simple_expression relop simple_expression 
//--------------------------------------------------------------------
Exp* expression(Exp* left_simple_expression,string* relop,Exp* right_simple_expression);
#endif
