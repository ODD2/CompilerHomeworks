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
#line 1 "y.yy"

#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include "header.h"
using namespace std;

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
#define Error(t)	{ errorMsg +="[ERROR] "+to_string(lineno)+"@"+"("+ to_string(charno)+ "): " + t + ".\n"; }
#define Warn(t)		{ warnMsg +="[WARN] "+ to_string(lineno)+"@"+"("+ to_string(charno)+ "): " + t + ".\n"; }


/////////GLOBAL VARIABLES////////////
std::string  errorMsg = "";
std::string  warnMsg = "";
std::ofstream jbfile;
std::string ClassName;
int LabelIndex = 0;

/////////Data Type Definitions/////////
enum SymbolType {
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
	varray,
	idList,
	typeList,
	idType,
	vunknown,
	blank
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
		case SymbolType::none:
			return TokenType::blank;
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
		case TokenType::blank:
			return SymbolType::none;
		break;
		default:
			return SymbolType::unknown;
		break;
	}
}

std::string SymType2Str(int type){
	switch(type){
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
		return "void";
		break;
		default:
		return "unknown";
		break;
	}
}

std::string SymType2JBStr(int type){
	switch(type){
		case SymbolType::integer :
		return "int";
		break;
		case SymbolType::real :
		return "float";
		break;
		case SymbolType::boolean :
		return "bool";
		break;
		case SymbolType::string :
		return "java.lang.String";
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
		return "void";
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
	int baseType;
	int retType;
	int argType;
	
	int _int;
	bool _bool;
	double _real;
	char * _str;
	void * value;
};

struct SymbolDesc{
	int symtype = SymbolType::unknown;
	bool readonly = false;
	bool global = false;
	vector<uDependency> symdeps;
	int symindex;
};



/////////Symbol Table Manipulations////////
vector< map<std::string,SymbolDesc> > SymTableStack;
vector<int> SymTableIndexStack;
vector<int> SCOPERET;

void InitialTableStack(){
	SymTableStack.push_back(map<std::string,SymbolDesc>());
	SymTableIndexStack.push_back(0);
}

int GETSCOPERETURN(){
	if(SCOPERET.size()==0){
		return SymbolType::none;
	}
	else {
		return SCOPERET.back();
	}
}

void ENTERSCOPE(){
	SymTableStack.push_back(map<std::string,SymbolDesc>());
	SymTableIndexStack.push_back(0);
}

void LEAVESCOPE(){
	if(SymTableStack.size() == 0){
		cout << "Error! SymTableStack.size() = 0" <<endl;
	}
	else{
		SymTableStack.pop_back();
		SymTableIndexStack.pop_back();
	}
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
	Error("Symbol: \'" + id + "\',Not Found");
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
	if(sd.symtype <= SymbolType::array){
		//Variable IDs
		if(!sd.readonly){
			//Non Constant Variable IDs
			if(SymTableStack.size()==1){
				//Global Non Constant Variable IDs
				sd.global = true;
				jbfile << "field static " << SymType2JBStr(sd.symtype) << " " << id<< endl;
			}
			else{
				//Local Non Constan Variable IDs
				sd.symindex = (SymTableIndexStack.back())++;		
			}
		}
	}
	else{
		//Unknown,Function,Procedure IDs
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

bool insert(std::string id,SymbolDesc& sd,int scope){
	map<std::string,SymbolDesc> & EarlyScope =   SymTableStack[SymTableStack.size()-1-scope];
	int & EarlySymIndex = SymTableIndexStack[SymTableIndexStack.size()-scope];
	if(EarlyScope.count(id)){
		Error("\'" + id + "\' duplicated");
		return false;
	}
	if(sd.symtype <= SymbolType::array){
		//Variable IDs
		if(!sd.readonly){
			//Non Constant Variable IDs
			if(SymTableStack.size() - scope ==1){
				//Global Non Constant Variable IDs
				sd.global = true;
				jbfile << "field static " << SymType2JBStr(sd.symtype) << " " << id<< endl;
			}
			else{
				//Local Non Constan Variable IDs
				sd.symindex = EarlySymIndex++;		
			}
		}
	}
	else{
		//Unknown,Function,Procedure IDs
	}
	EarlyScope[id] = sd;
	cout << "Insert OK";
	cout << id <<endl;
	return true;
}

bool matchArgs(vector<int>& list,SymbolDesc & sd){
	if(list.size()  != sd.symdeps.size() - 1){
		return false;
	}
	else{
		for(int i = 0; i < list.size();++i){
			if(list[i] !=sd.symdeps[i+1].argType) return false;
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
#line 454 "y.yy"
{
	TOKEN token;
}
/* Line 193 of yacc.c.  */
#line 670 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 683 "y.tab.c"

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
#define YYLAST   443

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  194

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
       0,     0,     3,     4,     5,     6,    19,    20,    22,    24,
      27,    30,    33,    39,    45,    47,    51,    60,    62,    64,
      66,    68,    70,    73,    79,    85,    87,    89,    91,    93,
      95,    96,    97,    98,   112,   113,   117,   118,   120,   124,
     130,   131,   134,   136,   138,   139,   140,   142,   148,   157,
     166,   167,   173,   174,   180,   185,   189,   194,   195,   209,
     220,   221,   222,   234,   241,   245,   246,   248,   250,   254,
     255,   259,   263,   267,   271,   275,   279,   282,   286,   290,
     294,   298,   302,   306,   310,   314,   317,   322,   327,   329,
     331,   333,   335,   337
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      74,     0,    -1,    -1,    -1,    -1,     3,    37,    75,    78,
      85,     5,    76,    94,     6,    77,    37,    65,    -1,    -1,
      79,    -1,    83,    -1,    83,    79,    -1,    79,    83,    -1,
      23,    66,    -1,    23,    80,    67,    81,    66,    -1,    79,
      80,    67,    81,    66,    -1,    37,    -1,    80,    68,    37,
      -1,    30,    69,    36,    68,    36,    70,    31,    82,    -1,
      82,    -1,    24,    -1,    29,    -1,    27,    -1,    28,    -1,
      26,    66,    -1,    26,    37,    47,    84,    66,    -1,    83,
      37,    47,    84,    66,    -1,    36,    -1,    35,    -1,    32,
      -1,    33,    -1,    34,    -1,    -1,    -1,    -1,    85,     4,
      37,    86,    88,    91,    87,    78,     5,    94,     6,    37,
      66,    -1,    -1,    71,    89,    72,    -1,    -1,    90,    -1,
      37,    67,    81,    -1,    89,    68,    37,    67,    81,    -1,
      -1,    67,    81,    -1,    52,    -1,    47,    -1,    -1,    -1,
      66,    -1,    94,    37,    92,   102,    66,    -1,    94,    37,
      69,   102,    70,    52,   102,    66,    -1,    94,    37,    69,
     102,    70,    47,   102,    66,    -1,    -1,    94,    53,    95,
     102,    66,    -1,    -1,    94,    54,    96,   102,    66,    -1,
      94,    58,    37,    66,    -1,    94,     8,    66,    -1,    94,
       8,   102,    66,    -1,    -1,    94,    17,    71,   102,    72,
      93,    18,    94,    19,    97,    94,     6,    66,    -1,    94,
      17,    71,   102,    72,    93,    18,    94,     6,    66,    -1,
      -1,    -1,    94,    11,    98,    71,   102,    72,    99,     9,
      94,     6,    66,    -1,    94,    37,    71,   100,    72,    66,
      -1,    94,    37,    66,    -1,    -1,   101,    -1,   102,    -1,
     101,    68,   102,    -1,    -1,    71,   102,    72,    -1,   102,
      59,   102,    -1,   102,    60,   102,    -1,   102,    61,   102,
      -1,   102,    62,   102,    -1,   102,    63,   102,    -1,    60,
     102,    -1,   102,    43,   102,    -1,   102,    44,   102,    -1,
     102,    47,   102,    -1,   102,    46,   102,    -1,   102,    45,
     102,    -1,   102,    48,   102,    -1,   102,    49,   102,    -1,
     102,    50,   102,    -1,    51,   102,    -1,    37,    69,   102,
      70,    -1,    37,    71,   100,    72,    -1,    37,    -1,    36,
      -1,    35,    -1,    32,    -1,    33,    -1,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   501,   501,   506,   514,   500,   531,   532,   533,   534,
     535,   538,   539,   546,   555,   559,   565,   575,   583,   586,
     589,   592,   597,   598,   612,   630,   634,   638,   642,   646,
     653,   655,   658,   654,   720,   724,   730,   734,   740,   752,
     765,   769,   775,   776,   779,   785,   786,   787,   818,   837,
     856,   856,   883,   883,   910,   913,   922,   947,   947,   957,
     964,   969,   964,   982,  1011,  1033,  1037,  1041,  1047,  1054,
    1057,  1060,  1084,  1108,  1133,  1157,  1181,  1195,  1237,  1279,
    1324,  1366,  1408,  1452,  1463,  1474,  1486,  1503,  1536,  1636,
    1640,  1644,  1648,  1652
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
  "','", "'['", "']'", "'('", "')'", "$accept", "PROGRAM", "@1", "@2",
  "@3", "VAR_CONST_DECL", "VAR_DECL", "ID_LIST", "ID_TYPE", "BASIC_TYPES",
  "CONST_DECL", "VALUES", "FUNC_DECL", "@4", "@5", "FUNC_ARGS",
  "FUNC_VARS", "FUNC_VARS_LIST", "FUNC_RET", "ASSIGN_SYMBOL", "IF_PREACT",
  "STMTS", "@6", "@7", "@8", "@9", "@10", "ARGS", "ARG_LIST", "EXPR", 0
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
       0,    73,    75,    76,    77,    74,    78,    78,    78,    78,
      78,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    84,    84,    84,    84,    84,
      85,    86,    87,    85,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    93,    94,    94,    94,    94,    94,
      95,    94,    96,    94,    94,    94,    94,    97,    94,    94,
      98,    99,    94,    94,    94,   100,   100,   101,   101,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,    12,     0,     1,     1,     2,
       2,     2,     5,     5,     1,     3,     8,     1,     1,     1,
       1,     1,     2,     5,     5,     1,     1,     1,     1,     1,
       0,     0,     0,    13,     0,     3,     0,     1,     3,     5,
       0,     2,     1,     1,     0,     0,     1,     5,     8,     8,
       0,     5,     0,     5,     4,     3,     4,     0,    13,    10,
       0,     0,    11,     6,     3,     0,     1,     1,     3,     0,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     4,     4,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     6,     0,     0,    30,     7,
       8,    14,    11,     0,     0,    22,     0,     0,    10,     0,
       9,     0,     0,     0,     0,     3,     0,     0,    18,    20,
      21,    19,     0,     0,    17,    15,    27,    28,    29,    26,
      25,     0,    31,    45,     0,     0,     0,    12,    23,    34,
      46,     0,    13,    24,     0,    36,    40,     4,    69,    60,
       0,     0,    50,    52,     0,     0,     0,     0,    37,     0,
      32,     0,    91,    92,    93,    90,    89,    88,    69,    69,
      55,    69,     0,     0,    69,    43,    42,    64,    69,    69,
      69,    69,    69,     0,     0,     0,     0,    35,    41,     6,
       0,    69,    69,    85,    76,     0,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    56,
      69,     0,     0,     0,    66,    67,     0,     0,     0,    54,
       0,    38,     0,     0,     5,     0,     0,    70,    77,    78,
      81,    80,    79,    82,    83,    84,    71,    72,    73,    74,
      75,     0,    44,     0,     0,    69,    47,    51,    53,     0,
       0,    45,    86,    87,    61,     0,    69,    69,    63,    68,
      16,    39,     0,     0,    45,     0,     0,     0,    45,     0,
      49,    48,     0,     0,     0,    57,    33,     0,    59,    45,
      62,     0,     0,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    43,    71,     8,     9,    17,    33,    34,
      10,    41,    16,    49,    99,    56,    67,    68,    70,    90,
     165,    51,    91,    92,   189,    83,   173,   123,   124,   125
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -160
static const yytype_int16 yypact[] =
{
       7,   -12,    29,  -160,  -160,    15,   -34,   -30,  -160,   -21,
     -17,  -160,  -160,   -50,    17,  -160,    42,    12,    38,    34,
      45,   -16,    49,    97,    50,  -160,   -16,    97,  -160,  -160,
    -160,  -160,    19,    25,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,    27,  -160,    28,    39,    40,    64,  -160,  -160,    33,
    -160,    31,  -160,  -160,    54,    70,    51,  -160,   125,  -160,
      52,   -43,  -160,  -160,    88,    90,    60,    -6,  -160,   -16,
    -160,    98,  -160,  -160,  -160,  -160,  -160,     2,   147,   147,
    -160,   147,   284,    65,   147,  -160,  -160,  -160,   147,   118,
     147,   147,   147,    73,    71,   -16,   103,  -160,  -160,    15,
      78,   147,   118,  -160,  -160,   165,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,  -160,
     147,   186,   228,    74,    79,   380,   292,   316,   324,  -160,
     117,  -160,    89,   159,  -160,   256,    93,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,   249,   249,   158,   158,  -160,  -160,
    -160,   207,  -160,    -7,   100,   147,  -160,  -160,  -160,    87,
     -16,    28,  -160,  -160,  -160,   145,   147,   147,  -160,   380,
    -160,  -160,    66,   161,    28,   348,   356,   130,    28,    59,
    -160,  -160,   102,    84,   105,  -160,  -160,   106,  -160,    28,
    -160,    91,   107,  -160
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,  -160,  -160,  -160,    75,   167,   169,   -26,    35,
     177,   160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -159,  -160,  -160,  -160,  -160,  -160,    86,  -160,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -66
static const yytype_int16 yytable[] =
{
      44,    82,   172,    11,    85,     7,     6,    14,    28,    86,
       1,    29,    30,    31,    32,   179,    11,    21,    22,   183,
      19,   103,   104,    87,   105,     3,    88,   121,    89,     4,
     191,   122,    12,   126,   127,   128,    15,    57,     6,    58,
     166,     7,    59,    98,   135,   167,    24,    25,    60,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    96,   151,    23,   184,    97,    58,    61,   131,
      59,   101,   177,   102,    58,    19,    60,    59,   185,    26,
      22,    27,    11,    60,    62,    63,    35,    42,    46,    64,
     187,    47,    58,    48,    50,    59,    61,   192,   169,    58,
      54,    60,    59,    61,    55,    52,    53,    66,    60,   175,
     176,    28,    62,    63,    29,    30,    31,    64,    69,    62,
      63,    61,    65,    84,    64,    93,    94,    95,    61,    36,
      37,    38,    39,    40,   171,   100,   120,    62,    63,   129,
     132,   130,    64,   134,    62,    63,   154,   155,   159,    64,
      72,    73,    74,    75,    76,    77,   160,    72,    73,    74,
      75,    76,    77,   174,   161,   163,   168,   182,   186,    78,
     178,   188,   190,   193,   133,    13,    78,    20,    79,    72,
      73,    74,    75,    76,    77,    79,    18,    45,   136,    81,
     -65,    80,     0,     0,   170,     0,    81,     0,    78,     0,
       0,   106,   107,   108,   109,   110,   111,    79,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,    81,   116,
     117,   118,     0,     0,   114,   115,   116,   117,   118,   106,
     107,   108,   109,   110,   111,   112,   113,   137,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     106,   107,   108,   109,   110,   111,   112,   113,   152,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   106,   107,   108,   109,   110,   111,   112,   113,   164,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   106,   107,   108,   109,   110,   111,   153,   106,
     107,   108,   109,   110,   111,   112,   113,     0,   114,   115,
     116,   117,   118,     0,     0,   114,   115,   116,   117,   118,
       0,     0,     0,     0,     0,     0,   162,   106,   107,   108,
     109,   110,   111,   112,   113,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
     119,   114,   115,   116,   117,   118,     0,     0,   156,   106,
     107,   108,   109,   110,   111,   112,   113,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       0,     0,   157,   114,   115,   116,   117,   118,     0,     0,
     158,   106,   107,   108,   109,   110,   111,   112,   113,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     0,     0,   180,   114,   115,   116,   117,   118,
       0,     0,   181,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118
};

static const yytype_int16 yycheck[] =
{
      26,    58,   161,    37,    47,    26,    23,    37,    24,    52,
       3,    27,    28,    29,    30,   174,    37,    67,    68,   178,
      37,    78,    79,    66,    81,    37,    69,    84,    71,     0,
     189,    88,    66,    90,    91,    92,    66,     6,    23,     8,
      47,    26,    11,    69,   101,    52,     4,     5,    17,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    68,   120,    47,     6,    72,     8,    37,    95,
      11,    69,     6,    71,     8,    37,    17,    11,    19,    67,
      68,    47,    37,    17,    53,    54,    37,    37,    69,    58,
       6,    66,     8,    66,    66,    11,    37,     6,   155,     8,
      36,    17,    11,    37,    71,    66,    66,    37,    17,   166,
     167,    24,    53,    54,    27,    28,    29,    58,    67,    53,
      54,    37,    68,    71,    58,    37,    36,    67,    37,    32,
      33,    34,    35,    36,   160,    37,    71,    53,    54,    66,
      37,    70,    58,    65,    53,    54,    72,    68,    31,    58,
      32,    33,    34,    35,    36,    37,    67,    32,    33,    34,
      35,    36,    37,    18,     5,    72,    66,    37,    66,    51,
       9,    66,    66,    66,    99,     6,    51,    10,    60,    32,
      33,    34,    35,    36,    37,    60,     9,    27,   102,    71,
      72,    66,    -1,    -1,   159,    -1,    71,    -1,    51,    -1,
      -1,    43,    44,    45,    46,    47,    48,    60,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    71,    61,
      62,    63,    -1,    -1,    59,    60,    61,    62,    63,    43,
      44,    45,    46,    47,    48,    49,    50,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      43,    44,    45,    46,    47,    48,    49,    50,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    43,    44,    45,    46,    47,    48,    49,    50,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    43,    44,    45,    46,    47,    48,    70,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    59,    60,
      61,    62,    63,    -1,    -1,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    43,    44,    45,
      46,    47,    48,    49,    50,    43,    44,    45,    46,    47,
      48,    49,    50,    59,    60,    61,    62,    63,    -1,    -1,
      66,    59,    60,    61,    62,    63,    -1,    -1,    66,    43,
      44,    45,    46,    47,    48,    49,    50,    43,    44,    45,
      46,    47,    48,    49,    50,    59,    60,    61,    62,    63,
      -1,    -1,    66,    59,    60,    61,    62,    63,    -1,    -1,
      66,    43,    44,    45,    46,    47,    48,    49,    50,    43,
      44,    45,    46,    47,    48,    49,    50,    59,    60,    61,
      62,    63,    -1,    -1,    66,    59,    60,    61,    62,    63,
      -1,    -1,    66,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    74,    37,     0,    75,    23,    26,    78,    79,
      83,    37,    66,    80,    37,    66,    85,    80,    83,    37,
      79,    67,    68,    47,     4,     5,    67,    47,    24,    27,
      28,    29,    30,    81,    82,    37,    32,    33,    34,    35,
      36,    84,    37,    76,    81,    84,    69,    66,    66,    86,
      66,    94,    66,    66,    36,    71,    88,     6,     8,    11,
      17,    37,    53,    54,    58,    68,    37,    89,    90,    67,
      91,    77,    32,    33,    34,    35,    36,    37,    51,    60,
      66,    71,   102,    98,    71,    47,    52,    66,    69,    71,
      92,    95,    96,    37,    36,    67,    68,    72,    81,    87,
      37,    69,    71,   102,   102,   102,    43,    44,    45,    46,
      47,    48,    49,    50,    59,    60,    61,    62,    63,    66,
      71,   102,   102,   100,   101,   102,   102,   102,   102,    66,
      70,    81,    37,    78,    65,   102,   100,    72,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,    72,    70,    72,    68,    66,    66,    66,    31,
      67,     5,    70,    72,    72,    93,    47,    52,    66,   102,
      82,    81,    94,    99,    18,   102,   102,     6,     9,    94,
      66,    66,    37,    94,     6,    19,    66,     6,    66,    97,
      66,    94,     6,    66
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
#line 501 "y.yy"
    {
 		   		jbfile << "class " << (yyvsp[(2) - (2)].token)._str << "{\n";
 		   		ClassName = std::string((yyvsp[(2) - (2)].token)._str);
 		   	}
    break;

  case 3:
#line 506 "y.yy"
    {
 		   		jbfile << "method public static void main(java.lang.String[])\n";
				jbfile << "max_stack 15\n";
				jbfile << "max_locals 15\n";
				jbfile << "{\n";

 		   	}
    break;

  case 4:
#line 514 "y.yy"
    {
 		   		jbfile << "return\n";
 		   		jbfile << "}\n";

 		   	}
    break;

  case 5:
#line 519 "y.yy"
    { 			
 				jbfile << "}\n";
 				Trail("Program Declaration");	
 				char * name1 = (yyvsp[(2) - (12)].token)._str, * name2 = (yyvsp[(11) - (12)].token)._str; 
 				if(strcmp(name1,name2)!=0){
 					Error(": begin ID != end ID");
 				}
 				delete name1,name2;
			}
    break;

  case 11:
#line 538 "y.yy"
    { Trail("Var Declare"); }
    break;

  case 12:
#line 539 "y.yy"
    { 
			auto idlist = (vector<std::string>*)(yyvsp[(2) - (5)].token)._ptr;
			auto sd = (SymbolDesc *)(yyvsp[(4) - (5)].token)._ptr;
			insert(*idlist,*sd);
			Trail("Var Declare"); 
			delete idlist,sd;
		}
    break;

  case 13:
#line 546 "y.yy"
    {
			auto idlist = (vector<std::string>*)(yyvsp[(2) - (5)].token)._ptr;
			auto sd = (SymbolDesc *)(yyvsp[(4) - (5)].token)._ptr;
			insert(*idlist,*sd);
			Trail("Var Declare"); 
			delete idlist,sd;
		}
    break;

  case 14:
#line 555 "y.yy"
    {
			(yyval.token)._ptr = new vector<std::string>();
			((vector<std::string>*)(yyval.token)._ptr)->push_back(std::string((yyvsp[(1) - (1)].token)._str));
		}
    break;

  case 15:
#line 559 "y.yy"
    {
			(yyval.token) = (yyvsp[(1) - (3)].token);
			((vector<std::string>*)(yyval.token)._ptr)->push_back(std::string((yyvsp[(3) - (3)].token)._str));
		}
    break;

  case 16:
#line 565 "y.yy"
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

  case 17:
#line 575 "y.yy"
    {
			SymbolDesc * sd = new SymbolDesc();
			(yyval.token).type = TokenType::idType;
			(yyval.token)._ptr = sd;
			sd->symtype = (yyvsp[(1) - (1)].token)._int;
		}
    break;

  case 18:
#line 583 "y.yy"
    {
				(yyval.token)._int = SymbolType::boolean;
			}
    break;

  case 19:
#line 586 "y.yy"
    {
				(yyval.token)._int = SymbolType::integer;
			}
    break;

  case 20:
#line 589 "y.yy"
    {
				(yyval.token)._int = SymbolType::real;
			}
    break;

  case 21:
#line 592 "y.yy"
    {
				(yyval.token)._int = SymbolType::string;
			}
    break;

  case 22:
#line 597 "y.yy"
    { Trail("Const Declare"); }
    break;

  case 23:
#line 598 "y.yy"
    { 
				char * name = (yyvsp[(2) - (5)].token)._str;
				SymbolDesc sd;
				uDependency value;

				sd.symtype = Token2Symbol((yyvsp[(4) - (5)].token).type);
				sd.readonly = true;
				value.value = (yyvsp[(4) - (5)].token)._ptr;
				sd.symdeps.push_back(value);

				insert(std::string(name),sd);
				Trail("Const Declare");
				delete name;
			 }
    break;

  case 24:
#line 612 "y.yy"
    {
				char * name = (yyvsp[(2) - (5)].token)._str; 
				SymbolDesc sd;
				uDependency value;

				sd.symtype = Token2Symbol((yyvsp[(4) - (5)].token).type);
				sd.readonly = true;
				value.value = (yyvsp[(4) - (5)].token)._ptr;
				sd.symdeps.push_back(value);

				insert(std::string(name),sd);
				Trail("Const Declare");
				delete name;
			 }
    break;

  case 25:
#line 630 "y.yy"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vint;
	}
    break;

  case 26:
#line 634 "y.yy"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vreal;
	}
    break;

  case 27:
#line 638 "y.yy"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vbool;
	}
    break;

  case 28:
#line 642 "y.yy"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vbool;
	}
    break;

  case 29:
#line 646 "y.yy"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
		(yyval.token).type = TokenType::vstring;
	}
    break;

  case 31:
#line 655 "y.yy"
    {
		ENTERSCOPE();
	}
    break;

  case 32:
#line 658 "y.yy"
    {
		jbfile << "method public static ";
		vector<int> * varlist =(vector<int> *)(yyvsp[(5) - (6)].token)._ptr;
		SymbolDesc * retype = (SymbolDesc*)(yyvsp[(6) - (6)].token)._ptr; 
		SymbolDesc * sd = new SymbolDesc(); //Function Description;
		sd->symtype = SymbolType::function;
		
		uDependency dep;
		if(retype != nullptr){
			jbfile << SymType2JBStr(retype->symtype)  <<" ";

			dep.retType = retype->symtype;
		}
		else {
			jbfile << "void ";

			dep.retType = SymbolType::none;
		}	

		sd->symdeps.push_back(dep);
		SCOPERET.push_back(dep.retType);

		jbfile << (yyvsp[(3) - (6)].token)._str << "(";

		if(varlist != nullptr ) {
			for(int i = 0 , j = varlist->size() ;  i < j; ++i){
				dep.argType = (*varlist)[i];
				sd->symdeps.push_back(dep);

				jbfile << SymType2JBStr(dep.argType);
				if(i!=j-1)jbfile << ", ";
			}
		}

		jbfile<< ")\n";
		jbfile << "max_stack 15\n";
		jbfile << "max_locals 15\n";
		jbfile << "{\n";

		(yyval.token)._ptr = sd;
		delete varlist,retype;
		cout << ((yyvsp[(3) - (6)].token)._str) <<endl;
		insert(std::string((yyvsp[(3) - (6)].token)._str),*sd,1);	
	}
    break;

  case 33:
#line 703 "y.yy"
    {
		jbfile << "return\n";
		jbfile << "}\n\n";

		if(strcmp((yyvsp[(3) - (13)].token)._str,(yyvsp[(12) - (13)].token)._str)!=0){
			Error("Function ID Unmatch");
		}
		else{
			LEAVESCOPE();
			SCOPERET.pop_back();

			SymbolDesc * sd =(SymbolDesc*) (yyvsp[(7) - (13)].token)._ptr;
			Trail( dumpVar(std::string((yyvsp[(3) - (13)].token)._str)) + "Function Declare");
		}
		delete (yyvsp[(3) - (13)].token)._str,(yyvsp[(12) - (13)].token)._str,(SymbolDesc*)(yyvsp[(7) - (13)].token)._ptr;
	}
    break;

  case 34:
#line 720 "y.yy"
    {
		(yyval.token).type = TokenType::typeList;
		(yyval.token)._ptr = nullptr;
	}
    break;

  case 35:
#line 724 "y.yy"
    {
		(yyval.token) = (yyvsp[(2) - (3)].token);
	 // Trail("Function Variables");
	}
    break;

  case 36:
#line 730 "y.yy"
    {
		(yyval.token).type = TokenType::typeList;
		(yyval.token)._ptr = new vector<int>();
	}
    break;

  case 37:
#line 734 "y.yy"
    {
		(yyval.token).type = TokenType::typeList;
		(yyval.token)._ptr = (yyvsp[(1) - (1)].token)._ptr;
	}
    break;

  case 38:
#line 740 "y.yy"
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

  case 39:
#line 752 "y.yy"
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

  case 40:
#line 765 "y.yy"
    {
		(yyval.token).type = TokenType::idType;
		(yyval.token)._ptr = nullptr;
	}
    break;

  case 41:
#line 769 "y.yy"
    {
		(yyval.token) = (yyvsp[(2) - (2)].token);
		// Trail("Function Return");
	}
    break;

  case 44:
#line 779 "y.yy"
    {
		jbfile << "ifeq L"<< LabelIndex++ <<endl;
		(yyval.token)._int = LabelIndex++;
	}
    break;

  case 47:
#line 787 "y.yy"
    { 
		SymbolDesc * pSD;
		if(seize(std::string((yyvsp[(2) - (5)].token)._str),pSD)){
			if(pSD->readonly){
				Error("Assignment to Readonly Variable!");
			}
			else if(pSD->symtype != Token2Symbol((yyvsp[(4) - (5)].token).type)){
				Error("Type Unmatch");
			}
			else {
				if(pSD->global){
					jbfile << "putstatic " << SymType2JBStr(pSD->symtype)<<
							  " " << ClassName << "." << (yyvsp[(2) - (5)].token)._str << "\n";
				}
				else{
					switch(pSD->symtype){
						case SymbolType::integer:
						jbfile <<"istore " << pSD->symindex << "\n";
						break;
						case SymbolType::real:
						jbfile <<"fstore " << pSD->symindex << "\n";
						break;
						case SymbolType::string:
						jbfile <<"astore " << pSD->symindex << "\n";
						break;
					}
				}
			}
		}
		Trail("Assign Stmt"); 
	}
    break;

  case 48:
#line 818 "y.yy"
    { 
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(2) - (8)].token)._str);

		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array (" + SymType2Str(pSD->symtype) + ")");
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

  case 49:
#line 837 "y.yy"
    { 
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(2) - (8)].token)._str);

		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array (" + SymType2Str(pSD->symtype) + ")");
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

  case 50:
