#include "Void.h"

//-----------------------------------------------------------------------------
//Member functions of class Void
//-----------------------------------------------------------------------------
Void::Void() :
		Scalar(tk_void, 0, 0) {
}
void Void::Print(ostream& o, int indent) {
	Scalar::Print(o, indent);
}
int Void::Size(void) {
	return Scalar::Size();
}
int Void::Alignment(void) {
	return Scalar::Alignment();
}
Void::~Void() {
}
