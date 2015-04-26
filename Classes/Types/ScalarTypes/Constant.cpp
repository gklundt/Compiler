#include "Constant.h"

//-----------------------------------------------------------------------------
//Member functions of class Constant
//-----------------------------------------------------------------------------
Constant::Constant(Typ* T, string V) :
		t(T), v(V) {
}
Typ* Constant::Type(void) {
	return t;
}
void Constant::Print(ostream& o, int indent) {
	o << endl;
	for (int a = 0; a < indent; a++)
		o << "  ";
	o << "Constant value(" << v << ")";
	t->Print(o, indent + 1);
}

int Constant::IntegerValue(void) {
	istringstream s(v);
	int i;
	s >> i;
	return i;
}
int Constant::Size(void) {
	return t->Size();
}
int Constant::Alignment(void) {
	return t->Alignment();
}
string Constant::ConstantValue(void) {
	return v;
}

