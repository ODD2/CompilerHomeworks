/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MODULE = 258,
     PROCEDURE = 259,
     BEG = 260,
     END = 261,
     EXIT = 262,
     RETURN = 263,
     DO = 264,
     LOOP = 265,
     WHILE = 266,
     REPEAT = 267,
     FOR = 268,
     CONTINUE = 269,
     BREAK = 270,
     CASE = 271,
     IF = 272,
     THEN = 273,
     ELSE = 274,
     RECORD = 275,
     TYPE = 276,
     USE = 277,
     VAR = 278,
     BOOLEAN = 279,
     CHAR = 280,
     CONST = 281,
     REAL = 282,
     STRING = 283,
     INTEGER = 284,
     ARRAY = 285,
     OF = 286,
     TRUE = 287,
     FALSE = 288,
     STRINGV = 289,
     REALV = 290,
     INTEGERV = 291,
     ID = 292,
     INTID = 293,
     REALID = 294,
     BOOLID = 295,
     STRID = 296,
     FUNCID = 297,
     LT = 298,
     LEQ = 299,
     GT = 300,
     GEQ = 301,
     EQ = 302,
     NEQ = 303,
     ANDL = 304,
     ORL = 305,
     NOTL = 306,
     ASSIGN = 307,
     PRINT = 308,
     PRINTLN = 309,
     UTIL = 310,
     FN = 311,
     IN = 312,
     READ = 313,
     UNARY = 314
   };
#endif
/* Tokens.  */
#define MODULE 258
#define PROCEDURE 259
#define BEG 260
#define END 261
#define EXIT 262
#define RETURN 263
#define DO 264
#define LOOP 265
#define WHILE 266
#define REPEAT 267
#define FOR 268
#define CONTINUE 269
#define BREAK 270
#define CASE 271
#define IF 272
#define THEN 273
#define ELSE 274
#define RECORD 275
#define TYPE 276
#define USE 277
#define VAR 278
#define BOOLEAN 279
#define CHAR 280
#define CONST 281
#define REAL 282
#define STRING 283
#define INTEGER 284
#define ARRAY 285
#define OF 286
#define TRUE 287
#define FALSE 288
#define STRINGV 289
#define REALV 290
#define INTEGERV 291
#define ID 292
#define INTID 293
#define REALID 294
#define BOOLID 295
#define STRID 296
#define FUNCID 297
#define LT 298
#define LEQ 299
#define GT 300
#define GEQ 301
#define EQ 302
#define NEQ 303
#define ANDL 304
#define ORL 305
#define NOTL 306
#define ASSIGN 307
#define PRINT 308
#define PRINTLN 309
#define UTIL 310
#define FN 311
#define IN 312
#define READ 313
#define UNARY 314




/* Copy the first part of user declarations.  */
#line 1 "hw2.yacc"

#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include "header.h"
using namespace std;
//#define Trail(t) printf("{"t"}");

//Extern Variables.
extern FILE *yyin;
extern int lineno;
extern int charno;
extern char buf[];
extern char * yytext;

extern "C"
{
    int yyparse(void);
    int yylex(void);
    int yywrap()
    {
        return 1;
    }
    //VARTYPE idFindType(char * id_name,void ** id_varbox_container );
}



//Yacc Required Function
void yyerror(const char *s){
   cout << buf << " (" << s  << ')' << endl;
}

#define TypeUnmatch(t,y)  "Type Unmatch("+ t + "<>" + t + ")"
#define LNPUTLN(t) {cout << #t << "\n";}
#define PUTLN(t) {cout << #t <<"\n";}
#define PUT(t) {cout << #t << " " ;}
#define Alert(t) 	{cout << "{!" << (t) << "!}";}
#define Trail(t)	{cout << " <--{" <<  (t) << "}";}
#define Error(t)	{ errorMsg +="[Error]"+to_string(lineno)+"@"+"("+ to_string(charno)+ "): " + t + ".\n"; }
#define Warn(t)		{ warnMsg +="[Warning]"+ to_string(lineno)+"@"+"("+ to_string(charno)+ "): " + t + ".\n"; }

std::string  errorMsg = "";
std::string  warnMsg = "";


/////////Data Type Definitions/////////
enum SymbolType {
	constant,
	integer,
	real,
	boolean,
	string,
	array,
	function,
	procedure,
	unknown,
	none,
};

enum TokenType{
	vint,
	vreal,
	vbool,
	vstring,
	idList,
	typeList,
	idType,
	vunknown,
};

int Symbol2Token(int symbol){
	switch(symbol){
		case SymbolType::integer:
			return  TokenType::vint;
		break;
		case SymbolType::real:
			return  TokenType::vreal;
		break;
		case SymbolType::string:
			return  TokenType::vstring;
		break;
		case SymbolType::boolean:
			return  TokenType::vbool;
		break;
		default:
			return TokenType::vunknown;
		break;
	}
}

int Token2Symbol(int token){
	switch(token){
		case TokenType::vint:
			return SymbolType::integer;
		break;
		case TokenType::vreal : 
			return SymbolType::real;
		break;
		case TokenType::vstring :
			return SymbolType::string;
		break;
		case TokenType::vbool :
			return SymbolType::boolean;
		break;
		default:
			return SymbolType::unknown;
		break;
	}
}

std::string SymType2Str(int type){
	switch(type){
		case SymbolType::constant :
		return "constant";
		break;
		case SymbolType::integer :
		return "integer";
		break;
		case SymbolType::real :
		return "real";
		break;
		case SymbolType::boolean :
		return "boolean";
		break;
		case SymbolType::string :
		return "string";
		break;
		case SymbolType::array :
		return "array";
		break;
		case SymbolType::function :
		return "function";
		break;
		case SymbolType::procedure :
		return "procedure";
		break;
		case SymbolType::none :
		return "none";
		break;
		default:
		return "unknown";
		break;
	}
}

