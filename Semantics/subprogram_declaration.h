#ifndef subprogram_declaration_h
#define subprogram_declaration_h 1
//---------------------------------------------------------
//File subprogram_declaration.h defines semantics for the production
//subprogram_declaration->subprogram_head declarations compound_statement
//---------------------------------------------------------
//---------------------------------------------------------------------
//C++ include files
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
void subprogram_declaration(void);
#endif
