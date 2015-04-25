//-------------------------------------------------------------------------
//File factor.cpp contains function that implement rules for factor
//factor_1: factor -> ID
//factor_2: factor -> ID [ expression ]
//factor_3: factor -> ID ( expession_list )
//factor_4: factor -> ( expression )
//factor_5: factor -> NOT factor
//factor_6: factor -> INTLIT
//factor_7: factor -> REALIT
//factor_8: factor -> CHRLIT 
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
#include "String.h"
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
#include "String.h"
#include "PCode.h"
#include "Exp.h"
//---------------------------------------------------------------------
//factor
//---------------------------------------------------------------------
#include "factor.h"
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream pfs;
extern ofstream tfs;
extern int line;
extern int col;
extern SymbolTable ST;
//-------------------------------------------------------------------------
//Function factor_1 implements the rule
//factor -> ID
//-------------------------------------------------------------------------
Exp* factor_1 ( string* id)
{  Sym* S=ST.Find(*id);
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (S) S->Print(tfs,0);
   symkind sk=S->Symkind();
   Exp* E=0;
   switch (sk) {
       case sk_constant:  //Create an ldc PCode Exp
           E=factor_1_constant((ConstantSymbol*)S);
       break;
       case sk_variable:  //Create a ldx PCode Exp
           E=factor_1_variable((VariableSymbol*)S);
       break;
       case sk_type:      //Not valid - call yyerror
           yyerror("Semantic error - ID cannot be a type name ");
       break;
       case sk_function:  //Call the function
           if (S->IsFunctionSymbol()) 
              E=factor_1_function((FunctionSymbol*)S);
           else
              yyerror("Semantic error - ID must be a function ");
           
       break;
   }
   return E;
}
//--------------------------------------------------------------------
//Function factor_1_constant
//--------------------------------------------------------------------
Exp* factor_1_constant(ConstantSymbol* S)
{   
    Typ* T=S->Type();
    string cv=S->ConstantValue();
    PCode* P=new PCode
        (""
        ,"ldc"
        ,T->TypeChar()
        ,cv
        );
    Exp* E=new Exp(T,P);
    E->PPrint(pfs); //printing p-code to .pcd file
    return E;
}
//--------------------------------------------------------------------
//Function factor_1_variable
//--------------------------------------------------------------------
Exp* factor_1_variable(VariableSymbol* S)
{  
    Typ* T=S->Type();
    string op="lv" + T->TypeChar();
    int ll=ST.LexicalLevel()-S->LexicalLevel();
    int a=S->Address();
    PCode* P=new PCode("",op,ll,a);
    Exp* E=new Exp(T,P);
    E->PPrint(pfs); //printing p-code to .pcd file
    return E;
}
//--------------------------------------------------------------------
//Function factor_1_function
//This code is incorrect and must be revised
//--------------------------------------------------------------------
Exp* factor_1_function(FunctionSymbol* S)
{   
    Typ* T=S->Type();
    Subprogram* F;
    if (T->IsSubprogram()) F=(Subprogram*)T;
    Typ* RT=F->ReturnType();
    PCode* P;
    Exp* E;
    int ll=ST.LexicalLevel()-S->LexicalLevel();
    P=new PCode("","mst",ll,"");
    E=new Exp(ST.TVoid(),P);
    int pc=S->ParameterCount();      
    P=new PCode
        (""                             //Label
        ,"cup"                          //P-Code Op - Call User Procedure
        ,pc                             //Operand 1 - Parameter Count
        ,S->ELabel()                    //Operand 2 - Entry Label
        );
    E=new Exp(E,0,RT,P);
    E->Print(tfs); 
    return E;
}
//--------------------------------------------------------------------
//Function factor_2 implements the rule
//factor -> ID [ expression ]
//1.  Find id - id must be an array
//2.  load the address of id
//3.  load the value of the expression
//4.  load the value of the smallest possible index value
//5.  subtract the index from the expression
//6.  add the difference to the address of id
//7.  load the value of the element of the array whose address was
//    computed in step 6
//                       ind
//                       /   
//                    ixa stride  
//                    / 
//                   -   
//                  / \
//  index expression   index lobound
//                /
//           adr(array)
//--------------------------------------------------------------------
Exp* factor_2(string* id,Exp* e)
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
   L=new Exp(L,0,ST.TAddress(),P); 
   //------------------------------------------------------------------
   //Employ the load-indirect, ind, p-code to fetch the element
   //------------------------------------------------------------------
   Typ* ELT=AT->ElementType();
   string tc=ELT->TypeChar();
   P=new PCode("","ind",tc,"");
   L=new Exp(L,0,ELT,P);
   L->Print(tfs);
   return L;
}
//--------------------------------------------------------------------
//Function UserFunction implements the rule
//factor -> ID ( expression_list )
//if ID is a user function
//1.  Create a node with a MST p-code - this p-code must be printed first
//2.  The nodes of the expression list must occur in the same order as
//    the argument-expressions they represent
//3.  Create a node with a CUP p-code
//                    cup
//                   /
//                 arg 
//                / \
//             ...   en
//             /
//          arg 
//          / \
//       arg   e2 
//       / \
//     mst  e1
//--------------------------------------------------------------------
Exp* UserFunction(FunctionSymbol* S,List<Exp*>* e)
{  //--------------------------------------------------------------------
   //Obtain the function type FT, and the return type, RT, of the function
   //--------------------------------------------------------------------
   Typ* RT=S->ReturnType();
   PCode* P;
   Exp* E;
   //--------------------------------------------------------------------
   //Put a mark stack, mst, at the bottom of the list.
   //--------------------------------------------------------------------
   int ll=ST.LexicalLevel()-S->LexicalLevel();
   P=new PCode("","mst",ll,"");
   E=new Exp(ST.TVoid(),P);
   //--------------------------------------------------------------------
   //Traverse the list of argument-expressions and create an arg-pcode
   //for each expression
   //--------------------------------------------------------------------
   for (e->First();!e->IsEol();e->Next()) {
      Exp* A=e->Member();
      P=new PCode("","arg","","");
      E=new Exp(E,A,ST.TVoid(),P); 
   }
   //--------------------------------------------------------------------
   //Create the cup-pcode and node
   //--------------------------------------------------------------------
   int pc=S->ParameterCount();      
   P=new PCode
       (""                             //Label
       ,"cup"                          //P-Code Op - Call User Procedure
       ,pc                             //Operand 1 - Parameter Count
       ,S->ELabel()                    //Operand 2 - Entry Label
       );
   E=new Exp(E,0,RT,P);
   E->Print(tfs);
   return E;
}
//--------------------------------------------------------------------
//Function StandardFunction implements the rule
//factor -> ID ( expression_list )
//if ID is a standard function
//--------------------------------------------------------------------
Exp* StandardFunction(StandardFunctionSymbol* S,List<Exp*>* e)
{  
   /*
   PCode* P;
   //--------------------------------------------------------------------
   //All Standard Functions have one and only one argument
   //--------------------------------------------------------------------
   e->First();
   Exp* E=e->Member();
   Typ* A=E->Type();
   string op=S->CSPID();
   Typ* F;
   if (op=="dec"||op=="inc") F=A;
   if (op=="rnd"||op=="trc") F=ST.TInteger();
   if (op=="chr") F=ST.TChar();
   if (op=="ord") F=ST.TInteger();
   if ((op=="abs") && (A==ST.TInteger())) op="abi";
   if ((op=="abs") && (A==ST.TReal())) op="abr";
   P=new PCode
       (""                             //Label
       ,op                             //P-Code instruction for the function
       ,""
       ,""
       );
   E=new Exp(E,0,F,P);
   return E;
   */
   return 0;
}
//--------------------------------------------------------------------
//Function factor_3 implements the rule
//factor -> ID ( expression_list )
//--------------------------------------------------------------------
Exp* factor_3(string* id,List<Exp*>* e)
{  
   Sym* S=ST.Find(*id);       //Find the function identifier
   //--------------------------------------------------------------------
   //Validate that (1) the identifier is in the symbol table and
   //(2) that the identifier is a function symbol
   //--------------------------------------------------------------------
   if (!S) yyerror("Semantic error - ID cannot be found");
   if (S->IsFunctionSymbol())
       return UserFunction((FunctionSymbol*)S,e);
   else if (S->IsStandardFunctionSymbol())
       return StandardFunction((StandardFunctionSymbol*)S,e);
   else yyerror("Semantic error - ID must be function");
   return 0;
}
//--------------------------------------------------------------------
//Function factor_4 implements the rule
//factor -> ( expression )
//--------------------------------------------------------------------
Exp* factor_4(Exp* E)
{
    return E;
}
//--------------------------------------------------------------------
//Function factor_5 implements the rule
//factor -> NOT factor 
//--------------------------------------------------------------------
Exp* factor_5(Exp* factor)
{  
   Typ* T=factor->Type();
   if (T!=ST.TBoolean()){
       yyerror("Semantic error NOT operand is not Boolean");
   }
   PCode* P=new PCode("","not","","");
   Exp* E=new Exp(factor,0,T,P);
   E->PPrint(pfs); //printing p-code to .pcd file
   return E;
}
//--------------------------------------------------------------------
//Function factor_6 implements the rule
//factor -> INTLIT 
//--------------------------------------------------------------------
Exp* factor_6(string* intlit)
{  PCode* P=new PCode("","ldc","i",*intlit);
   Exp* E=new Exp(ST.TInteger(),P);
   E->PPrint(pfs); //printing p-code to .pcd file
   return E;
}
//--------------------------------------------------------------------
//Function factor_7 implements the rule
//factor -> REALIT 
//--------------------------------------------------------------------
Exp* factor_7(string* realit)
{  PCode* P=new PCode("","ldc","r",*realit);
   Exp* E=new Exp(ST.TReal(),P);
   E->PPrint(pfs); //printing p-code to .pcd file
   return E;
}
//--------------------------------------------------------------------
//Function factor_8 implements the rule
//factor -> CHRLIT 
//--------------------------------------------------------------------
Exp* factor_8(string* chrlit)
{  PCode* P=new PCode("","ldc","c",*chrlit);
   Exp* E=new Exp(ST.TChar(),P);
   E->PPrint(pfs); //printing p-code to .pcd file
   return E;
}
