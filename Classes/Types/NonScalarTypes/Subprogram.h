#include "../Typ.h"

#ifndef SUBPROGRAM_H_
#define SUBPROGRAM_H_

class Subprogram: public Typ {
	List<Typ*>* parameters;                       //Parameters
	Typ* returntype;                              //Return type
public:
	Subprogram(List<Typ*>* p, Typ* rt);
	void Print(ostream& o, int indent);
	int Size(void);
	int Alignment(void);
	Typ* ReturnType(void);
	int ParameterCount(void);
	virtual ~Subprogram();
};

#endif /* SUBPROGRAM_H_ */
