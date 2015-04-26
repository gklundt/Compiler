#include "Scalar.h"

#ifndef INTEGER_H_
#define INTEGER_H_

class Integer: public Scalar {
public:
	Integer();
	Integer(int sz, int al);
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	virtual ~Integer();
};

#endif /* INTEGER_H_ */
