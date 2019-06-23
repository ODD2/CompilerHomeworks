%{
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <string.h>
#include "header.h"
using namespace std;
//#define Traail(t) printf("{"t"}");

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
#define Error(t)	{ errorMsg +="[ERROR] "+to_string(lineno)+"@"+"("+ to_string(charno)+ "): " + t + ".\n"; }
#define Warn(t)		{ warnMsg +="[WARN] "+ to_string(lineno)+"@"+"("+ to_string(charno)+ "): " + t + ".\n"; }

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




%}

//Definition of YYTYPE
%union {
	TOKEN token;
}

//TOKEN DECLARATION
%token MODULE PROCEDURE
%token BEG END 
%token EXIT RETURN
%token DO LOOP WHILE REPEAT FOR CONTINUE BREAK
%token CASE IF THEN ELSE  
%token RECORD TYPE USE
%token VAR BOOLEAN CHAR CONST REAL STRING INTEGER
%token ARRAY OF
%token <token> TRUE FALSE STRINGV REALV INTEGERV
%token <token> ID INTID REALID BOOLID STRID FUNCID
%token LT LEQ GT GEQ EQ NEQ
%token ANDL ORL NOTL
%token ASSIGN
%token PRINT PRINTLN UTIL FN IN READ





%left ANDL ORL
%left '+' '-' NOTL
%left '*' '/' '%'  LT LEQ GT GEQ EQ NEQ
%nonassoc UNARY

%start PROGRAM

%type <token> ID_LIST;
%type <token> VALUES;
%type <token> ID_TYPE;
%type <token> BASIC_TYPES;
// %type <token> FUNC_DECL;
%type <token> FUNC_VARS;
%type <token> FUNC_ARGS;
%type <token> FUNC_RET;
%type <token> EXPR;
%type <token> ARG_LIST;

%%

 PROGRAM : 	MODULE 
 		   	ID 
 		   	VAR_CONST_DECL FUNC_DECL BEG STMTS 
 		   	END
 		  	ID '.' {
 				Trail("Program Declaration");
 				
 				char * name1 = $2._str, * name2 = $8._str; 
 				if(strcmp(name1,name2)!=0){
 					Error("Module: begin ID != end ID");
 				}
 				delete name1,name2;
			}
			;

///////////////VARIABLE AND CONSTANT DECLARATIONS
VAR_CONST_DECL:
		| VAR_CONST_DECL VAR_DECL 
		| VAR_CONST_DECL CONST_DECL 
;

VAR_DECL:	VAR ';' { Trail("Var Declare"); }
		|	VAR ID_LIST  ':' ID_TYPE ';' { 
			auto idlist = (vector<std::string>*)$2._ptr;
			auto sd = (SymbolDesc *)$4._ptr;
			insert(*idlist,*sd);
			Trail("Var Declare"); 
			delete idlist,sd;
		}
		|	VAR_DECL ID_LIST ':' ID_TYPE ';' {
			auto idlist = (vector<std::string>*)$2._ptr;
			auto sd = (SymbolDesc *)$4._ptr;
			insert(*idlist,*sd);
			Trail("Var Declare"); 
			delete idlist,sd;
		}
		;

ID_LIST: 	ID {
			$$._ptr = new vector<std::string>();
			((vector<std::string>*)$$._ptr)->push_back(std::string($1._str));
		}
		| 	ID_LIST ',' ID {
			$$ = $1;
			((vector<std::string>*)$$._ptr)->push_back(std::string($3._str));
		}
		;

ID_TYPE:	ARRAY '[' INTEGERV ',' INTEGERV ']' OF BASIC_TYPES {
			SymbolDesc * sd = new SymbolDesc();
			$$.type = TokenType::idType;
			$$._ptr = sd;
			uDependency dp;
			sd->symtype =  SymbolType::array;
			dp.baseType = $8._int; sd->symdeps.push_back(dp);
			dp.low = $3._int; sd->symdeps.push_back(dp);
			dp.high = $5._int; sd->symdeps.push_back(dp);	
		}
		|	BASIC_TYPES {
			SymbolDesc * sd = new SymbolDesc();
			$$.type = TokenType::idType;
			$$._ptr = sd;
			sd->symtype = $1._int;
		}
		;

