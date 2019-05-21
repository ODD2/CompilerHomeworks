%{
#include <stdio.h>
#include "header.h"
#include "y.tab.h"
#define DLIST     {/*strcat(buf,yytext);*/ printf("%s",yytext); charno+=yyleng;}
#define DPRINT   {/*printf("%d: %s", lineno++, buf);*/ printf("%d: ",++lineno); buf[0] = '\0';charno = 0;}
#define token(t) {DLIST printf("<%s>\n",t);}
#define tokenInteger(t,i) {DLIST printf("<%s:%d>\n",t,i);}
#define tokenFloat(t,i) {DLIST printf("<%s:%lf>\n",t,i);}
#define tokenString(t,s) {DLIST printf("<%s:%s>\n",t,s);}
#define MAX_LINE_LENG 256


 enum VARTYPE idFindType(char *,void **);
 //Global Variables
 int lineno = 1;
 int charno = 0;
 char buf[MAX_LINE_LENG];
%}

 /*define the type of yytext (pointer|array) default:pointer*/
%pointer

%x COMMENT
 /* definitions */
 	/* Delimiters */
delims [,:;()\[\]\{\}\.]
    
    /* Operators */
arthops [-/%\*\+]
relaops <|<=|>=|>|=|<>
logops "&&"|"||"|"~"
asgnops :=

ops {arthops}|{relaops}|{logops}|{asgnops}

	/* Boolean */
boolean true|false

	/* Numerics */
integer [0-9]+
realnum [+-]?{integer}"."{integer}([Ee][+-]?{integer})?
	/* Strings */
string \"[^\"]*\"
stringd \"[^\"]*\"\"[^\"]*\"

	/* Identifiers */
id  [a-zA-Z]([0-9a-zA-Z]*)

	/* Line Comments */
lcomments "//"[^\n]*
	/* Block Comments */
bcomments \(\*
bcommente \*\)

 /* Actions*/
%%
 /* Keywords */
array {
	DLIST
	return ARRAY;
}

of {
	DLIST
	return OF;
}

boolean {
	DLIST
	return BOOLEAN;
}

begin {
	DLIST
	return BEG;
}

break {
	DLIST
	return BREAK;
}
char {
	DLIST
	return CHAR;
}
case {
	DLIST
	return CASE;
}
const {
	DLIST
	return CONST;
}
continue {
	DLIST
	return CONTINUE;
}
do {
	DLIST
	return DO;
}
else {
	DLIST
	return ELSE;
}
end {
	DLIST
	return END;
}
exit {
	DLIST
	return EXIT;
}

for {
	DLIST
	return FOR;
}
fn {
	DLIST
	return FN;
}
read {
	DLIST
	return READ;
}
if {
	DLIST
	return IF;
}
in {
	DLIST
	return IN;
}
integer {
	DLIST
	return INTEGER;
}
loop {
	DLIST
	return LOOP;
}
module {
	DLIST
	return MODULE;
}
print {
	DLIST
	return PRINT;
}
println {
	DLIST
	return PRINTLN;
}
procedure {
	DLIST
	return PROCEDURE;
}
repeat {
	DLIST
	return REPEAT;
}
return {
	DLIST
	return RETURN;
}
real {
	DLIST
	return REAL;
}
string {
	DLIST
	return STRING;
}
record {
	DLIST
	return RECORD;
}
then {
	DLIST
	return THEN;
}
type {
	DLIST
	return TYPE;
}
use {
	DLIST
	return USE;
}
util {
	DLIST
	return UTIL;
}
var {
	DLIST
	return VAR;
}
while {
	DLIST
	return WHILE;
}
 /* Delimiters */
{delims} {
	DLIST
	return *yytext;
}

 /* Operators */
{arthops} {
	DLIST
	return *yytext;

}

"<" {
	DLIST
	return LT;
}

"<=" {
	DLIST
	return LEQ;
}

">=" {
	DLIST
	return GEQ;
}

">"  {
	DLIST
	return GT;
}

"=" {
	DLIST
	return EQ;
}

"<>" {
	DLIST
	return NEQ;
}

"&&" {
	DLIST
	return ANDL;
}

"||" {
	DLIST
	return  ORL;
}

"~" {
	DLIST
	return NOTL;
}

:=  {
	DLIST
	return ASSIGN;
}

 /* Boolean */
true {
	DLIST
	return TRUE;
}
false {
	DLIST
	return FALSE;
}

 /* Strings */
{string} {

	char c = input();
	if(c =='"'){
		unput(c);
		yymore();
	}
	else{
		//buffer
		DLIST
		char * token = (char*)malloc(yyleng-1);
		int i;
		for( i = 1 ; i < yyleng ; ++i){
			if(yytext[i]=='"')
			break;
		}
		if(i==yyleng-1){ //if the end of first string is the end of the string.
			strcpy(token,yytext);
		}
		else{
			strncpy(token,yytext,i);
			strcat(token,yytext+i+1);
		}
		unput(c);


		yylval.token._str = token;
		return STRINGV;
	}
}

 /* Numerics */
{integer} {
	DLIST
	sscanf(yytext,"%d",&(yylval.token._int));
 	return INTEGERV;
}

{realnum} {
	DLIST
	sscanf(yytext,"%lf",&(yylval.token._real));
	return REALV;
} 

 /* Identifiers */
{id} {
	DLIST
	yylval.token._str = (char*)malloc(yyleng+1);
	strcpy(yylval.token._str,yytext);
	return ID;
	//printf("%s(%d)\n",yytext,idFindType(yytext,&(yylval.voidptr)));
}

 /* Comments */
{lcomments} {
	DLIST
}

{bcomments} {
	DLIST
	BEGIN COMMENT;
}

 /* COMMENT state actions */
<COMMENT>{bcommente} {
	DLIST
	BEGIN INITIAL;
}
<COMMENT>. {
	DLIST
}

<COMMENT>\n {
	DLIST
	DPRINT
}


 /* Newlines and Spaces */
\n {
	DLIST
	DPRINT
	//return '\n';
}

[ \t]* {DLIST}

 /* ERROR DETECTION */
. {
	DLIST
	DPRINT
	printf("bad character:’%s’\n",yytext);
	exit(-1);
}
%%
//Converts ASCII string into unsigned integer key


//the DIVISION hashing

//Lookup for the symbol in a specific table;
//found returns 1;
//not found returns 0;


//Insert a symbol in a specific table;
//Insert Success returns 1;
//Already Exists returns 0;


//Dump out the GLOBAL symbol table;


/*int yyFlexLexer::yywrap(){
	return 1;
}*/

