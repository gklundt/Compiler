#include "../Semantics.h"
//---------------------------------------------------------------------
//type->standard_type
//---------------------------------------------------------------------
Typ* Semantics::type(Typ* T) {
	return T;
}
//---------------------------------------------------------------------
//type->ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type
//---------------------------------------------------------------------
Array* Semantics::type(string lo, string hi, Typ* T) {
	Range* I = new Range(ST.TInteger(), lo, hi);
	return new Array(I, T);

}
