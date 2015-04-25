//-------------------------------------------------------------------------
//File expression.h contains prototypes for the following productions: 
//expression -> simple_expression 
//expression -> simple_expression relop simple_expression 
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
//P-Code and expression Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
//-------------------------------------------------------------------------
//Simple_expression
//-------------------------------------------------------------------------
#include "expression.h"
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream pfs;
extern ofstream tfs;
extern int line;
extern int col;
extern SymbolTable ST;

//-------------------------------------------------------------------------
//Function expression implements the rule
//expression -> simple_expression
//-------------------------------------------------------------------------
Exp* expression(Exp* simple_expression)
{
   return simple_expression;
}
//--------------------------------------------------------------------
//expression: Parameterizes all relational expressions
//--------------------------------------------------------------------
Exp* expression(Exp* LE,Exp* RE,string relop)
{  Typ* LT=LE->Type();
   Typ* RT=RE->Type();
   Typ* B=ST.TBoolean();
   if (LT!=RT) yyerror("Semantic Error:unequal left and right types.");
   string typechar=LT->TypeChar();
   PCode* P=new PCode("",relop,typechar,"");
   Exp* E=new Exp(LE,RE,B,P);
   E->Print(pfs); //printing p-code to .pcd file
   return E;
}
//--------------------------------------------------------------------
//expression: expression -> simple_expression relop simple_expression 
//--------------------------------------------------------------------
Exp* expression(Exp* left_simple_expression,string* relop,Exp* right_simple_expression)
{   if (*relop=="=" ) return expression(left_simple_expression,right_simple_expression,"equ");  
    if (*relop=="<>") return expression(left_simple_expression,right_simple_expression,"neq");  
    if (*relop=="<" ) return expression(left_simple_expression,right_simple_expression,"les");  
    if (*relop=="<=") return expression(left_simple_expression,right_simple_expression,"leq");  
    if (*relop==">" ) return expression(left_simple_expression,right_simple_expression,"grt");  
    if (*relop==">=") return expression(left_simple_expression,right_simple_expression,"geq");  
    yyerror("Semantic error: invalid relop");
}