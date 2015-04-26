#include "StandardTypes.h"
//-----------------------------------------------------------------------------
//Externals
//-----------------------------------------------------------------------------
Typ* TypeVoid;
Typ* TypeAddress;
Typ* TypeBoolean;
Typ* TypeChar;
Typ* TypeInteger;
Typ* TypeReal;
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SetTVoid(Typ* tv) {
	TypeVoid = tv;
}
void SetTAddress(Typ* ta) {
	TypeAddress = ta;
}
void SetTBoolean(Typ* tb) {
	TypeBoolean = tb;
}
void SetTChar(Typ* tc) {
	TypeChar = tc;
}
void SetTInteger(Typ* ti) {
	TypeInteger = ti;
}
void SetTReal(Typ* tr) {
	TypeReal = tr;
}
Typ* GetTVoid(void) {
	return TypeVoid;
}
Typ* GetTAddress(void) {
	return TypeAddress;
}
Typ* GetTBoolean(void) {
	return TypeBoolean;
}
Typ* GetTChar(void) {
	return TypeChar;
}
Typ* GetTInteger(void) {
	return TypeInteger;
}
Typ* GetTReal(void) {
	return TypeReal;
}

