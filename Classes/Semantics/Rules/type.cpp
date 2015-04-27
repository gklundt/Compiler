#include "../Semantics.h"
//---------------------------------------------------------------------
//type->standard_type
//---------------------------------------------------------------------
Typ* Semantics::type(Typ* T) {
	cout << "Typ* Semantics::type(Typ* T)" << endl;
	return T;
}
//---------------------------------------------------------------------
//type->ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type
//---------------------------------------------------------------------
Array* Semantics::type(string lo, string hi, Typ* T) {
	cout << "Array* Semantics::type(string lo, string hi, Typ* T)" << endl;
	Range* I = new Range(ST.TInteger(), lo, hi);
	return new Array(I, T);

}
