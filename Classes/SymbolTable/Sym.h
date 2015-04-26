#ifndef Sym_h
#define Sym_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

#include "../Types/Typ.h"
#include "symkind.h"

extern Typ* TypeVoid;
extern Typ* TypeAddress;
extern Typ* TypeBoolean;
extern Typ* TypeChar;
extern Typ* TypeInteger;
extern Typ* TypeReal;

class Sym {
	symkind sk;                                   //Symbol classification
	string id;                                    //Symbol identifier
	Typ* t;                                       //Symbol type
public:

	Sym(symkind k, const char* i, Typ* u);          //Constructor
	Sym(symkind k, string i, Typ* u);               //Constructor
	string SymkindSymbol(symkind sk);      //Return a string for the enumeration
										   //constant defining this symbol
	symkind Symkind(void);                    //Return the enumeration constant
											  //for this symbol
	virtual void Print(ostream& o, int indent);
	string Id(void);                              //Returns the Symbol's id.
	Typ* Type(void);                              //Return the Symbol's type
	bool IsStandardFunctionSymbol(void);     //Is the symbol a standard function
	bool IsStandardProcedureSymbol(void);   //Is the symbol a standard procedure
	bool IsVariableSymbol(void);                  //Is the symbol a variable
	bool IsProgramSymbol(void);                   //Is the symbol a program
	bool IsProcedureSymbol(void);                 //Is the symbol a procedure
	bool IsTypeSymbol(void);                      //Is the symbol a type
	bool IsFunctionSymbol(void);                  //Is the symbol a function
	virtual ~Sym();
};

#endif
