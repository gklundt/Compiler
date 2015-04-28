#include "../Semantics.h"

SubprogramSymbol* Semantics::program_head(string id) {

	List<VariableSymbol*>* VL = new List<VariableSymbol*>;
	Subprogram* PL = ParameterList(VL, SymbolTable::instance()->TVoid());
	ProcedureSymbol* P = new ProcedureSymbol(id, PL, 0);

	SymbolTable::instance()->Insert(P);
	SymbolTable::instance()->NewLocality();
	return P;
}
//void Semantics::program_head(string id)
//{
//   Sym* p=new ProgramSymbol(id);
//   ST.Insert(p);
//   ST.NewLocality();
//}
