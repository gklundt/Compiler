#ifndef statement_h
#define statement_h 1
//-------------------------------------------------------------------------
//File statement.h contains prototypes for the following productions: 
//statement -> variable := expression
//statement -> procedure_statement
//statement -> compound_statement
//statement -> IF expression THEN statement ELSE statement
//statement -> WHILE expression DO statement
//-------------------------------------------------------------------------
//---------------------------------------------------------------------
//Author:   Thomas R. Turner
//E-Mail:   trturner@uco.edu
//Date:     March, 2012
//---------------------------------------------------------------------
//Copyright March, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//---------------------------------------------------------------------
//C++ inlcude files
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
#include "String.h"
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> variable := expression
List<Exp*>* statement(Exp* variable,Exp* expression);
//--------------------------------------------------------------------
//Function statement implements the rule
//statement -> procedure_statement
List<Exp*>* statement(Exp* procedure_statement);
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> compound_statement
List<Exp*>* statement(List<Exp*>* compound_statement);
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> IF expression THEN statement ELSE statement
List<Exp*>* statement(Exp* expression,List<Exp*>* then_statement,List<Exp*>* else_statement);
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> WHILE expression DO statement
List<Exp*>* statement(Exp* expression,List<Exp*>* body_statement);
//--------------------------------------------------------------------
#endif
