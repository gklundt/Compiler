#ifndef Exp_h
#define Exp_h 1
//-------------------------------------------------------------------------
//File Exp.h defines class Exp.  Class Exp is designed to represent 
//p-code Expressions for the Subset Pascal Compiler
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//C++ include files
//-------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//-------------------------------------------------------------------------
//Application include files
//-------------------------------------------------------------------------
#include "PCode.h"
#include "../Types/Typ.h"
#include "../SymbolTable/Sym.h"
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
class Exp {
	Exp* LExp;
	Exp* RExp;
	Typ* T;
	PCode* P;
public:
	Exp(Typ* t, PCode* p);
	Exp(Exp* l, Exp* r, Typ* t, PCode* p);
	void PPrint(ostream& o);             //Print the P-Code of this instance
	void TPrint(ostream& o, int depth);   //Print the type of this instance
	void Print(ostream& o);            //Print P-Codes using postorder traversal
	Typ* Type(void);
	void LeftAppend(Exp* L);             //Append L to the leftmost leaf of this
										 //expression
	bool IsBoolean(void);
	bool IsCharacter(void);
	bool IsInteger(void);
	bool IsReal(void);
};
#endif
