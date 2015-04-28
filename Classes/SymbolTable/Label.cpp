#include "Label.h"

int Label::iNew(void) {
	label = label + 1;
	return label;
}

string Label::New(void) {
	ostringstream o;
	o << setw(width) << setfill(fillchar) << label++;
	return "L" + o.str();
}

Label *Label::instance() {
	if (!s_instance)
		s_instance = new Label;
	return s_instance;
}
