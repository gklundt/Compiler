////-----------------------------------------------------------------------------
////File Sym.cpp contains member functions of class Sym and derived classes
////-----------------------------------------------------------------------------
////Author: Thomas R. Turner
////E-Mail: trturner@uco.edu
////February, 2012
////-----------------------------------------------------------------------------
////Copyright February, 2012 by Thomas R. Turner.
////Do not reproduce without permission from Thomas R. Turner.
////-----------------------------------------------------------------------------
////C++ include files
////-----------------------------------------------------------------------------
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
//using namespace std;
////-----------------------------------------------------------------------------
////Symbol Table include files
////-----------------------------------------------------------------------------
//#include "Typ.h"
//#include "Label.h"
//#include "yyerror.h"
////-----------------------------------------------------------------------------
////External Variables
////-----------------------------------------------------------------------------

//Label L;
//-----------------------------------------------------------------------------
//class Sym member functions
//-----------------------------------------------------------------------------

#include "Sym.h"

Sym::Sym(symkind k, const char* i, Typ* u) :
		sk(k), id(i), t(u) {
}
Sym::Sym(symkind k, string i, Typ* u) :
		sk(k), id(i), t(u) {
}
//-----------------------------------------------------------------------------
string Sym::SymkindSymbol(symkind sk) {
	switch (sk) {
	case sk_constant:
		return "Constant Symbol";
	case sk_variable:
		return "Variable Symbol";
	case sk_type:
		return "Type Symbol";
	case sk_procedure:
		return "Procedure Symbol";
	case sk_function:
		return "Function Symbol";
	case sk_program:
		return "Program Symbol";
	case sk_standardprocedure:
		return "Standard Procedure Symbol";
	case sk_standardfunction:
		return "Standard Function Symbol";
	default:
		return "Unknown Symbol";
	}
}
//-----------------------------------------------------------------------------
symkind Sym::Symkind(void) {
	return sk;
}
//-----------------------------------------------------------------------------
void Sym::Print(ostream& o, int indent) {
	o << endl;
	for (int a = 0; a < indent; a++)
		o << "  ";
	o << "Symbol(" << SymkindSymbol(sk) << ")";
	o << " ";
	o << "id(" << id << ")";
	t->Print(o, indent + 1);
}
//-----------------------------------------------------------------------------
string Sym::Id(void) {
	return id;
}
//-----------------------------------------------------------------------------
Typ* Sym::Type(void) {
	return t;
}
//-----------------------------------------------------------------------------
bool Sym::IsStandardFunctionSymbol(void) {
	return sk == sk_standardfunction;
}
bool Sym::IsStandardProcedureSymbol(void) {
	return sk == sk_standardprocedure;
}
bool Sym::IsVariableSymbol(void) {
	return sk == sk_variable;
}
bool Sym::IsProgramSymbol(void) {
	return sk == sk_program;
}
bool Sym::IsProcedureSymbol(void) {
	return sk == sk_procedure;
}
bool Sym::IsTypeSymbol(void) {
	return sk == sk_type;
}
bool Sym::IsFunctionSymbol(void) {
	return sk == sk_function;
}
Sym::~Sym() {
}

