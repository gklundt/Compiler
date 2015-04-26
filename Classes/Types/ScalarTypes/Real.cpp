#include "Real.h"

//-----------------------------------------------------------------------------
//Member functions of class Real
//-----------------------------------------------------------------------------
Real::Real() :
		Scalar(tk_real, 1, 1) {
}
Real::Real(int sz, int al) :
		Scalar(tk_real, sz, al) {
}
void Real::Print(ostream& o, int indent) {
	Scalar::Print(o, indent);
}
int Real::Size(void) {
	return Scalar::Size();
}
int Real::Alignment(void) {
	return Scalar::Alignment();
}
Real::~Real() {
}
