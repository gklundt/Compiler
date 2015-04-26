#include "StandardFunctionSymbol.h"

StandardFunctionSymbol::StandardFunctionSymbol(const char* id, const char* cid) :
		StandardSubprogramSymbol(sk_standardfunction, id, cid) {
}
StandardFunctionSymbol::StandardFunctionSymbol(const char* id, string cid) :
		StandardSubprogramSymbol(sk_standardfunction, id, cid) {
}
StandardFunctionSymbol::StandardFunctionSymbol(string id, const char* cid) :
		StandardSubprogramSymbol(sk_standardfunction, id, cid) {
}
StandardFunctionSymbol::StandardFunctionSymbol(string id, string cid) :
		StandardSubprogramSymbol(sk_standardfunction, id, cid) {
}
void StandardFunctionSymbol::Print(ostream& o, int indent) {
	StandardSubprogramSymbol::Print(o, indent);
}

