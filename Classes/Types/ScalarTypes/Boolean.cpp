#include "Boolean.h"

Boolean::Boolean() :
		Scalar(tk_boolean, 1, 1) {
}
Boolean::Boolean(int sz, int al) :
		Scalar(tk_boolean, sz, al) {
}
void Boolean::Print(ostream& o, int indent) {
	Scalar::Print(o, indent);
}
int Boolean::Size(void) {
	return Scalar::Size();
}
int Boolean::Alignment(void) {
	return Scalar::Alignment();
}
Boolean::~Boolean() {
}
