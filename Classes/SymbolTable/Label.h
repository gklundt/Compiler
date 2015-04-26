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
public:
   Label(int w=5,char f='0');
   string New(void);
};
#endif
