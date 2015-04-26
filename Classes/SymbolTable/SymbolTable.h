#ifndef SymbolTable_h 
#define SymbolTable_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "StandardTypes.h"

#include "Symbols/TypeSymbol.h"
#include "Symbols/StandardFunctionSymbol.h"
#include "Symbols/ConstantSymbol.h"
#include "Symbols/StandardProcedureSymbol.h"

#include "../Types/Typ.h"
#include "../Types/ScalarTypes/Address.h"
#include "../Types/ScalarTypes/Boolean.h"
#include "../Types/ScalarTypes/Character.h"
#include "../Types/ScalarTypes/Constant.h"
#include "../Types/ScalarTypes/Integer.h"
#include "../Types/ScalarTypes/Real.h"
#include "../Types/ScalarTypes/Void.h"

class SymbolTable: public LocalityStack {
	Locality* L;              //Points to the current locality
	Typ* taddress;            //Points to standard type address
	Typ* tvoid;               //Points to standard type void
	Typ* tchar;               //Points to standard type char
	Typ* tinteger;            //Points to standard type integer
	Typ* treal;               //Points to standard type real
	Typ* tboolean;            //Points to standard type boolean
	Typ* tstring;             //Points to standard type string

public:
	SymbolTable();      //Creates locality 0 and pushes it on the locality Stack
	~SymbolTable();           //SymbolTable post processing

	void Standard(void);
	void StandardTypes(void);
	void StandardConstants(void);
	void StandardProcedures(void);
	void StandardFunctions(void);
	void Print(ostream& o);   //Print the symbols in the current lexical level
	void NewLocality(void); //Create a new locality and push it on the Locality Stack
	void PopLocality(void); //Pop the current locality from the LocalityStack and replace it with the locality next to the Top of the stack.

	Typ* TAddress(void);      //Returns internal type address
	Typ* TVoid(void);         //Returns internal type void
	Typ* TChar(void);         //Returns standard type char
	Typ* TInteger(void);      //Returns standard type integer
	Typ* TReal(void);         //Returns standard type real
	Typ* TBoolean(void);      //Returns standard type Boolean

};

#endif
