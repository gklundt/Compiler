#include "Typ.h"

Typ::Typ() :
		tk(tk_void) {
}
Typ::Typ(typekind t) :
		tk(t) {
}
void Typ::Print(ostream& o, int indent) {
	o << endl;
	for (int i = 0; i < indent; i++)
		o << "  ";
	o << "type(" << TypekindSymbol(tk) << ")";
}
string Typ::TypekindSymbol(typekind tk) {
	switch (tk) {
	case tk_void:
		return "Void";
	case tk_address:
		return "Address";
	case tk_boolean:
		return "Boolean";
	case tk_character:
		return "Character";
	case tk_integer:
		return "Integer";
	case tk_real:
		return "Real";
	case tk_string:
		return "String";
	case tk_range:
		return "Range";
	case tk_array:
		return "Array";
	case tk_subprogram:
		return "Subprogram";
	default:
		return "Unknown";
	}
}
int Typ::Size(void) {
	return 0;
}
int Typ::Alignment(void) {
	return 0;
}
bool Typ::IsBoolean(void) {
	return tk == tk_boolean;
}
bool Typ::IsCharacter(void) {
	return tk == tk_character;
}
bool Typ::IsInteger(void) {
	return tk == tk_integer;
}
bool Typ::IsReal(void) {
	return tk == tk_real;
}
bool Typ::IsString(void) {
	return tk == tk_string;
}
bool Typ::IsArray(void) {
	return tk == tk_array;
}
bool Typ::IsRange(void) {
	return tk == tk_range;
}
bool Typ::IsVoid(void) {
	return tk == tk_void;
}
bool Typ::IsSubprogram(void) {
	return tk == tk_subprogram;
}
string Typ::TypeChar(void) {
	switch (tk) {
	case tk_void:
		return "p";
	case tk_address:
		return "a";
	case tk_boolean:
		return "b";
	case tk_character:
		return "c";
	case tk_integer:
		return "i";
	case tk_real:
		return "r";
	case tk_string:
		return "s";
	case tk_range:
		return "u";
	case tk_array:
		return "u";
	case tk_subprogram:
		return "u";
	default:
		return "u";
	}
}

Typ::~Typ() {
}
