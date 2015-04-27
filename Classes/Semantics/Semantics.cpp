#include "Semantics.h"

Semantics::Semantics() {
}

Semantics::~Semantics() {
}

void Semantics::yyerror(string m) {
	cout << m << endl;
}
