%{

/* Parser for pascal subset grammar */
/* Include C++ libraries for string manipulation and writing to debug files */
#include <string>                          
#include <fstream>
#include <iostream>
#include <cstring>                          
#include <cstdlib>
#include <iomanip>
#include <string>

#include "Classes/Semantics/Semantics.h"
#include "Classes/Semantics/Semantics.h"

using namespace std;

extern int yylex();
extern void yyerror(string s);
extern FILE *yyin;
extern FILE *yyout;

/* declared in paslex.l */
extern unsigned line;
extern unsigned col;

%}

%union {
	SubprogramSymbol* subprog;
	string * token;
	List<string> *strlist;
	Typ* typ;
	List<VariableSymbol*>* varlist;
	Exp* exp;
	List<Exp*>* explist;
}

%type <subprog> program_head
%type <subprog> subprogram_head
%type <varlist> parameter_list
%type <varlist> sub_program_parameters
%type <typ>     type
%type <typ>     standard_type
%type <strlist> identifier_list

%type  <exp>     factor
%type  <exp>     term
%type  <exp>     simple_expression
%type  <exp>     expression
%type  <exp>     procedure_statement
%type  <exp>     variable

%type  <explist> program_body
%type  <explist> expression_list
%type  <explist> statement 
%type  <explist> compound_statement 
%type  <explist> statement_list 
%type  <explist> optional_statements 

%type <token>	relop
%type <token>	mulop
%type <token>	addop
%type <token>	sign

%token <token> 	PLUS
%token <token> 	MINUS
%token <token> 	STAR
%token <token> 	SLASH
%token <token> 	ASSIGN
%token <token> 	PERIOD
%token <token> 	COMMA
%token <token> 	SEMICOLON
%token <token> 	COLON
%token <token> 	EQU
%token <token> 	NEQ
%token <token> 	LES
%token <token> 	LEQ
%token <token> 	GRT
%token <token> 	GEQ
%token <token> 	LPAREN
%token <token> 	RPAREN
%token <token> 	LBRACKET
%token <token> 	RBRACKET
%token <token> 	RANGE
%token <token> 	AND
%token <token> 	ARRAY
%token <token> 	BEGAN
%token <token> 	DIV
%token <token> 	DO
%token <token> 	ELSE
%token <token> 	END
%token <token> 	FUNCTION
%token <token> 	IF
%token <token> 	MOD
%token <token> 	NOT
%token <token> 	OF
%token <token> 	OR
%token <token> 	PROCEDURE
%token <token> 	PROGRAM
%token <token> 	THEN
%token <token> 	TO
%token <token> 	TYPE
%token <token> 	VAR
%token <token> 	WHILE
%token <token> 	ID
%token <token> 	INTLIT
%token <token> 	REALIT
%token <token> 	CHRLIT
%token <token> 	COMMENT
%token <token> 	NOTOKEN
%token <token> 	ERROR

%%

program: program_head program_declarations program_body 
	{Semantics::instance()->tfs << endl << "#001 program --> program_head program_declarations program_body"; 
	 Semantics::instance()->program($1,$3) ;}
	;
program_head: PROGRAM ID program_parameters SEMICOLON 
	{Semantics::instance()->tfs << endl << "#002 program_head --> PROGRAM ID(" << (*$2) << ") program_parameters ;"; 
	 Semantics::instance()->program_head(*$2);}
	;
program_declarations: variable_declarations subprogram_declarations 
	{Semantics::instance()->tfs << endl << "#003 program_declarations --> variable_declarations subprogram_declarations";}
	;
program_body: compound_statement PERIOD 
	{Semantics::instance()->tfs << endl << "#004 program_body --> compound_statement .";
	$$=Semantics::instance()->program_body($1);}
	;
program_parameters: /*EMPTY*/
	{Semantics::instance()->tfs << endl << "#005 program_parameters --> empty";}
	| LPAREN program_parameter_list RPAREN
	{Semantics::instance()->tfs << endl << "#006 program_parameters --> ( program_parameter_list )";}
	;
program_parameter_list: identifier_list
	{Semantics::instance()->tfs << endl << "#007 program_parameter_list --> identifier_list(" << (*$1).Print() << ")";}
	;
identifier_list: ID
	{Semantics::instance()->tfs << endl << "#008 identifier_list --> ID(" << (*$1) << ")"; 
	 $$=Semantics::instance()->identifier_list($1);}
	| identifier_list COMMA ID
	{Semantics::instance()->tfs << endl << "#009 identifier_list --> identifier_list() , ID(" << (*$3) << ")"; 
	 $$=Semantics::instance()->identifier_list($1,$3);}
	;
