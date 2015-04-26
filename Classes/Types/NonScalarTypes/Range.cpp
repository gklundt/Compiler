#include "Range.h"
#include "../Typ.h"
//-----------------------------------------------------------------------------
//Member functions of class Range
//-----------------------------------------------------------------------------
Range::Range(Typ* t, const char* l, const char *h) :
		Typ(tk_range) {
	lo = new Constant(t, l);
	hi = new Constant(t, h);
}
Range::Range(Typ* t, string l, string h) :
		Typ(tk_range) {
	lo = new Constant(t, l);
	hi = new Constant(t, h);
}
void Range::Print(ostream& o, int indent) {
	Typ::Print(o, indent);
	lo->Print(o, indent + 1);
	hi->Print(o, indent + 1);
}
int Range::Cardinality(void) {
	int h = hi->IntegerValue();
	int l = lo->IntegerValue();
	return h - l + 1;
}
int Range::Size(void) {
	return lo->Size();
}
int Range::Alignment(void) {
	return lo->Alignment();
}
string Range::LoBound(void) {
	return lo->ConstantValue();
}

Range::~Range() {
}
