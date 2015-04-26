#include "Scalar.h"

#ifndef BOOLEAN_H_
#define BOOLEAN_H_

class Boolean: public Scalar {
public:
	Boolean();
	Boolean(int sz, int al);
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	virtual ~Boolean();
};

#endif /* BOOLEAN_H_ */
