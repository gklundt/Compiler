#ifndef usersubprogram_h
#define usersubprogram_h 1
//---------------------------------------------------------
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
#include "PCode.h"
#include "Exp.h"

//-------------------------------------------------------------------------
//Function UserSubprogram implements the rule
//procedure_statement -> ID ( expression_list )
//procedure_statement -> ID
//factor -> ID ( expression_list )
//factor -> ID *where ID is a function*
//when ID is the name of a user procedure.
//-------------------------------------------------------------------------
Exp* UserSubprogram(SubprogramSymbol* S,List<Exp*>* e);
#endif
