#include "../Sym.h"
#include "../symkind.h"

#ifndef STANDARDSUBPROGRAMSYMBOL_H
#define STANDARDSUBPROGRAMSYMBOL_H

class StandardSubprogramSymbol: public Sym {
	string cspid;                                 //Call Standard Procedure ID
public:
	StandardSubprogramSymbol(symkind sk, string id, string cid);
	void Print(ostream& id, int indent);
	string CSPID(void);
};

#endif
