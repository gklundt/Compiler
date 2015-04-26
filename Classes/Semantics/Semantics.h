// #include "../Semantics.h"
#include <string>

//#ifndef LINECOL_H_
//#define LINECOL_H_
//#endif

#ifndef SEMANTICS_H_
#define SEMANTICS_H_

#include "Exp.h"
#include "Height.h"
#include "../SymbolTable/SymbolTable.h"
#include "../SymbolTable/Symbols/ProgramSymbol.h"
#include "../SymbolTable/Symbols/ProcedureSymbol.h"
#include "../SymbolTable/Symbols/SubprogramSymbol.h"
#include "../SymbolTable/Symbols/FunctionSymbol.h"
#include "../List.h"
#include "../Types/Typ.h"
#include "../Types/NonScalarTypes/Array.h"

using namespace std;

extern unsigned line;
extern unsigned col;

class Semantics {
public:
	Semantics();
	virtual ~Semantics();

	SymbolTable ST;
	ofstream pfs;
	ofstream tfs;

	Label L;

	// Semantic Functions
	void yyerror(string m);

	void variable_declarations(List<string>* IL, Typ* T);

	Exp* UserSubprogram(SubprogramSymbol* S, List<Exp*>* e);

	Typ* type(Typ* T);
	Array* type(string lo, string hi, Typ* T);

	Exp* term_2(Exp* term, Exp* factor);
	Exp* term_3(Exp* term, Exp* factor);
	Exp* term_4(Exp* term, Exp* factor);
	Exp* term_5(Exp* term, Exp* factor);
	Exp* term_6(Exp* term, Exp* factor);
	Exp* term(Exp* f);
	Exp* term(Exp* t, string* op, Exp* f);

	List<VariableSymbol*>* subprogram_parameters(void);
	List<VariableSymbol*>* subprogram_parameters(List<VariableSymbol*>* V);

	Subprogram* ParameterList(List<VariableSymbol*>* VL, Typ* RT);
	void InsertVariables(List<VariableSymbol*>* VL);
	void subprogram_head(string id, List<VariableSymbol*>* VL, Typ* RT);
	void subprogram_head(string id, List<VariableSymbol*>* VL);

	Exp* CoerceLeftExpressionToReal(Exp* LE, Exp* RE);
	Exp* CoerceRightExpressionToReal(Exp* LE, Exp* RE);
	List<Exp*>* Compound_statement(List<Exp*>* os);

	Exp* expression(Exp* simple_expression);
	Exp* expression(Exp* LE, Exp* RE, string relop);
	Exp* expression(Exp* left_simple_expression, string* relop,
			Exp* right_simple_expression);

	List<Exp*>* expression_list(Exp* expression);
	List<Exp*>* expression_list(List<Exp*>* expression_list, Exp* expression);

	Exp* factor_1(string* id);
	Exp* factor_1_constant(ConstantSymbol* S);
	Exp* factor_1_variable(VariableSymbol* S);
	Exp* factor_1_function(FunctionSymbol* S);
	Exp* factor_2(string* id, Exp* e);
	Exp* UserFunction(FunctionSymbol* S, List<Exp*>* e);
	Exp* StandardFunction(StandardFunctionSymbol* S, List<Exp*>* e);
	Exp* factor_3(string* id, List<Exp*>* e);
	Exp* factor_4(Exp* E);
	Exp* factor_5(Exp* factor);
	Exp* factor_6(string* intlit);
	Exp* factor_7(string* realit);
	Exp* factor_8(string* chrlit);

	Exp* variable_symbol(VariableSymbol* V);
	Exp* function_symbol(FunctionSymbol* F);
	Exp* variable(string* id);
	Exp* variable(string* id, Exp* e);

	List<string>* identifier_list(string* i);
	List<string>* identifier_list(List<string>* L, string* i);

	List<Exp*>* Optional_statements(void);
	List<Exp*>* Optional_statements(List<Exp*>* sl);

	List<VariableSymbol*>* parameter_list(List<string>* IL, Typ* T);
	List<VariableSymbol*>* parameter_list(List<VariableSymbol*>* VL,
			List<string>* IL, Typ* T);

	Exp* StandardProcedure(StandardProcedureSymbol* S);
	Exp* procedure_statement(string* id);
	Exp* StandardProcedure(StandardProcedureSymbol* S, List<Exp*>* e);
	Exp* procedure_statement(string* id, List<Exp*>* EL);

	void program_head(string id);
	void program(void);

	Exp* simple_expression(Exp* term);
	Exp* simple_expression(string* sign, Exp* term);
	Exp* add(Exp* l, Exp* r);
	Exp* subtract(Exp* l, Exp* r);
	Exp* disjunction(Exp* l, Exp* r);
	Exp* simple_expression(Exp* simpleexpression, string* addop, Exp* term);

	Typ* standard_type(string id);

	List<Exp*>* Statement_list(List<Exp*>* s);
	List<Exp*>* Statement_list(List<Exp*>* sl, List<Exp*>* s);

	List<Exp*>* statement(Exp* variable, Exp* expression);
	List<Exp*>* statement(Exp* procedure_statement);
	List<Exp*>* statement(List<Exp*>* compound_statement);
	List<Exp*>* statement(Exp* expression, List<Exp*>* then_statement,
			List<Exp*>* else_statement);
	List<Exp*>* statement(Exp* expression, List<Exp*>* body_statement);

	void subprogram_declaration(void);

	List<Exp*>* program_body(List<Exp*>* compound_statement);

	List<Exp*>* subprogram_epilog(SubprogramSymbol* S,
			List<Exp*>* compound_statement);

	List<Exp*>* subprogram_prolog(SubprogramSymbol* S);
}
;

#endif /* SEM_H_ */