#line 856 "y.yy"
    {
		jbfile << "getstatic java.io.PrintStream java.lang.System.out\n";
	}
    break;

  case 51:
#line 858 "y.yy"
    {
		jbfile << "invokevirtual void java.io.PrintStream.print(";
		switch((yyvsp[(4) - (5)].token).type){
			case TokenType::vint:
			jbfile << "int";
			break;
			case TokenType::vreal:
			jbfile << "float";
			break;
			case TokenType::vbool:
			jbfile << "boolean";
			break;
			case TokenType::vstring:
			jbfile << "java.lang.String";
			break;
			case TokenType::blank:
			//jbfile << "void";
			default:
			Error("Printing Unknown Data Type");
			break;
		}
		jbfile << ")\n";

		Trail("Print Stmt"); 
	}
    break;

  case 52:
#line 883 "y.yy"
    {
		jbfile << "getstatic java.io.PrintStream java.lang.System.out\n";
	}
    break;

  case 53:
#line 885 "y.yy"
    { 
		jbfile << "invokevirtual void java.io.PrintStream.println(";
		switch((yyvsp[(4) - (5)].token).type){
			case TokenType::vint:
			jbfile << "int";
			break;
			case TokenType::vreal:
			jbfile << "float";
			break;
			case TokenType::vbool:
			jbfile << "boolean";
			break;
			case TokenType::vstring:
			jbfile << "java.lang.String";
			break;
			case TokenType::blank:
			jbfile << "void";
			default:
			Error("Printing Unknown Data Type");
			break;
		}
		jbfile << ")\n";

		Trail("Println Stmt"); 
	}
    break;

  case 54:
#line 910 "y.yy"
    { 
		Trail("Read Stmt"); 
	}
    break;

  case 55:
#line 913 "y.yy"
    { 
		if(GETSCOPERETURN()!=SymbolType::none){
			Error("Return Type Unmatch: " + SymType2Str(GETSCOPERETURN()));
		}
		else {
			jbfile << "return\n";
		}
		Trail("Return Stmt"); 
	}
    break;

  case 56:
#line 922 "y.yy"
    { 
		int req = GETSCOPERETURN();
		int got = Token2Symbol((yyvsp[(3) - (4)].token).type);
		cout << SymType2Str(req) << " vs " << SymType2Str(got)<<"\n";
		if(req != got){
			Error("Return Type Unmatch: "+ SymType2Str(got) + "("
					 + SymType2Str(GETSCOPERETURN()) + ")");
		}
		else {
			switch(req){
				case SymbolType::integer:
				jbfile << "ireturn\n";	
				break;
				case SymbolType::boolean:
				break;
				case SymbolType::string:
				break;
				case SymbolType::array:
				break;
				default:
				jbfile << "return\n";	
			}
		}
		Trail("Return Stmt"); 
	}
    break;

  case 57:
#line 947 "y.yy"
    {
		jbfile << "goto L"<< (yyvsp[(6) - (9)].token)._int <<"\n";
		jbfile << "L"<< (yyvsp[(6) - (9)].token)._int - 1 << ":\nnop\n";
	}
    break;

  case 58:
