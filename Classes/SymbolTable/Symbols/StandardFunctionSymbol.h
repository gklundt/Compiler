#include "StandardSubprogramSymbol.h"

#ifndef STANDARDFUNCTIONSYMBOL_H
#define STANDARDFUNCTIONSYMBOL_H

class StandardFunctionSymbol: public StandardSubprogramSymbol {
public:
	StandardFunctionSymbol(const char* id, const char* cid);
	StandardFunctionSymbol(const char* id, string cid);
	StandardFunctionSymbol(string id, const char* cid);
	StandardFunctionSymbol(string id, string cid);
	void Print(ostream& o, int indent);
};

#endif
