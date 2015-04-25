//---------------------------------------------------------
//File subprogram_head.cpp defines semantics for the production
//subprogram_head->FUNCTION ID subprogram_parameters COLON standard_type SEMICOLON
//subprogram_head->PROCEDURE ID subprogram_parameters SEMICOLON
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
#include "subprogram_head.h"
//---------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;
extern int line;
extern int col;
extern Label L;
//---------------------------------------------------------------------
//Global variables defined in paspar.y
//---------------------------------------------------------------------
extern SymbolTable ST;        //The SymbolTable
//---------------------------------------------------------------------
//Function ParameterList creates a parameter list from a list of Variables
//---------------------------------------------------------------------
static Subprogram* ParameterList(List<VariableSymbol*>* VL,Typ* RT)
{   List<Typ*>* PL=new List<Typ*>;
    for (VL->First();!VL->IsEol();VL->Next())
    {   VariableSymbol* S=VL->Member();
        Typ* T=S->Type();
        PL->Insert(T);
    }
    return new Subprogram(PL,RT);
}
//---------------------------------------------------------------------
//Function InsertVariables inserts variables into the symbol table
//---------------------------------------------------------------------
static void InsertVariables(List<VariableSymbol*>* VL)
{   for (VL->First();!VL->IsEol();VL->Next()) {
        VariableSymbol* S=VL->Member();
        ST.Insert(S);
    }
}
//---------------------------------------------------------------------
//subprogram_head->FUNCTION ID subprogram_parameters COLON standard_type SEMICOLON
//1.  Traverse the list of variable symbols to create list of parameters
//2.  Create a function symbol using the list of parameters created in step 1.
//3.  Insert the function symbol into the symbol table.
//4.  Create a new locality.
//5.  Insert the variable symbols into the symbol table.
//---------------------------------------------------------------------
void subprogram_head(string id,List<VariableSymbol*>* VL,Typ* RT)
{  Subprogram* PL=ParameterList(VL,RT);
   FunctionSymbol* F=new FunctionSymbol(id,PL,ST.LexicalLevel());
   ST.Insert(F);
   ST.NewLocality();
   InsertVariables(VL);
}
//---------------------------------------------------------------------
//subprogram_head->PROCEDURE ID subprogram_parameters SEMICOLON
//1.  Traverse the list of variable symbols to create list of parameters
//2.  Create a procedure symbol using the list of parameters created in step 1.
//3.  Insert the procedure symbol into the symbol table.
//4.  Create a new locality.
//5.  Insert the variable symbols into the symbol table.
//---------------------------------------------------------------------
void subprogram_head(string id,List<VariableSymbol*>* VL)
{  Subprogram* PL=ParameterList(VL,ST.TVoid());
   ProcedureSymbol* P=new ProcedureSymbol(id,PL,ST.LexicalLevel());
   ST.Insert(P);
   ST.NewLocality();
   InsertVariables(VL);
}
