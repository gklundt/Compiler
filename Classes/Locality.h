#ifndef Locality_h 
#define Locality_h 1
//-----------------------------------------------------------------------------
//File Locality.h defines the attributes of a Locality for the symbol table 
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
#include "Namespace.h"
//-----------------------------------------------------------------------------
//A locality is a Namespace and functions that manage addresses relative to
//the start of the locality.
//-----------------------------------------------------------------------------
class Locality : public Namespace {
    int lexicallevel;         //Lexical Level of the Locality
    int offset;               //Next available bit-address
public:
    Locality(int ll);         //Record the lexical level of the locality and 
                              //initialize the relative address counter
    int Offset(void);         //Return the current offset
    int Offset                //Return the starting bit-address for the 
                              //next available variable or field based
                              //on parameters size and alignment
        (int size             //Number of bits required by a variable or
                              //field of type requesting storage
        ,int alignment        //Alignment specification given in bits
                              //for the variable or field of the type
                              //requesting storage
        );
    void Print(ostream& o);   //Print all the symbols in this locality
    int LexicalLevel(void);   //Return the lexical level of the locality
    void Insert(Sym* S);      //Insert Symbol Descriptor S into the Namespace
};
#endif
