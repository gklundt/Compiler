/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "paspar.y"

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


/* Line 268 of yacc.c  */
#line 153 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
#line 82 "paspar.y"

	string * token;
	List<string> *strlist;
	Typ* typ;
	List<VariableSymbol*>* varlist;
	Exp* exp;
	List<Exp*>* explist;



/* Line 293 of yacc.c  */
#line 298 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 310 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    12,    15,    18,    19,    23,    25,
      27,    31,    32,    39,    41,    50,    52,    53,    57,    61,
      68,    73,    74,    78,    82,    88,    92,    93,    95,    97,
     101,   105,   107,   109,   116,   121,   123,   128,   130,   135,
     137,   141,   143,   147,   149,   151,   153,   155,   157,   159,
     161,   164,   168,   170,   172,   174,   176,   178,   180,   184,
     186,   188,   190,   192,   194,   196,   201,   206,   210,   213,
     215,   217
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    53,    54,    -1,    37,    43,    55,
      10,    -1,    58,    61,    -1,    66,     8,    -1,    -1,    18,
      56,    19,    -1,    57,    -1,    43,    -1,    57,     9,    43,
      -1,    -1,    58,    41,    57,    11,    59,    10,    -1,    60,
      -1,    24,    20,    44,    22,    44,    21,    34,    60,    -1,
      43,    -1,    -1,    61,    62,    10,    -1,    63,    58,    66,
      -1,    30,    43,    64,    11,    60,    10,    -1,    36,    43,
      64,    10,    -1,    -1,    18,    65,    19,    -1,    57,    11,
      59,    -1,    65,    10,    57,    11,    59,    -1,    25,    67,
      29,    -1,    -1,    68,    -1,    69,    -1,    68,    10,    69,
      -1,    70,     7,    73,    -1,    71,    -1,    66,    -1,    31,
      73,    38,    69,    28,    69,    -1,    42,    73,    27,    69,
      -1,    43,    -1,    43,    20,    73,    21,    -1,    43,    -1,
      43,    18,    72,    19,    -1,    73,    -1,    72,     9,    73,
      -1,    75,    -1,    75,    74,    75,    -1,    12,    -1,    13,
      -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,    78,
      -1,    76,    78,    -1,    75,    77,    78,    -1,     3,    -1,
       4,    -1,     3,    -1,     4,    -1,    35,    -1,    80,    -1,
      78,    79,    80,    -1,     5,    -1,     6,    -1,    26,    -1,
      32,    -1,    23,    -1,    43,    -1,    43,    20,    73,    21,
      -1,    43,    18,    72,    19,    -1,    18,    73,    19,    -1,
      33,    80,    -1,    44,    -1,    45,    -1,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   169,   174,   177,   181,   182,   185,   189,
     192,   198,   199,   203,   205,   210,   215,   216,   219,   223,
     227,   233,   235,   239,   243,   248,   253,   255,   259,   262,
     266,   269,   272,   275,   278,   282,   285,   289,   292,   297,
     300,   304,   307,   311,   313,   315,   317,   319,   321,   324,
     327,   330,   334,   336,   339,   341,   343,   346,   349,   353,
     355,   357,   359,   361,   364,   367,   370,   373,   376,   379,
     382,   385
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "STAR", "SLASH",
  "ASSIGN", "PERIOD", "COMMA", "SEMICOLON", "COLON", "EQU", "NEQ", "LES",
  "LEQ", "GRT", "GEQ", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "RANGE",
  "AND", "ARRAY", "BEGAN", "DIV", "DO", "ELSE", "END", "FUNCTION", "IF",
  "MOD", "NOT", "OF", "OR", "PROCEDURE", "PROGRAM", "THEN", "TO", "TYPE",
  "VAR", "WHILE", "ID", "INTLIT", "REALIT", "CHRLIT", "COMMENT", "NOTOKEN",
  "ERROR", "$accept", "program", "program_head", "program_declarations",
  "program_body", "program_parameters", "program_parameter_list",
  "identifier_list", "variable_declarations", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "sub_program_parameters", "parameter_list", "compound_statement",
  "optional_statements", "statement_list", "statement", "variable",
  "procedure_statement", "expression_list", "expression", "relop",
  "simple_expression", "sign", "addop", "term", "mulop", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    53,    54,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    77,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     2,     2,     0,     3,     1,     1,
       3,     0,     6,     1,     8,     1,     0,     3,     3,     6,
       4,     0,     3,     3,     5,     3,     0,     1,     1,     3,
       3,     1,     1,     6,     4,     1,     4,     1,     4,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     2,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    11,     6,     1,     0,    16,     0,     0,
      26,     2,     0,     0,     4,     9,     0,     8,     3,     0,
       0,    37,    32,     0,    27,    28,     0,    31,     5,     0,
       0,     0,     0,    11,     7,     0,    52,    53,     0,     0,
      64,    69,    70,    71,     0,    41,     0,    49,    57,     0,
       0,     0,    25,     0,     0,     0,    21,    21,    17,     0,
      10,     0,    68,     0,     0,     0,    54,    55,    43,    44,
      45,    46,    47,    48,    56,     0,     0,    50,    59,    60,
      63,    61,    62,     0,     0,     0,    39,     0,    29,    30,
       0,    15,     0,    13,     0,     0,     0,    18,    67,     0,
       0,     0,    42,    51,    58,    34,     0,    38,    36,     0,
      12,     0,     0,     0,    20,    66,    65,     0,    40,     0,
       0,     0,    22,     0,    33,     0,    23,     0,    19,     0,
       0,     0,    24,     0,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,    11,     9,    16,    17,     7,    92,
      93,    14,    32,    33,    95,   112,    22,    23,    24,    25,
      26,    27,    85,    86,    75,    45,    46,    76,    47,    83,
      48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -106
