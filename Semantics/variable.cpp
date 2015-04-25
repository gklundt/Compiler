//-------------------------------------------------------------------------
//File variable.cpp contains function that implement rules for variable
//variable -> ID
//variable -> ID [ expression ]
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
//C++ include files
//---------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
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
#include "Label.h"
#include "Typ.h"
#include "Sym.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"
//---------------------------------------------------------------------
//P-Code and Expression Trees
//---------------------------------------------------------------------
#include "String.h"
#include "PCode.h"
#include "Exp.h"
//---------------------------------------------------------------------
//variable
//---------------------------------------------------------------------
#include "variable.h"
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;
extern int line;
extern int col;
extern SymbolTable ST;
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
Exp* variable_symbol(VariableSymbol* V)
{   int ll=ST.LexicalLevel()-V->LexicalLevel();
    PCode* P=new PCode("","lda",ll,V->Address());
    Exp* E=new Exp(V->Type(),P);
    E->Print(tfs);
    return E;
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
Exp* function_symbol(FunctionSymbol* F)
{   PCode* P=new PCode("","lda",0,0);
    Exp* E=new Exp(F->ReturnType(),P);
    E->Print(tfs);
    return E;
}
//-------------------------------------------------------------------------
//Function variable implements the rule
//variable -> ID
//-------------------------------------------------------------------------
Exp* variable(string* id)
{   Sym* S=ST.Find(*id);
    if (!S) yyerror("Semantic error - ID cannot be found");
    if (S) S->Print(tfs,0);
    symkind sk=S->Symkind();
    Exp* E=0;
    List<Exp*>* e=new List<Exp*>;
    switch (sk) {
        case sk_variable:  
            return variable_symbol((VariableSymbol*)S);
        break;
        case sk_function:  
            return function_symbol((FunctionSymbol*)S);
        break;
        default:
            yyerror("Semantic error - ID must be a variable or a function");
    }
    return E;
}
//--------------------------------------------------------------------
//Function variable implements the rule
//variable -> ID [ expression ]
//1.  Find id - id must be an array
//2.  load the address of id
//3.  load the value of the expression
//4.  load the value of the smallest possible index value
//5.  subtract the index from the expression
//6.  add the difference to the address of id
//
//                    ixa stride  
//                    / 
//                   -   
//                  / \
//  index expression   index lobound
//                /
//           adr(array)
//--------------------------------------------------------------------
Exp* variable(string* id,Exp* e)
{  
    //------------------------------------------------------------------
    //------------------------------------------------------------------
    Sym* S=ST.Find(*id);       //Find the array identifier
    if (!S) yyerror("Semantic error - ID cannot be found");
    if (!S->IsVariableSymbol()) yyerror("Semantic error: identifier is not a variable");
    VariableSymbol* V=(VariableSymbol*)S;
    //------------------------------------------------------------------
    //Validate that the id is an array
    //------------------------------------------------------------------
    Typ* T=V->Type();         //Obtain the array type
    if (!T->IsArray()) yyerror("Semantic error: identifier is not an array");
    Array* AT=(Array*)T;
    //------------------------------------------------------------------
    //Validate that the index expression type is an integer
    //------------------------------------------------------------------
    Typ* ET=e->Type();         //Obtain the index expression type
    if (!ET->IsInteger()) yyerror("Semantic error: index expression is not an integer");
    //------------------------------------------------------------------
    //------------------------------------------------------------------
    PCode* P;                  //A pointer to a p-code for general use
    Exp* L;                    //Left expression pointer 
    Exp* R;                    //Right expression pointer
    //------------------------------------------------------------------
    //Load the base address of the array.  
    //------------------------------------------------------------------
    int ll=ST.LexicalLevel()-V->LexicalLevel();
    int a=V->Address();
    P=new PCode("","lda",ll,a);
    R=new Exp(ST.TAddress(),P);
    //------------------------------------------------------------------
    //Append R on the left-most side of the index expression e
    //------------------------------------------------------------------
    e->LeftAppend(R);
    //------------------------------------------------------------------
    //Let e represent the index expression coded in the program
    //    e is represented by Exp* e, the input parameter
    //Let b represent the smallest permissible value coded in the 
    //      declaration for this array
    //    b is the lower bound represented by lo
    //Find the difference e-b, the unbiased index expression
    //------------------------------------------------------------------
    Range* IT=AT->IndexType();
    string lo=IT->LoBound();
    P=new PCode("","ldc","i",lo);
    R=new Exp(ST.TInteger(),P);
    P=new PCode("","sbi","","");
    L=new Exp(e,R,ST.TInteger(),P);
    //------------------------------------------------------------------
    //Next, obtain the stride, the distance between elements of the array
    //------------------------------------------------------------------
    int stride=AT->Stride();
    P=new PCode("","ixa","",stride);
    Typ* ELT=AT->ElementType();
    L=new Exp(L,0,ELT,P); 
    L->Print(tfs);
    return L;
}