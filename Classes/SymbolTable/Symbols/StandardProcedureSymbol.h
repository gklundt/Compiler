#include "StandardSubprogramSymbol.h"

#ifndef STANDARDPROCEDURESYMBOL_H
#define STANDARDPROCEDURESYMBOL_H

class StandardProcedureSymbol: public StandardSubprogramSymbol {
public:
	StandardProcedureSymbol(const char* id, const char* cid);
	StandardProcedureSymbol(const char* id, string cid);
	StandardProcedureSymbol(string id, const char* cid);
	StandardProcedureSymbol(string id, string cid);
	void Print(ostream& o, int indent);
};

#endif
