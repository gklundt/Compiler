#include "../Semantics.h"
List<Exp*>* Semantics::subprogram_epilog(SubprogramSymbol* S,
		List<Exp*>* compound_statement) {
	List<Exp*>* L = new List<Exp*>;
	//ToDo: subprogram_epilog labels
	string tc = "?";
	if (S->IsFunctionSymbol())
		tc = "u";
	if (S->IsProcedureSymbol())
		tc = "u";
	if (S->IsProgramSymbol())
		tc = "u";
	if (S->IsStandardFunctionSymbol())
		tc = "u";
	if (S->IsStandardProcedureSymbol())
		tc = "u";
	if (S->IsTypeSymbol())
		tc = "?";
	if (S->IsVariableSymbol())
		tc = "?";
	//string tc = S->ReturnType()->TypeChar();
	PCode* P = new PCode("", "rtn", tc, "");
	Exp* E = new Exp(SymbolTable::instance()->TVoid(), P);
	L->Insert(E);
	int spvalue = SymbolTable::instance()->Offset();
	P = new PCode("#define", S->SPLabel(), spvalue, "");
	//P = new PCode("#define", "BROKEN", spvalue, "");
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	L->Insert(E);
	Height H;

	//-----------------------------------------------------------------------
	//Find the maximum height of the computation stack, epvalue
	//-----------------------------------------------------------------------
	for (compound_statement->First(); !compound_statement->IsEol();
			compound_statement->Next()) {
		Exp* E = compound_statement->Member();
		H.FindHeight(E);
	}
	int epvalue = spvalue + H.Maximum();
	P = new PCode("#define", S->EPLabel(), epvalue, "");
	//P = new PCode("#define", "BROKEN", epvalue, "");
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	L->Insert(E);
	return L;
}
