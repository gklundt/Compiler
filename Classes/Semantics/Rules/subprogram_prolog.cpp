#include "../Semantics.h"

List<Exp*>* Semantics::subprogram_prolog(SubprogramSymbol* S) {
	List<Exp*>* L = new List<Exp*>;
	//ToDo: subprogram_prolog labels
	PCode* P = new PCode(S->ELabel(), "ent", "sp", S->SPLabel());
	//PCode* P = new PCode("BROKEN", "ent", "sp", "BROKEN");
	Exp* E = new Exp(SymbolTable::instance()->TVoid(), P);
	L->Insert(E);
	P = new PCode("", "ent", "ep", S->EPLabel());
	//P = new PCode("", "ent", "ep", "BROKEN");
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	L->Insert(E);
	return L;
}
