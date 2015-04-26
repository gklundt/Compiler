#include "../Sym.h"

#ifndef VARIABLESYMBOL_H
#define VARIABLESYMBOL_H

class VariableSymbol: public Sym {
	int lexicallevel;
	int address;
public:
	VariableSymbol(const char* id, Typ* t, int ll = 0, int a = 5);
	VariableSymbol(string id, Typ* t, int ll = 0, int a = 5);
	void Print(ostream& o, int indent);
	void setLexicalLevel(int ll);
	void setAddress(int a);
	int LexicalLevel(void);
	int Address(void);
};

#endif
