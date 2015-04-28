//ToDo: Fix this stuff
#include "SubprogramSymbol.h"

SubprogramSymbol::SubprogramSymbol(symkind sk, string id, Typ* t, int ll) :
		Sym(sk, id, t), lexicallevel(ll) {
	elabel = 0;
	splabel = 0;
	eplabel = 0;
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
int SubprogramSymbol::LexicalLevel() {
	return lexicallevel;
}
string SubprogramSymbol::ELabel() {
	if (elabel == 0)
		elabel = Label::instance()->iNew();
	ostringstream o;
	o << setw(5) << setfill('0') << elabel;
	return "L" + o.str();
	//return elabel;
}
string SubprogramSymbol::SPLabel() {
	if (splabel == 0)
		splabel = Label::instance()->iNew();
	ostringstream o;
	o << setw(5) << setfill('0') << splabel;
	return "L" + o.str();
	//return splabel;
}
string SubprogramSymbol::EPLabel() {
	if (eplabel == 0)
		eplabel = Label::instance()->iNew();
	ostringstream o;
	o << setw(5) << setfill('0') << eplabel;
	return "L" + o.str();
	//return eplabel;
}
int SubprogramSymbol::ParameterCount() {
	Typ* T = Sym::Type();
	Subprogram* ST = 0;
	if (T->IsSubprogram()) {
		ST = (Subprogram*) T;
		return ST->ParameterCount();
	} else {
		yyerror("Semantic error: no return type.");
	}
	return -1;
}

Typ* SubprogramSymbol::ReturnType() {
	Typ* T = Sym::Type();
	Subprogram* st = 0;

	if (T->IsSubprogram()) {
		st = (Subprogram*) T;
		return st->ReturnType();
	} else {
		yyerror("Semantic error: no return type.");
	}
	return NULL;
}
SubprogramSymbol::~SubprogramSymbol() {
}
