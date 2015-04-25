//-----------------------------------------------------------------------------
//File SymbolTable.cpp implements member functions of class SymbolTable 
//-----------------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//February, 2012
//-----------------------------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//-----------------------------------------------------------------------------
//C++ include files and namespace std
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
//-----------------------------------------------------------------------------
//Application include files
//-----------------------------------------------------------------------------
#include "List.h"
#include "Typ.h"
#include "StandardTypes.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SymbolTable::SymbolTable()
{   NewLocality();
    Standard();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SymbolTable::~SymbolTable()
{   PopLocality();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SymbolTable::Standard(void)
{   StandardTypes();
    StandardConstants();
    StandardProcedures();
    StandardFunctions();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SymbolTable::StandardTypes(void)
{       
    tvoid=new Void();
    SetTVoid(tvoid);
    
    taddress=new Address();
    SetTAddress(taddress);
    
    tboolean=new Boolean();
    SetTBoolean(tboolean);
    Sym* sboolean=new TypeSymbol("boolean",tboolean);
    Insert(sboolean);

    tchar=new Character();
    SetTChar(tchar);
    Sym* schar=new TypeSymbol("char",tchar);
    Insert(schar);

    tinteger=new Integer();
    SetTInteger(tinteger);
    Sym* sinteger=new TypeSymbol("integer",tinteger);
    Insert(sinteger);

    treal=new Real();
    SetTReal(treal);
    Sym* sreal=new TypeSymbol("real",treal);
    Insert(sreal);
}
//-----------------------------------------------------------------------------
//Function StandardConstants initalizes standard constants.
//-----------------------------------------------------------------------------
void SymbolTable::StandardConstants(void)
{  Sym* sfalse=new ConstantSymbol("false",tboolean,"0");
   Insert(sfalse);
   Sym* strue= new ConstantSymbol("true" ,tboolean,"1");
   Insert(strue);
}
void SymbolTable::StandardProcedures(void)
{  Sym* wrb=new StandardProcedureSymbol("writeboolean"    ,"wrb");
   Insert(wrb);
   Sym* wrc=new StandardProcedureSymbol("writechar"       ,"wrc");
   Insert(wrc);
   Sym* wri=new StandardProcedureSymbol("writeinteger"    ,"wri");
   Insert(wri);
   Sym* wre=new StandardProcedureSymbol("writeexponential","wre");
   Insert(wre); 
   Sym* wrf=new StandardProcedureSymbol("writefixed"      ,"wrf");
   Insert(wrf);
   Sym* wln=new StandardProcedureSymbol("writeln"         ,"wln");
   Insert(wln);
   Sym* wrs=new StandardProcedureSymbol("writestring"     ,"wrs");
   Insert(wrs);
   Sym* rdc=new StandardProcedureSymbol("readchar"        ,"rdc");
   Insert(rdc);
   Sym* rdi=new StandardProcedureSymbol("readinteger"     ,"rdi");
   Insert(rdi);
   Sym* rdr=new StandardProcedureSymbol("readreal"        ,"rdr");
   Insert(rdr);
   Sym* rds=new StandardProcedureSymbol("readstring"      ,"rds");
   Insert(rds);
   Sym* rln=new StandardProcedureSymbol("readln"          ,"rln");
   Insert(rln);
}
void SymbolTable::StandardFunctions(void)
{  Sym* abs=new StandardFunctionSymbol("abs"  ,"abs");
   Insert(abs);
   Sym* sqt=new StandardFunctionSymbol("sqrt" ,"sqt");
   Insert(sqt);
   Sym* trc=new StandardFunctionSymbol("trunc","trc");
   Insert(trc);
   Sym* rnd=new StandardFunctionSymbol("round","rnd");
   Insert(rnd);
   Sym* ord=new StandardFunctionSymbol("ord"  ,"ord");
   Insert(ord);
   Sym* chr=new StandardFunctionSymbol("chr"  ,"chr");
   Insert(chr);
   Sym* inc=new StandardFunctionSymbol("succ" ,"inc");
   Insert(inc);
   Sym* dec=new StandardFunctionSymbol("pred" ,"dec");
   Insert(dec);
}
//-----------------------------------------------------------------------------
//Print the symbols in the Symbol Table stored at the current lexical level
//-----------------------------------------------------------------------------
void SymbolTable::Print(ostream& o)
{   if (L) L->Print(o);
}
//-----------------------------------------------------------------------------
//Function NewLocality creates a new locality and pushes it on the stack.
//-----------------------------------------------------------------------------
void SymbolTable::NewLocality(void)
{   L=new Locality(LexicalLevel()+1);   //Create a new locality 
    Push(L);                            //Push the locality on the 
                                        //LocalityStack
}
//-----------------------------------------------------------------------------
//Function PopLocality pops the locality from the top of the LocalityStack
//-----------------------------------------------------------------------------
void SymbolTable::PopLocality(void)
{  
   L=Pop();                             //Pop the current Locality from
                                        //the LocalityStack
   L=Top();                             //Make L the top of the locality stack
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Typ* SymbolTable::TVoid(void){return tvoid;}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Typ* SymbolTable::TAddress(void){return taddress;}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Typ* SymbolTable::TChar(void){return tchar;}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Typ* SymbolTable::TInteger(void){return tinteger;}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Typ* SymbolTable::TReal(void){return treal;}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Typ* SymbolTable::TBoolean(void){return tboolean;}
