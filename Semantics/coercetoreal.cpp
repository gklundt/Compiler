//-------------------------------------------------------------------------
//File coercetoreal contains functions that coerce left and right expressions
//to real if they are integer and if the opposite expression are real.
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
//Header file
//-------------------------------------------------------------------------
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
//Function CoerceLeftExpressionToReal coerces the left expression to
//real if the left expression has type integer and the right expression
//has type real.
//--------------------------------------------------------------------
Exp* CoerceLeftExpressionToReal
    (Exp* LE                  //Left Expression
    ,Exp* RE                  //Right Expression
    )
{
    //---------------------------------------------------------------------
    //The expression must be either integer or real
    //---------------------------------------------------------------------
    if (!LE->IsReal()&&!LE->IsInteger()) 
       yyerror("Semantic error: left expression is not Integer and not Real");
    //---------------------------------------------------------------------
    //Insert a conversion to type real if the left expression has type integer
    //and the right expression has type integer
    //---------------------------------------------------------------------
    if (LE->IsInteger()&&RE->IsReal()) {
        PCode* P=new PCode("","flt","","");
        return new Exp(LE,0,ST.TReal(),P);
    } else {
        return LE;
    }
}
//--------------------------------------------------------------------
//Function CoerceRightExpressionToReal coerces the right expression to
//real if the right expression has type integer and the left expression
//has type real.
//--------------------------------------------------------------------
Exp* CoerceRightExpressionToReal
    (Exp* LE                  //Left Expression
    ,Exp* RE                  //Right Expression
    )
{
    //---------------------------------------------------------------------
    //The expression must be either integer or real
    //---------------------------------------------------------------------
    if (!RE->IsReal()&&!RE->IsInteger()) 
        yyerror("Semantic error: right expression is not Integer and not Real");
    //---------------------------------------------------------------------
    //Insert a conversion to type real if the right expression has type integer
    //and the left expression has type real
    //---------------------------------------------------------------------
    if (RE->IsInteger()&&LE->IsReal()) {
        PCode* P=new PCode("","flt","","");
        return new Exp(0,RE,ST.TReal(),P);
    } else {
        return RE;
    }
}