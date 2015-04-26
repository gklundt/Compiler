#include "Integer.h"

//-----------------------------------------------------------------------------
//Member functions of class Integer
//-----------------------------------------------------------------------------
Integer::Integer() :
		Scalar(tk_integer, 1, 1) {
}
Integer::Integer(int sz, int al) :
		Scalar(tk_integer, sz, al) {
}
void Integer::Print(ostream& o, int indent) {
	Scalar::Print(o, indent);
}
int Integer::Size(void) {
	return Scalar::Size();
}
int Integer::Alignment(void) {
	return Scalar::Alignment();
}
Integer::~Integer() {
}