#line 950 "y.yy"
    {	
		if((yyvsp[(4) - (13)].token).type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		jbfile << "L"<< (yyvsp[(6) - (13)].token)._int<< ":\nnop\n";
		Trail("If Else Stmt"); 
	}
    break;

  case 59:
#line 957 "y.yy"
    {	
		if((yyvsp[(4) - (10)].token).type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		jbfile << "L"<< (yyvsp[(6) - (10)].token)._int-1 << ":\nnop\n";
		Trail("If Stmt"); 
	}
    break;

  case 60:
#line 964 "y.yy"
    {
		//$<token>$._int = LabelIndex;
		jbfile << "L"<< LabelIndex++ <<":\nnop\n";
		(yyval.token)._int = LabelIndex++;
	}
    break;

  case 61:
#line 969 "y.yy"
    {
		if((yyvsp[(5) - (6)].token).type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		jbfile << "ifeq L"<< (yyvsp[(3) - (6)].token)._int << "\n";
	}
    break;

  case 62:
#line 975 "y.yy"
    { 
		
		jbfile << "goto L" << (yyvsp[(3) - (11)].token)._int - 1 <<endl;
		jbfile << "L" << (yyvsp[(3) - (11)].token)._int <<":\nnop\n";
		
		Trail("While Stmt"); 
	}
    break;

  case 63:
#line 982 "y.yy"
    { 
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(2) - (6)].token)._str); delete (yyvsp[(2) - (6)].token)._str;
		vector<int>* list = (std::vector<int>*)(yyvsp[(4) - (6)].token)._ptr;
		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::function){
				Error("\'" + id + "\' is not a Function") ;
			}
			else if(!matchArgs(*list,*pSD)) {
				 Error("Argument type Unmatch!");
			}
			else {
				jbfile << "invokestatic " 
					   << SymType2JBStr(pSD->symdeps[0].retType)
					   << " " + ClassName + "." + id + "( ";
				for(int i = 0 ; i < list->size();++i ){
					jbfile << SymType2JBStr((*list)[i]);
					if(i != list->size()-1){
						jbfile << ", ";
					}
				}
				jbfile << ")\n";
			}
		}
		else {
		}
		delete list;
		Trail("Function Stmt"); 
	}
    break;

  case 64:
