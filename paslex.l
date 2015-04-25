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
// Project:		p08
// Due:			March ##, 2015
// Account:		tt098
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
	
/* Subset Pascal Scanner */

/* Include standard libraries for string and text manipulation */
#include <string>
#include <locale>

/* include the token defs from y.tab.h */
#include "List.h"
#include "pastkn.h" 	/* token codes from the parser */

using namespace std;

unsigned line=1, col=1;
int tkn_handler(int,string);

extern ofstream pfs;
extern ofstream tfs;

%}

PLUS "+"
MINUS "-"
STAR "*"
SLASH "/"
ASSIGN ":="
PERIOD "."
COMMA ","
SEMICOLON ";" 
COLON ":"
EQU "="
NEQ "<>"
LES "<"
LEQ "<="
GRT ">"
GEQ ">="
LPAREN "("
RPAREN ")"
LBRACKET "["
RBRACKET "]"
RANGE ".."
AND (?i:and)
ARRAY (?i:array)
BEGAN (?i:begin)
DIV (?i:div)
DO (?i:do)
ELSE (?i:else)
END (?i:end)
FUNCTION (?i:function)
IF (?i:if)
MOD (?i:mod)
NOT (?i:not)
OF (?i:of)
OR (?i:or)
PROCEDURE (?i:procedure)
PROGRAM (?i:program)
THEN (?i:then)
TO (?i:to)
TYPE (?i:type)
VAR (?i:var)
WHILE (?i:while)
CHRLITa "''''"|"'"."'"
CHRLIT ([']([^']|[']['])*['])
IDold (?i:['](([^'])|([']['].))+['])|(?i:[a-z][a-z|0-9|_]*)|(?i:_[a-z]?[a-z|0-9|_]*)|(?i:[']([^']+).['])
ID [_a-zA-Z][_a-zA-Z0-9]*
INTLIT [0-9]+
REALIT ([0-9]+[Ee][+-]?[0-9]+)|([0-9]+\.[0-9]+([Ee][+-]?[0-9]+)?)

WSAold [ \t]+
WSB [ \t]+