variable_declarations: /*EMPTY*/
	{Semantics::instance()->tfs << endl << "#010 variable_declarations --> empty";}
	| variable_declarations VAR identifier_list COLON type SEMICOLON
	{Semantics::instance()->tfs << endl << "#011 variable_declarations --> variable_declarations VAR identifier_list(" << (*$3).Print() << ") : type ; "; 
	 Semantics::instance()->variable_declarations($3,$5);}
	;
type: standard_type
	{Semantics::instance()->tfs << endl << "#012 type --> standard_type ";
	 $$=Semantics::instance()->type($1);}
	| ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type 
	{Semantics::instance()->tfs << endl << "#013 type --> ARRAY [ INTLIT(" << (*$3) << ") .. INTLIT(" << (*$5) << ") ] OF standard_type"; 
	 $$=Semantics::instance()->type(*$3,*$5,$8);}
	;
standard_type: ID 
	{Semantics::instance()->tfs << endl << "#014 standard_type --> ID(" << (*$1) << ")"; 
	 $$=Semantics::instance()->standard_type(*$1);}
	;
subprogram_declarations: /*EMPTY*/ 
	{Semantics::instance()->tfs << endl << "#015 subprogram_declarations --> empty";}
	| subprogram_declarations subprogram_declaration SEMICOLON
	{Semantics::instance()->tfs << endl << "#016 subprogram_declarations --> subprogram_declarations subprogram_declaration ; ";}
	;
subprogram_declaration: subprogram_head variable_declarations compound_statement 
	{Semantics::instance()->tfs << endl << "#017 subprogram_declaration --> subprogram_head variable_declarations compound_statement ";
	 Semantics::instance()->subprogram_declaration($1,$3);}
	;
subprogram_head: FUNCTION ID sub_program_parameters COLON standard_type SEMICOLON 
	{Semantics::instance()->tfs << endl << "#018 subprogram_head --> FUNCTION ID(" << (*$2) << ") sub_program_parameters : standard_type ; ";
	 Semantics::instance()->subprogram_head(*$2,$3,$5);}
	| PROCEDURE ID sub_program_parameters SEMICOLON 
	{Semantics::instance()->tfs << endl << "#019 subprogram_head --> PROCEDURE ID(" << (*$2) << ") sub_program_parameters ; ";
	 Semantics::instance()->subprogram_head(*$2,$3);}
	;
sub_program_parameters: /*EMPTY*/ 
	{Semantics::instance()->tfs << endl << "#020 sub_program_parameters --> empty "; 
	 $$=Semantics::instance()->subprogram_parameters();}
	| LPAREN parameter_list RPAREN 
	{Semantics::instance()->tfs << endl << "#021 sub_program_parameters --> ( parameter_list ) "; 
	 $$=Semantics::instance()->subprogram_parameters($2);}
	;
parameter_list: identifier_list COLON type 
	{Semantics::instance()->tfs << endl << "#022 parameter_list --> identifier_list(" << (*$1).Print() << ") : type "; 
	 $$=Semantics::instance()->parameter_list($1,$3);}
	| parameter_list SEMICOLON identifier_list COLON type 
	{Semantics::instance()->tfs << endl << "#023 parameter_list --> parameter_list ; identifier_list(" << (*$3).Print() << ") : type "; 
	 $$=Semantics::instance()->parameter_list($1,$3,$5);}
	;
compound_statement: BEGAN optional_statements END 
	{Semantics::instance()->tfs << endl << "#024 compound_statement --> BEGIN optional_statements END ";
	$$=Semantics::instance()->Compound_statement($2);}
	;
optional_statements: /*EMPTY*/ 
	{Semantics::instance()->tfs << endl << "#025 optional_statements --> empty ";
	$$=Semantics::instance()->Optional_statements();}
	| statement_list 
	{Semantics::instance()->tfs << endl << "#026 optional_statements --> statement_list ";
	$$=Semantics::instance()->Optional_statements($1);}
	;
statement_list: statement 
	{Semantics::instance()->tfs << endl << "#027 statement_list --> statement ";
	$$=Semantics::instance()->Statement_list($1);}
	| statement_list SEMICOLON statement 
	{Semantics::instance()->tfs << endl << "#028 statement_list --> statement_list ; statement ";
	$$=Semantics::instance()->Statement_list($1,$3);}
	;
