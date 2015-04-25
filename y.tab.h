/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PLUS = 258,
     MINUS = 259,
     STAR = 260,
     SLASH = 261,
     ASSIGN = 262,
     PERIOD = 263,
     COMMA = 264,
     SEMICOLON = 265,
     COLON = 266,
     EQU = 267,
     NEQ = 268,
     LES = 269,
     LEQ = 270,
     GRT = 271,
     GEQ = 272,
     LPAREN = 273,
     RPAREN = 274,
     LBRACKET = 275,
     RBRACKET = 276,
     RANGE = 277,
     AND = 278,
     ARRAY = 279,
     BEGAN = 280,
     DIV = 281,
     DO = 282,
     ELSE = 283,
     END = 284,
     FUNCTION = 285,
     IF = 286,
     MOD = 287,
     NOT = 288,
     OF = 289,
     OR = 290,
     PROCEDURE = 291,
     PROGRAM = 292,
     THEN = 293,
     TO = 294,
     TYPE = 295,
     VAR = 296,
     WHILE = 297,
     ID = 298,
     INTLIT = 299,
     REALIT = 300,
     CHRLIT = 301,
     COMMENT = 302,
     NOTOKEN = 303,
     ERROR = 304
   };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define STAR 260
#define SLASH 261
#define ASSIGN 262
#define PERIOD 263
#define COMMA 264
#define SEMICOLON 265
#define COLON 266
#define EQU 267
#define NEQ 268
#define LES 269
#define LEQ 270
#define GRT 271
#define GEQ 272
#define LPAREN 273
#define RPAREN 274
#define LBRACKET 275
#define RBRACKET 276
#define RANGE 277
#define AND 278
#define ARRAY 279
#define BEGAN 280
#define DIV 281
#define DO 282
#define ELSE 283
#define END 284
#define FUNCTION 285
#define IF 286
#define MOD 287
#define NOT 288
#define OF 289
#define OR 290
#define PROCEDURE 291
#define PROGRAM 292
#define THEN 293
#define TO 294
#define TYPE 295
#define VAR 296
#define WHILE 297
#define ID 298
#define INTLIT 299
#define REALIT 300
#define CHRLIT 301
#define COMMENT 302
#define NOTOKEN 303
#define ERROR 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 82 "paspar.y"

	string * token;
	List<string> *strlist;
	Typ* typ;
	List<VariableSymbol*>* varlist;
	Exp* exp;
	List<Exp*>* explist;



/* Line 2068 of yacc.c  */
#line 159 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