std::string TokType2Str(int type){
	switch(type){
		case TokenType::vint:
		return "vint";
		break;
		case TokenType::vreal:
		return "vreal";
		break;
		case TokenType::vbool:
		return "vbool";
		break;
		case TokenType::vstring:
		return "vstring";
		break;
		case TokenType::idList:
		return "idList";
		break;
		case TokenType::typeList:
		return "typeList";
		break;
		case TokenType::idType:
		return "idType";
		break;
		case TokenType::vunknown:
		return "vunknown";
		break;
	}
    return "vunknown";;
}

struct SymbolDesc;

union uDependency{
	int low;
	int high;
	int _int;
	int baseType;
	int retType;
	int argType;
};

struct SymbolDesc{
	int symtype;
	vector<uDependency> symdeps;
};



/////////Symbol Table Manipulations////////
vector< map<std::string,SymbolDesc> > SymTableStack;
vector<SymbolDesc> FuncStack;

void InitialTableStack(){
	SymTableStack.push_back(map<std::string,SymbolDesc>());
}

int GETSCOPERETURN(){
	if(FuncStack.size()==0){
		return SymbolType::none;
	}
	else {
		if(FuncStack.back().symtype == SymbolType::procedure){
			return SymbolType::none;
		}
		else
		{
			return FuncStack.back().symdeps[0].retType;
		}
	}
}

void ENTERSCOPE(){
	SymTableStack.push_back(map<std::string,SymbolDesc>());
}

void LEAVESCOPE(){
	if(SymTableStack.size() == 0) cout << "Error! SymTableStack.size() = 0" <<endl;
	else SymTableStack.pop_back();
}

bool seize(std::string id,SymbolDesc *& sd){
	for(int i = SymTableStack.size() -1 ; i>=0;--i){
		if(SymTableStack[i].count(id)){
			sd = &(SymTableStack[i][id]);
			return true;
		}
	}
	Error("Symbol: \'" + id + "\',Not Found");
	return false;
}

bool seize(std::string id,SymbolDesc & sd){
	for(int i = SymTableStack.size() -1 ; i>=0;--i){
		if(SymTableStack[i].count(id)){
			sd = (SymTableStack[i][id]);
			return true;
		}
	}
	Error("Symbol:" + id + ",Not Found");
	return false;
}

bool inScope(std::string id){
	if(SymTableStack.back().count(id)){
		return true;
	}
	return false;
}

bool insert(std::string id,SymbolDesc& sd){
	if(inScope(id)){
		Error("\'" + id + "\' duplicated");
		return false;
	}
	SymTableStack.back()[id] = sd;
	return true;
}

bool insert(vector<std::string> list,SymbolDesc& sd){
	bool success = true;
	for(int i = 0 ; i < list.size() ; ++i){
		insert(list[i],sd);
	}
	return success;
}

bool matchArgs(vector<int>& list,SymbolDesc & sd){
	int i = 0;
	int isfunc = 0;
	if(sd.symtype == SymbolType::function) isfunc = 1;
	if(list.size() + isfunc > sd.symdeps.size()){
		return false;
	}
	else{
		for(i = 0; i < list.size();++i){
			if(list[i] !=sd.symdeps[i+isfunc].argType) return false;
		}	
	}
	return true;
}

std::string dumpSd(const SymbolDesc & sd){
	std::string ret;
	ret += "{" + SymType2Str(sd.symtype);
	if(sd.symtype == SymbolType::array){
		ret += "," + SymType2Str(sd.symdeps[0].argType);
		ret += "," + to_string(sd.symdeps[1].low); //low range
		ret += "," + to_string(sd.symdeps[2].high); //high range
	}
	else if(sd.symtype == SymbolType::constant){
		ret +="," + SymType2Str(sd.symdeps[0].baseType);
	}
	else if (sd.symtype == SymbolType::function){
		ret += "," + SymType2Str(sd.symdeps[0].retType);
		ret += ",(";
		for(int j = 1, jl = sd.symdeps.size() ; j < jl ;++j){
			ret += SymType2Str(sd.symdeps[j].argType);
			if(j != jl-1) ret += ",";
		}
		ret += ")";
	}
	else if (sd.symtype == SymbolType::procedure){
		ret +=",(";
		for(int j = 0, jl = sd.symdeps.size() ; j < jl ;++j){
			ret +=SymType2Str(sd.symdeps[j].argType);
			if(j != jl-1) ret +=",";
		}
		ret +=")";
	}
	ret +="}";
	return ret;
}

std::string dumpVar(std::string id){
	SymbolDesc  sd;
	std::string ret;
	if(seize(id, sd)){
		ret = "<" + id + "," + dumpSd(sd) + ">";
	}
	else {
		ret = " ";
	}
	return ret;
}

