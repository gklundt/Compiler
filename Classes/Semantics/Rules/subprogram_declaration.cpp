#include "../Semantics.h"

void Semantics::subprogram_declaration(void) {
	ST.Print(tfs);
	ST.PopLocality();
}
