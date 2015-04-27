#include "../Semantics.h"

SubprogramSymbol* Semantics::program_head(string id) {
	cout << "SubprogramSymbol* Semantics::program_head(string id)" << endl;
	List<VariableSymbol*>* VL = new List<VariableSymbol*>;
	Subprogram* PL = ParameterList(VL, ST.TVoid());
	ProcedureSymbol* P = new ProcedureSymbol(id, PL, 0);

	ST.Insert(P);
	ST.NewLocality();
	return P;
}
//void Semantics::program_head(string id)
//{
//   Sym* p=new ProgramSymbol(id);
//   ST.Insert(p);
//   ST.NewLocality();
//}
