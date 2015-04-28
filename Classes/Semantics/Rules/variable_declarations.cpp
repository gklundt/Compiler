#include "../Semantics.h"
//---------------------------------------------------------------------
//variable_declarations->variable_declarations VAR identifier_list COLON type
//---------------------------------------------------------------------
void Semantics::variable_declarations(List<string>* IL, Typ* T) {
	for (IL->First(); !IL->IsEol(); IL->Next()) {
		string Id = IL->Member();
		VariableSymbol* S = new VariableSymbol(Id, T);
		SymbolTable::instance()->Insert(S);
	}
}
