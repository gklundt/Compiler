#include "../Typ.h"
#include "../ScalarTypes/Constant.h"

#ifndef RANGE_H_
#define RANGE_H_

class Range: public Typ {
	Constant *lo;
	Constant *hi;
public:
	Range(Typ* t, const char* l, const char* h);
	Range(Typ* t, string l, string h);
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	int Cardinality(void);
	string LoBound(void);
	virtual ~Range();
};

#endif /* RANGE_H_ */
