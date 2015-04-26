#include "Scalar.h"

#ifndef REAL_H_
#define REAL_H_

class Real: public Scalar {
public:
	Real();
	Real(int sz, int al);
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	virtual ~Real();
};

#endif /* REAL_H_ */
