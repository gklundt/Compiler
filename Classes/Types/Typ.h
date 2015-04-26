#ifndef Typ_h 
#define Typ_h 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

#include "typekind.h"
#include "../List.h"
class Typ {
	typekind tk;                                  //type classification
public:
	Typ();                                        //default constructor
	Typ(typekind t);                              //typed constructor
	string TypekindSymbol(typekind tk);         //returns a printable string for
												//the enumerated type typekind
	virtual void Print(ostream& o, int indent);    //prints all types
	virtual int Size();                          //returns the size of all types
	virtual int Alignment();                //returns the alignment of all types
	bool IsBoolean(void);                    //determines if the type is Boolean
	bool IsCharacter(void);                //determines if the type is character
	bool IsInteger(void);                 //determines if the type is an integer
	bool IsReal(void);                          //determines if the type is real
	bool IsString(void);                      //determines if the type is string
	bool IsArray(void);                     //determines if the type is an array
	bool IsRange(void);                 //determines if the type is a range type
	bool IsVoid(void);                   //determines if the type is a void type
	bool IsSubprogram(void);            //determines if the type is a subprogram
	string TypeChar(void);                   //Returns the P-Code type-character
	virtual ~Typ();
};

#endif