void dump(){
	cout << endl;
	for(int i = 0 ; i < SymTableStack.size();++i){
		cout << "SCOPE(" << i << "):" <<endl;
		for(auto it = SymTableStack[i].begin(),ed = SymTableStack[i].end();
			it!=ed;
			++it){
			cout << "<" << it->first << ","; dumpSd(it->second); cout << ">\n";
		}
	}
	cout << endl;
}
/////////HELPER FUNCTIONS///////////
void dumpIDLIST(vector<std::string> * list){
	cout << "[ ";
	for(auto it = list->begin(),ed=list->end();it!=ed;++it){
		cout << (*it) << " "	;
	}
	cout << "]";
}






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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 362 "hw2.yacc"
{
	TOKEN token;
}
/* Line 193 of yacc.c.  */
#line 578 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 591 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   387

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    63,     2,     2,
      71,    72,    61,    59,    68,    60,    65,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    66,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    13,    14,    17,    20,    23,    29,    35,
      37,    41,    50,    52,    54,    56,    58,    60,    63,    69,
      75,    77,    79,    81,    83,    85,    86,    87,    88,   102,
     103,   107,   111,   117,   118,   121,   122,   128,   134,   143,
     152,   157,   162,   167,   171,   176,   188,   198,   208,   215,
     219,   221,   225,   229,   233,   237,   241,   245,   248,   252,
     256,   260,   264,   268,   272,   276,   280,   283,   288,   293,
     295,   297,   299,   301,   303
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      74,     0,    -1,     3,    37,    75,    82,     5,    88,     6,
      37,    65,    -1,    -1,    75,    76,    -1,    75,    80,    -1,
      23,    66,    -1,    23,    77,    67,    78,    66,    -1,    76,
      77,    67,    78,    66,    -1,    37,    -1,    77,    68,    37,
      -1,    30,    69,    36,    68,    36,    70,    31,    79,    -1,
      79,    -1,    24,    -1,    29,    -1,    27,    -1,    28,    -1,
      26,    66,    -1,    26,    37,    47,    81,    66,    -1,    80,
      37,    47,    81,    66,    -1,    36,    -1,    35,    -1,    32,
      -1,    33,    -1,    34,    -1,    -1,    -1,    -1,    82,    83,
       4,    37,    85,    87,    84,    75,     5,    88,     6,    37,
      66,    -1,    -1,    71,    86,    72,    -1,    37,    67,    78,
      -1,    86,    68,    37,    67,    78,    -1,    -1,    67,    78,
      -1,    -1,    88,    37,    52,    90,    66,    -1,    88,    37,
      47,    90,    66,    -1,    88,    37,    69,    90,    70,    52,
      90,    66,    -1,    88,    37,    69,    90,    70,    47,    90,
      66,    -1,    88,    53,    90,    66,    -1,    88,    54,    90,
      66,    -1,    88,    58,    37,    66,    -1,    88,     8,    66,
      -1,    88,     8,    90,    66,    -1,    88,    17,    71,    90,
      72,    18,    88,    19,    88,     6,    66,    -1,    88,    17,
      71,    90,    72,    18,    88,     6,    66,    -1,    88,    11,
      71,    90,    72,     9,    88,     6,    66,    -1,    88,    37,
      71,    89,    72,    66,    -1,    88,    37,    66,    -1,    90,
      -1,    89,    68,    90,    -1,    90,    59,    90,    -1,    90,
      60,    90,    -1,    90,    61,    90,    -1,    90,    62,    90,
      -1,    90,    63,    90,    -1,    60,    90,    -1,    90,    43,
      90,    -1,    90,    44,    90,    -1,    90,    47,    90,    -1,
      90,    46,    90,    -1,    90,    45,    90,    -1,    90,    48,
      90,    -1,    90,    49,    90,    -1,    90,    50,    90,    -1,
      51,    90,    -1,    37,    69,    90,    70,    -1,    37,    71,
      89,    72,    -1,    37,    -1,    36,    -1,    35,    -1,    32,
      -1,    33,    -1,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   406,   406,   422,   423,   424,   427,   428,   435,   444,
     448,   454,   464,   472,   475,   478,   481,   486,   487,   499,
     516,   520,   524,   528,   532,   539,   540,   543,   540,   589,
     593,   599,   612,   624,   628,   634,   635,   649,   667,   686,
     705,   708,   711,   714,   720,   729,   735,   741,   747,   766,
     781,   787,   794,   816,   838,   860,   882,   904,   918,   937,
     956,   983,  1002,  1021,  1048,  1059,  1070,  1081,  1098,  1116,
    1126,  1130,  1134,  1138,  1142
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MODULE", "PROCEDURE", "BEG", "END",
  "EXIT", "RETURN", "DO", "LOOP", "WHILE", "REPEAT", "FOR", "CONTINUE",
  "BREAK", "CASE", "IF", "THEN", "ELSE", "RECORD", "TYPE", "USE", "VAR",
  "BOOLEAN", "CHAR", "CONST", "REAL", "STRING", "INTEGER", "ARRAY", "OF",
  "TRUE", "FALSE", "STRINGV", "REALV", "INTEGERV", "ID", "INTID", "REALID",
  "BOOLID", "STRID", "FUNCID", "LT", "LEQ", "GT", "GEQ", "EQ", "NEQ",
  "ANDL", "ORL", "NOTL", "ASSIGN", "PRINT", "PRINTLN", "UTIL", "FN", "IN",
  "READ", "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY", "'.'", "';'", "':'",
  "','", "'['", "']'", "'('", "')'", "$accept", "PROGRAM",
  "VAR_CONST_DECL", "VAR_DECL", "ID_LIST", "ID_TYPE", "BASIC_TYPES",
  "CONST_DECL", "VALUES", "FUNC_DECL", "@1", "@2", "FUNC_ARGS",
  "FUNC_VARS", "FUNC_RET", "STMTS", "ARG_LIST", "EXPR", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,    43,
      45,    42,    47,    37,   314,    46,    59,    58,    44,    91,
      93,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    75,    75,    76,    76,    76,    77,
      77,    78,    78,    79,    79,    79,    79,    80,    80,    80,
      81,    81,    81,    81,    81,    82,    83,    84,    82,    85,
      85,    86,    86,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     0,     2,     2,     2,     5,     5,     1,
       3,     8,     1,     1,     1,     1,     1,     2,     5,     5,
       1,     1,     1,     1,     1,     0,     0,     0,    13,     0,
       3,     3,     5,     0,     2,     0,     5,     5,     8,     8,
       4,     4,     4,     3,     4,    11,     9,     9,     6,     3,
       1,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     4,     4,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,    25,     0,     0,     4,     5,
      26,     9,     6,     0,     0,    17,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    15,    16,
      14,     0,     0,    12,    10,    22,    23,    24,    21,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     7,    18,     8,    19,     0,    72,    73,
      74,    71,    70,    69,     0,     0,    43,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,    33,
       0,     2,     0,     0,    66,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,    50,    40,    41,    42,
       0,     0,     0,    27,     0,     0,     0,    58,    59,    62,
      61,    60,    63,    64,    65,    52,    53,    54,    55,    56,
       0,     0,    37,    36,     0,     0,     0,     0,     0,    30,
      34,     3,     0,    67,    68,    35,    35,     0,     0,    51,
      48,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      35,     0,     0,     0,    35,    39,    38,    32,     0,    11,
      47,    46,     0,     0,     0,     0,    45,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     8,    13,    32,    33,     9,    40,    10,
      19,   141,    79,   111,   113,    25,   105,   106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
      21,    19,    37,   -60,   -60,    12,   -34,   -33,    20,    28,
      73,   -60,   -60,   -59,    11,   -60,   -52,    32,   -60,    79,
     -17,    48,   163,   -17,   163,    53,    51,   -60,   -60,   -60,
     -60,    17,    25,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
      29,    43,    44,    57,    90,    27,    41,    49,   155,   155,
      66,    60,    83,   -60,   -60,   -60,   -60,    70,   -60,   -60,
     -60,   -60,   -60,     4,   155,   155,   -60,   220,   155,   155,
     155,   155,   -60,   155,   155,   228,   252,    71,   101,    72,
      74,   -60,   155,   155,   -60,   -60,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   -60,
     114,   122,   260,   284,   164,    -6,   324,   -60,   -60,   -60,
      81,    -5,   -17,   -60,   104,   192,     0,   -60,   -60,   -60,
     -60,   -60,   -60,   157,   157,   185,   185,   -60,   -60,   -60,
     134,   128,   -60,   -60,   -11,   155,    86,   -17,   116,   -60,
     -60,   -60,    84,   -60,   -60,   -60,   -60,   155,   155,   324,
     -60,   -60,    88,    -3,   147,    63,    23,   292,   316,   -17,
     -60,   -10,   113,   127,   -60,   -60,   -60,   -60,    76,   -60,
     -60,   -60,    91,   143,   156,   177,   -60,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,    80,   -60,   236,   -23,    89,   -60,   221,   -60,
     -60,   -60,   -60,   -60,   -60,   -13,   166,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      41,    67,   160,    11,    14,    75,    76,    27,    20,    21,
      28,    29,    30,    31,    27,    23,    21,    28,    29,    30,
       6,    84,    85,     7,     1,   100,   101,   102,   103,   163,
     104,    44,    12,    15,    45,     6,   147,     4,     7,   115,
      46,   148,   164,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     3,    11,    22,    43,
      47,    44,   135,   138,    45,    17,   136,   139,   135,   162,
      46,    44,   144,    82,    45,    83,    48,    49,    18,    24,
      46,    50,   173,    26,    44,    34,    52,    45,    51,   140,
      47,    53,   149,    46,    57,    54,    70,   174,    68,    44,
      47,    71,    45,    77,   157,   158,    48,    49,    46,    55,
      56,    50,    69,    47,   151,    72,    48,    49,    73,    80,
      74,    50,    58,    59,    60,    61,    62,    63,    47,    48,
      49,    78,   155,   156,    50,    81,   167,   109,   110,   112,
     142,    64,   114,   145,    48,    49,   146,   168,   137,    50,
      65,   172,   150,   152,   154,   159,    66,    86,    87,    88,
      89,    90,    91,    92,    93,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   161,   170,
     175,    94,    95,    96,    97,    98,   130,    58,    59,    60,
      61,    62,    63,   171,   131,    35,    36,    37,    38,    39,
      86,    87,    88,    89,    90,    91,    64,    86,    87,    88,
      89,    90,    91,    92,    93,    65,    94,    95,    96,    97,
      98,   153,   176,    94,    95,    96,    97,    98,    86,    87,
      88,    89,    90,    91,   134,    86,    87,    88,    89,    90,
      91,    92,    93,   177,    16,    42,    96,    97,    98,   116,
     169,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,   143,    86,    87,    88,    89,    90,    91,    92,
      93,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,     0,    99,    94,    95,    96,
      97,    98,     0,     0,   107,    86,    87,    88,    89,    90,
      91,    92,    93,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,   108,    94,
      95,    96,    97,    98,     0,     0,   132,    86,    87,    88,
      89,    90,    91,    92,    93,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
     133,    94,    95,    96,    97,    98,     0,     0,   165,    86,
      87,    88,    89,    90,    91,    92,    93,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,   166,    94,    95,    96,    97,    98
};

