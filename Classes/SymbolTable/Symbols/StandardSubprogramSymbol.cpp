#include "StandardSubprogramSymbol.h"

StandardSubprogramSymbol::StandardSubprogramSymbol(symkind sk, string id,
		string cid) :
		Sym(sk, id, TypeVoid), cspid(cid) {
}
void StandardSubprogramSymbol::Print(ostream& o, int indent) {
	Sym::Print(o, indent);
	o << endl;
	for (int a = 0; a < indent + 1; a++)
		o << "  ";
	o << "cspid(" << cspid << ")";
}
string StandardSubprogramSymbol::CSPID(void) {
	return cspid;
}
