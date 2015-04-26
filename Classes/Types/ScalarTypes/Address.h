#include "Scalar.h"

#ifndef ADDRESS_H_
#define ADDRESS_H_

class Address: public Scalar {
public:
	Address();
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	virtual ~Address();
};

#endif /* ADDRESS_H_ */
