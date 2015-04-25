#ifndef term_h
#define term_h 1
//-------------------------------------------------------------------------
//File term.h contains prototypes for the following productions: 
//term -> factor
//term -> term mulop factor
//-------------------------------------------------------------------------
//term_1: term -> factor 
//term_2: term -> term * factor
//term_3: term -> term / factor
//term_4: term -> term DIV factor
//term_5: term -> term MOD factor
//term_6: term -> term AND factor
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
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
//-------------------------------------------------------------------------
//Function term implements the rule
//term -> factor
//-------------------------------------------------------------------------
Exp* term(Exp* f);
//-------------------------------------------------------------------------
//Function term implements the rule
//term -> term mulop factor
//-------------------------------------------------------------------------
Exp* term(Exp* t,string* op,Exp* f);
#endif