#include "ConstantSymbol.h"

ConstantSymbol::ConstantSymbol(const char* id, Typ* t, const char* v) :
		Sym(sk_constant, id, t) {
	constant = new Constant(t, v);
}
ConstantSymbol::ConstantSymbol(string id, Typ* t, const char* v) :
		Sym(sk_constant, id, t) {
	constant = new Constant(t, v);
}
ConstantSymbol::ConstantSymbol(const char* id, Typ* t, string v) :
		Sym(sk_constant, id, t) {
	constant = new Constant(t, v);
}
ConstantSymbol::ConstantSymbol(string id, Typ* t, string v) :
		Sym(sk_constant, id, t) {
	constant = new Constant(t, v);
}
void ConstantSymbol::Print(ostream& o, int indent) {
	Sym::Print(o, indent);
	constant->Print(o, indent + 1);
}
string ConstantSymbol::ConstantValue(void) {
	return constant->ConstantValue();
}