static const yytype_int16 yycheck[] =
{
      23,    44,     5,    37,    37,    48,    49,    24,    67,    68,
      27,    28,    29,    30,    24,    67,    68,    27,    28,    29,
      23,    64,    65,    26,     3,    68,    69,    70,    71,     6,
      73,     8,    66,    66,    11,    23,    47,     0,    26,    82,
      17,    52,    19,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    37,    37,    47,     6,
      37,     8,    68,    68,    11,    37,    72,    72,    68,     6,
      17,     8,    72,    69,    11,    71,    53,    54,     5,    47,
      17,    58,     6,     4,     8,    37,    69,    11,    37,   112,
      37,    66,   135,    17,    37,    66,    47,     6,    71,     8,
      37,    52,    11,    37,   147,   148,    53,    54,    17,    66,
      66,    58,    71,    37,   137,    66,    53,    54,    69,    36,
      71,    58,    32,    33,    34,    35,    36,    37,    37,    53,
      54,    71,   145,   146,    58,    65,   159,    66,    37,    67,
      36,    51,    68,     9,    53,    54,    18,   160,    67,    58,
      60,   164,    66,    37,    70,    67,    66,    43,    44,    45,
      46,    47,    48,    49,    50,    43,    44,    45,    46,    47,
      48,    49,    50,    59,    60,    61,    62,    63,    31,    66,
      37,    59,    60,    61,    62,    63,    72,    32,    33,    34,
      35,    36,    37,    66,    72,    32,    33,    34,    35,    36,
      43,    44,    45,    46,    47,    48,    51,    43,    44,    45,
      46,    47,    48,    49,    50,    60,    59,    60,    61,    62,
      63,   141,    66,    59,    60,    61,    62,    63,    43,    44,
      45,    46,    47,    48,    70,    43,    44,    45,    46,    47,
      48,    49,    50,    66,     8,    24,    61,    62,    63,    83,
     161,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    43,    44,    45,    46,    47,    48,    49,
      50,    43,    44,    45,    46,    47,    48,    49,    50,    59,
      60,    61,    62,    63,    -1,    -1,    66,    59,    60,    61,
      62,    63,    -1,    -1,    66,    43,    44,    45,    46,    47,
      48,    49,    50,    43,    44,    45,    46,    47,    48,    49,
      50,    59,    60,    61,    62,    63,    -1,    -1,    66,    59,
      60,    61,    62,    63,    -1,    -1,    66,    43,    44,    45,
      46,    47,    48,    49,    50,    43,    44,    45,    46,    47,
      48,    49,    50,    59,    60,    61,    62,    63,    -1,    -1,
      66,    59,    60,    61,    62,    63,    -1,    -1,    66,    43,
      44,    45,    46,    47,    48,    49,    50,    43,    44,    45,
      46,    47,    48,    49,    50,    59,    60,    61,    62,    63,
      -1,    -1,    66,    59,    60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    74,    37,     0,    75,    23,    26,    76,    80,
      82,    37,    66,    77,    37,    66,    77,    37,     5,    83,
      67,    68,    47,    67,    47,    88,     4,    24,    27,    28,
      29,    30,    78,    79,    37,    32,    33,    34,    35,    36,
      81,    78,    81,     6,     8,    11,    17,    37,    53,    54,
      58,    37,    69,    66,    66,    66,    66,    37,    32,    33,
      34,    35,    36,    37,    51,    60,    66,    90,    71,    71,
      47,    52,    66,    69,    71,    90,    90,    37,    71,    85,
      36,    65,    69,    71,    90,    90,    43,    44,    45,    46,
      47,    48,    49,    50,    59,    60,    61,    62,    63,    66,
      90,    90,    90,    90,    90,    89,    90,    66,    66,    66,
      37,    86,    67,    87,    68,    90,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      72,    72,    66,    66,    70,    68,    72,    67,    68,    72,
      78,    84,    36,    70,    72,     9,    18,    47,    52,    90,
      66,    78,    37,    75,    70,    88,    88,    90,    90,    67,
       5,    31,     6,     6,    19,    66,    66,    78,    88,    79,
      66,    66,    88,     6,     6,    37,    66,    66
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 410 "hw2.yacc"
    {
 				Trail("Program Declaration");
 				
 				char * name1 = (yyvsp[(2) - (9)].token)._str, * name2 = (yyvsp[(8) - (9)].token)._str; 
 				if(strcmp(name1,name2)!=0){
 					Error("Module: begin ID != end ID");
 				}
 				delete name1,name2;
			}
    break;

  case 6:
#line 427 "hw2.yacc"
    { Trail("Var Declare"); }
    break;

  case 7:
#line 428 "hw2.yacc"
    { 
			auto idlist = (vector<std::string>*)(yyvsp[(2) - (5)].token)._ptr;
			auto sd = (SymbolDesc *)(yyvsp[(4) - (5)].token)._ptr;
			insert(*idlist,*sd);
			Trail("Var Declare"); 
			delete idlist,sd;
		}
    break;

  case 8:
#line 435 "hw2.yacc"
    {
			auto idlist = (vector<std::string>*)(yyvsp[(2) - (5)].token)._ptr;
			auto sd = (SymbolDesc *)(yyvsp[(4) - (5)].token)._ptr;
			insert(*idlist,*sd);
			Trail("Var Declare"); 
			delete idlist,sd;
		}
    break;

  case 9:
#line 444 "hw2.yacc"
    {
			(yyval.token)._ptr = new vector<std::string>();
			((vector<std::string>*)(yyval.token)._ptr)->push_back(std::string((yyvsp[(1) - (1)].token)._str));
		}
    break;

  case 10:
#line 448 "hw2.yacc"
    {
			(yyval.token) = (yyvsp[(1) - (3)].token);
			((vector<std::string>*)(yyval.token)._ptr)->push_back(std::string((yyvsp[(3) - (3)].token)._str));
		}
    break;

  case 11:
#line 454 "hw2.yacc"
    {
			SymbolDesc * sd = new SymbolDesc();
			(yyval.token).type = TokenType::idType;
			(yyval.token)._ptr = sd;
			uDependency dp;
			sd->symtype =  SymbolType::array;
			dp.baseType = (yyvsp[(8) - (8)].token)._int; sd->symdeps.push_back(dp);
			dp.low = (yyvsp[(3) - (8)].token)._int; sd->symdeps.push_back(dp);
			dp.high = (yyvsp[(5) - (8)].token)._int; sd->symdeps.push_back(dp);	
		}
    break;

  case 12:
#line 464 "hw2.yacc"
    {
			SymbolDesc * sd = new SymbolDesc();
			(yyval.token).type = TokenType::idType;
			(yyval.token)._ptr = sd;
			sd->symtype = (yyvsp[(1) - (1)].token)._int;
		}
    break;

  case 13:
#line 472 "hw2.yacc"
    {
				(yyval.token)._int = SymbolType::boolean;
			}
    break;

  case 14:
#line 475 "hw2.yacc"
    {
				(yyval.token)._int = SymbolType::integer;
			}
    break;

  case 15:
#line 478 "hw2.yacc"
    {
				(yyval.token)._int = SymbolType::real;
			}
    break;

  case 16:
#line 481 "hw2.yacc"
    {
				(yyval.token)._int = SymbolType::string;
			}
    break;

  case 17:
#line 486 "hw2.yacc"
    { Trail("Const Declare"); }
    break;

  case 18:
#line 487 "hw2.yacc"
    { 
				char * name = (yyvsp[(2) - (5)].token)._str;
				SymbolDesc sd;
				sd.symtype = SymbolType::constant;
				uDependency dp;
				dp.baseType = Token2Symbol((yyvsp[(4) - (5)].token).type);
				sd.symdeps.push_back(dp);

				insert(std::string(name),sd);
				Trail("Const Declare");
				delete name;
			 }
    break;

  case 19:
#line 499 "hw2.yacc"
    {
				char * name = (yyvsp[(2) - (5)].token)._str; 
				SymbolDesc sd;
				sd.symtype = SymbolType::constant;
				uDependency dp;
				dp.baseType = Token2Symbol((yyvsp[(4) - (5)].token).type);
				sd.symdeps.push_back(dp);

				insert(std::string(name),sd);
				Trail("Const Declare");
				delete name;
				if(dp.baseType == SymbolType::string)delete (yyvsp[(4) - (5)].token)._str;
			 }
    break;

  case 20:
#line 516 "hw2.yacc"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vint;
	}
    break;

  case 21:
