#include "../Semantics.h"

Exp* Semantics::CoerceLeftExpressionToReal(Exp* LE, Exp* RE) {
	cout << "Exp* Semantics::CoerceLeftExpressionToReal(Exp* LE, Exp* RE)"
			<< endl;
	if (!LE->IsReal() && !LE->IsInteger())
		yyerror("Semantic error: left expression is not Integer and not Real");
	if (LE->IsInteger() && RE->IsReal()) {
		PCode* P = new PCode("", "flt", "", "");
		return new Exp(LE, 0, ST.TReal(), P);
	} else {
		return LE;
	}
}

Exp* Semantics::CoerceRightExpressionToReal(Exp* LE, Exp* RE) {
	cout << "Exp* Semantics::CoerceRightExpressionToReal(Exp* LE, Exp* RE)"
			<< endl;
	if (!RE->IsReal() && !RE->IsInteger())
		yyerror("Semantic error: right expression is not Integer and not Real");
	if (RE->IsInteger() && LE->IsReal()) {
		PCode* P = new PCode("", "flt", "", "");
		return new Exp(0, RE, ST.TReal(), P);
	} else {
		return RE;
	}
}
