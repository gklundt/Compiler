#include "../Semantics.h"
//---------------------------------------------------------------------
//subprogram_parameters->empty
//---------------------------------------------------------------------
List<VariableSymbol*>* Semantics::subprogram_parameters(void) {
	return new List<VariableSymbol*> ;
}
//---------------------------------------------------------------------
//subprogram_parameters->LPAREN parameter_list RPAREN
//---------------------------------------------------------------------
List<VariableSymbol*>* Semantics::subprogram_parameters(
		List<VariableSymbol*>* V) {
	return V;
}