COMMENTA ^[ \t]*"{"
COMMENTB ^[ \t]*"{".*"}"[ \t]*\n
COMMENTC [{].*[}]
COMMENTE [{]
WSC [\n]

%x CBCOMMENT 
%%

{WSB}		{ /* fprintf(yyout,"WSB\n") */; col+=yyleng; /* ignore whitespace */;}
{WSC}		{ /* fprintf(yyout,"WSC\n") */; line++; col=1; /* ignore whitespace */;}
{PLUS}		{ return tkn_handler(PLUS,"PLUS"); }	
{MINUS}		{ return tkn_handler(MINUS,"MINUS"); }	
{STAR}		{ return tkn_handler(STAR,"STAR"); }	
{SLASH}		{ return tkn_handler(SLASH,"SLASH"); }	
{ASSIGN}	{ return tkn_handler(ASSIGN,"ASSIGN"); }	
{PERIOD}	{ return tkn_handler(PERIOD,"PERIOD"); }	
{COMMA}		{ return tkn_handler(COMMA,"COMMA"); }	
{SEMICOLON}	{ return tkn_handler(SEMICOLON,"SEMICOLON"); }	
{COLON}		{ return tkn_handler(COLON,"COLON"); }	
{EQU}		{ return tkn_handler(EQU,"EQU"); }	
{NEQ}		{ return tkn_handler(NEQ,"NEQ"); }	
{LES}		{ return tkn_handler(LES,"LES"); }	
{LEQ}		{ return tkn_handler(LEQ,"LEQ"); }	
{GRT}		{ return tkn_handler(GRT,"GRT"); }	
{GEQ}		{ return tkn_handler(GEQ,"GEQ"); }	
{LPAREN}	{ return tkn_handler(LPAREN,"LPAREN"); }	
{RPAREN}	{ return tkn_handler(RPAREN,"RPAREN"); }	
{LBRACKET}	{ return tkn_handler(LBRACKET,"LBRACKET"); }	
{RBRACKET}	{ return tkn_handler(RBRACKET,"RBRACKET"); }	
{RANGE}		{ return tkn_handler(RANGE,"RANGE"); }
{AND}		{ return tkn_handler(AND,"AND"); }	
{ARRAY}		{ return tkn_handler(ARRAY,"ARRAY"); }	
{BEGAN}		{ return tkn_handler(BEGAN,"BEGIN"); }	
{DIV}		{ return tkn_handler(DIV,"DIV"); }	
{DO}		{ return tkn_handler(DO,"DO"); }	
{ELSE}		{ return tkn_handler(ELSE,"ELSE"); }	
{END}		{ return tkn_handler(END,"END"); }	
{FUNCTION}	{ return tkn_handler(FUNCTION,"FUNCTION"); }	
{IF}		{ return tkn_handler(IF,"IF"); }	
{MOD}		{ return tkn_handler(MOD,"MOD"); }	
{NOT}		{ return tkn_handler(NOT,"NOT"); }	
{OF}		{ return tkn_handler(OF,"OF"); }	
{OR}		{ return tkn_handler(OR,"OR"); }	
{PROCEDURE}	{ return tkn_handler(PROCEDURE,"PROCEDURE"); }	
{PROGRAM}	{ return tkn_handler(PROGRAM,"PROGRAM"); }	
{THEN}		{ return tkn_handler(THEN,"THEN"); }	
{TO}		{ return tkn_handler(TO,"TO"); }	
{TYPE}		{ return tkn_handler(TYPE,"TYPE"); }	
{VAR}		{ return tkn_handler(VAR,"VAR"); }	
{WHILE}		{ return tkn_handler(WHILE,"WHILE"); }	
{ID} 		{ return tkn_handler(ID,"ID"); }
{INTLIT}	{ return tkn_handler(INTLIT,"INTLIT"); }
{REALIT}	{ return tkn_handler(REALIT,"REALIT"); }
{CHRLIT}	{ return tkn_handler(CHRLIT,"CHRLIT"); }

{COMMENTA}	{/* fprintf(yyout,"comment a\n") */; BEGIN CBCOMMENT; /* START EATING COMMENTS */;}
{COMMENTB}	{/* fprintf(yyout,"comment b\n") */; line++; col=1; /* Self Contained Comment */;}

<CBCOMMENT>"}"[ \t]*\n	{/* fprintf(yyout,"curly brace comment 1\n") */; line++; col=1; BEGIN 0;}
<CBCOMMENT>"}"		{/* fprintf(yyout,"curly brace comment 2\n") */; BEGIN 0;}
<CBCOMMENT>\n		{/* fprintf(yyout,"curly brace comment 3\n") */; line++; col=1; /* eat lines */;}
<CBCOMMENT>.\n		{/* fprintf(yyout,"curly brace comment 4\n") */; line++; col=1; /* eat more lines, nom nom */;}

{COMMENTC}	{/* fprintf(yyout,"comment C\n") */; col+=yyleng;}
{COMMENTE}	{/* fprintf(yyout,"comment E\n") */; col+=yyleng; BEGIN CBCOMMENT;}

.		{/* fprintf(yyout,"anything %d\n",yytext[0]) */; /*tkn_handler(ERROR,"ERROR")*/; /*return yytext[0]*/; col++; }

%%

int tkn_handler(int tkn_code, string tkn_name ){

	/* Make yytext lower case */
	std::locale loc;
	for (std::string::size_type i=0; i < strlen(yytext); ++i)
		yytext[i] = std::tolower(yytext[i],loc);
	
	yylval.token=new string(yytext);

	/* Print the token to file */
	//fprintf (yyout, "Token:Code=%d Name=%10s line=%4u col=%4u Spelling=\"%s\"\n", tkn_code, tkn_name.c_str(), line, col, yytext ); 
	//printf (	"Token:Code=%d Name=%10s line=%4u col=%4u Spelling=\"%s\"\n", tkn_code, tkn_name.c_str(), line, col, yytext ); 
	tfs << endl << "Token:Code=" << tkn_code << " Name=" << tkn_name << " line=" << line << " col=" << col << " Spelling=\"" << yytext << "\""; 
	/* Increment the column number*/
	col+=yyleng;

	/* Return token code to the caller (parser yyparse in this case) */
	return tkn_code;
}