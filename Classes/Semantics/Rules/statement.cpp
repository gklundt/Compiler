#include "../Semantics.h"

//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> variable := expression
//-------------------------------------------------------------------------
List<Exp*>* Semantics::statement(Exp* variable, Exp* expression) {
	if (variable->Type() != expression->Type()) {
		yyerror("Semantic error:Assignment type mismatch");
	}
	string tc = expression->Type()->TypeChar();
	PCode* P = new PCode("", "sti", tc, "");
	Exp* E = new Exp(variable, expression, SymbolTable::instance()->TVoid(), P);
	List<Exp*>* S = new List<Exp*>;
	S->Insert(E);
	return S;
}
//--------------------------------------------------------------------
//Function statement implements the rule
//statement -> procedure_statement
List<Exp*>* Semantics::statement(Exp* procedure_statement) {
	List<Exp*>* L = new List<Exp*>;
	L->Insert(procedure_statement);
	return L;
}
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> compound_statement
List<Exp*>* Semantics::statement(List<Exp*>* compound_statement) {
	return compound_statement;
}
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> IF expression THEN statement ELSE statement
//  expression
//  fjp "elsebegin"
//  true_statement
//  ujp "elseend"
//  elsebegin:
//  else_statement
//  elseend
//-------------------------------------------------------------------------
List<Exp*>* Semantics::statement(Exp* expression, List<Exp*>* then_statement,
		List<Exp*>* else_statement) {
	string elsebegin = Label::instance()->New(); //Create label that begins the else-statement
	PCode* P;
	P = new PCode("", "fjp", "", elsebegin); //Jump to else-statement if expression is false
	Exp* E;
	E = new Exp(expression, 0, SymbolTable::instance()->TVoid(), P);
	List<Exp*>* IS = new List<Exp*>;      //Create an If-Statement
	IS->Insert(E);               //Insert the fjp expression to the If-Statement
	IS->Append(then_statement);  //Append the then-statement to the If-Statement
	string elseend = Label::instance()->New(); //Create the label that is placed after the else-statement
	P = new PCode("", "ujp", "", elseend); //Jump to the end of the else-statement after completing
										   //the then-statement
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	IS->Insert(E);                      //Insert the expression on the list
	P = new PCode(elsebegin, "", "", ""); //Create a label expression that begins the else-statement
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	IS->Insert(E);
	IS->Append(else_statement);         //Append the else-statement
	P = new PCode(elseend, "", "", "");
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	IS->Insert(E);           //Insert the label at the end of the else-statement
	return IS;
}
//-------------------------------------------------------------------------
//Function statement implements the rule
//statement -> WHILE expression DO statement
//    whilebegin:
//    expression
//    fjp "whileend"
//    body_statement
//    ujp "whilebegin"
//    whileend:
//-------------------------------------------------------------------------
List<Exp*>* Semantics::statement(Exp* expression, List<Exp*>* body_statement) {
	PCode* P;
	Exp* E;
	string whilebegin = Label::instance()->New();      //Create whilebegin label
	string whileend = Label::instance()->New();          //Create whileend label
	P = new PCode(whilebegin, "", "", "");
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	List<Exp*>* WS = new List<Exp*>;
	WS->Insert(E);                      //Insert whilebegin label
	P = new PCode("", "fjp", "", whileend);
	E = new Exp(expression, 0, SymbolTable::instance()->TVoid(), P);
	WS->Insert(E);                 //Insert while-test expression and false-jump
	WS->Append(body_statement);         //Append the while-body-statement
	P = new PCode("", "ujp", "", whilebegin);
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	WS->Insert(E);                     //Insert unconditional jump to while-test
	P = new PCode(whileend, "", "", "");
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	WS->Insert(E);                      //Insert whileend label
	return WS;
}
//--------------------------------------------------------------------

