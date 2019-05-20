%{
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <vector>
#include "header.h"
using namespace std;
extern "C"
{
    int yyparse(void);
    int yylex(void);
    int yywrap()
    {
        return 1;
    }
    VARTYPE idFindType(char * id_name,void ** id_varbox_container );
}

//IDLIST buffer, Variable Constructions.
vector<string> IDLIST;
bool isArray = false;
int low_range = 0;
int high_range = 0;
VARTYPE idType = IDUNKNOWN;

void InitDeclAssists(){
	isArray = false;
	low_range = 0;
	high_range = 0;
	idType = IDUNKNOWN;
}



//Symbol Table Dependencies.
union VARVALUE{
	int integer;
	double real;
	bool boolean;
	char * str;
	int * ArgTypeList;
	vector<string>* strvec;
	vector<VARTYPE> * typevec;
};

struct VARBOX{
	VARVALUE val;
	VARTYPE var_type = VARTYPE::IDUNKNOWN;
	bool is_array = false;
	bool is_constant = false;
	int position = -1;
};

struct TableChain{
	TableChain * prev;
	map<string,VARBOX> ChainTable;
};

//Symbol Tablechain
TableChain * TABLECHAIN;

//Symbol Table Manipulations
bool idFind(string id_name,VARBOX *& id_varbox);

VARTYPE idFindType(char * id_name,void ** id_varbox_container ){
	VARBOX *& id_varbox = *((VARBOX**)id_varbox_container);
	if(idFind(id_name,id_varbox)){
		return id_varbox->var_type;
	}
	return VARTYPE::IDUNKNOWN;
}

bool idFind(string id_name,VARBOX *& id_varbox){
	// cout << "idFind():\n";
	TableChain * Cur = TABLECHAIN;
	do{
		if(Cur->ChainTable.count(id_name)){
			id_varbox = &(Cur->ChainTable[id_name]);
			//cout << "Symbol Found:" << id_name << endl;
			return true;
		}
	}while((Cur = Cur->prev));

	// cout << "Symbol Not Found\n";
	id_varbox = nullptr;
	return false;
}

VARBOX& idInsert(string id_name,VARTYPE id_type,bool array = false,int lr=0,int hr=0){
	VARBOX& newID = TABLECHAIN->ChainTable[id_name];
	newID.var_type = id_type;
	newID.is_array = array;
	return newID;
}

///////DISPLAY FUNCTIONS///////
string typePrint(VARTYPE type){
	switch(type){
		case IDINT:
		return "INT";
		break;
		case IDREAL:
		return "REAL";
		break;
		case IDBOOL:
		return "BOOL";
		break;
		case IDSTR:
		return "STR";
		break;
		case IDFUNC:
		return "FUNC";
		break;
		default:
		return "ID";
		break;
	}
}

void varPrint(const string& name,const VARBOX & variable){
	cout 	<< "<"<<name 
			<< ",type:" << typePrint(variable.var_type)
			<< ",Array:" << (variable.is_array?"yes":"no")
			<< ",Const:" << (variable.is_constant?"yes":"no")
			<< ">" <<endl;
}

void tablePrint(){
	map<string,VARBOX> & printTable = TABLECHAIN->ChainTable;
	for(auto it = printTable.begin(),ed = printTable.end();it!=ed;++it){
		varPrint(it->first,it->second);
	}
}





//Extern Variables.
extern FILE *yyin;
extern int lineno;
extern int charno;
extern char buf[];
extern char * yytext;

//Yacc Required Function
void yyerror(const char *s){
   cout << buf << " (" << s  << ')' << endl;
}


#define LNPUTLN(t) {cout << #t << "\n";}
#define PUTLN(t) {cout << #t <<"\n";}
#define PUT(t) {cout << #t << " " ;}



VARBOX * VARBUFFER=nullptr;
string funcName;
%}

