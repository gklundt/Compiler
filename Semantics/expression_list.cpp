//-------------------------------------------------------------------------
//File expression_list.cpp contains implementations for the following 
//productions: 
//expression_list: expression_list -> expression
//expression_list: expression_list -> expression_list , expression
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
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
#include "String.h"
//-------------------------------------------------------------------------
//Function prototypes are given in file expression_list.h
//-------------------------------------------------------------------------
#include "expression_list.h"
//-------------------------------------------------------------------------
//Function Expression_1 implements the rule
//expression_list -> expression 
//-------------------------------------------------------------------------
List<Exp*>* expression_list(Exp* expression)
{  List<Exp*>* L=new List<Exp*>;
   L->Insert(expression);
   return L;
}
//--------------------------------------------------------------------
//Expression_2: expression_list -> expression_list , expression 
//--------------------------------------------------------------------
List<Exp*>* expression_list(List<Exp*>* expression_list,Exp* expression)
{  expression_list->Insert(expression);
   return expression_list;
}