#include "SubprogramSymbol.h"

#ifndef PROCEDURESYMBOL_H
#define PROCEDURESYMBOL_H

class ProcedureSymbol: public SubprogramSymbol {
public:
	ProcedureSymbol(const char* id, Typ* t, int ll);
	ProcedureSymbol(string id, Typ* t, int ll);
	void Print(ostream& o, int indent);
};

#endif
