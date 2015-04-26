#include "Scalar.h"

#ifndef VOID_H_
#define VOID_H_

class Void: public Scalar {
public:
	Void();
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	virtual ~Void();
};

#endif /* VOID_H_ */
