#include "../Typ.h"

#ifndef SCALAR_H_
#define SCALAR_H_

class Scalar: public Typ {

public:

	int size;          //Number of bits required to store an entity of this type
	int alignment;          //Alignment specification for this type

	Scalar(typekind tk);
	Scalar(typekind tk, int sz, int al);
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	virtual ~Scalar();

};

#endif /* SCALAR_H_ */
