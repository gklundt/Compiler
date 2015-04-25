%{
//-----------------------------------------------------------------------------
// Author 1:	Mrs. Debra Hogue
// Student ID:	*20343220
// E-Mail:		dhogue1@uco.edu
// Author 2: 	Mr. Gordon Klundt
// Student ID:	*20336928
// E-Mail:		gklundt@uco.edu
// Author 3:	Mr. William McLain
// Student ID:	*10066002
// E-Mail:		wmclain@uco.edu
// Author 4: 	Mr. Noah Sefcik
// Student ID:	*20309262
// E-Mail:		nsefcik@uco.edu
// Course:		CMSC 4173 - Translator Design
// CRN:			27419 Spring 2015
// Project:		p09
// Due:			April 17, 2015
// Account:		tt097
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/* Parser for pascal subset grammar */
/* Include C++ libraries for string manipulation and writing to debug files */
#include <string>                          
#include <fstream>
#include <iostream>
#include <cstring>                          
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

#include "List.h"
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "Namespace.h"
#include "Locality.h"
#include "LocalityStack.h"
#include "SymbolTable.h"

#include "program.h"
#include "program_head.h"
#include "subprogram_head.h"
#include "subprogram_declaration.h"
#include "standard_type.h"
#include "subprogram_parameters.h"
#include "variable_declarations.h"
#include "type.h"
#include "parameter_list.h"
#include "identifier_list.h"
#include "factor.h"
#include "term.h"
#include "simple_expression.h"
#include "expression.h"
#include "expression_list.h"
#include "procedure_statement.h"
#include "variable.h"
#include "statement.h"
#include "statement_list.h"
#include "optional_statements.h"
#include "compound_statement.h"

#include "String.h"
#include "PCode.h"
#include "Exp.h"

ofstream pfs;
ofstream tfs;

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;
extern unsigned line;
extern unsigned col;

SymbolTable ST;
%}

%union {
	string * token;
	List<string> *strlist;
	Typ* typ;
	List<VariableSymbol*>* varlist;
	Exp* exp;
	List<Exp*>* explist;
}

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
	{tfs << endl << "#001 program --> program_head program_declarations program_body"; 
	 program() ;}
	;
program_head: PROGRAM ID program_parameters SEMICOLON 
	{tfs << endl << "#002 program_head --> PROGRAM ID(" << (*$2) 
		 << ") program_parameters ;"; 
	 program_head(*$2);}
	;
program_declarations: variable_declarations subprogram_declarations 
	{tfs << endl << "#003 program_declarations --> variable_declarations subprogram_declarations";}
	;
program_body: compound_statement PERIOD 
	{tfs << endl << "#004 program_body --> compound_statement .";}
	;
program_parameters: /*EMPTY*/
	{tfs << endl << "#005 program_parameters --> empty";}
	| LPAREN program_parameter_list RPAREN
	{tfs << endl << "#006 program_parameters --> ( program_parameter_list )";}
	;
program_parameter_list: identifier_list
	{tfs << endl << "#007 program_parameter_list --> identifier_list(" 
		 << (*$1).Print() << ")";}
	;
identifier_list: ID
	{tfs << endl << "#008 identifier_list --> ID(" << (*$1) << ")"; 
	 $$=identifier_list($1);}
	| identifier_list COMMA ID
	{tfs << endl << "#009 identifier_list --> identifier_list() , ID(" << (*$3) 
		 << ")"; 
	 $$=identifier_list($1,$3);}
	;
variable_declarations: /*EMPTY*/
	{tfs << endl << "#010 variable_declarations --> empty";}
	| variable_declarations VAR identifier_list COLON type SEMICOLON
	{tfs << endl << "#011 variable_declarations --> variable_declarations VAR identifier_list(" << (*$3).Print() << ") : type ; "; 
	 variable_declarations($3,$5);}
	;
type: standard_type
	{tfs << endl << "#012 type --> standard_type ";$$=type($1);}
	| ARRAY LBRACKET INTLIT RANGE INTLIT RBRACKET OF standard_type 
	{tfs << endl << "#013 type --> ARRAY [ INTLIT(" << (*$3) << ") .. INTLIT(" 
		 << (*$5) << ") ] OF standard_type"; 
	 $$=type(*$3,*$5,$8);}
	;
standard_type: ID 
	{tfs << endl << "#014 standard_type --> ID(" << (*$1) << ")"; 
	 $$=standard_type((*$1));}
	;
