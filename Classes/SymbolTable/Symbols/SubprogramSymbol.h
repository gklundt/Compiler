#include "../Sym.h"
#include "../Label.h"
#include "../../Types/NonScalarTypes/Subprogram.h"
#include "../symkind.h"

#ifndef SUBPROGRAMSYMBOL_H
#define SUBPROGRAMSYMBOL_H

extern void yyerror(string s);
extern Label L;

class SubprogramSymbol: public Sym {
	int lexicallevel;                             //Lexical level of subprogram
	int elabel;                                //Entry label
	int splabel;                               //Stack pointer label
	int eplabel;                                //Entry label

public:
	SubprogramSymbol(symkind sk, string id, Typ* t, int ll);
	void Print(ostream& o, int indent);
	int LexicalLevel(void);
	string ELabel(void);
	string SPLabel(void);
	string EPLabel(void);
	Typ* ReturnType(void);
	int ParameterCount(void);
	virtual ~SubprogramSymbol();
};

#endif
