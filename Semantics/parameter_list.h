#ifndef parameter_list_h
#define parameter_list_h 1
//---------------------------------------------------------
//File parameter_list.h defines semantics for the production
//parameter_list->identifier_list COLON type
//parameter_list->parameter_list SEMICOLON identifier_list COLON type
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
//parameter_list->identifier_list COLON type
//---------------------------------------------------------------------
List <VariableSymbol*>* parameter_list(List<string>* IL,Typ* T);
//---------------------------------------------------------------------
//parameter_list->parameter_list SEMICOLON identifier_list COLON type
//---------------------------------------------------------------------
List <VariableSymbol*>* parameter_list(List<VariableSymbol*>* VL,List<string>* IL,Typ* T);
#endif