#line 520 "hw2.yacc"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vreal;
	}
    break;

  case 22:
#line 524 "hw2.yacc"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vbool;
	}
    break;

  case 23:
#line 528 "hw2.yacc"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vbool;
	}
    break;

  case 24:
#line 532 "hw2.yacc"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vstring;
	}
    break;

  case 26:
#line 540 "hw2.yacc"
    {
		ENTERSCOPE();
	}
    break;

  case 27:
#line 543 "hw2.yacc"
    {
		//char * name1 = $4._str
		SymbolDesc * retype = (SymbolDesc*)(yyvsp[(6) - (6)].token)._ptr; 
		//Create Function Symbol;
		SymbolDesc sd; 
		sd.symtype = SymbolType::procedure;
		uDependency dep;
		if(retype != nullptr){
			sd.symtype = SymbolType::function;
			dep.retType = retype->symtype;
			sd.symdeps.push_back(dep);
			delete retype;
		}
		FuncStack.push_back(sd);
	}
    break;

  case 28:
#line 559 "hw2.yacc"
    {
		char * name1 = (yyvsp[(4) - (13)].token)._str, * name2 = (yyvsp[(12) - (13)].token)._str;
		//SymbolDesc * retype = (SymbolDesc*)$6._ptr; 
		vector<int> * list =(vector<int> *)(yyvsp[(5) - (13)].token)._ptr;
		if(std::string(name1)!=std::string(name2)){
			Error("Function ID Unmatch");
		}
		else{

			//Print For Debug;
			//dump();
			LEAVESCOPE();
			
			SymbolDesc sd = FuncStack.back(); 
			FuncStack.pop_back();
			if(list !=nullptr ) {
				uDependency dep;
				for(int i = 0 ; i < list->size(); ++i){
					dep.argType = (*list)[i];
					sd.symdeps.push_back(dep);
				}
			}
			//Create Function Symbol;
			insert(std::string(name1),sd);
			
			Trail( dumpVar(name1) + "Function Declare");
		}
		delete name1,name2,list;
	}
    break;

  case 29:
