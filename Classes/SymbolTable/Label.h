#ifndef Label_h
#define Label_h 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class Label {

	int label;
	int width;
	char fillchar;
	static Label *s_instance;

	Label(int w = 5, char f = '0') {
		label = 0;
		width = w;
		fillchar = f;
	}

public:

	string New();
	int iNew();
	static Label *instance();

};
#endif
