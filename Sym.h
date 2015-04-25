#ifndef Sym_h
#define Sym_h 1
//-----------------------------------------------------------------------------
//File Sym.h defines the attributes of Symbols for the Subset Pascal
//symbol table
//-----------------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//January, 2012
//-----------------------------------------------------------------------------
//Copyright January, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
enum symkind
    {sk_constant              //Constant symbol
    ,sk_variable              //Variable symbol
    ,sk_type                  //Type symbol
    ,sk_procedure             //Type procedure
    ,sk_function              //Type function
    ,sk_program               //Type program
    ,sk_standardprocedure     //Type standard procedure
    ,sk_standardfunction      //type standard function
    };
//---------------------------------------------------------------------------
//All Symbols have, at minimum, a symbol classification - symkind -, an 
//identifier, and a type
//---------------------------------------------------------------------------
class Sym {
    symkind sk;                                   //Symbol classification
    string id;                                    //Symbol identifier
    Typ* t;                                       //Symbol type
public:
    Sym(symkind k,const char* i,Typ* u);          //Constructor 
    Sym(symkind k,string i,Typ* u);               //Constructor
    string SymkindSymbol(symkind sk);             //Return a string for the enumeration
                                                  //constant defining this symbol
    symkind Symkind(void);                        //Return the enumeration constant 
                                                  //for this symbol
    virtual void Print(ostream& o,int indent);
    string Id(void);                              //Returns the Symbol's id.
    Typ* Type(void);                              //Return the Symbol's type
    bool IsStandardFunctionSymbol(void);          //Is the symbol a standard function
    bool IsStandardProcedureSymbol(void);         //Is the symbol a standard procedure
    bool IsVariableSymbol(void);                  //Is the symbol a variable
    bool IsProgramSymbol(void);                   //Is the symbol a program
    bool IsProcedureSymbol(void);                 //Is the symbol a procedure
    bool IsTypeSymbol(void);                      //Is the symbol a type
    bool IsFunctionSymbol(void);                  //Is the symbol a function
};
//---------------------------------------------------------------------------
//class TypeSymbol
//---------------------------------------------------------------------------
class TypeSymbol: public Sym {
public:
    TypeSymbol(const char* id,Typ* t);
    TypeSymbol(string id,Typ* t);
    void Print(ostream& o,int indent);
};
//---------------------------------------------------------------------------
//class ConstantSymbol
//---------------------------------------------------------------------------
class ConstantSymbol: public Sym {
    Constant* constant;
public:
    ConstantSymbol(const char* id,Typ* t,const char* v);
    ConstantSymbol(string id,Typ* t,const char* v);
    ConstantSymbol(const char* id,Typ* t,string v);
    ConstantSymbol(string id,Typ* t,string v);
    void Print(ostream& o,int indent);
    string ConstantValue(void);
};
//---------------------------------------------------------------------------
//class StandardSubprogramSymbol
//---------------------------------------------------------------------------
class StandardSubprogramSymbol: public Sym {
    string cspid;                                 //Call Standard Procedure ID
public:
    StandardSubprogramSymbol(symkind sk,string id,string cid);
    void Print(ostream& id,int indent);
    string CSPID(void);
};
//---------------------------------------------------------------------------
//class StandardProcedureSymbol
//---------------------------------------------------------------------------
class StandardProcedureSymbol: public StandardSubprogramSymbol {
public:
    StandardProcedureSymbol(const char* id,const char* cid);
    StandardProcedureSymbol(const char* id,string cid);
    StandardProcedureSymbol(string id,const char* cid);
    StandardProcedureSymbol(string id,string cid);
    void Print(ostream& o,int indent);
};
//---------------------------------------------------------------------------
//class StandardFunctionSymbol
//---------------------------------------------------------------------------
class StandardFunctionSymbol: public StandardSubprogramSymbol {
public:
    StandardFunctionSymbol(const char* id,const char* cid);
    StandardFunctionSymbol(const char* id,string cid);
    StandardFunctionSymbol(string id,const char* cid);
    StandardFunctionSymbol(string id,string cid);
    void Print(ostream& o,int indent);
};
//---------------------------------------------------------------------------
//class VariableSymbol
//---------------------------------------------------------------------------
class VariableSymbol: public Sym {
    int lexicallevel;
    int address;
public:
    VariableSymbol(const char* id,Typ* t,int ll=0,int a=5);
    VariableSymbol(string id,Typ* t,int ll=0,int a=5);
    void Print(ostream& o,int indent);
    void setLexicalLevel(int ll);
    void setAddress(int a);
    int LexicalLevel(void);
    int Address(void);
};
//---------------------------------------------------------------------------
//class SubprogramSymbol
//---------------------------------------------------------------------------
class SubprogramSymbol: public Sym {
    int lexicallevel;                             //Lexical level of subprogram
    string elabel;                                //Entry label
    string splabel;                               //Stack pointer label
    string eplabel;                               //Extreme pointer label
public:
    SubprogramSymbol(symkind sk,string id,Typ* t,int ll);
    void Print(ostream& o,int indent);
    int LexicalLevel(void);
    string ELabel(void);
    string SPLabel(void);
    string EPLabel(void);
    Typ* ReturnType(void);
    int ParameterCount(void);
};
//---------------------------------------------------------------------------
//class ProcedureSymbol
//---------------------------------------------------------------------------
class ProcedureSymbol: public SubprogramSymbol {
public:
    ProcedureSymbol(const char* id,Typ* t,int ll);
    ProcedureSymbol(string id,Typ* t,int ll);
    void Print(ostream& o,int indent);
};
//---------------------------------------------------------------------------
//class FunctionSymbol
//---------------------------------------------------------------------------
class FunctionSymbol: public SubprogramSymbol {
public:
    FunctionSymbol(const char* id,Typ* t,int ll);
    FunctionSymbol(string id,Typ* t,int ll);
    void Print(ostream& o,int indent);
};
//---------------------------------------------------------------------------
//class ProgramSymbol
//---------------------------------------------------------------------------
class ProgramSymbol: public SubprogramSymbol {
public:
    ProgramSymbol(const char* id);
    ProgramSymbol(string id);
    void Print(ostream& o,int indent);
};
#endif
