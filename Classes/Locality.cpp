//-----------------------------------------------------------------------------
//File Locality.cpp defines the attributes of a Locality for the symbol table 
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
#include "Locality.h"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct AlignmentException {
    AlignmentException(int al)
    {   cout << endl;
        "Alignment Exception - an alignment can never be zero.";
        cout << endl;
    }
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Locality::Locality(int ll):lexicallevel(ll),offset(4){}
int Locality::Offset(void){return offset;}
int Locality::Offset(int size,int alignment)
{    //-------------------------------------------------------------------
     //Variables and fields must be aligned on the boundaries given by
     //their types.  For example, floating point values having type
     //real must be aligned on 64-bit boundaries.
     //-------------------------------------------------------------------
     //Determine if the current offset can be used to allocate the
     //input variable or field.
     //-------------------------------------------------------------------
     if (alignment==0) throw AlignmentException(alignment);
     int remainder=offset%alignment;
     //-------------------------------------------------------------------
     //Add unused space to make the current offset suitable to allocate
     //storage for the next item
     //-------------------------------------------------------------------
     if (remainder) offset=offset+(alignment-remainder);
     return offset=offset+size;  //Allocate storage for the given item
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Locality::Print(ostream& o)
{   o << endl;
    o << "Locality: lexical level " << lexicallevel;
    Namespace::Print(o);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int Locality::LexicalLevel(void){return lexicallevel;}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Locality::Insert(Sym* S)
{   if (S->IsVariableSymbol()) { 
        VariableSymbol* vs=(VariableSymbol*)S;
        vs->setLexicalLevel(lexicallevel);
        Typ* T=S->Type();
        int sz=T->Size();
        int al=T->Alignment();
        int address=Offset(sz,al);
        vs->setAddress(address);
    }
    Namespace::Insert(S);
}
