#ifndef SymbolTable_h 
#define SymbolTable_h 1
//-----------------------------------------------------------------------------
//File SymbolTable.h defines the attributes of SymbolTables for the symbol table 
//-----------------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//February, 2012
//-----------------------------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//-----------------------------------------------------------------------------
//C++ include files and namespace std
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
//-----------------------------------------------------------------------------
//Application include files
//-----------------------------------------------------------------------------
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class SymbolTable : public LocalityStack {
    Locality* L;              //Points to the current locality

    Typ* taddress;            //Points to standard type address
    Typ* tvoid;               //Points to standard type void
    Typ* tchar;               //Points to standard type char
    Typ* tinteger;            //Points to standard type integer
    Typ* treal;               //Points to standard type real
    Typ* tboolean;            //Points to standard type boolean
    Typ* tstring;             //Points to standard type string
public:
    SymbolTable();            //Creates locality 0 and pushes it on the locality
                              //Stack
    ~SymbolTable();           //SymbolTable post processing
    //-------------------------------------------------------------------------
    //Function StandardTypes puts Subset Pascal Standard Types in the symbol
    //table at locality zero.  Standard types include integer,char,real,
    //and boolean.
    //-------------------------------------------------------------------------
    void Standard(void);
    void StandardTypes(void);
    void StandardConstants(void);
    void StandardProcedures(void);
    void StandardFunctions(void);
    void Print(ostream& o);   //Print the symbols in the current lexical level
    void NewLocality(void);   //Create a new locality and push it on the
                              //Locality Stack
    void PopLocality(void);   //Pop the current locality from the LocalityStack
                              //and replace it with the locality next to the
                              //Top of the stack.

    Typ* TAddress(void);      //Returns internal type address
    Typ* TVoid(void);         //Returns internal type void
    Typ* TChar(void);         //Returns standard type char
    Typ* TInteger(void);      //Returns standard type integer
    Typ* TReal(void);         //Returns standard type real
    Typ* TBoolean(void);      //Returns standard type Boolean

};        
#endif
