#ifndef LocalityStack_h 
#define LocalityStack_h 1
//-----------------------------------------------------------------------------
//File LocalityStack.h defines the attributes of LocalityStacks for the 
//symbol table 
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
//A LocalityStack is a stack of localities.  Each locality stores the symbols
//created in that locality.  Member tos corresponds to the lexical level. 
//Standard or native symbols like, integer, char, real, etc., are stored
//at lexical level zero (0).
//-----------------------------------------------------------------------------
class LocalityStack {
    int size;                 //Maximum number of localities in the symbol table
    int tos;                  //Index of the locality on top of the stack
    Locality** L;             //Points to an array of pointers to Localities
public:
    LocalityStack(int sz=100);//Allocate storage for the stack
    ~LocalityStack();         //Reclaim storage for the stack
    bool IsEmpty(void);       //Is the stack empty?
    bool IsFull(void);        //Is the stack full?
    void Push(Locality* L);   //Push a new locality on the stack
    Locality* Pop(void);      //Pop a locality from the stack
    Locality* Top(void);      //Obtain the locality on top of the stack
    Sym* Find(string& id);    //Find a symbol in the stack
    Sym* Find(char* id);      //Find a symbol in the stack
    void Insert(Sym* S);      //Insert a symbol in the locality on top of the
                              //stack
    int LexicalLevel(void);   //Return the lexical level of the locality on
                              //top of the stack
    int Offset(void);         //Return the current offset
    void Print(ostream& o);   //Print all the localities currently on the
                              //stack
    void Print                //Print the locality on top of the stack
       (ostream& o            
       ,int ll
       );
};
#endif
