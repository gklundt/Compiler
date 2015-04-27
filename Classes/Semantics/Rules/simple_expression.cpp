#include "../Semantics.h"

//-------------------------------------------------------------------------
//Function simple_expression_1 implements the rule
//simple_expression -> term
//-------------------------------------------------------------------------
Exp* Semantics::simple_expression(Exp* term) {
	cout << "Exp* Semantics::simple_expression(Exp* term)" << endl;
	return term;
}
//--------------------------------------------------------------------
//Function simple_expression -> sign term
//--------------------------------------------------------------------

Exp* Semantics::simple_expression(string* sign, Exp* term) {
	cout << "Exp* Semantics::simple_expression(string* sign, Exp* term)"
			<< endl;
	//------------------------------------------------------------------
	//Emit a semantic error if the term has neither type integer or real
	//------------------------------------------------------------------
	if (!term->IsInteger() && !term->IsReal())
		yyerror("Semantic error: term must be integer or real");
	//------------------------------------------------------------------
	//Do nothing if the sign is positive "+"
	//------------------------------------------------------------------
	if (*sign == "+")
		return term;
	//------------------------------------------------------------------
	//------------------------------------------------------------------
	PCode* P;
	Exp* E;
	//------------------------------------------------------------------
	//  Term must have type integer or real
	//  Generate a negate integer, ngi, if the term has type integer
	//  Generate a negate real, ngr, if the term has type real
	//------------------------------------------------------------------
	if (term->IsInteger()) {
		P = new PCode("", "ngi", "", "");
		E = new Exp(term, 0, ST.TInteger(), P);
	} else {
		P = new PCode("", "ngr", "", "");
		E = new Exp(term, 0, ST.TReal(), P);
	}
	return E;
}
//--------------------------------------------------------------------
//Function add creates an expression to add the left and right 
//expressions
//--------------------------------------------------------------------
Exp* Semantics::add(Exp* l, Exp* r) {
	cout << "Exp* Semantics::add(Exp* l, Exp* r)" << endl;
	//--------------------------------------------------------------------
	//Coerce left and right expressions to real if either is integer and
	//the other is real
	//--------------------------------------------------------------------
	l = CoerceLeftExpressionToReal(l, r);
	r = CoerceRightExpressionToReal(l, r);
	//---------------------------------------------------------------------
	//add
	//---------------------------------------------------------------------
	PCode* P;
	Exp* E;
	if (l->IsReal() || r->IsReal()) {
		P = new PCode("", "adr", "", "");
		E = new Exp(l, r, ST.TReal(), P);
	} else {
		P = new PCode("", "adi", "", "");
		E = new Exp(l, r, ST.TInteger(), P);
	}
	return E;
}
//--------------------------------------------------------------------
//Function subtract creates an expression to subtract the left 
//expression from the  right expression
//--------------------------------------------------------------------
Exp* Semantics::subtract(Exp* l, Exp* r) {
	cout << "Exp* Semantics::subtract(Exp* l, Exp* r)" << endl;
	//--------------------------------------------------------------------
	//Coerce left and right expressions to real if either is integer and
	//the other is real
	//--------------------------------------------------------------------
	l = CoerceLeftExpressionToReal(l, r);
	r = CoerceRightExpressionToReal(l, r);
	//---------------------------------------------------------------------
	//subtract
	//---------------------------------------------------------------------
	PCode* P;
	Exp* E;
	if (l->IsReal() || r->IsReal()) {
		P = new PCode("", "sbr", "", "");
		E = new Exp(l, r, ST.TReal(), P);
	} else {
		P = new PCode("", "sbi", "", "");
		E = new Exp(l, r, ST.TInteger(), P);
	}
	return E;
}
//--------------------------------------------------------------------
//Function disjunction creates an expression to find the disjunction
//of the two expressions
//--------------------------------------------------------------------
Exp* Semantics::disjunction(Exp* l, Exp* r) {
	cout << "Exp* Semantics::disjunction(Exp* l, Exp* r)" << endl;
	//--------------------------------------------------------------------
	//Both expressions must be Boolean
	//-------------------------------------------------------------------
	if (!l->IsBoolean())
		yyerror("Semantic error: the left expression must be Boolean");
	if (!r->IsBoolean())
		yyerror("Semantic error: the right expression must be Boolean");
	//---------------------------------------------------------------------
	//disjunction
	//---------------------------------------------------------------------
	PCode* P = new PCode("", "ior", "", "");
	Exp* E = new Exp(l, r, ST.TBoolean(), P);
	return E;
}
//--------------------------------------------------------------------
//Function simple_expression -> simple_expression addop term
//--------------------------------------------------------------------
Exp* Semantics::simple_expression(Exp* simpleexpression, string* addop,
		Exp* term) {
	cout
			<< "Exp* Semantics::simple_expression(Exp* simpleexpression, string* addop, Exp* term)"
			<< endl;
	if (*addop == "+")
		return add(simpleexpression, term);
	if (*addop == "-")
		return subtract(simpleexpression, term);
	if (*addop == "or")
		return disjunction(simpleexpression, term);
	yyerror("Semantic error: invalid addop");
	return NULL;
}

