//-------------------------------------------------------------------------
//File simple_expression.cpp contains functions that implement the 
//following productions: 
//simple_expression - > term
//simple_expression - > sign term
//simple_expression - > simple_expression addop term
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
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
//simple_expression
//-------------------------------------------------------------------------
#include "simple_expression.h"
#include "coercetoreal.h"
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream pfs;
extern ofstream tfs;
extern int line;
extern int col;
extern SymbolTable ST;
//-------------------------------------------------------------------------
//Function simple_expression_1 implements the rule
//simple_expression -> term
//-------------------------------------------------------------------------
Exp* simple_expression(Exp* term){return term;}
//--------------------------------------------------------------------
//Function simple_expression -> sign term
//--------------------------------------------------------------------
Exp* simple_expression(string* sign,Exp* term)
{  
    //------------------------------------------------------------------
    //Emit a semantic error if the term has neither type integer or real
    //------------------------------------------------------------------
    if (!term->IsInteger()&&!term->IsReal())
        yyerror("Semantic error: term must be integer or real");
    //------------------------------------------------------------------
    //Do nothing if the sign is positive "+"
    //------------------------------------------------------------------
    if (*sign=="+") return term;
    //------------------------------------------------------------------
    //------------------------------------------------------------------
    PCode* P;
    Exp*  E;
    //------------------------------------------------------------------
    //  Term must have type integer or real
    //  Generate a negate integer, ngi, if the term has type integer
    //  Generate a negate real, ngr, if the term has type real
    //------------------------------------------------------------------
    if (term->IsInteger()) {
        P=new PCode("","ngi","","");
        E=new Exp(term,0,ST.TInteger(),P);
    } else {
        P=new PCode("","ngr","","");
        E=new Exp(term,0,ST.TReal(),P);
    }
    E->Print(pfs); //printing p-code to .pcd file
    return E;
}
//--------------------------------------------------------------------
//Function add creates an expression to add the left and right 
//expressions
//--------------------------------------------------------------------
Exp* add(Exp* l,Exp* r)
{   //--------------------------------------------------------------------
    //Coerce left and right expressions to real if either is integer and
    //the other is real
    //--------------------------------------------------------------------
    l=CoerceLeftExpressionToReal(l,r);
    r=CoerceRightExpressionToReal(l,r);
    //---------------------------------------------------------------------
    //add
    //---------------------------------------------------------------------
    PCode* P;
    Exp* E;
    if (l->IsReal()||r->IsReal()) {
        P=new PCode("","adr","","");
        E=new Exp(l,r,ST.TReal(),P);
    } else {
        P=new PCode("","adi","","");
        E=new Exp(l,r,ST.TInteger(),P);
    }
    E->Print(pfs); //printing p-code to .pcd file
    return E;
}
//--------------------------------------------------------------------
//Function subtract creates an expression to subtract the left 
//expression from the  right expression
//--------------------------------------------------------------------
Exp* subtract(Exp* l,Exp* r)
{   //--------------------------------------------------------------------
    //Coerce left and right expressions to real if either is integer and
    //the other is real
    //--------------------------------------------------------------------
    l=CoerceLeftExpressionToReal(l,r);
    r=CoerceRightExpressionToReal(l,r);
    //---------------------------------------------------------------------
    //subtract
    //---------------------------------------------------------------------
    PCode* P;
    Exp* E;
    if (l->IsReal()||r->IsReal()) {
        P=new PCode("","sbr","","");
        E=new Exp(l,r,ST.TReal(),P);
    } else {
        P=new PCode("","sbi","","");
        E=new Exp(l,r,ST.TInteger(),P);
    }
    E->Print(pfs); //printing p-code to .pcd file
    return E;
}
//--------------------------------------------------------------------
//Function disjunction creates an expression to find the disjunction
//of the two expressions
//--------------------------------------------------------------------
Exp* disjunction(Exp* l,Exp* r)
{   //--------------------------------------------------------------------
    //Both expressions must be Boolean
    //-------------------------------------------------------------------
    if (!l->IsBoolean()) yyerror("Semantic error: the left expression must be Boolean");
    if (!r->IsBoolean()) yyerror("Semantic error: the right expression must be Boolean");
    //---------------------------------------------------------------------
    //disjunction
    //---------------------------------------------------------------------
    PCode* P=new PCode("","ior","","");
    Exp* E=new Exp(l,r,ST.TBoolean(),P);
    E->Print(pfs); //printing p-code to .pcd file
    return E;
}
//--------------------------------------------------------------------
//Function simple_expression -> simple_expression addop term
//--------------------------------------------------------------------
Exp* simple_expression(Exp* simpleexpression, string* addop, Exp* term)
{   if (*addop=="+" ) return add(simpleexpression,term);
    if (*addop=="-" ) return subtract(simpleexpression,term);
    if (*addop=="or") return disjunction(simpleexpression,term);
    yyerror("Semantic error: invalid addop");
}