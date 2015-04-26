#include "../Sym.h"
#include "../../Types/ScalarTypes/Constant.h"

#ifndef CONSTANTSYMBOL_H
#define CONSTANTSYMBOL_H

class ConstantSymbol: public Sym {
	Constant* constant;
public:
	ConstantSymbol(const char* id, Typ* t, const char* v);
	ConstantSymbol(string id, Typ* t, const char* v);
	ConstantSymbol(const char* id, Typ* t, string v);
	ConstantSymbol(string id, Typ* t, string v);
	void Print(ostream& o, int indent);
	string ConstantValue(void);
};

#endif
