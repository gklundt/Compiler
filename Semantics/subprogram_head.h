#ifndef subprogram_head_h
#define subprogram_head_h 1
//---------------------------------------------------------
//File subprogram_head.h defines semantics for the production
//subprogram_head->PROGRAM ID program_parameters ;
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
void subprogram_head(string id,List<VariableSymbol*>* VL,Typ* T);
void subprogram_head(string id,List<VariableSymbol*>* VL);
#endif
