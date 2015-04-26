#include "SubprogramSymbol.h"

SubprogramSymbol::SubprogramSymbol(symkind sk, string id, Typ* t, int ll) :
		Sym(sk, id, t), lexicallevel(ll) {
	Label L;
	elabel = L.New();
	splabel = L.New();
	eplabel = L.New();
}
void SubprogramSymbol::Print(ostream& o, int indent) {
	Sym::Print(o, indent);
	o << endl;
	for (int a = 0; a < indent + 1; a++)
		o << "  ";
	o << "lexicallevel(" << lexicallevel << ")";
	o << " ";
	o << "elabel(" << elabel << ")";
	o << " ";
	o << "splabel(" << splabel << ")";
	o << " ";
	o << "eplabel(" << eplabel << ")";
}
int SubprogramSymbol::LexicalLevel(void) {
	return lexicallevel;
}
string SubprogramSymbol::ELabel(void) {
	return elabel;
}
string SubprogramSymbol::SPLabel(void) {
	return splabel;
}
string SubprogramSymbol::EPLabel(void) {
	return eplabel;
}
int SubprogramSymbol::ParameterCount(void) {
	Typ* T = Sym::Type();
	Subprogram* ST = 0;
	if (T->IsSubprogram()) {
		ST = (Subprogram*) T;
		return ST->ParameterCount();
	} else {
		//ToDo: fix this
		//yyerror("Semantic error: no return type.");
	}
	return -1;
}
Typ* SubprogramSymbol::ReturnType(void) {
	Typ* T = Sym::Type();
	Subprogram* ST = 0;
	if (T->IsSubprogram()) {
		ST = (Subprogram*) T;
		return ST->ReturnType();
	} else {
		//ToDo: fix this
		//yyerror("Semantic error: no return type.");
	}
	return NULL;
}
SubprogramSymbol::~SubprogramSymbol() {
}