#line 1011 "y.yy"
    { 
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(2) - (3)].token)._str); delete (yyvsp[(2) - (3)].token)._str;
		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::function){
				Error("\'" + id + "\' is not a Function") ;
			}
			else if (pSD->symdeps.size()!=1){
				Error("\'" + id + "\' needs arguments") ;	
			}
			else {
				jbfile << "invokestatic " 
					   << SymType2JBStr(pSD->symdeps[0].retType)
					   << " " + ClassName + "." + id + "()\n";
			}
		}
		else {
		}
		Trail("Function Stmt"); 
	}
    break;

  case 65:
#line 1033 "y.yy"
    {
		(yyval.token).type = TokenType::typeList;
		(yyval.token)._ptr = new vector<int>();
	}
    break;

  case 66:
#line 1037 "y.yy"
    {
		(yyval.token) = (yyvsp[(1) - (1)].token);
	}
    break;

  case 67:
#line 1041 "y.yy"
    {
		(yyval.token).type = TokenType::typeList;
		vector<int> & list = *(new vector<int>());
		list.push_back(Token2Symbol((yyvsp[(1) - (1)].token).type));
		(yyval.token)._ptr = &list;
	}
    break;

  case 68:
#line 1047 "y.yy"
    {
		(yyval.token) = (yyvsp[(1) - (3)].token);
		vector<int> & list = *(vector<int>*)(yyval.token)._ptr;
		list.push_back(Token2Symbol((yyvsp[(3) - (3)].token).type));
	}
    break;

  case 69:
