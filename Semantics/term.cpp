//-------------------------------------------------------------------------
//File term.cpp contains functions that implement the following productions: 
//term -> factor
//term -> term mulop factor
//-------------------------------------------------------------------------
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
#include "yyerror.h"
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
//term
//-------------------------------------------------------------------------
#include "term.h"
#include "coercetoreal.h"
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream pfs;
extern ofstream tfs;
extern int line;
extern int col;
extern SymbolTable ST;
//--------------------------------------------------------------------
//Function term -> term * factor
//--------------------------------------------------------------------
Exp* term_2(Exp* term, Exp* factor)
{   term=CoerceLeftExpressionToReal(term,factor);
    factor=CoerceRightExpressionToReal(term,factor);
    //---------------------------------------------------------------------
    //multiply
    //---------------------------------------------------------------------
    PCode* P;
    Exp* E;
    if (term->IsReal()||factor->IsReal()) {
        P=new PCode("","mpr","",""); 
        E=new Exp(term,factor,ST.TReal(),P);
    } else {
        P=new PCode("","mpi","","");
        E=new Exp(term,factor,ST.TReal(),P);
    }
    E->Print(pfs); //printing p-code to .pcd file
    return E;
}
//--------------------------------------------------------------------
//Function term -> term / factor
//--------------------------------------------------------------------
Exp* term_3(Exp* term, Exp* factor)
{   term=CoerceLeftExpressionToReal(term,factor);
    factor=CoerceRightExpressionToReal(term,factor);
    //---------------------------------------------------------------------
    //divide
    //---------------------------------------------------------------------
    if (!term->IsReal())
        yyerror("Semantic error: the left expressions must be real");
    if (!factor->IsReal())
        yyerror("Semantic error: the right expressions must be real");
   //---------------------------------------------------------------------
   //Divide real
   //---------------------------------------------------------------------
   PCode* P=new PCode("","dvr","","");
   Exp* E=new Exp(term,factor,ST.TReal(),P);
   E->Print(pfs); //printing p-code to .pcd file
   return E;
}
//--------------------------------------------------------------------
//Function term -> term DIV factor
//--------------------------------------------------------------------
Exp* term_4(Exp* term, Exp* factor)
{
    if (!term->IsInteger()) 
        yyerror("Semantic error:: the left expression must be integer");
    if (!factor->IsInteger()) 
        yyerror("Semantic error:: the right expression must be integer");
    
    PCode* P=new PCode("","dvi","","");
    Exp* E=new Exp(term,factor,ST.TInteger(),P);
    E->Print(pfs); //printing p-code to .pcd file
    return E;
}
//--------------------------------------------------------------------
//Function term -> term MOD factor
//--------------------------------------------------------------------
Exp* term_5(Exp* term, Exp* factor)
{
    if (!term->IsInteger()) 
        yyerror("Semantic error:: the left expression must be integer");
    if (!factor->IsInteger()) 
        yyerror("Semantic error:: the right expression must be integer");
    
    PCode* P=new PCode("","mod","","");
    Exp* E=new Exp(term,factor,ST.TInteger(),P);
    E->Print(pfs); //printing p-code to .pcd file
    return E;
}
//--------------------------------------------------------------------
//Function term -> term AND factor
//--------------------------------------------------------------------
Exp* term_6(Exp* term, Exp* factor)
{
    if (!term->IsBoolean()) 
        yyerror("Semantic error:: the left expression must be Boolean");
    if (!factor->IsBoolean()) 
        yyerror("Semantic error:: the right expression must be Boolean");
    
    PCode* P=new PCode("","and","","");
    Exp* E=new Exp(term,factor,ST.TBoolean(),P);
    E->Print(pfs); //printing p-code to .pcd file
    return E;
}
//-------------------------------------------------------------------------
//Function term implements the rule
//term -> factor
//-------------------------------------------------------------------------
Exp* term(Exp* f){return f;}
//-------------------------------------------------------------------------
//Function term implements the rule
//term -> term mulop factor
//-------------------------------------------------------------------------
Exp* term(Exp* t,string* op,Exp* f)
{   if (*op=="*"  ) return term_2(t,f);
    if (*op=="/"  ) return term_3(t,f);
    if (*op=="div") return term_4(t,f);
    if (*op=="mod") return term_5(t,f);
    if (*op=="and") return term_6(t,f);
    yyerror("Semantic error: invalid mulop");
}
