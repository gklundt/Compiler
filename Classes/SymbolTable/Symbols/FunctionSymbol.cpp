#include "FunctionSymbol.h"

FunctionSymbol::FunctionSymbol(const char* id, Typ* t, int ll) :
		SubprogramSymbol(sk_function, id, t, ll) {
}
FunctionSymbol::FunctionSymbol(string id, Typ* t, int ll) :
		SubprogramSymbol(sk_function, id, t, ll) {
}
void FunctionSymbol::Print(ostream& o, int indent) {
	SubprogramSymbol::Print(o, indent);
}
FunctionSymbol::~FunctionSymbol(){}
