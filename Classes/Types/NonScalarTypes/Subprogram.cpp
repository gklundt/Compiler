#include "Subprogram.h"

//-----------------------------------------------------------------------------
//Member functions of class Subprogram
//-----------------------------------------------------------------------------
Subprogram::Subprogram(List<Typ*>* p, Typ* r) :
		Typ(tk_subprogram), parameters(p), returntype(r) {
}
void Subprogram::Print(ostream& o, int indent) {
	Typ::Print(o, indent);
	//------------------------------------------------------------------------
	//Process return type
	//------------------------------------------------------------------------
	o << endl;
	for (int a = 0; a < indent + 2; a++)
		o << "  ";
	o << "Return Type";
	returntype->Print(o, indent + 3);
	//------------------------------------------------------------------------
	//Process parameter types
	//------------------------------------------------------------------------
	o << endl;
	for (int a = 0; a < indent + 2; a++)
		o << "  ";
	o << "Parameter Types";
	for (parameters->First(); !parameters->IsEol(); parameters->Next()) {
		Typ* p = parameters->Member();
		p->Print(o, indent + 3);
	}
}
int Subprogram::Size(void) {
	return 0;
}
int Subprogram::Alignment(void) {
	return 0;
}
Typ* Subprogram::ReturnType(void) {
	return returntype;
}
int Subprogram::ParameterCount(void) {
	return parameters->Count();
}
Subprogram::~Subprogram() {
}
