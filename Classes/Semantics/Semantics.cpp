#include "Semantics.h"


Semantics::~Semantics() {
}

void Semantics::yyerror(string m) {
	cout << m << endl;
}
