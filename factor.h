#ifndef factor_h
#define factor_h 1
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
#include <string>
//#include "yyerror.h"
using namespace std;
extern void yyerror(string);
//---------------------------------------------------------------------
//Supporting utilities
//---------------------------------------------------------------------
#include "List.h"
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
//-------------------------------------------------------------------------
//Function factor_1 implements the rule
//factor -> ID
//-------------------------------------------------------------------------
Exp* factor_1 ( string* id);
//--------------------------------------------------------------------
//Function factor_1_constant
//--------------------------------------------------------------------
Exp* factor_1_constant(ConstantSymbol* S);
//--------------------------------------------------------------------
//Function factor_1_variable
//--------------------------------------------------------------------
Exp* factor_1_variable(VariableSymbol* S);
//--------------------------------------------------------------------
//Function factor_1_function
//This code is incorrect and must be revised
//--------------------------------------------------------------------
Exp* factor_1_function(FunctionSymbol* S);
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
//--------------------------------------------------------------------
Exp* factor_2(string* id,Exp* e);
//--------------------------------------------------------------------
//Function factor_3 implements the rule
//factor -> ID ( expression_list )
//1.  find id - id must be a function
//2.  Create a node with a MST p-code - this p-code must be printed first
//3.  The nodes of the expression list must occur in the same order as
//    the argument-expressions they represent
//4.  Create a node with a CUP p-code
//--------------------------------------------------------------------
Exp* factor_3(string* id,List<Exp*>* e);
//--------------------------------------------------------------------
//Function factor_4 implements the rule
//factor -> ( expression )
//--------------------------------------------------------------------
Exp* factor_4(Exp* N);
//--------------------------------------------------------------------
//Function factor_5 implements the rule
//factor -> NOT factor 
//--------------------------------------------------------------------
Exp* factor_5(Exp* N);
//--------------------------------------------------------------------
//Function factor_6 implements the rule
//factor -> INTLIT 
//--------------------------------------------------------------------
Exp* factor_6(string* intlit);
//--------------------------------------------------------------------
//Function factor_7 implements the rule
//factor -> REALIT 
//--------------------------------------------------------------------
Exp* factor_7(string* realit);
//--------------------------------------------------------------------
//Function factor_8 implements the rule
//factor -> CHRLIT 
//--------------------------------------------------------------------
Exp* factor_8(string* chrlit);
#endif
