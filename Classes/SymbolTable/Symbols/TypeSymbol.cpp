#include "TypeSymbol.h"

TypeSymbol::TypeSymbol(const char* id, Typ* t) :
		Sym(sk_type, id, t) {
}
TypeSymbol::TypeSymbol(string id, Typ* t) :
		Sym(sk_type, id, t) {
}
void TypeSymbol::Print(ostream& o, int indent) {
	Sym::Print(o, indent);
}
