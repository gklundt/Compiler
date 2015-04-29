#include "Label.h"

int Label::iNew(void) {
	label = label + 1;
//	cout << "L:" + label << endl;
	return label;
}

string Label::New(void) {
	ostringstream o;
	o << setw(width) << setfill(fillchar) << label++;
//	cout << "L" + o.str() << endl;
	return "L" + o.str();
}

Label *Label::instance() {
	if (!s_instance) {
//		cout << "I'm new!" << endl;
		s_instance = new Label;
	}
	return s_instance;
}
