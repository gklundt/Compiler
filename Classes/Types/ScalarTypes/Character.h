#include "Scalar.h"

#ifndef CHARACTER_H_
#define CHARACTER_H_

class Character: public Scalar {
public:
	Character();
	Character(int sz, int al);
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	virtual ~Character();
};

#endif /* CHARACTER_H_ */
