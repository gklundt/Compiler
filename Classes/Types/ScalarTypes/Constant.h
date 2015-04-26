#include "Scalar.h"

#ifndef CONSTANT_H_
#define CONSTANT_H_

class Constant {
	Typ* t;                   //Constant type
	string v;                 //Constant value
public:
	Constant(Typ* T, string V);
	void Print(ostream& o, int indent);
	Typ* Type(void);
	int IntegerValue(void);
	int Size(void);
	int Alignment(void);
	string ConstantValue(void);
};

#endif /* CONSTANT_H_ */
