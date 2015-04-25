#ifndef subprogram_parameters_h
#define subprogram_parameters_h 1
//---------------------------------------------------------
//File subprogram_parameters.h defines semantics for the production
//subprogram_parameters->empty
//subprogram_parameters->LPAREN parameter_list RPAREN
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
//subprogram_parameters->empty
//---------------------------------------------------------------------
List<VariableSymbol*>* subprogram_parameters(void);
//---------------------------------------------------------------------
//subprogram_parameters->LPAREN parameter_list RPAREN
//---------------------------------------------------------------------
List <VariableSymbol*>* subprogram_parameters(List<VariableSymbol*>* V);
#endif
