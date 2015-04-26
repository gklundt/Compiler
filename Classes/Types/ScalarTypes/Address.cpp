#include "Address.h"
//-----------------------------------------------------------------------------
//Member functions of class Address
//-----------------------------------------------------------------------------
Address::Address():Scalar(tk_address,0,0){}
void Address::Print(ostream& o,int indent)
{   Scalar::Print(o,indent);
}
int Address::Size(void){return Scalar::Size();}
int Address::Alignment(void){return Scalar::Alignment();}
Address::~Address(){}