statement: variable ASSIGN expression 
	{Semantics::instance()->tfs << endl << "#029 statement --> variable := expression ";
	$$=Semantics::instance()->statement($1,$3);}
	| procedure_statement 
	{Semantics::instance()->tfs << endl << "#030 statement --> procedure_statement ";
	$$=Semantics::instance()->statement($1);}
	| compound_statement 
	{Semantics::instance()->tfs << endl << "#031 statement --> compound_statement ";
	$$=Semantics::instance()->statement($1);}
	| IF expression THEN statement ELSE statement 
	{Semantics::instance()->tfs << endl << "#032 statement --> IF expression THEN statement ELSE statement ";
	$$=Semantics::instance()->statement($2,$4,$6);}
	| WHILE expression DO statement 
	{Semantics::instance()->tfs << endl << "#033 statement --> WHILE expression DO statement ";
	$$=Semantics::instance()->statement($2,$4);}
	;
variable: ID 
	{Semantics::instance()->tfs << endl << "#034 variable --> ID(" << (*$1) << ")";
	 $$=Semantics::instance()->variable($1);}
	| ID LBRACKET expression RBRACKET 
	{Semantics::instance()->tfs << endl << "#035 variable --> ID(" << (*$1) << ") [ expression ] ";
	 $$=Semantics::instance()->variable($1,$3);}
	;
procedure_statement: ID
	{Semantics::instance()->tfs << endl << "#036 procedure_statement --> ID(" << (*$1) << ") ";
	 $$=Semantics::instance()->procedure_statement($1);}
	| ID LPAREN expression_list RPAREN 
	{Semantics::instance()->tfs << endl << "#037 procedure_statement --> ID(" << (*$1) << ") ( expression_list ) ";
	 $$=Semantics::instance()->procedure_statement($1,$3);}
	;
expression_list: expression 
	{Semantics::instance()->tfs << endl << "#038 expression_list --> expression ";
	 $$=Semantics::instance()->expression_list($1);}
	| expression_list COMMA expression 
	{Semantics::instance()->tfs << endl << "#039 expression_list --> expression_list , expression ";
	 $$=Semantics::instance()->expression_list($1,$3);}
	;
expression: simple_expression 
	{Semantics::instance()->tfs << endl << "#040 expression --> simple_expression "; 
	 $$=Semantics::instance()->expression($1);}
	| simple_expression relop simple_expression 
	{Semantics::instance()->tfs << endl << "#041 expression --> simple_expression relop simple_expression ";
	 $$=Semantics::instance()->expression($1,$2,$3);}
	;
relop: EQU 
	{Semantics::instance()->tfs << endl << "#042 relop --> = ";}
	| NEQ 
	{Semantics::instance()->tfs << endl << "#043 relop --> <> ";}
	| LES 
	{Semantics::instance()->tfs << endl << "#044 relop --> < ";}
	| LEQ 
	{Semantics::instance()->tfs << endl << "#045 relop --> <= ";}
	| GRT 
	{Semantics::instance()->tfs << endl << "#046 relop --> > ";}
	| GEQ 
	{Semantics::instance()->tfs << endl << "#047 relop --> >= ";}
	; 
simple_expression: term 
	{Semantics::instance()->tfs << endl << "#048 simple_expression --> term ";
	 $$=Semantics::instance()->simple_expression($1);}
	| sign term 
	{Semantics::instance()->tfs << endl << "#049 simple_expression --> sign term ";
	 $$=Semantics::instance()->simple_expression($1,$2);}
	| simple_expression addop term 
	{Semantics::instance()->tfs << endl << "#050 simple_expression --> simple_expression addop term ";
	 $$=Semantics::instance()->simple_expression($1,$2,$3);}
	;
sign: PLUS 
	{Semantics::instance()->tfs << endl << "#051 sign --> + ";}
	| MINUS 
	{Semantics::instance()->tfs << endl << "#052 sign --> - ";}
	;
addop: PLUS 
	{Semantics::instance()->tfs << endl << "#053 addop --> + ";}
	| MINUS 
	{Semantics::instance()->tfs << endl << "#054 addop --> - ";}
	| OR 
	{Semantics::instance()->tfs << endl << "#055 addop --> OR ";}
	;
