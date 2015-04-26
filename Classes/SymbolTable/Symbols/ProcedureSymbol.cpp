#include "ProcedureSymbol.h"

//-----------------------------------------------------------------------------
//class ProcedureSymbol
//-----------------------------------------------------------------------------
ProcedureSymbol::ProcedureSymbol(const char* id, Typ* t, int ll) :
		SubprogramSymbol(sk_procedure, id, t, ll) {
}
ProcedureSymbol::ProcedureSymbol(string id, Typ* t, int ll) :
		SubprogramSymbol(sk_procedure, id, t, ll) {
}
void ProcedureSymbol::Print(ostream& o, int indent) {
	SubprogramSymbol::Print(o, indent);
}