subprogram_declarations: /*EMPTY*/ 
	{tfs << endl << "#015 subprogram_declarations --> empty";}
	| subprogram_declarations subprogram_declaration SEMICOLON
	{tfs << endl << "#016 subprogram_declarations --> subprogram_declarations subprogram_declaration ; ";}
	;
subprogram_declaration: subprogram_head variable_declarations compound_statement 
	{tfs << endl << "#017 subprogram_declaration --> subprogram_head variable_declarations compound_statement ";
	 subprogram_declaration();}
	;
subprogram_head: FUNCTION ID sub_program_parameters COLON standard_type SEMICOLON 
	{tfs << endl << "#018 subprogram_head --> FUNCTION ID(" << (*$2) 
		 << ") sub_program_parameters : standard_type ; ";
	 subprogram_head(*$2,$3,$5);}
	| PROCEDURE ID sub_program_parameters SEMICOLON 
	{tfs << endl << "#019 subprogram_head --> PROCEDURE ID(" << (*$2) 
		 << ") sub_program_parameters ; ";
	 subprogram_head(*$2,$3);}
	;
sub_program_parameters: /*EMPTY*/ 
	{tfs << endl << "#020 sub_program_parameters --> empty "; 
	 $$=subprogram_parameters();}
	| LPAREN parameter_list RPAREN 
	{tfs << endl << "#021 sub_program_parameters --> ( parameter_list ) "; 
	 $$=subprogram_parameters($2);}
	;
parameter_list: identifier_list COLON type 
	{tfs << endl << "#022 parameter_list --> identifier_list(" << (*$1).Print() 
		 << ") : type "; 
	 $$=parameter_list($1,$3);}
	| parameter_list SEMICOLON identifier_list COLON type 
	{tfs << endl << "#023 parameter_list --> parameter_list ; identifier_list(" 
		 << (*$3).Print() << ") : type "; 
	 $$=parameter_list($1,$3,$5);}
	;
compound_statement: BEGAN optional_statements END 
	{tfs << endl << "#024 compound_statement --> BEGIN optional_statements END ";
	$$=Compound_statement($2);}
	;
optional_statements: /*EMPTY*/ 
	{tfs << endl << "#025 optional_statements --> empty ";
	$$=Optional_statements();}
	| statement_list 
	{tfs << endl << "#026 optional_statements --> statement_list ";
	$$=Optional_statements($1);}
	;
statement_list: statement 
	{tfs << endl << "#027 statement_list --> statement ";
	$$=Statement_list($1);}
	| statement_list SEMICOLON statement 
	{tfs << endl << "#028 statement_list --> statement_list ; statement ";
	$$=Statement_list($1,$3);}
	;
statement: variable ASSIGN expression 
	{tfs << endl << "#029 statement --> variable := expression ";
	$$=statement($1,$3);}
	| procedure_statement 
	{tfs << endl << "#030 statement --> procedure_statement ";
	$$=statement($1);}
	| compound_statement 
	{tfs << endl << "#031 statement --> compound_statement ";
	$$=statement($1);}
	| IF expression THEN statement ELSE statement 
	{tfs << endl << "#032 statement --> IF expression THEN statement ELSE statement ";
	$$=statement($2,$4,$6);}
	| WHILE expression DO statement 
	{tfs << endl << "#033 statement --> WHILE expression DO statement ";
	$$=statement($2,$4);}
	;
variable: ID 
	{tfs << endl << "#034 variable --> ID(" << (*$1) << ")";
	 $$=variable($1);}
	| ID LBRACKET expression RBRACKET 
	{tfs << endl << "#035 variable --> ID(" << (*$1) << ") [ expression ] ";
	 $$=variable($1,$3);}
	;
procedure_statement: ID
	{tfs << endl << "#036 procedure_statement --> ID(" << (*$1) << ") ";
	 $$=procedure_statement($1);}
	| ID LPAREN expression_list RPAREN 
	{tfs << endl << "#037 procedure_statement --> ID(" << (*$1) 
		 << ") ( expression_list ) ";
	 $$=procedure_statement($1,$3);}
	;
expression_list: expression 
	{tfs << endl << "#038 expression_list --> expression ";
	 $$=expression_list($1);}
	| expression_list COMMA expression 
	{tfs << endl << "#039 expression_list --> expression_list , expression ";
	 $$=expression_list($1,$3);}
	;
expression: simple_expression 
	{tfs << endl << "#040 expression --> simple_expression ";
	 $$=expression($1);}
	| simple_expression relop simple_expression 
	{tfs << endl << "#041 expression --> simple_expression relop simple_expression ";
	 $$=expression($1,$2,$3);}
	;
