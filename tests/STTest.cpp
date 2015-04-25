//-----------------------------------------------------------
//File STTest.cpp exercises the Symbol Table
//-----------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//Date:   January, 2012
//-----------------------------------------------------------
//Copyright January, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner
//-----------------------------------------------------------
//C++ include files
//-----------------------------------------------------------
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//-----------------------------------------------------------
//Symbol Table include files
//-----------------------------------------------------------
#include "List.h"
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "SymbolTable.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
static Typ* tbool;
static Typ* tchar;
static Typ* tinteger;
static Typ* treal;
static Typ* tvoid;
//-----------------------------------------------------------
//-----------------------------------------------------------
void StandardTypes(void)
{   
     tbool=new Boolean();
     Sym* sbool=new TypeSymbol("boolean",tbool);
     sbool->Print(cout,0);

     tchar=new Character();
     Sym* schar=new TypeSymbol("char",tchar);
     schar->Print(cout,0);

     tinteger=new Integer();
     Sym* sinteger=new TypeSymbol("integer",tinteger);
     sinteger->Print(cout,0);

     treal=new Real();
     Sym* sreal=new TypeSymbol("real",treal);
     sreal->Print(cout,0);

     tvoid=new Void();
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void StandardConstants(void)
{   Sym* sfalse=new ConstantSymbol("false",tbool,"0");
    sfalse->Print(cout,0);
    Sym* strue =new ConstantSymbol("true" ,tbool,"1");
    strue ->Print(cout,0);
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void StandardProcedures(void)
{  Sym* wrb=new StandardProcedureSymbol("writeboolean","wrb");
   wrb->Print(cout,0);
   Sym* wrc=new StandardProcedureSymbol("writechar","wrc");
   wrc->Print(cout,0);
   Sym* wri=new StandardProcedureSymbol("writeinteger","wri");
   wri->Print(cout,0);
   Sym* wre=new StandardProcedureSymbol("writeexponential","wre");
   wre->Print(cout,0);
   Sym* wrf=new StandardProcedureSymbol("writefixed","wrf");
   wrf->Print(cout,0);
   Sym* wln=new StandardProcedureSymbol("writeln","wln");
   wln->Print(cout,0);
}
void StandardFunctions(void)
{  Sym* abs=new StandardFunctionSymbol ("abs"  ,"abs");
   abs->Print(cout,0);
   Sym* sqt=new StandardFunctionSymbol ("sqrt" ,"sqt");
   sqt->Print(cout,0);
   Sym* trc=new StandardFunctionSymbol ("trunc","trc");
   trc->Print(cout,0);
   Sym* rnd=new StandardFunctionSymbol ("round","rnd");
   rnd->Print(cout,0);
   Sym* ord=new StandardFunctionSymbol ("ord"  ,"ord");
   ord->Print(cout,0);
   Sym* chr=new StandardFunctionSymbol ("chr"  ,"chr");
   chr->Print(cout,0);
   Sym* inc=new StandardFunctionSymbol ("succ" ,"inc");
   inc->Print(cout,0);
   Sym* dec=new StandardFunctionSymbol ("pred" ,"dec");
   dec->Print(cout,0);
}
void VariableSymbols(void)
{   //----------------------------------------------------------
    //Scalar variables
    //----------------------------------------------------------
    Sym* b=new VariableSymbol("b",tbool);
    b->Print(cout,0);
    Sym* c=new VariableSymbol("c",tchar,1);
    c->Print(cout,0);
    Sym* i=new VariableSymbol("i",tinteger,1,6);
    i->Print(cout,0);
    Sym* r=new VariableSymbol(string("r"),treal);
    r->Print(cout,0);
    //----------------------------------------------------------
    //Array
    //----------------------------------------------------------
    Typ* tndx=new Range(tinteger,"1","10");
    Typ* tary=new Array(tndx,treal);
    Sym* A=new VariableSymbol("A",tary);
    A->Print(cout,0);
}
void SubprogramSymbols(void)
{
    //------------------------------------------------------
    //A FunctionSymbol 
    //------------------------------------------------------
    Typ* rt=tinteger;                        //Return type
    List<Typ*>* p=new List<Typ*>;            //First a list for parameters
    p->Insert(treal);                        //First parameter type
    Typ* tf=new Subprogram(p,rt);            //Subprogram type/function
    Sym* rnd=new FunctionSymbol("rnd",tf);
    rnd->Print(cout,0);
    //------------------------------------------------------
    //A ProcedureSymbol
    //------------------------------------------------------
    List<Typ*>* q=new List<Typ*>;            //First a list for parameters
    q->Insert(tinteger);                     //First parameter type
    q->Insert(tinteger);                     //Second parameter type
    Typ* tp=new Subprogram(q,tvoid);         //Subprogram type/procedure
    Sym* swap=new ProcedureSymbol("swap",tp);
    swap->Print(cout,0);
}
void ProgramSymbolTest(void)
{   Sym* p=new ProgramSymbol("p001_000");
    p->Print(cout,0);
}
void LocalityTest(void)
{   Locality L(2);
    
    Typ* tndx=new Range(tinteger,"1","10");
    Typ* tary=new Array(tndx,treal);
    Sym* A=new VariableSymbol("A",tary);
    L.Insert(A);

    Sym* b=new VariableSymbol("b",tbool);
    L.Insert(b);
    Sym* c=new VariableSymbol("c",tchar,1);
    L.Insert(c);
    Sym* i=new VariableSymbol("i",tinteger,1,6);
    L.Insert(i);
    Sym* r=new VariableSymbol(string("r"),treal);
    L.Insert(r);

    L.Print(cout);
}
void SymbolTableTest(void)
{   SymbolTable ST;
    ST.NewLocality();
    Typ* tndx=new Range(tinteger,"1","10");
    Typ* tary=new Array(tndx,treal);
    Sym* A=new VariableSymbol("A",tary);
    ST.Insert(A);

    Sym* b=new VariableSymbol("b",tbool);
    ST.Insert(b);
    Sym* c=new VariableSymbol("c",tchar,1);
    ST.Insert(c);
    Sym* i=new VariableSymbol("i",tinteger,1,6);
    ST.Insert(i);
    Sym* r=new VariableSymbol(string("r"),treal);
    ST.Insert(r);

    ST.Print(cout);
    ST.PopLocality();
    ST.Print(cout);
}
//-----------------------------------------------------------
//Function main directs the process of exercising the symbol
//table
//-----------------------------------------------------------
int main()
{   StandardTypes();
/*
    StandardConstants();
    StandardProcedures();
    StandardFunctions();
    VariableSymbols();
    SubprogramSymbols();
    ProgramSymbolTest();
    LocalityTest();
*/
    SymbolTableTest();
    cout << endl;
    return 0;
}

