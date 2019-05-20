/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 158 "hw2.yacc"
{
	int boolean;
	int integer;
	double real;
	char * str;
	void * voidptr;
	VARTYPE vartype;
}
/* Line 1529 of yacc.c.  */
#line 176 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