//Definition of YYTYPE
%union {
	int boolean;
	int integer;
	double real;
	char * str;
	void * voidptr;
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
%token TRUE FALSE <str>STRINGV <real>REALV <integer>INTEGERV
%token <str>ID INTID REALID BOOLID STRID FUNCID
%token LT LEQ GT GEQ EQ NEQ
%token ANDL ORL NOTL
%token ASSIGN
%token PRINT PRINTLN UTIL FN IN READ





%left ANDL ORL
%left '+' '-' NOTL
%left '*' '/' '%'  LT LEQ GT GEQ EQ NEQ
%nonassoc UNARY

%start PROGRAM

%%

PROGRAM : MODULE ID VAR_CONST_DECL FUNC_DECL BEG STMTS END ID '.' {
	if(strcmp($2,$8)!=0)cout << "Function ERROR" <<endl;
}

FUNC_DECL : PROCEDURE ID FUNC_ARGS FUNC_RET VAR_CONST_DECL BEGIN STMTS END ID '.' {
	if()
}



stmt: 
	|stmt vardecl {cout << "[vardecl]" <<endl;};
	|stmt constdecl{cout << "[constdecl]" <<endl;};;
	|stmt EQ EQ {
		tablePrint();
	}

test:| 
	 |test vardecl;
	 |test EQ EQ {
	 	tablePrint();
	 }



%type <boolean> BOOLV;
BOOLV:	TRUE {
			$$ = true;
		}
		|FALSE {	
			$$ = false;
		}

id_list: 	ID {
			IDLIST.push_back(string(yytext));
			}
		| 	id_list ',' ID {	
			IDLIST.push_back(string(yytext));
			}
		;

id_type: array_indicator type_indicator
		;

array_indicator:
				| ARRAY '[' INTEGERV ',' INTEGERV ']' OF {
					low_range = $3;
					high_range = $5;
					isArray = true;
				}
				;

type_indicator: {
					idType = IDUNKNOWN;
				}
				| BOOLEAN {
					idType = IDBOOL;
				}	
				| INTEGER {
					idType = IDINT;
				}
				| REAL {
					idType = IDREAL;
				}
				| STRING {
					idType = IDSTR;
				}
				;


const_list:
		  |	const_list ID EQ INTEGERV ';'{
		  	VARBOX & vb = idInsert($2,IDINT);
		  	vb.val.integer = $4;
		  	vb.is_constant = true;
		  }
		  |	const_list ID EQ REALV ';'{
		  	VARBOX& vb = idInsert($2,IDREAL);
		  	vb.val.real = $4;
		  	vb.is_constant = true;
		  }
		  |	const_list ID EQ STRINGV ';'{
		  	VARBOX& vb = idInsert($2,IDSTR);
		  	vb.val.str = $4;
		  	vb.is_constant = true;
		  }
		  |	const_list ID EQ BOOLV ';'{
		  	VARBOX& vb = idInsert($2,IDBOOL);
		  	vb.val.boolean = $4;
		  	vb.is_constant = true;
		  }

constdecl : CONST ';'
		  | CONST const_list
		  ;

//use only with vardecl
var_list:	id_list id_type {
				for(int i = 0 ; i < IDLIST.size(); ++i){
						idInsert(IDLIST[i],idType,isArray,low_range,high_range);
				}
				InitDeclAssists();
			}
			;

vardecl: 	VAR ';'
		|	VAR var_list ';'
		|	vardecl var_list ';'
		;

varstmts :	 
		|	varstmts vardecl
		|	varstmts constdecl
		;

funcdecl: PROCEDURE ID { 
			funcName = string(yytext);
		  } funcargs funcrets {

		  } varstmts BEG stmt END ID{
		  	if(funcName != string(yytext)){
		  		cout << "ERROR! NOT THE SAME END"<<endl;
		  	}
		  } ';' 
		  ;

funcargs : 
			| '(' arg_list ')'
funcrets : 
		 | ':' id_type

arnmjg_list:
		| arg_list  ID ':' id_type ',';

argsdecl:
		|	argsdecl ID ':' INTEGER ','{

		}
		|	argsdecl ID ':' INTEGER ','{

		}
		|	argsdecl ID ':' INTEGER ','{

		}
		|	argsdecl ID ':' INTEGER ','{

		}

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
	TABLECHAIN = new TableChain();
	//Start parsing.
	yyparse();
	printf("\n");
}