BASIC_TYPES : BOOLEAN {
				$$._int = SymbolType::boolean;
			}
			| INTEGER {
				$$._int = SymbolType::integer;
			}
			| REAL {
				$$._int = SymbolType::real;
			}
			| STRING {
				$$._int = SymbolType::string;
			}
			;

CONST_DECL:	CONST ';'{ Trail("Const Declare"); }
		|	CONST ID EQ VALUES ';'{ 
				char * name = $2._str;
				SymbolDesc sd;
				sd.symtype = SymbolType::constant;
				uDependency dp;
				dp.baseType = Token2Symbol($4.type);
				sd.symdeps.push_back(dp);

				insert(std::string(name),sd);
				Trail("Const Declare");
				delete name;
			 }
		|	CONST_DECL ID EQ VALUES ';'{
				char * name = $2._str; 
				SymbolDesc sd;
				sd.symtype = SymbolType::constant;
				uDependency dp;
				dp.baseType = Token2Symbol($4.type);
				sd.symdeps.push_back(dp);

				insert(std::string(name),sd);
				Trail("Const Declare");
				delete name;
				if(dp.baseType == SymbolType::string)delete $4._str;
			 }
		;



VALUES: INTEGERV {
		$$ = $1;
		$$.type = TokenType::vint;
	}
	|	REALV{
		$$ = $1;
		$$.type = TokenType::vreal;
	}
	|	TRUE {
		$$ = $1;
		$$.type = TokenType::vbool;
	}
	|	FALSE {
		$$ = $1;
		$$.type = TokenType::vbool;
	}
	|	STRINGV {
		$$ = $1;
		$$.type = TokenType::vstring;
	}
	;

