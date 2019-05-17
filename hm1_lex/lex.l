%{
#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);}
#define tokenFloat(t,i) {LIST; printf("<%s:%lf>\n",t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}

#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];
#include <stdio.h>
#include <memory.h>
#define BUCKETS 37
#define DIVISION 37


//Type Definitions
enum SYMTYPE {
	TEST,
};

typedef struct {
	char * name;
	void * next;
	void * prev;
	enum SYMTYPE type;
	void * value;
} SymbolNode;

typedef struct {
	//char * name;
	void * parent;
	SymbolNode ** TABLE;
} SymbolTable;

//Declare Functions
unsigned int str2int(char * str);
unsigned int hash(unsigned int key);
SymbolTable * create(SymbolTable * parent);
int lookup(char * name,SymbolTable * ST);
int insert(char * name,SymbolTable * ST);
void dump();


//Global Variables
SymbolTable * GLOBAL;
SymbolTable * CURRENT = NULL;
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
	token("ARRAY");
}

boolean {
	token("BOOLEAN");
}

begin {
	token("BEGIN");
}

break {
	token("BREAK");
}
char {
	token("CHAR");
}
case {
	token("CASE");
}
const {
	token("CONST");
}
continue {
	token("CONTINUE");
}
do {
	token("DO");
}
else {
	token("ELSE");
}
end {
	token("END");
}
exit {
	token("EXIT");
}
false {
	token("FALSE");
}
for {
	token("FOR");
}
fn {
	token("FN");
}
if {
	token("IF");
}
in {
	token("IN");
}
integer {
	token("INTEGER");
}
loop {
	token("LOOP");
}
module {
	token("MODULE");
}
print {
	token("PRINT");
}
println {
	token("PRINTLN");
}
procedure {
	token("PROCEDURE");
}
repeat {
	token("REPEAT");
}
return {
	token("RETURN");
}
real {
	token("REAL");
}
string {
	token("STRING");
}
record {
	token("RECORD");
}
then {
	token("THEN");
}
true {
	token("TRUE");
}
type {
	token("TYPE");
}
use {
	token("USE");
}
util {
	token("UTIL");
}
var {
	token("VAR");
}
while {
	token("WHILE");
}

 /* Delimiters */
{delims} {
	token(yytext);
}

 /* Operators */
{ops} {
	token(yytext);
}

 /* Boolean */
{boolean} {
	tokenString("boolean",yytext);
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
		tokenString("string",token);
		free(token);
		unput(c);
	}
}

 /* Numerics */
{integer} {
	int tmp;
	sscanf(yytext,"%d",&tmp);
	tokenInteger("integer",tmp)
}

{realnum} {
	double tmp;
	sscanf(yytext,"%lf",&tmp);
	tokenFloat("real",tmp)
} 
 /* Identifiers */
{id} {
	tokenString("id",yytext);
	insert(yytext,GLOBAL);
}
 /* Comments */
{lcomments} {
	LIST;
}

{bcomments} {
	LIST;
	BEGIN COMMENT;
}

 /* COMMENT state actions */
<COMMENT>{bcommente} {
	LIST;
	BEGIN INITIAL;
}
<COMMENT>. {
	LIST;
}

<COMMENT>\n {
	LIST;
	printf("%d: %s", linenum++, buf);
	buf[0] = '\0';	
}


 /* Newlines and Spaces */
\n {
	LIST;
	printf("%d: %s", linenum++, buf);
	buf[0] = '\0';
}

[ \t]* {LIST;}

 /* ERROR DETECTION */
. {
	LIST;
	printf("%d:%s\n", linenum, buf);
	printf("bad character:’%s’\n",yytext);
	exit(-1);
}

%%
//Converts ASCII string into unsigned integer key
unsigned int str2int(char * str){
	unsigned int ans = 0;
	while(*(str)!=0){
		ans = 5 * ans + *(str++);
	}
	return  ans;
}

//the DIVISION hashing
unsigned int hash(unsigned int key) {
	unsigned int index = key % BUCKETS;
	return index;
}

SymbolTable * create(SymbolTable * parent){
	SymbolTable * tmp = malloc(sizeof(SymbolTable));
	//Set Outer Scope Table;
	tmp->parent = parent;
	//Allocate Table
	tmp->TABLE =  malloc(sizeof(SymbolNode)*BUCKETS);
	//Initialize Table
	memset(tmp->TABLE , 0 ,sizeof(SymbolNode) * BUCKETS);
	return  tmp;
}
//Lookup for the symbol in a specific table;
//found returns 1;
//not found returns 0;
int lookup(char * name,SymbolTable * ST){
	unsigned int index = hash(str2int(name));
	for(SymbolNode * it = ST->TABLE[index]; it!=NULL; it = it->next){
		if(strcmp(name,it->name)==0){
			return 1;
		}
		else if(strcmp(name,it->name)>0){
			return 0;
		}
	}
	return 0;
}

//Insert a symbol in a specific table;
//Insert Success returns 1;
//Already Exists returns 0;
int insert(char * name,SymbolTable * ST){
	unsigned int index = hash(str2int(name));
	SymbolNode * ITER = ST->TABLE[index];
	if(ITER == NULL)//The Bucket is Empty!
	{
		SymbolNode * newNode  = malloc(sizeof(SymbolNode));
		newNode->name = malloc(yyleng+1);
		strcpy(newNode->name,name);
		newNode->next = NULL;
		newNode->prev = NULL;
		ST->TABLE[index] = newNode;
		return 1;
	}
	else {
		for(;ITER!=NULL; ITER = ITER->next){
			if(strcmp(name,ITER->name)==0){
				return 0;
			}
			else if(strcmp(name,ITER->name)>0){
				break;
			}
		}
		SymbolNode * newNode  = malloc(sizeof(SymbolNode));
		newNode->name = malloc(yyleng+1);
		strcpy(newNode->name,name);
		newNode->next = ITER;
		//Adjust the relationships of Neighbor Nodes.
		if(ITER->prev==NULL){//if ITER is the HEAD of the bucket;
			ST->TABLE[index] = newNode;
		}
		else {
			((SymbolNode*)ITER->prev)->next = newNode;
		}
		newNode->prev = ITER->prev;
		ITER->prev = newNode;
		return 1;
	}
}

//Dump out the GLOBAL symbol table;
void dump(){
	printf("Global Symbol:\n");
	for(int i = 0 ; i < BUCKETS ; ++ i ){
		int neednewline = 0;
		for(SymbolNode * ITER = GLOBAL->TABLE[i]; ITER!=NULL ; ITER=ITER->next){
			printf("%s ",ITER->name);		
			neednewline = 1;
		}
		if(neednewline)printf("\n");
	}
}





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
	//Initialize GLOBAL table;
	GLOBAL = create(CURRENT);
	//Start parsing.
	yylex();
	//Dump Symbol Table
	printf("\n");
	dump();
}
