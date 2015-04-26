#include "Array.h"
#include "Range.h"

#ifndef STRING_H_
#define STRING_H_

class String: public Array {
public:
	String(Range* i, Typ* e);
	virtual ~String();
};

#endif /* STRING_H_ */
