#include "../Semantics.h"
//---------------------------------------------------------------------
//subprogram_parameters->empty
//---------------------------------------------------------------------
List<VariableSymbol*>* Semantics::subprogram_parameters(void) {
	cout << "List<VariableSymbol*>* Semantics::subprogram_parameters(void)"
			<< endl;
	return new List<VariableSymbol*> ;
}
//---------------------------------------------------------------------
//subprogram_parameters->LPAREN parameter_list RPAREN
//---------------------------------------------------------------------
List<VariableSymbol*>* Semantics::subprogram_parameters(
		List<VariableSymbol*>* V) {
	cout
			<< "List<VariableSymbol*>* Semantics::subprogram_parameters( List<VariableSymbol*>* V)"
			<< endl;
	return V;
}