///////////////////FUNCTION DECLARATION//////////////////
FUNC_DECL : 
	| FUNC_DECL {
		ENTERSCOPE();
	}
	PROCEDURE ID FUNC_ARGS FUNC_RET {
		//char * name1 = $4._str
		SymbolDesc * retype = (SymbolDesc*)$6._ptr; 
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
	VAR_CONST_DECL BEG STMTS 
	END ID ';' {
		char * name1 = $4._str, * name2 = $12._str;
		//SymbolDesc * retype = (SymbolDesc*)$6._ptr; 
		vector<int> * list =(vector<int> *)$5._ptr;
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

FUNC_ARGS: {
		$$.type = TokenType::typeList;
		$$._ptr = nullptr;
	}
	|  '(' FUNC_VARS ')' {
		$$ = $2;
	 // Trail("Function Variables");
	}
	;

FUNC_VARS: ID ':' ID_TYPE {
		char * name = $1._str;
		SymbolDesc * sd = (SymbolDesc*)$3._ptr;

		$$.type = TokenType::typeList;
		vector<int> * list =  new vector<int>();
		list->push_back(sd->symtype);
		$$._ptr = list;

		insert(std::string(name),*sd);
		delete name;
		delete sd;
	}
	| FUNC_VARS ',' ID ':' ID_TYPE {
		char * name = $3._str;
		SymbolDesc * sd = (SymbolDesc*)$5._ptr;

		$$ = $1;
		((vector<int>*)$$._ptr)->push_back(sd->symtype);

		insert(std::string(name),*sd);
		delete name;
		delete sd;
	}

FUNC_RET: {
		$$.type = TokenType::idType;
		$$._ptr = nullptr;
	}
	| ':' ID_TYPE {
		$$ = $2;
		// Trail("Function Return");
	}
	;
//////////////////STMT DECLARATION/////////////////////
STMTS: 
	| STMTS ID ASSIGN EXPR ';' { 
		SymbolDesc * pSD;
		if(seize(std::string($2._str),pSD)){
			if(pSD->symtype == SymbolType::constant){
				Error("Assignment to Constant!");
			}
			else if(pSD->symtype != Token2Symbol($4.type)){
				Error("Type Unmatch");
			}
			else {
			}
		}
		Trail("Assign Stmt"); 
	}
	| STMTS ID EQ EXPR ';' { 
		SymbolDesc * pSD;
		if(seize(std::string($2._str),pSD)){
			if(pSD->symtype == SymbolType::constant){
				Error("Assignment to Constant!");
			}
			else if(pSD->symtype != Token2Symbol($4.type)){
				Error("Type Unmatch");
			}
			else {

			}
		}
		else {
		}

		Trail("Assign Stmt"); 
	}
	| STMTS ID '[' EXPR ']' ASSIGN EXPR ';' { 
		SymbolDesc * pSD;
		std::string id = std::string($2._str);

		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array");
			}
			else if($4.type != TokenType::vint){
				Error("Array alloc must be integer");
			}
			else{
			}
		}
		else {
		}

		Trail("Array Assign Stmt"); 
	}
	| STMTS ID '[' EXPR ']' EQ EXPR ';' { 
		SymbolDesc * pSD;
		std::string id = std::string($2._str);

		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array");
			}
			else if($4.type != TokenType::vint){
				Error("Array alloc must be integer");
			}
			else{
			}
		}
		else {
		}

		Trail("Array Assign Stmt"); 
	}
	| STMTS PRINT EXPR ';' {
		 Trail("Print Stmt"); 
	}
	| STMTS PRINTLN EXPR ';' { 
		Trail("Println Stmt"); 
	}
	| STMTS READ ID ';' { 
		Trail("Read Stmt"); 
	}
	| STMTS RETURN ';' { 
		if(GETSCOPERETURN()!=SymbolType::none){
			Error("Return Type Unmatch: " + SymType2Str(GETSCOPERETURN()));
		}
		Trail("Return Stmt"); 
	}
	| STMTS RETURN EXPR ';' { 
		int req = GETSCOPERETURN();
		int got = Token2Symbol($3.type);
		if(req != got){
			Error("Return Type Unmatch: "+ SymType2Str(got) + "("
					 + SymType2Str(GETSCOPERETURN()) + ")");
		}
		Trail("Return Stmt"); 
	}
	| STMTS IF '(' EXPR ')' THEN STMTS ELSE STMTS END ';' {
		if($4.type != TokenType::vbool){
			Error("Expression must be boolean");
		}
	 	Trail("If Else Stmt"); 
	}
	| STMTS IF '(' EXPR ')' THEN STMTS END ';' { 
		if($4.type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		Trail("If Stmt"); 
	}
	| STMTS WHILE '(' EXPR ')' DO STMTS END ';' { 
		if($4.type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		Trail("While Stmt"); 
	}
	| STMTS ID '(' ARG_LIST ')'  ';' { 
		SymbolDesc * pSD;
		std::string id = std::string($2._str); delete $2._str;
		vector<int>* list = (std::vector<int>*)$4._ptr;
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
	| STMTS ID ';' { 
		SymbolDesc * pSD;
		std::string id = std::string($2._str); delete $2._str;
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

ARG_LIST: EXPR {
		$$.type = TokenType::typeList;
		vector<int> & list = *(new vector<int>());
		list.push_back(Token2Symbol($1.type));
		$$._ptr = &list;
	}
	| ARG_LIST ',' EXPR {
		$$ = $1;
		vector<int> & list = *(vector<int>*)$$._ptr;
		list.push_back(Token2Symbol($3.type));
	}


EXPR: '(' EXPR ')' {
		$$ = $2;
		}
	|  EXPR '+' EXPR {
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$.type = TokenType::vint;
				$$._int = $1._int + $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				$$._real = $1._real + (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._real = (double)$1._int + $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._real = $1._real + $3._real;
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR '-' EXPR {
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$.type = TokenType::vint;
				$$._int = $1._int - $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				$$._real = $1._real - (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._real = (double)$1._int - $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._real = $1._real - $3._real;
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR '*' EXPR {
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$.type = TokenType::vint;
				$$._int = $1._int * $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				$$._real = $1._real * (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._real = (double)$1._int * $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._real = $1._real * $3._real;
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR '/' EXPR {
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$.type = TokenType::vint;
				$$._int = $1._int + $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				$$._int = $1._real + (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._int = (double)$1._int + $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._int = $1._real + $3._real;
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR '%' EXPR {
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$.type = TokenType::vint;
				$$._int = $1._int % $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				$$._real = fmod($1._real,(double)$3._int);
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._real = fmod((double)$1._int,$3._real);
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				$$._real = fmod($1._real,$3._real);
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| '-' EXPR %prec UNARY {
		if($2.type == TokenType::vreal){
			$$.type = TokenType::vreal;
			$$._real = -1 * $2._real;
		}
		else if($2.type == TokenType::vint){
			$$.type = TokenType::vint;
			$$._int = -1 * $2._int;
		}
		else {
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR LT EXPR {
		$$.type = TokenType::vbool;
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$._bool = $1._int < $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$._bool = $1._real < (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$._bool = (double)$1._int < $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$._bool = $1._real < $3._real;
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR LEQ EXPR {
		$$.type = TokenType::vbool;
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$._bool = $1._int <= $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$._bool = $1._real <= (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$._bool = (double)$1._int <= $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$._bool = $1._real <= $3._real;
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR EQ EXPR {
		$$.type = TokenType::vbool;
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$._bool = $1._int == $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$._bool = $1._real == (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$._bool = (double)$1._int == $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$._bool = $1._real == $3._real;
		}
		else if($1.type == $3.type){
			if($1.type == TokenType::vstring){
				$$._bool = (strcmp($1._str,$3._str) == 0);
			}
			else{
				$$._bool = ($1._ptr != $3._ptr);	
			}
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR GEQ EXPR {
		$$.type = TokenType::vbool;
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$._bool = $1._int >= $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$._bool = $1._real >= (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$._bool = (double)$1._int >= $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$._bool = $1._real >= $3._real;
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR GT EXPR {
		$$.type = TokenType::vbool;
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$._bool = $1._int > $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$._bool = $1._real > (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$._bool = (double)$1._int > $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$._bool = $1._real > $3._real;
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR NEQ EXPR {
		$$.type = TokenType::vbool;
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$._bool = $1._int != $3._int;
		}
		else if($1.type==TokenType::vreal || $3.type==TokenType::vint){
				$$._bool = $1._real != (double)$3._int;
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$._bool = (double)$1._int != $3._real;
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$._bool = $1._real != $3._real;
		}
		else if($1.type == $3.type){
			if($1.type == TokenType::vstring){
				$$._bool = !(strcmp($1._str,$3._str) == 0);
			}
			else{
				$$._bool = !($1._ptr != $3._ptr);	
			}
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR ANDL EXPR {
		$$.type = TokenType::vbool;
		if($1.type == $3.type && $1.type == TokenType::vbool){
			$$._bool = $1._bool && $3._bool;
		}
		else
		{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR ORL EXPR {
		$$.type = TokenType::vbool;
		if($1.type == $3.type && $1.type == TokenType::vbool){
			$$._bool = $1._bool || $3._bool;
		}
		else
		{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| NOTL EXPR %prec UNARY {
		$$.type = TokenType::vbool;
		if($2.type == TokenType::vbool){
			$$._bool = !($2._bool);
		}
		else
		{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| ID '[' EXPR ']' {
		SymbolDesc * pSD;
		std::string id = std::string($1._str); delete $1._str;
		if(seize(std::string(id),pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array");
			}
			else if($3.type != TokenType::vint){
				Error("Array alloc must be integer");
			}
			else{
				$$.type = Symbol2Token(pSD->symdeps[0].baseType);
			}
		}
		else {
		}
	}
	| ID '(' ARG_LIST ')' {
		SymbolDesc * pSD;
		std::string id = std::string($1._str);delete $1._str;
		if(seize(std::string(id),pSD)){
			vector<int>& list = *(std::vector<int>*)$3._ptr;
			if(pSD->symtype != SymbolType::function){
				Error(id + ": Is not a Array");
			}
			else if(!matchArgs(list,*pSD)){
				Error("Argument type Unmatch");
			}
			else{
				$$.type = Symbol2Token(pSD->symdeps[0].retType);
			}
		}
		else {
		}
	}
	| ID {
		SymbolDesc * pSD;
		if(seize(std::string($1._str),pSD)){
			$$.type = Symbol2Token(pSD->symtype);
		}
		else {
			// cout << "NO SUCH ID";
		}
		delete $1._str;
	}
	| INTEGERV {
		$$.type = TokenType::vint;
		$$._int = $1._int;
	}
	| REALV{
		$$.type = TokenType::vreal;
		$$._real = $1._real;
	}
	| TRUE {
		$$.type = TokenType::vbool;
		$$._bool = true;
	}
	| FALSE {
		$$.type = TokenType::vbool;
		$$._bool = false;
	}
	| STRINGV {
		$$.type = TokenType::vstring;
		$$._str = $1._str;
	}
;

%%
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

