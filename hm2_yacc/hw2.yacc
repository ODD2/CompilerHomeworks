%{
#include <iostream>
#include <stdio.h>
using namespace std;
extern "C"
{
    int yyparse(void);
    int yylex(void);
    int yywrap()
    {
        return 1;
    }

    //void yyerror(const char[]);
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
%}

%token MODULE PROCEDURE
%token BEG END 
%token EXIT RETURN
%token DO LOOP WHILE REPEAT FOR CONTINUE BREAK
%token CASE IF THEN ELSE  
%token RECORD TYPE USE
%token VAR ARRAY BOOLEAN CHAR CONST REAL STRING INTEGER
%token ID TRUE FALSE STRINGV REALV INTEGERV
%token PRINT PRINTLN UTIL FN IN READ
%token LT LEQ GT GEQ EQ NEQ
%token ANDL ORL NOTL
%token ASSIGN

%union {
	int boolean;
	int integer;
	double real;
	char * str;
}

%left ANDL ORL
%left '+' '-' NOTL
%left '*' '/' '%'  LT LEQ GT GEQ EQ NEQ
%nonassoc UNARY

%start  stmts
%%
stmts:
	| stmts boolean_expr ';' { LNPUTLN([boolean_expr]);}
	| stmts arith_expr ';' { LNPUTLN([arith_expr]);}
	| stmts int_expr ';' { LNPUTLN([int_expr]);}
	| stmts assign_expr ';' { LNPUTLN([assign_expr]);}
	| stmts print_expr ';' { LNPUTLN([print_expr]);}
	| stmts read_expr ';'
	| stmts var_sym ';' {LNPUTLN([var_expr]);}
	;

var_sym:		ID
			|	var_sym '[' int_expr ']'


arith_expr :  '(' arith_expr ')'
			| arith_expr '+' arith_expr { PUT(add);}
			| arith_expr '-' arith_expr { PUT(minus);}
			| arith_expr '*' arith_expr { PUT(product);}
			| arith_expr '/' arith_expr { PUT(divide);}
			| arith_expr '%' arith_expr { PUT(mod);}
			| '-' arith_expr %prec UNARY {PUT(unary(-));}
			| '+' arith_expr %prec UNARY {PUT(unary(+));}
			| REALV { PUT(realv);}
			| int_expr
			;
%type <real> arith_expr;


int_expr:	'(' int_expr ')'
			| int_expr '+' int_expr { PUT(add);}
			| int_expr '-' int_expr { PUT(minus);}
			| int_expr '*' int_expr { PUT(product);}
			| int_expr '/' int_expr { PUT(divide);}
			| int_expr '%' int_expr { PUT(mod);}
			| '-' int_expr %prec UNARY {PUT(unary(-));}
			| '+' int_expr %prec UNARY {PUT(unary(+));}
			| var_sym
			| INTEGERV { PUT(intv);}
			;
%type <integer> int_expr;


boolean_expr :	'(' boolean_expr ')'
			|	NOTL boolean_expr {PUT(NOTL);}
			|	boolean_expr ANDL boolean_expr {PUT(ANDL);}
			|	boolean_expr ORL boolean_expr {PUT(ORL);}
			|   arith_expr LT arith_expr {PUT(LT);}
			|   arith_expr LEQ arith_expr {PUT(LEQ);}
			|   arith_expr EQ arith_expr {PUT(EQ);}
			|   arith_expr GEQ arith_expr {PUT(GEQ);}
			|   arith_expr GT arith_expr {PUT(GT);}
			|   arith_expr NEQ arith_expr {PUT(NEQ);}
			|   TRUE {PUT(TRUE);}
			|   FALSE {PUT(FALSE);}
			|	var_sym;
			;
%type <boolean> boolean_expr;			


assign_sym:		EQ
			|	ASSIGN;

assign_expr:	var_sym assign_sym var_sym %prec UNARY {LNPUTLN([id_assign_id])}
			| 	var_sym assign_sym arith_expr {LNPUTLN([id_assign_arith])}
			|	var_sym assign_sym boolean_expr {LNPUTLN([id_assign_boolean])}
			

print_expr:		PRINT arith_expr
			|	PRINTLN arith_expr
			|	PRINT boolean_expr
			|	PRINTLN boolean_expr
			|	PRINTLN var_sym

read_expr:	READ var_sym {LNPUTLN(READ);}


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
	//Start parsing.
	yyparse();
	printf("\n");
}

