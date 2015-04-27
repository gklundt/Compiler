#include "../Semantics.h"

List<VariableSymbol*>* Semantics::parameter_list(List<string>* IL, Typ* T) {
	cout
			<< "List<VariableSymbol*>* Semantics::parameter_list(List<string>* IL, Typ* T)"
			<< endl;
	List<VariableSymbol*>* VL = new List<VariableSymbol*>;
	for (IL->First(); !IL->IsEol(); IL->Next()) {
		string Id = IL->Member();
		VariableSymbol* S = new VariableSymbol(Id, T);
		VL->Insert(S);
	}
	return VL;
}
//---------------------------------------------------------------------
//parameter_list->parameter_list SEMICOLON identifier_list COLON type
//---------------------------------------------------------------------
List<VariableSymbol*>* Semantics::parameter_list(List<VariableSymbol*>* VL,
		List<string>* IL, Typ* T) {
	cout
			<< "List<VariableSymbol*>* Semantics::parameter_list(List<VariableSymbol*>* VL, List<string>* IL, Typ* T)"
			<< endl;
	for (IL->First(); !IL->IsEol(); IL->Next()) {
		string Id = IL->Member();
		VariableSymbol* S = new VariableSymbol(Id, T);
		VL->Insert(S);
	}
	return VL;
}

