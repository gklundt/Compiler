#include "ProgramSymbol.h"

ProgramSymbol::ProgramSymbol(const char* id) :
		SubprogramSymbol(sk_program, id, TypeVoid, 0) {
}
ProgramSymbol::ProgramSymbol(string id) :
		SubprogramSymbol(sk_program, id, TypeVoid, 0) {
}
void ProgramSymbol::Print(ostream& o, int indent) {
	SubprogramSymbol::Print(o, indent);
}
