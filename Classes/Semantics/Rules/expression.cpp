#include "../Semantics.h"

Exp* Semantics::expression(Exp* simple_expression) {
	return simple_expression;
}

Exp* Semantics::expression(Exp* LE, Exp* RE, string relop) {
	Typ* LT = LE->Type();
	Typ* RT = RE->Type();
	Typ* B = ST.TBoolean();
	if (LT != RT)
		yyerror("Semantic Error:unequal left and right types.");
	string typechar = LT->TypeChar();
	PCode* P = new PCode("", relop, typechar, "");
	Exp* E = new Exp(LE, RE, B, P);
	E->Print(pfs); //printing p-code to .pcd file
	return E;
}

Exp* Semantics::expression(Exp* left_simple_expression, string* relop,
		Exp* right_simple_expression) {
	if (*relop == "=")
		return expression(left_simple_expression, right_simple_expression,
				"equ");
	if (*relop == "<>")
		return expression(left_simple_expression, right_simple_expression,
				"neq");
	if (*relop == "<")
		return expression(left_simple_expression, right_simple_expression,
				"les");
	if (*relop == "<=")
		return expression(left_simple_expression, right_simple_expression,
				"leq");
	if (*relop == ">")
		return expression(left_simple_expression, right_simple_expression,
				"grt");
	if (*relop == ">=")
		return expression(left_simple_expression, right_simple_expression,
				"geq");
	yyerror("Semantic error: invalid relop");
	return NULL;
}

