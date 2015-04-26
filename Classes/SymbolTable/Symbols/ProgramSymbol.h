#include "SubprogramSymbol.h"

#ifndef PROGRAMSYMBOL_H
#define PROGRAMSYMBOL_H

class ProgramSymbol: public SubprogramSymbol {
public:
	ProgramSymbol(const char* id);
	ProgramSymbol(string id);
	void Print(ostream& o, int indent);
};

#endif
