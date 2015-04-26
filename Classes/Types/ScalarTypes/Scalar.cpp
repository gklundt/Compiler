#include "Scalar.h"

Scalar::Scalar(typekind tk) :
		Typ(tk), size(1), alignment(1) {
}
Scalar::Scalar(typekind tk, int sz, int al) :
		Typ(tk), size(sz), alignment(al) {
}
void Scalar::Print(ostream& o, int indent) {
	Typ::Print(o, indent);
	o << endl;
	for (int i = 0; i < indent + 1; i++)
		o << "  ";
	o << "size(" << size << ")";
	o << " ";
	o << "alignment(" << alignment << ")";
}
int Scalar::Size(void) {
	return size;
}
int Scalar::Alignment(void) {
	return alignment;
}
Scalar::~Scalar() {
}