relop: EQU 
	{tfs << endl << "#042 relop --> = ";}
	| NEQ 
	{tfs << endl << "#043 relop --> <> ";}
	| LES 
	{tfs << endl << "#044 relop --> < ";}
	| LEQ 
	{tfs << endl << "#045 relop --> <= ";}
	| GRT 
	{tfs << endl << "#046 relop --> > ";}
	| GEQ 
	{tfs << endl << "#047 relop --> >= ";}
	; //----------------------------------------------------------------------------------------
simple_expression: term 
	{tfs << endl << "#048 simple_expression --> term ";
	 $$=simple_expression($1);}
	| sign term 
	{tfs << endl << "#049 simple_expression --> sign term ";
	 $$=simple_expression($1,$2);}
	| simple_expression addop term 
	{tfs << endl << "#050 simple_expression --> simple_expression addop term ";
	 $$=simple_expression($1,$2,$3);}
	;
sign: PLUS 
	{tfs << endl << "#051 sign --> + ";}
	| MINUS 
	{tfs << endl << "#052 sign --> - ";}
	;
addop: PLUS 
	{tfs << endl << "#053 addop --> + ";}
	| MINUS 
	{tfs << endl << "#054 addop --> - ";}
	| OR 
	{tfs << endl << "#055 addop --> OR ";}
	;
term: factor 
	{tfs << endl << "#056 term --> factor ";
	 $$=term($1);}
	| term mulop factor 
	{tfs << endl << "#057 term --> term mulop factor ";
	 $$=term($1,$2,$3);}
	;
mulop: STAR 
	{tfs << endl << "#058 mulop --> * ";}
	| SLASH 
	{tfs << endl << "#059 mulop --> / ";}
	| DIV 
	{tfs << endl << "#060 mulop --> DIV ";}
	| MOD 
	{tfs << endl << "#061 mulop --> MOD ";}
	| AND 
	{tfs << endl << "#062 mulop --> AND ";}
	; 
factor: ID 
	{tfs << endl << "#063 factor --> ID(" << (*$1) << ") "; 
	 $$=factor_1($1);}
	| ID LBRACKET expression RBRACKET 
	{tfs << endl << "#064 factor --> ID(" << (*$1) << ") [ expression ] "; 
	 $$=factor_2($1,$3);}
	| ID LPAREN expression_list RPAREN 
	{tfs << endl << "#065 factor --> ID(" << (*$1) << ") ( expression_list ) "; 
	 $$=factor_3($1,$3);}
	| LPAREN expression RPAREN 
	{tfs << endl << "#066 factor --> ( expression ) "; 
	 $$=factor_4($2);}
	| NOT factor 
	{tfs << endl << "#067 factor --> NOT factor "; 
	 $$=factor_5($2);}
	| INTLIT 
	{tfs << endl << "#068 factor --> INTLIT(" << (*$1) << ") "; 
	 $$=factor_6($1);}
	| REALIT 
	{tfs << endl << "#069 factor --> REALIT(" << (*$1) << ") "; 
	 $$=factor_7($1);}
	| CHRLIT 
	{tfs << endl << "#070 factor --> CHRLIT(" << (*$1) << ") "; 
	 $$=factor_8($1);}
	;
%%

//--------------------------------------------------------------------
//FileException
//--------------------------------------------------------------------
struct FileException {
   FileException(const char* fn)
   {   cout << endl;
       cout << "File " << fn << " could not be opened.";
       cout << endl;
   }
};


/* Main is included here and becomes the main entry point for the application */
/* This seems more simple */
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

	tfs.open(ofn1); if (!tfs) throw FileException(ofn1);
	pfs.open(ofn2); if (!pfs) throw FileException(ofn2);

	/* This section is the parser */
	/* Main is in the parser because the parser is the higher level program */
	/* Main can be in the lexer only to test lex replace the yyparse loop with the yylex() call */
	/* This was done in lex, but yacc calls yyparse which gets the token from lex */
	do {
		yyparse();
	} while (!feof(yyin));

	fclose(i); 
	tfs << endl;
	pfs << endl;
	tfs.close();
	pfs.close();

	/* Made it to the end, good job */
	//printf("Line: %u Column: %u\n",line, col);
	printf("Done. Files .pcd and .trc are created. \n");
	return 0;
}

void yyerror(string s) {
	cout << s << endl;
}