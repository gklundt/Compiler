#include "SubprogramSymbol.h"

#ifndef FUNCTIONSYMBOL_H
#define FUNCTIONSYMBOL_H

class FunctionSymbol: public SubprogramSymbol {
public:
	FunctionSymbol(const char* id, Typ* t, int ll);
	FunctionSymbol(string id, Typ* t, int ll);
	void Print(ostream& o, int indent);
	~FunctionSymbol();
};

#endif