#line 589 "hw2.yacc"
    {
		(yyval.token).type = TokenType::typeList;
		(yyval.token)._ptr = nullptr;
	}
    break;

  case 30:
#line 593 "hw2.yacc"
    {
		(yyval.token) = (yyvsp[(2) - (3)].token);
	 // Trail("Function Variables");
	}
    break;

  case 31:
#line 599 "hw2.yacc"
    {
		char * name = (yyvsp[(1) - (3)].token)._str;
		SymbolDesc * sd = (SymbolDesc*)(yyvsp[(3) - (3)].token)._ptr;

		(yyval.token).type = TokenType::typeList;
		vector<int> * list =  new vector<int>();
		list->push_back(sd->symtype);
		(yyval.token)._ptr = list;

		insert(std::string(name),*sd);
		delete name;
		delete sd;
	}
    break;

  case 32:
#line 612 "hw2.yacc"
    {
		char * name = (yyvsp[(3) - (5)].token)._str;
		SymbolDesc * sd = (SymbolDesc*)(yyvsp[(5) - (5)].token)._ptr;

		(yyval.token) = (yyvsp[(1) - (5)].token);
		((vector<int>*)(yyval.token)._ptr)->push_back(sd->symtype);

		insert(std::string(name),*sd);
		delete name;
		delete sd;
	}
    break;

  case 33:
#line 624 "hw2.yacc"
    {
		(yyval.token).type = TokenType::idType;
		(yyval.token)._ptr = nullptr;
	}
    break;

  case 34:
#line 628 "hw2.yacc"
    {
		(yyval.token) = (yyvsp[(2) - (2)].token);
		// Trail("Function Return");
	}
    break;

  case 36:
#line 635 "hw2.yacc"
    { 
		SymbolDesc * pSD;
		if(seize(std::string((yyvsp[(2) - (5)].token)._str),pSD)){
			if(pSD->symtype == SymbolType::constant){
				Error("Assignment to Constant!");
			}
			else if(pSD->symtype != Token2Symbol((yyvsp[(4) - (5)].token).type)){
				Error("Type Unmatch");
			}
			else {
			}
		}
		Trail("Assign Stmt"); 
	}
    break;

  case 37:
#line 649 "hw2.yacc"
    { 
		SymbolDesc * pSD;
		if(seize(std::string((yyvsp[(2) - (5)].token)._str),pSD)){
			if(pSD->symtype == SymbolType::constant){
				Error("Assignment to Constant!");
			}
			else if(pSD->symtype != Token2Symbol((yyvsp[(4) - (5)].token).type)){
				Error("Type Unmatch");
			}
			else {

			}
		}
		else {
		}

		Trail("Assign Stmt"); 
	}
    break;

  case 38:
#line 667 "hw2.yacc"
    { 
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(2) - (8)].token)._str);

		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array");
			}
			else if((yyvsp[(4) - (8)].token).type != TokenType::vint){
				Error("Array alloc must be integer");
			}
			else{
			}
		}
		else {
		}

		Trail("Array Assign Stmt"); 
	}
    break;

  case 39:
