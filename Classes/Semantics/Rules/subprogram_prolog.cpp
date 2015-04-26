#include "../Semantics.h"

List<Exp*>* Semantics::subprogram_prolog(SubprogramSymbol* S) {
	List<Exp*>* L = new List<Exp*>;
	PCode* P = new PCode(S->ELabel(), "ent", "sp", S->SPLabel());
	Exp* E = new Exp(ST.TVoid(), P);
	L->Insert(E);
	P = new PCode("", "ent", "ep", S->EPLabel());
	E = new Exp(ST.TVoid(), P);
	L->Insert(E);
	return L;
}
