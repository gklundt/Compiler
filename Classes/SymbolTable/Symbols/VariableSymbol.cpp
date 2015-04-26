#include "VariableSymbol.h"

//-----------------------------------------------------------------------------
//class VariableSymbol
//-----------------------------------------------------------------------------
VariableSymbol::VariableSymbol(const char* id, Typ* t, int ll, int a) :
		Sym(sk_variable, id, t), lexicallevel(ll), address(a) {
}
VariableSymbol::VariableSymbol(string id, Typ* t, int ll, int a) :
		Sym(sk_variable, id, t), lexicallevel(ll), address(a) {
}
void VariableSymbol::Print(ostream& o, int indent) {
	Sym::Print(o, indent);
	o << endl;
	for (int a = 0; a < indent + 1; a++)
		o << "  ";
	o << "lexicallevel(" << lexicallevel << ") address(" << address << ")";
}
void VariableSymbol::setLexicalLevel(int ll) {
	lexicallevel = ll;
}
void VariableSymbol::setAddress(int a) {
	address = a;
}
int VariableSymbol::LexicalLevel(void) {
	return lexicallevel;
}
int VariableSymbol::Address(void) {
	return address;
}
