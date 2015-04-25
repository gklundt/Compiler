//-------------------------------------------------------------------------
//File procedure_statement.cpp contains functions for the 
//following productions: 
//procedure_statement_1: procedure_statement -> ID
//procedure_statement_2: procedure_statement -> ID ( expression_list )
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
#include "String.h"
#include "yyerror.h"
//---------------------------------------------------------------------
//Symbol Table
//---------------------------------------------------------------------
#include "Label.h"
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//---------------------------------------------------------------------
//P-Code and Statement Trees
//---------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
//-------------------------------------------------------------------------
//Statement
//-------------------------------------------------------------------------
#include "procedure_statement.h"
#include "usersubprogram.h"
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream pfs;
extern ofstream tfs;
extern SymbolTable ST;
//-------------------------------------------------------------------------
//Function StandardProcedure implements the rule
//procedure_statement -> ID
//if ID is the name of a standard procedure
//-------------------------------------------------------------------------
Exp* StandardProcedure(StandardProcedureSymbol* S)
{   PCode* P=new PCode("","csp","",S->CSPID());
    Exp* E=new Exp(ST.TVoid(),P);
    return E;
}
//-------------------------------------------------------------------------
//Function procedure_statement implements the rule
//procedure_statement: procedure_statement -> ID
//-------------------------------------------------------------------------
Exp* procedure_statement(string* id)
{  Sym* S=ST.Find(*id);
   List<Exp*>* e=new List<Exp*>;
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (S->IsProcedureSymbol())
       return UserSubprogram((SubprogramSymbol*)S,e);
   else if (S->IsStandardProcedureSymbol() )
       return StandardProcedure((StandardProcedureSymbol*)S);
   else yyerror("Semantic error - ID must be a procedure");
}
//-------------------------------------------------------------------------
//Function StandardProcedure implements the rule
//procedure_statement -> ID ( expression_list )
//when ID is the name of a standard procedure.
//-------------------------------------------------------------------------
Exp* StandardProcedure(StandardProcedureSymbol* S,List<Exp*>* e)
{
    PCode* P;
    Exp* E=0;
    //--------------------------------------------------------------------
    //Traverse the list of argument-expressions and create an arg-pcode
    //for each expression
    //--------------------------------------------------------------------
    for (e->First();!e->IsEol();e->Next()) {
       Exp* A=e->Member();
       P=new PCode("","arg","","");
       E=new Exp(E,A,ST.TVoid(),P);
    }
    P=new PCode
        (""                             //Label
        ,"csp"                          //P-Code Op - Call Standard Procedure
        ,""
        ,S->CSPID()
        );
    E=new Exp(E,0,ST.TVoid(),P);
	E->PPrint(pfs);
    E->PPrint(tfs);
    return E;
}
//-------------------------------------------------------------------------
//Function procedure_statement_2 implements the rule
//procedure_statement_2: procedure_statement -> ID ( expression_list )
//-------------------------------------------------------------------------
Exp* procedure_statement(string* id, List<Exp*>* EL)
{  Sym* S=ST.Find(*id);
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (S->IsProcedureSymbol())
       return UserSubprogram((SubprogramSymbol*)S,EL);
   else if (S->IsStandardProcedureSymbol() )
       return StandardProcedure((StandardProcedureSymbol*)S,EL);
   else yyerror("Semantic error - ID must be a procedure");
}