#line 686 "hw2.yacc"
    { 
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(2) - (8)].token)._str);

		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array");
			}
			else if((yyvsp[(4) - (8)].token).type != TokenType::vint){
				Error("Array alloc must be integer");
			}
			else{
			}
		}
		else {
		}

		Trail("Array Assign Stmt"); 
	}
    break;

  case 40:
#line 705 "hw2.yacc"
    {
		 Trail("Print Stmt"); 
	}
    break;

  case 41:
#line 708 "hw2.yacc"
    { 
		Trail("Println Stmt"); 
	}
    break;

  case 42:
#line 711 "hw2.yacc"
    { 
		Trail("Read Stmt"); 
	}
    break;

  case 43:
#line 714 "hw2.yacc"
    { 
		if(GETSCOPERETURN()!=SymbolType::none){
			Error("Return Type Unmatch: " + SymType2Str(GETSCOPERETURN()));
		}
		Trail("Return Stmt"); 
	}
    break;

  case 44:
#line 720 "hw2.yacc"
    { 
		int req = GETSCOPERETURN();
		int got = Token2Symbol((yyvsp[(3) - (4)].token).type);
		if(req != got){
			Error("Return Type Unmatch: "+ SymType2Str(got) + "("
					 + SymType2Str(GETSCOPERETURN()) + ")");
		}
		Trail("Return Stmt"); 
	}
    break;

  case 45:
#line 729 "hw2.yacc"
    {
		if((yyvsp[(4) - (11)].token).type != TokenType::vbool){
			Error("Expression must be boolean");
		}
	 	Trail("If Else Stmt"); 
	}
    break;

  case 46:
#line 735 "hw2.yacc"
    { 
		if((yyvsp[(4) - (9)].token).type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		Trail("If Stmt"); 
	}
    break;

  case 47:
#line 741 "hw2.yacc"
    { 
		if((yyvsp[(4) - (9)].token).type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		Trail("While Stmt"); 
	}
    break;

  case 48:
#line 747 "hw2.yacc"
    { 
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(2) - (6)].token)._str); delete (yyvsp[(2) - (6)].token)._str;
		vector<int>* list = (std::vector<int>*)(yyvsp[(4) - (6)].token)._ptr;
		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::function || pSD->symtype != SymbolType::procedure){
				Error("\'" + id + "\' is not a Function") ;
			}
			else if(!matchArgs(*list,*pSD)){
				 Error("Argument type Unmatch!");
			}
			else{
			}
		}
		else {
		}
		delete list;
		Trail("Function Stmt"); 
	}
    break;

  case 49:
#line 766 "hw2.yacc"
    { 
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(2) - (3)].token)._str); delete (yyvsp[(2) - (3)].token)._str;
		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::function || pSD->symtype != SymbolType::procedure){
				Error("\'" + id + "\' is not a Function") ;
			}
			else{
			}
		}
		else {
		}
		Trail("Function Stmt"); 
	}
    break;

  case 50:
#line 781 "hw2.yacc"
    {
		(yyval.token).type = TokenType::typeList;
		vector<int> & list = *(new vector<int>());
		list.push_back(Token2Symbol((yyvsp[(1) - (1)].token).type));
		(yyval.token)._ptr = &list;
	}
    break;

  case 51:
#line 787 "hw2.yacc"
    {
		(yyval.token) = (yyvsp[(1) - (3)].token);
		vector<int> & list = *(vector<int>*)(yyval.token)._ptr;
		list.push_back(Token2Symbol((yyvsp[(3) - (3)].token).type));
	}
    break;

  case 52:
#line 794 "hw2.yacc"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				(yyval.token)._int = (yyvsp[(1) - (3)].token)._int + (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = (yyvsp[(1) - (3)].token)._real + (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = (double)(yyvsp[(1) - (3)].token)._int + (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = (yyvsp[(1) - (3)].token)._real + (yyvsp[(3) - (3)].token)._real;
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 53:
#line 816 "hw2.yacc"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				(yyval.token)._int = (yyvsp[(1) - (3)].token)._int - (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = (yyvsp[(1) - (3)].token)._real - (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = (double)(yyvsp[(1) - (3)].token)._int - (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = (yyvsp[(1) - (3)].token)._real - (yyvsp[(3) - (3)].token)._real;
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 54:
#line 838 "hw2.yacc"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				(yyval.token)._int = (yyvsp[(1) - (3)].token)._int * (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = (yyvsp[(1) - (3)].token)._real * (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = (double)(yyvsp[(1) - (3)].token)._int * (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = (yyvsp[(1) - (3)].token)._real * (yyvsp[(3) - (3)].token)._real;
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 55:
#line 860 "hw2.yacc"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				(yyval.token)._int = (yyvsp[(1) - (3)].token)._int + (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._int = (yyvsp[(1) - (3)].token)._real + (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._int = (double)(yyvsp[(1) - (3)].token)._int + (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._int = (yyvsp[(1) - (3)].token)._real + (yyvsp[(3) - (3)].token)._real;
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 56:
#line 882 "hw2.yacc"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				(yyval.token)._int = (yyvsp[(1) - (3)].token)._int % (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = fmod((yyvsp[(1) - (3)].token)._real,(double)(yyvsp[(3) - (3)].token)._int);
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = fmod((double)(yyvsp[(1) - (3)].token)._int,(yyvsp[(3) - (3)].token)._real);
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				(yyval.token)._real = fmod((yyvsp[(1) - (3)].token)._real,(yyvsp[(3) - (3)].token)._real);
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 57:
#line 904 "hw2.yacc"
    {
		if((yyvsp[(2) - (2)].token).type == TokenType::vreal){
			(yyval.token).type = TokenType::vreal;
			(yyval.token)._real = -1 * (yyvsp[(2) - (2)].token)._real;
		}
		else if((yyvsp[(2) - (2)].token).type == TokenType::vint){
			(yyval.token).type = TokenType::vint;
			(yyval.token)._int = -1 * (yyvsp[(2) - (2)].token)._int;
		}
		else {
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 58:
#line 918 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._int < (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real < (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (double)(yyvsp[(1) - (3)].token)._int < (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real < (yyvsp[(3) - (3)].token)._real;
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 59:
#line 937 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._int <= (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real <= (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (double)(yyvsp[(1) - (3)].token)._int <= (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real <= (yyvsp[(3) - (3)].token)._real;
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 60:
#line 956 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._int == (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real == (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (double)(yyvsp[(1) - (3)].token)._int == (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real == (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type == (yyvsp[(3) - (3)].token).type){
			if((yyvsp[(1) - (3)].token).type == TokenType::vstring){
				(yyval.token)._bool = (strcmp((yyvsp[(1) - (3)].token)._str,(yyvsp[(3) - (3)].token)._str) == 0);
			}
			else{
				(yyval.token)._bool = ((yyvsp[(1) - (3)].token)._ptr != (yyvsp[(3) - (3)].token)._ptr);	
			}
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 61:
#line 983 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._int >= (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real >= (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (double)(yyvsp[(1) - (3)].token)._int >= (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real >= (yyvsp[(3) - (3)].token)._real;
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 62:
#line 1002 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._int > (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real > (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (double)(yyvsp[(1) - (3)].token)._int > (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real > (yyvsp[(3) - (3)].token)._real;
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 63:
#line 1021 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._int != (yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal || (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real != (double)(yyvsp[(3) - (3)].token)._int;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (double)(yyvsp[(1) - (3)].token)._int != (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token)._bool = (yyvsp[(1) - (3)].token)._real != (yyvsp[(3) - (3)].token)._real;
		}
		else if((yyvsp[(1) - (3)].token).type == (yyvsp[(3) - (3)].token).type){
			if((yyvsp[(1) - (3)].token).type == TokenType::vstring){
				(yyval.token)._bool = !(strcmp((yyvsp[(1) - (3)].token)._str,(yyvsp[(3) - (3)].token)._str) == 0);
			}
			else{
				(yyval.token)._bool = !((yyvsp[(1) - (3)].token)._ptr != (yyvsp[(3) - (3)].token)._ptr);	
			}
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 64:
#line 1048 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type == (yyvsp[(3) - (3)].token).type && (yyvsp[(1) - (3)].token).type == TokenType::vbool){
			(yyval.token)._bool = (yyvsp[(1) - (3)].token)._bool && (yyvsp[(3) - (3)].token)._bool;
		}
		else
		{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 65:
#line 1059 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type == (yyvsp[(3) - (3)].token).type && (yyvsp[(1) - (3)].token).type == TokenType::vbool){
			(yyval.token)._bool = (yyvsp[(1) - (3)].token)._bool || (yyvsp[(3) - (3)].token)._bool;
		}
		else
		{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 66:
#line 1070 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(2) - (2)].token).type == TokenType::vbool){
			(yyval.token)._bool = !((yyvsp[(2) - (2)].token)._bool);
		}
		else
		{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 67:
#line 1081 "hw2.yacc"
    {
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(1) - (4)].token)._str); delete (yyvsp[(1) - (4)].token)._str;
		if(seize(std::string(id),pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array");
			}
			else if((yyvsp[(3) - (4)].token).type != TokenType::vint){
				Error("Array alloc must be integer");
			}
			else{
				(yyval.token).type = Symbol2Token(pSD->symdeps[0].baseType);
			}
		}
		else {
		}
	}
    break;

  case 68:
#line 1098 "hw2.yacc"
    {
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(1) - (4)].token)._str);delete (yyvsp[(1) - (4)].token)._str;
		if(seize(std::string(id),pSD)){
			vector<int>& list = *(std::vector<int>*)(yyvsp[(3) - (4)].token)._ptr;
			if(pSD->symtype != SymbolType::function){
				Error(id + ": Is not a Array");
			}
			else if(!matchArgs(list,*pSD)){
				Error("Argument type Unmatch");
			}
			else{
				(yyval.token).type = Symbol2Token(pSD->symdeps[0].retType);
			}
		}
		else {
		}
	}
    break;

  case 69:
#line 1116 "hw2.yacc"
    {
		SymbolDesc * pSD;
		if(seize(std::string((yyvsp[(1) - (1)].token)._str),pSD)){
			(yyval.token).type = Symbol2Token(pSD->symtype);
		}
		else {
			// cout << "NO SUCH ID";
		}
		delete (yyvsp[(1) - (1)].token)._str;
	}
    break;

  case 70:
#line 1126 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vint;
		(yyval.token)._int = (yyvsp[(1) - (1)].token)._int;
	}
    break;

  case 71:
#line 1130 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vreal;
		(yyval.token)._real = (yyvsp[(1) - (1)].token)._real;
	}
    break;

  case 72:
#line 1134 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		(yyval.token)._bool = true;
	}
    break;

  case 73:
#line 1138 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vbool;
		(yyval.token)._bool = false;
	}
    break;

  case 74:
#line 1142 "hw2.yacc"
    {
		(yyval.token).type = TokenType::vstring;
		(yyval.token)._str = (yyvsp[(1) - (1)].token)._str;
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2953 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 1148 "hw2.yacc"

int main(int argc,char ** argv )
{
	++argv, --argc;  /* skip over program name */
	if ( argc > 0 )
	    yyin = fopen( argv[0], "r" );
	else
	    yyin = stdin;
	if(!yyin){
		printf("file not found.\n");
		return -1;
	} 
	//Global Symbol Table
	InitialTableStack();
	cout << lineno << ":";
	//Start parsing.
	yyparse();
	cout << endl << endl;
	cout << warnMsg << endl;
	cout << errorMsg << endl;
}


