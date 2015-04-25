//---------------------------------------------------------
//File standard_type.cpp defines semantics for the production
//standard_type->ID
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
//Application include files
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
#include "standard_type.h"
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
//---------------------------------------------------------------------
struct TypeException {
    TypeException(Sym* s)
    {   cout << endl;
        cout << "Error on line " << line << " column " << col;
        cout << endl;
        cout << "The symbol shown below is not a type symbol.";
        cout << endl;
        s->Print(cout,0);
        cout << endl;
    }
};
//---------------------------------------------------------------------
//---------------------------------------------------------------------
Typ* standard_type(string id)
{
    Sym* s=ST.Find(id);
    if (!s->IsTypeSymbol()) throw TypeException(s);
    s->Print(tfs ,0);
    return s->Type();
}
