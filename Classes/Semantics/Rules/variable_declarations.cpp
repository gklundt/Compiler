#include "../Semantics.h"
//---------------------------------------------------------------------
//variable_declarations->variable_declarations VAR identifier_list COLON type
//---------------------------------------------------------------------
void Semantics::variable_declarations(List<string>* IL, Typ* T) {
	cout << "void Semantics::variable_declarations(List<string>* IL, Typ* T)"
			<< endl;
	for (IL->First(); !IL->IsEol(); IL->Next()) {
		string Id = IL->Member();
		VariableSymbol* S = new VariableSymbol(Id, T);
		ST.Insert(S);
	}
}
