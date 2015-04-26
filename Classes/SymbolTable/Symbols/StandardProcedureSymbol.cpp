#include "StandardProcedureSymbol.h"


StandardProcedureSymbol::StandardProcedureSymbol(const char* id,
		const char* cid) :
		StandardSubprogramSymbol(sk_standardprocedure, id, cid) {
}
StandardProcedureSymbol::StandardProcedureSymbol(const char* id, string cid) :
		StandardSubprogramSymbol(sk_standardprocedure, id, cid) {
}
StandardProcedureSymbol::StandardProcedureSymbol(string id, const char* cid) :
		StandardSubprogramSymbol(sk_standardprocedure, id, cid) {
}
StandardProcedureSymbol::StandardProcedureSymbol(string id, string cid) :
		StandardSubprogramSymbol(sk_standardprocedure, id, cid) {
}
void StandardProcedureSymbol::Print(ostream& o, int indent) {
	StandardSubprogramSymbol::Print(o, indent);
}
