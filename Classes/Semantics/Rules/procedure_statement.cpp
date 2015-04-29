#include "../Semantics.h"

Exp* Semantics::StandardProcedure(StandardProcedureSymbol* S) {
	PCode* P = new PCode("", "csp", "", S->CSPID());
	Exp* E = new Exp(SymbolTable::instance()->TVoid(), P);
	//pfs << "procedure_statement.cpp" << endl;
	//E->PPrint(pfs);
	return E;
}
//-------------------------------------------------------------------------
//Function procedure_statement implements the rule
//procedure_statement: procedure_statement -> ID
//-------------------------------------------------------------------------
Exp* Semantics::procedure_statement(string* id) {
	Sym* S = SymbolTable::instance()->Find(*id);
	List<Exp*>* e = new List<Exp*>;
	if (!S)
		yyerror("Semantic error - ID cannot be found");
	if (S->IsProcedureSymbol())
		return UserSubprogram((SubprogramSymbol*) S, e);
	else if (S->IsStandardProcedureSymbol())
		return StandardProcedure((StandardProcedureSymbol*) S);
	else
		yyerror("Semantic error - ID must be a procedure");
	return NULL;
}
//-------------------------------------------------------------------------
//Function StandardProcedure implements the rule
//procedure_statement -> ID ( expression_list )
//when ID is the name of a standard procedure.
//-------------------------------------------------------------------------
Exp* Semantics::StandardProcedure(StandardProcedureSymbol* S, List<Exp*>* e) {
	PCode* P;
	Exp* E = 0;
	//--------------------------------------------------------------------
	//Traverse the list of argument-expressions and create an arg-pcode
	//for each expression
	//--------------------------------------------------------------------
	for (e->First(); !e->IsEol(); e->Next()) {
		Exp* A = e->Member();
		P = new PCode("", "arg", "", "");
		E = new Exp(E, A, SymbolTable::instance()->TVoid(), P);
	}
	P = new PCode(""                             //Label
			, "csp"                        //P-Code Op - Call Standard Procedure
			, "", S->CSPID());
	E = new Exp(E, 0, SymbolTable::instance()->TVoid(), P);
	//pfs << "procedure_statement.cpp" << endl;
	//E->PPrint(pfs);
	//E->PPrint(tfs);
	return E;
}
//-------------------------------------------------------------------------
//Function procedure_statement_2 implements the rule
//procedure_statement_2: procedure_statement -> ID ( expression_list )
//-------------------------------------------------------------------------
Exp* Semantics::procedure_statement(string* id, List<Exp*>* EL) {
	Sym* S = SymbolTable::instance()->Find(*id);
	if (!S)
		yyerror("Semantic error - ID cannot be found");
	if (S->IsProcedureSymbol())
		return UserSubprogram((SubprogramSymbol*) S, EL);
	else if (S->IsStandardProcedureSymbol())
		return StandardProcedure((StandardProcedureSymbol*) S, EL);
	else
		yyerror("Semantic error - ID must be a procedure");
	return NULL;
}