#line 1054 "y.yy"
    {
		(yyval.token).type = TokenType::blank;
	}
    break;

  case 70:
#line 1057 "y.yy"
    {
		(yyval.token) = (yyvsp[(2) - (3)].token);
	}
    break;

  case 71:
#line 1060 "y.yy"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				jbfile << "iadd\n"; 
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "fadd\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				jbfile << "fadd\n";
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 72:
#line 1084 "y.yy"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				jbfile << "isub\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "fsub\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				jbfile << "fsub\n";
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 73:
#line 1108 "y.yy"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				(yyval.token)._int = (yyvsp[(1) - (3)].token)._int * (yyvsp[(3) - (3)].token)._int;
				jbfile << "imul\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "fmul\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				jbfile << "fmul\n";
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 74:
#line 1133 "y.yy"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				jbfile << "idiv\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "fdiv\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				jbfile << "fdiv\n";
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 75:
#line 1157 "y.yy"
    {
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vint;
				jbfile << "irem\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
				(yyval.token).type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "frem\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
				(yyval.token).type = TokenType::vreal;
				jbfile << "frem\n";
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 76:
#line 1181 "y.yy"
    {
		if((yyvsp[(2) - (2)].token).type == TokenType::vint){
			(yyval.token).type = TokenType::vint;
			jbfile << "ineg\n";
		}
		else if((yyvsp[(2) - (2)].token).type == TokenType::vreal){
			(yyval.token).type = TokenType::vreal;
			jbfile << "fneg\n";
		}
		else {
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 77:
#line 1195 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);	
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "iflt " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "i2f\n";
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "iflt " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "iflt " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 78:
#line 1237 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifle " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "i2f\n";
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifle " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifle " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 79:
#line 1279 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifeq " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "i2f\n";
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifeq " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifeq " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type == (yyvsp[(3) - (3)].token).type){

		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 80:
#line 1324 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifge " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "i2f\n";
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifge " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifge " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 81:
#line 1366 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifgt " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "i2f\n";
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifgt " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifgt " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 82:
#line 1408 "y.yy"
    {
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifne " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vint){
			jbfile << "i2f\n";
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifne " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vint && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if((yyvsp[(1) - (3)].token).type==TokenType::vreal && (yyvsp[(3) - (3)].token).type==TokenType::vreal){
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifne " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if((yyvsp[(1) - (3)].token).type == (yyvsp[(3) - (3)].token).type){
		}
		else{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 83:
#line 1452 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type == (yyvsp[(3) - (3)].token).type && (yyvsp[(1) - (3)].token).type == TokenType::vbool){
			jbfile << "iand\n"; 
		}
		else
		{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 84:
#line 1463 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(1) - (3)].token).type == (yyvsp[(3) - (3)].token).type && (yyvsp[(1) - (3)].token).type == TokenType::vbool){
			jbfile << "ior\n"; 
		}
		else
		{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 85:
#line 1474 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		if((yyvsp[(2) - (2)].token).type == TokenType::vbool){
			jbfile << "iconst_1\n";
			jbfile << "ixor\n";
		}
		else
		{
			(yyval.token).type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
    break;

  case 86:
#line 1486 "y.yy"
    {
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(1) - (4)].token)._str); delete (yyvsp[(1) - (4)].token)._str;
		if(seize(std::string(id),pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array (" + SymType2Str(pSD->symtype) + ")");
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

  case 87:
#line 1503 "y.yy"
    {
		SymbolDesc * pSD;
		std::string id = std::string((yyvsp[(1) - (4)].token)._str);
		delete (yyvsp[(1) - (4)].token)._str;

		if(seize(id,pSD)){
			vector<int> * list = (std::vector<int>*)(yyvsp[(3) - (4)].token)._ptr;
			if(pSD->symtype != SymbolType::function){
				Error(id + ": Is not a Function");
			}
			else if(!matchArgs(*list,*pSD)){
				Error("Argument type Unmatch");
			}
			else{
				jbfile << "invokestatic " << SymType2JBStr(pSD->symdeps[0].retType)
							+ " " + ClassName + "." + id + "( ";
				for(int i = 0 ; i < list->size();++i ){
					jbfile << SymType2JBStr((*list)[i]);
					if(i != list->size()-1){
						jbfile << ", ";
					}
				}
				jbfile << ")\n";

				(yyval.token).type = Symbol2Token(pSD->symdeps[0].retType);

				delete list;
			}
		}
		else {
			(yyval.token).type = TokenType::blank;
		}
	}
    break;

  case 88:
#line 1536 "y.yy"
    {
		SymbolDesc * pSD;
		if(seize(std::string((yyvsp[(1) - (1)].token)._str),pSD)){
			(yyval.token).type = Symbol2Token(pSD->symtype);
			if(pSD->readonly){

				switch(pSD->symtype){
					case SymbolType::integer:
					jbfile << "sipush " << pSD->symdeps[0]._int <<endl;
					(yyval.token).type = TokenType::vint;
					if(pSD->symdeps[0]._bool){
						jbfile << "iconst_1\n";
					}
					else {
						jbfile << "iconst_0\n";	
					}
					(yyval.token).type = TokenType::vbool;
					break;
					case SymbolType::boolean:
					break;
					case SymbolType::string:
					jbfile << "ldc " <<  pSD->symdeps[0]._str << "\n";
					(yyval.token).type = TokenType::vstring;
					break;
					case SymbolType::real:
					jbfile << "ldc " <<  pSD->symdeps[0]._real << "f\n";
					break;
					default:
					Error("unsupported symbol type");
					break;

				}
			}
			else {
				//If ID is a Variable.
				if(pSD->global){
					//If ID is global variable.
					jbfile << "getstatic";
					switch(pSD->symtype){
						case SymbolType::integer:
						jbfile << " int ";
						(yyval.token).type = TokenType::vint;
						break;
						case SymbolType::real:
						jbfile << " float ";
						(yyval.token).type = TokenType::vreal;
						break;
						case SymbolType::string:
						jbfile << " java.lang.String ";
						(yyval.token).type = TokenType::vstring;
						break;
						/*case SymbolType::boolean:
						jbfile << " boolean ";
						$$.type = TokenType::vbool;
						break;
						case SymbolType::array:
						jbfile << " array ";
						$$.type = TokenType::varray;
						break;*/
						default:
						Error("unsupported symbol type");
						break;
					}
					jbfile << ClassName << "." << (yyvsp[(1) - (1)].token)._str <<endl;
				}
				else{
					//If ID is local variable.
					switch(pSD->symtype){
						case SymbolType::integer:
						jbfile << "iload " << pSD->symindex << endl;
						(yyval.token).type = TokenType::vint;
						break;
						case SymbolType::real:
						jbfile << "fload " << pSD->symindex << endl;
						(yyval.token).type = TokenType::vreal;
						break;
						case SymbolType::string:
						jbfile << "aload " << pSD->symindex <<endl;
						(yyval.token).type = TokenType::vstring;
						break;
						/*case SymbolType::boolean:
						jbfile << "cload " << <<endl;
						break;
						case SymbolType::std::string:
						jbfile << "sload " << <<endl;
						break;
						case SymbolType::array:
						jbfile << "aload " << <<endl;
						break;*/
						default:
						Error("unsupported symbol type");
						break;
					}
				}
			}
		}
		else {
		}
		delete (yyvsp[(1) - (1)].token)._str;
	}
    break;

  case 89:
#line 1636 "y.yy"
    {
		(yyval.token).type = TokenType::vint;
		jbfile << "sipush " << (yyvsp[(1) - (1)].token)._int <<endl;
	}
    break;

  case 90:
#line 1640 "y.yy"
    {
		(yyval.token).type = TokenType::vreal;
		jbfile << "ldc " << (yyvsp[(1) - (1)].token)._real <<"f"<<endl;
	}
    break;

  case 91:
#line 1644 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		jbfile << "iconst_1\n";
	}
    break;

  case 92:
#line 1648 "y.yy"
    {
		(yyval.token).type = TokenType::vbool;
		jbfile << "iconst_0\n";
	}
    break;

  case 93:
#line 1652 "y.yy"
    {
		(yyval.token).type = TokenType::vstring;
		jbfile << "ldc " <<  (yyvsp[(1) - (1)].token)._str << endl;
	}
    break;


/* Line 1267 of yacc.c.  */
#line 3538 "y.tab.c"
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


#line 1659 "y.yy"

int main(int argc,char ** argv )
{

	++argv, --argc;  /* skip over program name */
	if ( argc > 0 )
	    yyin = fopen( argv[0], "r" );
	else
	    yyin = stdin;
	//
	if(argc > 1)
		jbfile.open(argv[1],ios::out);
	else 
		jbfile.open("example.jasm",ios::out);
	
	if(!yyin){
		printf("file not found.\n");
		return -1;
	}
	else if(!jbfile){
		printf("cannot open file for java byte code.\n");
		return -1;
	}

	//Global Symbol Table
	LabelIndex = 0;
	InitialTableStack();
	cout << lineno << ":";
	//Start parsing.
	yyparse();
	cout << endl << endl;
	cout << warnMsg << endl;
	cout << errorMsg << endl;
}