static const yytype_int8 yypact[] =
{
     -19,    -8,    41,  -106,    40,  -106,    30,    20,    36,    75,
      23,  -106,    78,    36,   -14,  -106,    68,    81,  -106,     7,
       7,     6,  -106,    63,    83,  -106,    87,  -106,  -106,    12,
      52,    53,    88,  -106,  -106,    54,  -106,  -106,     7,    -1,
      58,  -106,  -106,  -106,    61,    56,    -1,    57,  -106,    74,
       7,     7,  -106,    23,     7,   -12,    82,    82,  -106,   -11,
    -106,    84,  -106,     7,     7,    23,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,     7,    -1,    57,  -106,  -106,
    -106,  -106,  -106,    -1,    23,    10,  -106,    85,  -106,  -106,
      89,  -106,    92,  -106,    36,    93,    95,  -106,  -106,    18,
      86,    90,     3,    57,  -106,  -106,     7,  -106,  -106,    67,
    -106,    66,    37,    69,  -106,  -106,  -106,    23,  -106,    91,
     -12,    36,  -106,   100,  -106,    70,  -106,    73,  -106,    94,
     -12,    96,  -106,    69,  -106
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -106,  -106,  -106,  -106,  -106,  -106,  -106,   -13,    98,   -56,
    -105,  -106,  -106,  -106,    59,  -106,    -2,  -106,  -106,   -50,
    -106,  -106,    60,   -18,  -106,    42,  -106,  -106,   -37,  -106,
     -34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -36
static const yytype_int16 yytable[] =
{
      29,    44,    49,    88,    12,    62,    66,    67,   123,    77,
      36,    37,    90,   -35,    10,   101,    30,    38,     1,   106,
      61,    35,    31,    55,    50,    38,    51,   106,   134,   107,
      13,    91,    39,    87,   105,     4,    89,   115,    74,   103,
      39,     5,    40,    41,    42,    43,   100,   121,    10,   104,
      40,    41,    42,    43,    19,    10,   122,    97,     8,    66,
      67,    13,    78,    79,   126,    20,    21,   124,    68,    69,
      70,    71,    72,    73,   132,    35,    63,   120,    64,    15,
      80,   111,    35,    81,   130,    18,    28,    34,   118,    82,
      35,    74,    52,    53,    54,    56,    57,    60,    58,    65,
      94,    84,   110,    98,   113,   114,   108,   116,   127,   109,
     128,   119,    91,   125,   129,   131,    96,   102,   117,     0,
       0,     0,     0,    99,     0,     0,     0,     0,     0,     0,
     133,    59
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-106))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      13,    19,    20,    53,     6,    39,     3,     4,   113,    46,
       3,     4,    24,     7,    25,    65,    30,    18,    37,     9,
      38,     9,    36,    11,    18,    18,    20,     9,   133,    19,
      41,    43,    33,    51,    84,    43,    54,    19,    35,    76,
      33,     0,    43,    44,    45,    46,    64,    10,    25,    83,
      43,    44,    45,    46,    31,    25,    19,    59,    18,     3,
       4,    41,     5,     6,   120,    42,    43,   117,    12,    13,
      14,    15,    16,    17,   130,     9,    18,    11,    20,    43,
      23,    94,     9,    26,    11,    10,     8,    19,   106,    32,
       9,    35,    29,    10,     7,    43,    43,    43,    10,    38,
      18,    27,    10,    19,    11,    10,    21,    21,   121,    20,
      10,    44,    43,    22,    44,    21,    57,    75,    28,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    51,    52,    43,     0,    53,    58,    18,    55,
      25,    54,    66,    41,    61,    43,    56,    57,    10,    31,
      42,    43,    66,    67,    68,    69,    70,    71,     8,    57,
      30,    36,    62,    63,    19,     9,     3,     4,    18,    33,
      43,    44,    45,    46,    73,    75,    76,    78,    80,    73,
      18,    20,    29,    10,     7,    11,    43,    43,    10,    58,
      43,    73,    80,    18,    20,    38,     3,     4,    12,    13,
      14,    15,    16,    17,    35,    74,    77,    78,     5,     6,
      23,    26,    32,    79,    27,    72,    73,    73,    69,    73,
      24,    43,    59,    60,    18,    64,    64,    66,    19,    72,
      73,    69,    75,    78,    80,    69,     9,    19,    21,    20,
      10,    57,    65,    11,    10,    19,    21,    28,    73,    44,
      11,    10,    19,    60,    69,    22,    59,    57,    10,    44,
      11,    21,    59,    34,    60
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 166 "paspar.y"
    {tfs << endl << "#001 program --> program_head program_declarations program_body"; 
	 program() ;}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 170 "paspar.y"
    {tfs << endl << "#002 program_head --> PROGRAM ID(" << (*(yyvsp[(2) - (4)].token)) 
		 << ") program_parameters ;"; 
	 program_head(*(yyvsp[(2) - (4)].token));}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 175 "paspar.y"
    {tfs << endl << "#003 program_declarations --> variable_declarations subprogram_declarations";}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 178 "paspar.y"
    {tfs << endl << "#004 program_body --> compound_statement .";}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 181 "paspar.y"
    {tfs << endl << "#005 program_parameters --> empty";}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 183 "paspar.y"
    {tfs << endl << "#006 program_parameters --> ( program_parameter_list )";}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 186 "paspar.y"
    {tfs << endl << "#007 program_parameter_list --> identifier_list(" 
		 << (*(yyvsp[(1) - (1)].strlist)).Print() << ")";}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 190 "paspar.y"
    {tfs << endl << "#008 identifier_list --> ID(" << (*(yyvsp[(1) - (1)].token)) << ")"; 
	 (yyval.strlist)=identifier_list((yyvsp[(1) - (1)].token));}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 193 "paspar.y"
    {tfs << endl << "#009 identifier_list --> identifier_list() , ID(" << (*(yyvsp[(3) - (3)].token)) 
		 << ")"; 
	 (yyval.strlist)=identifier_list((yyvsp[(1) - (3)].strlist),(yyvsp[(3) - (3)].token));}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 198 "paspar.y"
    {tfs << endl << "#010 variable_declarations --> empty";}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 200 "paspar.y"
    {tfs << endl << "#011 variable_declarations --> variable_declarations VAR identifier_list(" << (*(yyvsp[(3) - (6)].strlist)).Print() << ") : type ; "; 
	 variable_declarations((yyvsp[(3) - (6)].strlist),(yyvsp[(5) - (6)].typ));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 204 "paspar.y"
    {tfs << endl << "#012 type --> standard_type ";(yyval.typ)=type((yyvsp[(1) - (1)].typ));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 206 "paspar.y"
    {tfs << endl << "#013 type --> ARRAY [ INTLIT(" << (*(yyvsp[(3) - (8)].token)) << ") .. INTLIT(" 
		 << (*(yyvsp[(5) - (8)].token)) << ") ] OF standard_type"; 
	 (yyval.typ)=type(*(yyvsp[(3) - (8)].token),*(yyvsp[(5) - (8)].token),(yyvsp[(8) - (8)].typ));}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 211 "paspar.y"
    {tfs << endl << "#014 standard_type --> ID(" << (*(yyvsp[(1) - (1)].token)) << ")"; 
	 (yyval.typ)=standard_type((*(yyvsp[(1) - (1)].token)));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 215 "paspar.y"
    {tfs << endl << "#015 subprogram_declarations --> empty";}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 217 "paspar.y"
    {tfs << endl << "#016 subprogram_declarations --> subprogram_declarations subprogram_declaration ; ";}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 220 "paspar.y"
    {tfs << endl << "#017 subprogram_declaration --> subprogram_head variable_declarations compound_statement ";
	 subprogram_declaration();}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 224 "paspar.y"
    {tfs << endl << "#018 subprogram_head --> FUNCTION ID(" << (*(yyvsp[(2) - (6)].token)) 
		 << ") sub_program_parameters : standard_type ; ";
	 subprogram_head(*(yyvsp[(2) - (6)].token),(yyvsp[(3) - (6)].varlist),(yyvsp[(5) - (6)].typ));}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 228 "paspar.y"
    {tfs << endl << "#019 subprogram_head --> PROCEDURE ID(" << (*(yyvsp[(2) - (4)].token)) 
		 << ") sub_program_parameters ; ";
	 subprogram_head(*(yyvsp[(2) - (4)].token),(yyvsp[(3) - (4)].varlist));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 233 "paspar.y"
    {tfs << endl << "#020 sub_program_parameters --> empty "; 
	 (yyval.varlist)=subprogram_parameters();}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 236 "paspar.y"
    {tfs << endl << "#021 sub_program_parameters --> ( parameter_list ) "; 
	 (yyval.varlist)=subprogram_parameters((yyvsp[(2) - (3)].varlist));}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 240 "paspar.y"
    {tfs << endl << "#022 parameter_list --> identifier_list(" << (*(yyvsp[(1) - (3)].strlist)).Print() 
		 << ") : type "; 
	 (yyval.varlist)=parameter_list((yyvsp[(1) - (3)].strlist),(yyvsp[(3) - (3)].typ));}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 244 "paspar.y"
    {tfs << endl << "#023 parameter_list --> parameter_list ; identifier_list(" 
		 << (*(yyvsp[(3) - (5)].strlist)).Print() << ") : type "; 
	 (yyval.varlist)=parameter_list((yyvsp[(1) - (5)].varlist),(yyvsp[(3) - (5)].strlist),(yyvsp[(5) - (5)].typ));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 249 "paspar.y"
    {tfs << endl << "#024 compound_statement --> BEGIN optional_statements END ";
	(yyval.explist)=Compound_statement((yyvsp[(2) - (3)].explist));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 253 "paspar.y"
    {tfs << endl << "#025 optional_statements --> empty ";
	(yyval.explist)=Optional_statements();}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 256 "paspar.y"
    {tfs << endl << "#026 optional_statements --> statement_list ";
	(yyval.explist)=Optional_statements((yyvsp[(1) - (1)].explist));}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 260 "paspar.y"
    {tfs << endl << "#027 statement_list --> statement ";
	(yyval.explist)=Statement_list((yyvsp[(1) - (1)].explist));}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 263 "paspar.y"
    {tfs << endl << "#028 statement_list --> statement_list ; statement ";
	(yyval.explist)=Statement_list((yyvsp[(1) - (3)].explist),(yyvsp[(3) - (3)].explist));}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 267 "paspar.y"
    {tfs << endl << "#029 statement --> variable := expression ";
	(yyval.explist)=statement((yyvsp[(1) - (3)].exp),(yyvsp[(3) - (3)].exp));}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 270 "paspar.y"
    {tfs << endl << "#030 statement --> procedure_statement ";
	(yyval.explist)=statement((yyvsp[(1) - (1)].exp));}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 273 "paspar.y"
    {tfs << endl << "#031 statement --> compound_statement ";
	(yyval.explist)=statement((yyvsp[(1) - (1)].explist));}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 276 "paspar.y"
    {tfs << endl << "#032 statement --> IF expression THEN statement ELSE statement ";
	(yyval.explist)=statement((yyvsp[(2) - (6)].exp),(yyvsp[(4) - (6)].explist),(yyvsp[(6) - (6)].explist));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 279 "paspar.y"
    {tfs << endl << "#033 statement --> WHILE expression DO statement ";
	(yyval.explist)=statement((yyvsp[(2) - (4)].exp),(yyvsp[(4) - (4)].explist));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 283 "paspar.y"
    {tfs << endl << "#034 variable --> ID(" << (*(yyvsp[(1) - (1)].token)) << ")";
	 (yyval.exp)=variable((yyvsp[(1) - (1)].token));}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 286 "paspar.y"
    {tfs << endl << "#035 variable --> ID(" << (*(yyvsp[(1) - (4)].token)) << ") [ expression ] ";
	 (yyval.exp)=variable((yyvsp[(1) - (4)].token),(yyvsp[(3) - (4)].exp));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 290 "paspar.y"
    {tfs << endl << "#036 procedure_statement --> ID(" << (*(yyvsp[(1) - (1)].token)) << ") ";
	 (yyval.exp)=procedure_statement((yyvsp[(1) - (1)].token));}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 293 "paspar.y"
    {tfs << endl << "#037 procedure_statement --> ID(" << (*(yyvsp[(1) - (4)].token)) 
		 << ") ( expression_list ) ";
	 (yyval.exp)=procedure_statement((yyvsp[(1) - (4)].token),(yyvsp[(3) - (4)].explist));}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 298 "paspar.y"
    {tfs << endl << "#038 expression_list --> expression ";
	 (yyval.explist)=expression_list((yyvsp[(1) - (1)].exp));}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 301 "paspar.y"
    {tfs << endl << "#039 expression_list --> expression_list , expression ";
	 (yyval.explist)=expression_list((yyvsp[(1) - (3)].explist),(yyvsp[(3) - (3)].exp));}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 305 "paspar.y"
    {tfs << endl << "#040 expression --> simple_expression ";
	 (yyval.exp)=expression((yyvsp[(1) - (1)].exp));}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 308 "paspar.y"
    {tfs << endl << "#041 expression --> simple_expression relop simple_expression ";
	 (yyval.exp)=expression((yyvsp[(1) - (3)].exp),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].exp));}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 312 "paspar.y"
    {tfs << endl << "#042 relop --> = ";}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 314 "paspar.y"
    {tfs << endl << "#043 relop --> <> ";}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 316 "paspar.y"
    {tfs << endl << "#044 relop --> < ";}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 318 "paspar.y"
    {tfs << endl << "#045 relop --> <= ";}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 320 "paspar.y"
    {tfs << endl << "#046 relop --> > ";}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 322 "paspar.y"
    {tfs << endl << "#047 relop --> >= ";}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 325 "paspar.y"
    {tfs << endl << "#048 simple_expression --> term ";
	 (yyval.exp)=simple_expression((yyvsp[(1) - (1)].exp));}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 328 "paspar.y"
    {tfs << endl << "#049 simple_expression --> sign term ";
	 (yyval.exp)=simple_expression((yyvsp[(1) - (2)].token),(yyvsp[(2) - (2)].exp));}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 331 "paspar.y"
    {tfs << endl << "#050 simple_expression --> simple_expression addop term ";
	 (yyval.exp)=simple_expression((yyvsp[(1) - (3)].exp),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].exp));}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 335 "paspar.y"
    {tfs << endl << "#051 sign --> + ";}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 337 "paspar.y"
    {tfs << endl << "#052 sign --> - ";}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 340 "paspar.y"
    {tfs << endl << "#053 addop --> + ";}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 342 "paspar.y"
    {tfs << endl << "#054 addop --> - ";}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 344 "paspar.y"
    {tfs << endl << "#055 addop --> OR ";}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 347 "paspar.y"
    {tfs << endl << "#056 term --> factor ";
	 (yyval.exp)=term((yyvsp[(1) - (1)].exp));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 350 "paspar.y"
    {tfs << endl << "#057 term --> term mulop factor ";
	 (yyval.exp)=term((yyvsp[(1) - (3)].exp),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].exp));}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 354 "paspar.y"
    {tfs << endl << "#058 mulop --> * ";}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 356 "paspar.y"
    {tfs << endl << "#059 mulop --> / ";}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 358 "paspar.y"
    {tfs << endl << "#060 mulop --> DIV ";}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 360 "paspar.y"
    {tfs << endl << "#061 mulop --> MOD ";}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 362 "paspar.y"
    {tfs << endl << "#062 mulop --> AND ";}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 365 "paspar.y"
    {tfs << endl << "#063 factor --> ID(" << (*(yyvsp[(1) - (1)].token)) << ") "; 
	 (yyval.exp)=factor_1((yyvsp[(1) - (1)].token));}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 368 "paspar.y"
    {tfs << endl << "#064 factor --> ID(" << (*(yyvsp[(1) - (4)].token)) << ") [ expression ] "; 
	 (yyval.exp)=factor_2((yyvsp[(1) - (4)].token),(yyvsp[(3) - (4)].exp));}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 371 "paspar.y"
    {tfs << endl << "#065 factor --> ID(" << (*(yyvsp[(1) - (4)].token)) << ") ( expression_list ) "; 
	 (yyval.exp)=factor_3((yyvsp[(1) - (4)].token),(yyvsp[(3) - (4)].explist));}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 374 "paspar.y"
    {tfs << endl << "#066 factor --> ( expression ) "; 
	 (yyval.exp)=factor_4((yyvsp[(2) - (3)].exp));}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 377 "paspar.y"
    {tfs << endl << "#067 factor --> NOT factor "; 
	 (yyval.exp)=factor_5((yyvsp[(2) - (2)].exp));}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 380 "paspar.y"
    {tfs << endl << "#068 factor --> INTLIT(" << (*(yyvsp[(1) - (1)].token)) << ") "; 
	 (yyval.exp)=factor_6((yyvsp[(1) - (1)].token));}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 383 "paspar.y"
    {tfs << endl << "#069 factor --> REALIT(" << (*(yyvsp[(1) - (1)].token)) << ") "; 
	 (yyval.exp)=factor_7((yyvsp[(1) - (1)].token));}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 386 "paspar.y"
    {tfs << endl << "#070 factor --> CHRLIT(" << (*(yyvsp[(1) - (1)].token)) << ") "; 
	 (yyval.exp)=factor_8((yyvsp[(1) - (1)].token));}
    break;



/* Line 1806 of yacc.c  */
#line 2204 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 389 "paspar.y"


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
