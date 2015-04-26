#include "Label.h"

Label::Label(int w, char f) :
		label(1), width(w), fillchar(f) {
}
string Label::New(void) {
	ostringstream o;
	o << setw(width) << setfill(fillchar) << label++;
	return "L" + o.str();
}
