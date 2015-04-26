#ifndef CLASSES_SEMANTICS_HEIGHT_H_
#define CLASSES_SEMANTICS_HEIGHT_H_

//-------------------------------------------------------------------------
//File Height.h defines class Height.
//-------------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//April, 2012
//-------------------------------------------------------------------------
//Copyright: April, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//-------------------------------------------------------------------------
//C++ include files
//-------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;
//-------------------------------------------------------------------------
//Application include files
//-------------------------------------------------------------------------
#include "PCode.h"
#include "Exp.h"
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
class Height {
	int C;                     //Current height of the computation stack
	int M;                     //Maximum height of the computation stack
	void InitStackDelta(void);
	void Compute(PCode* P);    //Add the difference contributed by PCode P
							   //to the running total.
public:
	Height();
	int Maximum(void);      //Return the maximum height of the computation stack
	void FindHeight(Exp* E);   //Find the height of the expression E
};

#endif /* CLASSES_SEMANTICS_RULES_HEIGHT_H_ */
