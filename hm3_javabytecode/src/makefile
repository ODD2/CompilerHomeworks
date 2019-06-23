CC=g++
JAVA=java6
JAVAA=../javaa
LEX=lex
YACC=yacc
C=gcc
all: lex.yy.o  y.tab.o
	$(CC) -o compiler -std=c11 lex.yy.o y.tab.o -ll
	./compiler Bonus4.modula example.out
	$(JAVAA) example.out
scanner: lex.yy.o y.tab.o
	$(CC) -o scanner lex.yy.o -ll
lex.yy.o: lex.l y.tab.h
	$(LEX) lex.l
	$(C) -c -g lex.yy.c
y.tab.o: y.tab.h y.tab.c
	$(CC) -c  y.tab.c -std=c++11
y.tab.h y.tab.c: y.yy
	$(YACC) -d -v y.yy
clean:
	rm -f *.o lex.yy.c
	rm -f *.class
	rm -f *.output
	rm -f y.tab.c y.tab.h
