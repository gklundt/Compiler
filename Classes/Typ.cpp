//-----------------------------------------------------------------------------
//File Typ.cpp implements the attributes of Types for the Subset Pascal
//symbol table 
//-----------------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//January, 2012
//-----------------------------------------------------------------------------
//Copyright January, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//-----------------------------------------------------------------------------
//C++ include files and namespace std
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
//-----------------------------------------------------------------------------
//Application include files
//-----------------------------------------------------------------------------
#include "Typ.h"
//-----------------------------------------------------------------------------
//Helper functions
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//Member functions of class Typ
//-----------------------------------------------------------------------------
Typ::Typ():tk(tk_void){}
Typ::Typ(typekind t):tk(t){}
void Typ::Print(ostream& o,int indent)
{   o << endl;
    for (int i=0;i<indent;i++) o << "  ";
    o << "type(" << TypekindSymbol(tk) << ")";
}
string Typ::TypekindSymbol(typekind tk)
{   switch(tk) {
        case tk_void              : return "Void";
        case tk_address           : return "Address";
        case tk_boolean           : return "Boolean";
        case tk_character         : return "Character";
        case tk_integer           : return "Integer";
        case tk_real              : return "Real";
        case tk_string            : return "String";
        case tk_range             : return "Range";
        case tk_array             : return "Array";
        case tk_subprogram        : return "Subprogram";
        default                   : return "Unknown";
    }
}
int Typ::Size(void){return 0;}
int Typ::Alignment(void){return 0;}
bool Typ::IsBoolean(void){return tk==tk_boolean;}
bool Typ::IsCharacter(void){return tk==tk_character;}
bool Typ::IsInteger(void){return tk==tk_integer;}
bool Typ::IsReal(void){return tk==tk_real;}
bool Typ::IsString(void){return tk==tk_string;}
bool Typ::IsArray(void){return tk==tk_array;}
bool Typ::IsRange(void){return tk==tk_range;}
bool Typ::IsVoid(void){return tk==tk_void;}
bool Typ::IsSubprogram(void){return tk==tk_subprogram;}
string Typ::TypeChar(void)
{   switch(tk) {
        case tk_void              : return "p";
        case tk_address           : return "a";
        case tk_boolean           : return "b";
        case tk_character         : return "c";
        case tk_integer           : return "i";
        case tk_real              : return "r";
        case tk_string            : return "s";
        case tk_range             : return "u";
        case tk_array             : return "u";
        case tk_subprogram        : return "u";
        default                   : return "u";
    }
}
//-----------------------------------------------------------------------------
//Member functions of class Scalar
//-----------------------------------------------------------------------------
Scalar::Scalar(typekind tk):Typ(tk),size(1),alignment(1){}
Scalar::Scalar(typekind tk,int sz,int al):Typ(tk),size(sz),alignment(al){}
void Scalar::Print(ostream& o,int indent)
{   Typ::Print(o,indent);
    o << endl;
    for (int i=0;i<indent+1;i++) o << "  ";
    o << "size(" << size << ")";
    o << " ";
    o << "alignment(" << alignment << ")";
}
int Scalar::Size(void){return size;}
int Scalar::Alignment(void){return alignment;}
//-----------------------------------------------------------------------------
//Member functions of class Boolean 
//-----------------------------------------------------------------------------
Boolean::Boolean():Scalar(tk_boolean,1,1){}
Boolean::Boolean(int sz,int al):Scalar(tk_boolean,sz,al){}
void Boolean::Print(ostream& o,int indent)
{   Scalar::Print(o,indent);
}
int Boolean::Size(void){return Scalar::Size();}
int Boolean::Alignment(void){return Scalar::Alignment();}
//-----------------------------------------------------------------------------
//Member functions of class Character 
//-----------------------------------------------------------------------------
Character::Character():Scalar(tk_character,1,1){}
Character::Character(int sz,int al):Scalar(tk_character,sz,al){}
void Character::Print(ostream& o,int indent)
{   Scalar::Print(o,indent);
}
int Character::Size(void){return Scalar::Size();}
int Character::Alignment(void){return Scalar::Alignment();}
//-----------------------------------------------------------------------------
//Member functions of class Integer
//-----------------------------------------------------------------------------
Integer::Integer():Scalar(tk_integer,1,1){}
Integer::Integer(int sz,int al):Scalar(tk_integer,sz,al){}
void Integer::Print(ostream& o,int indent)
{   Scalar::Print(o,indent);
}
int Integer::Size(void){return Scalar::Size();}
int Integer::Alignment(void){return Scalar::Alignment();}
//-----------------------------------------------------------------------------
//Member functions of class Real
//-----------------------------------------------------------------------------
Real::Real():Scalar(tk_real,1,1){}
Real::Real(int sz,int al):Scalar(tk_real,sz,al){}
void Real::Print(ostream& o,int indent)
{   Scalar::Print(o,indent);
}
int Real::Size(void){return Scalar::Size();}
int Real::Alignment(void){return Scalar::Alignment();}
//-----------------------------------------------------------------------------
//Member functions of class Void 
//-----------------------------------------------------------------------------
Void::Void():Scalar(tk_void,0,0){}
void Void::Print(ostream& o,int indent)
{   Scalar::Print(o,indent);
}
int Void::Size(void){return Scalar::Size();}
int Void::Alignment(void){return Scalar::Alignment();}
//-----------------------------------------------------------------------------
//Member functions of class Address 
//-----------------------------------------------------------------------------
Address::Address():Scalar(tk_address,0,0){}
void Address::Print(ostream& o,int indent)
{   Scalar::Print(o,indent);
}
int Address::Size(void){return Scalar::Size();}
int Address::Alignment(void){return Scalar::Alignment();}
//-----------------------------------------------------------------------------
//Member functions of class Constant
//-----------------------------------------------------------------------------
Constant::Constant(Typ* T,string V):t(T),v(V){}
Typ* Constant::Type(void){return t;}
void Constant::Print(ostream& o,int indent)
{   o << endl;
    for (int a=0;a<indent;a++) o << "  ";
    o << "Constant value(" << v << ")";
    t->Print(o,indent+1);
}
int Constant::IntegerValue(void)
{   istringstream s(v);
    int i;
    s >> i;
    return i;
}
int Constant::Size(void){return t->Size();}
int Constant::Alignment(void){return t->Alignment();}
string Constant::ConstantValue(void){return v;}
//-----------------------------------------------------------------------------
//Member functions of class Range
//-----------------------------------------------------------------------------
Range::Range(Typ* t,const char* l,const char *h):Typ(tk_range)
{   
    lo=new Constant(t,l);
    hi=new Constant(t,h);
}
Range::Range(Typ* t,string l,string h):Typ(tk_range)
{   lo=new Constant(t,l);
    hi=new Constant(t,h);
}
void Range::Print(ostream& o,int indent)
{   Typ::Print(o,indent);
    lo->Print(o,indent+1);
    hi->Print(o,indent+1);
}
int Range::Cardinality(void)
{   int h=hi->IntegerValue();
    int l=lo->IntegerValue();
    return h-l+1;
}
int Range::Size(void){return lo->Size();}
int Range::Alignment(void){return lo->Alignment();}
string Range::LoBound(void){return lo->ConstantValue();}
//-----------------------------------------------------------------------------
//Member functions of class Array
//-----------------------------------------------------------------------------
Array::Array(Range* i,Typ* e):Typ(tk_array),index(i),element(e){}
Array::Array(typekind tk,Range* i,Typ* e):Typ(tk_array),index(i),element(e){}
void Array::Print(ostream& o,int indent)
{   Typ::Print(o,indent);
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "Size(" << Size() << ")";
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "Index Type";
    index->Print(o,indent+2);
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "Element Type";
    element->Print(o,indent+2);
}
struct ArrayException {
    ArrayException(Array* a)
    {   cout << endl;
        cout << "Array Exception - the index type is not a range.";
        cout << endl;
        a->Print(cout,0);
        cout << endl;
    }
};
int Array::Size(void)
{   if (!(index->IsRange())) throw ArrayException(this); 
    Range* i=(Range*)index;
    int elementcount=i->Cardinality();
    int elementsize=element->Size();
    return elementcount*elementsize;
}
int Array::Alignment(void)
{   return element->Alignment();
}
Range* Array::IndexType(void){return index;}
Typ* Array::ElementType(void){return element;}
int Array::Stride(void){return element->Size();}
//-----------------------------------------------------------------------------
//Member functions of class String
//-----------------------------------------------------------------------------
String::String(Range* i,Typ* e):Array(tk_string,i,e){}
//-----------------------------------------------------------------------------
//Member functions of class Subprogram
//-----------------------------------------------------------------------------
Subprogram::Subprogram(List<Typ*>* p,Typ* r)
    :Typ(tk_subprogram),parameters(p),returntype(r){}
void Subprogram::Print(ostream& o,int indent)
{   Typ::Print(o,indent);
    //------------------------------------------------------------------------
    //Process return type
    //------------------------------------------------------------------------
    o << endl;
    for (int a=0;a<indent+2;a++) o << "  ";
    o << "Return Type";  
    returntype->Print(o,indent+3);
    //------------------------------------------------------------------------
    //Process parameter types
    //------------------------------------------------------------------------
    o << endl;
    for (int a=0;a<indent+2;a++) o << "  ";
    o << "Parameter Types";  
    for (parameters->First();!parameters->IsEol();parameters->Next()) {
        Typ* p=parameters->Member();
        p->Print(o,indent+3);
    }
}
int Subprogram::Size(void){return 0;}
int Subprogram::Alignment(void){return 0;}
Typ* Subprogram::ReturnType(void){return returntype;}
int Subprogram::ParameterCount(void){return parameters->Count();}
