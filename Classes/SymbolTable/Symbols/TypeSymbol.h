#include "../Sym.h"

#ifndef TYPESYMBOL_H
#define TYPESYMBOL_H

class TypeSymbol: public Sym {
public:
	TypeSymbol(const char* id, Typ* t);
	TypeSymbol(string id, Typ* t);
	void Print(ostream& o, int indent);
};

#endif
