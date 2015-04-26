#include "../Typ.h"
#include "Range.h"

#ifndef ARRAY_H_
#define ARRAY_H_

class Array: public Typ {
	Range* index;
	Typ* element;
public:
	Array(typekind tk, Range* i, Typ* e);
	Array(Range* i, Typ* e);
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	Range* IndexType(void);
	Typ* ElementType(void);
	int Stride(void);
	virtual ~Array();
};

#endif /* ARRAY_H_ */