term: factor 
	{Semantics::instance()->tfs << endl << "#056 term --> factor ";
	 $$=Semantics::instance()->term($1);}
	| term mulop factor 
	{Semantics::instance()->tfs << endl << "#057 term --> term mulop factor ";
	 $$=Semantics::instance()->term($1,$2,$3);}
	;
mulop: STAR 
	{Semantics::instance()->tfs << endl << "#058 mulop --> * ";}
	| SLASH 
	{Semantics::instance()->tfs << endl << "#059 mulop --> / ";}
	| DIV 
	{Semantics::instance()->tfs << endl << "#060 mulop --> DIV ";}
	| MOD 
	{Semantics::instance()->tfs << endl << "#061 mulop --> MOD ";}
	| AND 
	{Semantics::instance()->tfs << endl << "#062 mulop --> AND ";}
	; 
factor: ID 
	{Semantics::instance()->tfs << endl << "#063 factor --> ID(" << (*$1) << ") "; 
	 $$=Semantics::instance()->factor_1($1);}
	| ID LBRACKET expression RBRACKET 
	{Semantics::instance()->tfs << endl << "#064 factor --> ID(" << (*$1) << ") [ expression ] "; 
	 $$=Semantics::instance()->factor_2($1,$3);}
	| ID LPAREN expression_list RPAREN 
	{Semantics::instance()->tfs << endl << "#065 factor --> ID(" << (*$1) << ") ( expression_list ) "; 
	 $$=Semantics::instance()->factor_3($1,$3);}
	| LPAREN expression RPAREN 
	{Semantics::instance()->tfs << endl << "#066 factor --> ( expression ) "; 
	 $$=Semantics::instance()->factor_4($2);}
	| NOT factor 
	{Semantics::instance()->tfs << endl << "#067 factor --> NOT factor "; 
	 $$=Semantics::instance()->factor_5($2);}
	| INTLIT 
	{Semantics::instance()->tfs << endl << "#068 factor --> INTLIT(" << (*$1) << ") "; 
	 $$=Semantics::instance()->factor_6($1);}
	| REALIT 
	{Semantics::instance()->tfs << endl << "#069 factor --> REALIT(" << (*$1) << ") "; 
	 $$=Semantics::instance()->factor_7($1);}
	| CHRLIT 
	{Semantics::instance()->tfs << endl << "#070 factor --> CHRLIT(" << (*$1) << ") "; 
	 $$=Semantics::instance()->factor_8($1);}
	;
%%

struct FileException {
   FileException(const char* fn)
   {   cout << endl;
       cout << "File " << fn << " could not be opened.";
       cout << endl;
   }
};


/* Main is included here and becomes the main entry point for the application */
/* This seems more simple */

Label *Label::s_instance = 0;
SymbolTable *SymbolTable::s_instance = 0;
Semantics *Semantics::s_instance = 0;

int main (int argc,char *argv[]) {

	char ifn[255];
	char ofn1[255];
	char ofn2[255];

	unsigned pos;

	switch (argc) {
		case 1:
			cout << "Enter the input file name: ";
			cin >> ifn;
			break;
		case 2:
			strcpy(ifn, argv[1]);
			break;
		default: 
			exit(EXIT_FAILURE);
	}

	string str = string(ifn);
	str.replace(str.length()-3,3,"trc");
	strcpy(ofn1,str.c_str());
	
	str.replace(str.length()-3,3,"pcd");
	strcpy(ofn2,str.c_str());

	FILE* i = fopen(ifn, "r");
	yyin = i;

	Semantics::instance()->tfs.open(ofn1); if (!Semantics::instance()->tfs) throw FileException(ofn1);
	Semantics::instance()->pfs.open(ofn2); if (!Semantics::instance()->pfs) throw FileException(ofn2);

	/* This section is the parser */
	/* Main is in the parser because the parser is the higher level program */
	/* Main can be in the lexer only to test lex replace the yyparse loop with the yylex() call */
	/* This was done in lex, but yacc calls yyparse which gets the token from lex */
	do {
		yyparse();
	} while (!feof(yyin));

	fclose(i); 
	Semantics::instance()->tfs << endl;
	Semantics::instance()->pfs << endl;
	Semantics::instance()->tfs.close();
	Semantics::instance()->pfs.close();

	/* Made it to the end, good job */
	//printf("Line: %u Column: %u\n",line, col);
	printf("\nDone. Files .pcd and .trc are created. \n");
	return 0;
}
void yyerror(string s) {
	cout << s << endl;
}
