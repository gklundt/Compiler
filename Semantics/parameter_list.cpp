//---------------------------------------------------------
//File parameter_list.cpp defines semantics for the production
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
#include "parameter_list.h"
//---------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream pfs;
extern ofstream tfs;
extern int line;
extern int col;
extern Label L;
//---------------------------------------------------------------------
//Global variables defined in paspar.y
//---------------------------------------------------------------------
extern SymbolTable ST;        //The SymbolTable
//---------------------------------------------------------------------
//parameter_list->identifier_list COLON type
//---------------------------------------------------------------------
List<VariableSymbol*>* parameter_list(List<string>* IL,Typ* T)
{   List<VariableSymbol*>* VL=new List<VariableSymbol*>;
    for (IL->First();!IL->IsEol();IL->Next()) {
        string Id=IL->Member();
        VariableSymbol* S=new VariableSymbol(Id,T);
        VL->Insert(S);
    }
    return VL;
}
//---------------------------------------------------------------------
//parameter_list->parameter_list SEMICOLON identifier_list COLON type
//---------------------------------------------------------------------
List<VariableSymbol*>* parameter_list(List<VariableSymbol*>* VL,List<string>* IL,Typ* T)
{   for (IL->First();!IL->IsEol();IL->Next()) {
        string Id=IL->Member();
        VariableSymbol* S=new VariableSymbol(Id,T);
        VL->Insert(S);
    }
    return VL;
}

