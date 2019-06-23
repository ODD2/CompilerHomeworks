%{
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
%type <token> FUNC_VARS_LIST;
%type <token> FUNC_ARGS;
%type <token> FUNC_RET;
%type <token> EXPR;
%type <token> ARGS;
%type <token> ARG_LIST;
%type <token> IF_PREACT

%%
PROGRAM: 	MODULE 
 		   	ID {
 		   		jbfile << "class " << $2._str << "{\n";
 		   		ClassName = std::string($2._str);
 		   	} 
 		   	VAR_CONST_DECL FUNC_DECL 
 		   	BEG {
 		   		jbfile << "method public static void main(java.lang.String[])\n";
				jbfile << "max_stack 15\n";
				jbfile << "max_locals 15\n";
				jbfile << "{\n";

 		   	}
 		   	STMTS 
 		   	END {
 		   		jbfile << "return\n";
 		   		jbfile << "}\n";

 		   	}
 		  	ID '.' { 			
 				jbfile << "}\n";
 				Trail("Program Declaration");	
 				char * name1 = $2._str, * name2 = $11._str; 
 				if(strcmp(name1,name2)!=0){
 					Error(": begin ID != end ID");
 				}
 				delete name1,name2;
			}
			;

///////////////VARIABLE AND CONSTANT DECLARATIONS
VAR_CONST_DECL:
		| VAR_DECL
		| CONST_DECL
		| CONST_DECL VAR_DECL 
		| VAR_DECL CONST_DECL 
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

BASIC_TYPES: BOOLEAN {
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
				uDependency value;

				sd.symtype = Token2Symbol($4.type);
				sd.readonly = true;
				value.value = $4._ptr;
				sd.symdeps.push_back(value);

				insert(std::string(name),sd);
				Trail("Const Declare");
				delete name;
			 }
		|	CONST_DECL ID EQ VALUES ';'{
				char * name = $2._str; 
				SymbolDesc sd;
				uDependency value;

				sd.symtype = Token2Symbol($4.type);
				sd.readonly = true;
				value.value = $4._ptr;
				sd.symdeps.push_back(value);

				insert(std::string(name),sd);
				Trail("Const Declare");
				delete name;
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
FUNC_DECL: 
	| FUNC_DECL PROCEDURE ID 
	{
		ENTERSCOPE();
	} 
	FUNC_ARGS FUNC_RET {
		jbfile << "method public static ";
		vector<int> * varlist =(vector<int> *)$5._ptr;
		SymbolDesc * retype = (SymbolDesc*)$6._ptr; 
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

		jbfile << $3._str << "(";

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

		$<token>$._ptr = sd;
		delete varlist,retype;
		cout << ($3._str) <<endl;
		insert(std::string($3._str),*sd,1);	
	} 
	VAR_CONST_DECL BEG STMTS 
	END ID ';' {
		jbfile << "return\n";
		jbfile << "}\n\n";

		if(strcmp($3._str,$12._str)!=0){
			Error("Function ID Unmatch");
		}
		else{
			LEAVESCOPE();
			SCOPERET.pop_back();

			SymbolDesc * sd =(SymbolDesc*) $<token>7._ptr;
			Trail( dumpVar(std::string($3._str)) + "Function Declare");
		}
		delete $3._str,$12._str,(SymbolDesc*)$<token>7._ptr;
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

FUNC_VARS: 	{
		$$.type = TokenType::typeList;
		$$._ptr = new vector<int>();
	}
	| FUNC_VARS_LIST {
		$$.type = TokenType::typeList;
		$$._ptr = $1._ptr;
	}

FUNC_VARS_LIST:
	ID ':' ID_TYPE {
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
	|	FUNC_VARS ',' ID ':' ID_TYPE {
		char * name = $3._str;
		SymbolDesc * sd = (SymbolDesc*)$5._ptr;

		$$ = $1;
		((vector<int>*)$$._ptr)->push_back(sd->symtype);

		insert(std::string(name),*sd);
		delete name;
		delete sd;
	}
	;

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
ASSIGN_SYMBOL: ASSIGN
	| EQ
	;

IF_PREACT : {
		jbfile << "ifeq L"<< LabelIndex++ <<endl;
		$<token>$._int = LabelIndex++;
	}
	;

STMTS:
	| ';'
	| STMTS ID ASSIGN_SYMBOL EXPR ';'{ 
		SymbolDesc * pSD;
		if(seize(std::string($2._str),pSD)){
			if(pSD->readonly){
				Error("Assignment to Readonly Variable!");
			}
			else if(pSD->symtype != Token2Symbol($4.type)){
				Error("Type Unmatch");
			}
			else {
				if(pSD->global){
					jbfile << "putstatic " << SymType2JBStr(pSD->symtype)<<
							  " " << ClassName << "." << $2._str << "\n";
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
	| STMTS ID '[' EXPR ']' ASSIGN EXPR ';' { 
		SymbolDesc * pSD;
		std::string id = std::string($2._str);

		if(seize(id,pSD)){
			if(pSD->symtype != SymbolType::array){
				Error(id + ": Is not an Array (" + SymType2Str(pSD->symtype) + ")");
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
				Error(id + ": Is not an Array (" + SymType2Str(pSD->symtype) + ")");
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
	| STMTS PRINT {
		jbfile << "getstatic java.io.PrintStream java.lang.System.out\n";
	} EXPR ';' {
		jbfile << "invokevirtual void java.io.PrintStream.print(";
		switch($4.type){
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
	| STMTS PRINTLN {
		jbfile << "getstatic java.io.PrintStream java.lang.System.out\n";
	} EXPR ';' { 
		jbfile << "invokevirtual void java.io.PrintStream.println(";
		switch($4.type){
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
	| STMTS READ ID ';' { 
		Trail("Read Stmt"); 
	}
	| STMTS RETURN ';' { 
		if(GETSCOPERETURN()!=SymbolType::none){
			Error("Return Type Unmatch: " + SymType2Str(GETSCOPERETURN()));
		}
		else {
			jbfile << "return\n";
		}
		Trail("Return Stmt"); 
	}
	| STMTS RETURN EXPR ';' { 
		int req = GETSCOPERETURN();
		int got = Token2Symbol($3.type);
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
	| STMTS IF '(' EXPR ')' IF_PREACT THEN STMTS ELSE {
		jbfile << "goto L"<< $<token>6._int <<"\n";
		jbfile << "L"<< $<token>6._int - 1 << ":\nnop\n";
	} STMTS END ';' {	
		if($4.type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		jbfile << "L"<< $<token>6._int<< ":\nnop\n";
		Trail("If Else Stmt"); 
	}
	| STMTS IF '(' EXPR ')' IF_PREACT THEN STMTS END ';' {	
		if($4.type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		jbfile << "L"<< $<token>6._int-1 << ":\nnop\n";
		Trail("If Stmt"); 
	}
	| STMTS WHILE {
		//$<token>$._int = LabelIndex;
		jbfile << "L"<< LabelIndex++ <<":\nnop\n";
		$<token>$._int = LabelIndex++;
	}
	'(' EXPR ')' {
		if($5.type != TokenType::vbool){
			Error("Expression must be boolean");
		}
		jbfile << "ifeq L"<< $<token>3._int << "\n";
	}
	DO STMTS END ';' { 
		
		jbfile << "goto L" << $<token>3._int - 1 <<endl;
		jbfile << "L" << $<token>3._int <<":\nnop\n";
		
		Trail("While Stmt"); 
	}
	| STMTS ID '(' ARGS ')' ';' { 
		SymbolDesc * pSD;
		std::string id = std::string($2._str); delete $2._str;
		vector<int>* list = (std::vector<int>*)$4._ptr;
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
	| STMTS ID ';' { 
		SymbolDesc * pSD;
		std::string id = std::string($2._str); delete $2._str;
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
	;

ARGS: {
		$$.type = TokenType::typeList;
		$$._ptr = new vector<int>();
	}
	| ARG_LIST {
		$$ = $1;
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
	;

EXPR:{
		$$.type = TokenType::blank;
	}
	| '(' EXPR ')' %prec UNARY {
		$$ = $2;
	}
	| EXPR '+' EXPR {
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$.type = TokenType::vint;
				jbfile << "iadd\n"; 
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "fadd\n";
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				jbfile << "fadd\n";
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR '-' EXPR {
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$.type = TokenType::vint;
				jbfile << "isub\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "fsub\n";
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				jbfile << "fsub\n";
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
				jbfile << "imul\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "fmul\n";
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				jbfile << "fmul\n";
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR '/' EXPR {
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$.type = TokenType::vint;
				jbfile << "idiv\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "fdiv\n";
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				jbfile << "fdiv\n";
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR '%' EXPR {
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
				$$.type = TokenType::vint;
				jbfile << "irem\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
				$$.type = TokenType::vreal;
				jbfile << "i2f\n";
				jbfile << "frem\n";
		}
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				//UnSupported Function.
				Error("Not Supported... Real at Front Please");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
				$$.type = TokenType::vreal;
				jbfile << "frem\n";
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| '-' EXPR %prec UNARY {
		if($2.type == TokenType::vint){
			$$.type = TokenType::vint;
			jbfile << "ineg\n";
		}
		else if($2.type == TokenType::vreal){
			$$.type = TokenType::vreal;
			jbfile << "fneg\n";
		}
		else {
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR LT EXPR {
		$$.type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);	
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "iflt " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
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
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
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
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR LEQ EXPR {
		$$.type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifle " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
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
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
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
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR EQ EXPR {
		$$.type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifeq " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
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
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifeq " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if($1.type == $3.type){

		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR GEQ EXPR {
		$$.type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifge " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
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
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
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
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR GT EXPR {
		$$.type = TokenType::vbool;
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifgt " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
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
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
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
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR NEQ EXPR {
		std::string L1 = "L" + std::to_string(LabelIndex++);
		std::string L2 = "L" + std::to_string(LabelIndex++);
		$$.type = TokenType::vbool;
		if($1.type==TokenType::vint && $3.type==TokenType::vint){
			jbfile << "isub\n";
			jbfile << "ifne " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vint){
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
		else if($1.type==TokenType::vint && $3.type==TokenType::vreal){
			Error("Unsupported.Place Float Value in the front");
		}
		else if($1.type==TokenType::vreal && $3.type==TokenType::vreal){
			jbfile << "fsub\n";
			jbfile << "f2i\n";
			jbfile << "ifne " + L1 + "\n";
			jbfile << "iconst_0\n";
			jbfile << "goto "+L2 + "\n";
			jbfile << L1+":\nnop\n";
			jbfile << "iconst_1\n";
			jbfile << L2+":\nnop\n";
		}
		else if($1.type == $3.type){
		}
		else{
			$$.type = TokenType::vunknown;
			Warn("Unknown Action");
		}
	}
	| EXPR ANDL EXPR {
		$$.type = TokenType::vbool;
		if($1.type == $3.type && $1.type == TokenType::vbool){
			jbfile << "iand\n"; 
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
			jbfile << "ior\n"; 
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
			jbfile << "iconst_1\n";
			jbfile << "ixor\n";
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
				Error(id + ": Is not an Array (" + SymType2Str(pSD->symtype) + ")");
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
	| ID '(' ARGS ')' {
		SymbolDesc * pSD;
		std::string id = std::string($1._str);
		delete $1._str;

		if(seize(id,pSD)){
			vector<int> * list = (std::vector<int>*)$3._ptr;
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

				$$.type = Symbol2Token(pSD->symdeps[0].retType);

				delete list;
			}
		}
		else {
			$$.type = TokenType::blank;
		}
	}
	| ID {
		SymbolDesc * pSD;
		if(seize(std::string($1._str),pSD)){
			$$.type = Symbol2Token(pSD->symtype);
			if(pSD->readonly){

				switch(pSD->symtype){
					case SymbolType::integer:
					jbfile << "sipush " << pSD->symdeps[0]._int <<endl;
					$$.type = TokenType::vint;
					if(pSD->symdeps[0]._bool){
						jbfile << "iconst_1\n";
					}
					else {
						jbfile << "iconst_0\n";	
					}
					$$.type = TokenType::vbool;
					break;
					case SymbolType::boolean:
					break;
					case SymbolType::string:
					jbfile << "ldc " <<  pSD->symdeps[0]._str << "\n";
					$$.type = TokenType::vstring;
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
						$$.type = TokenType::vint;
						break;
						case SymbolType::real:
						jbfile << " float ";
						$$.type = TokenType::vreal;
						break;
						case SymbolType::string:
						jbfile << " java.lang.String ";
						$$.type = TokenType::vstring;
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
					jbfile << ClassName << "." << $1._str <<endl;
				}
				else{
					//If ID is local variable.
					switch(pSD->symtype){
						case SymbolType::integer:
						jbfile << "iload " << pSD->symindex << endl;
						$$.type = TokenType::vint;
						break;
						case SymbolType::real:
						jbfile << "fload " << pSD->symindex << endl;
						$$.type = TokenType::vreal;
						break;
						case SymbolType::string:
						jbfile << "aload " << pSD->symindex <<endl;
						$$.type = TokenType::vstring;
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
		delete $1._str;
	}
	| INTEGERV {
		$$.type = TokenType::vint;
		jbfile << "sipush " << $1._int <<endl;
	}
	| REALV{
		$$.type = TokenType::vreal;
		jbfile << "ldc " << $1._real <<"f"<<endl;
	}
	| TRUE {
		$$.type = TokenType::vbool;
		jbfile << "iconst_1\n";
	}
	| FALSE {
		$$.type = TokenType::vbool;
		jbfile << "iconst_0\n";
	}
	| STRINGV {
		$$.type = TokenType::vstring;
		jbfile << "ldc " <<  $1._str << endl;
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

