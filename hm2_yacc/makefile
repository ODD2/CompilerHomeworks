all: lex.yy.o  y.tab.o
	g++ -o compiler lex.yy.o y.tab.o -ll
scanner: lex.yy.o y.tab.o
	g++ -o scanner lex.yy.o -ll

lex.yy.o: lex.l y.tab.h
	lex lex.l
	gcc -c -g lex.yy.c

y.tab.o: y.tab.h y.tab.c
	g++ -c -g y.tab.c

y.tab.h y.tab.c: hw2.yacc
	yacc -d hw2.yacc

clean:
	rm -f *.o lex.yy.c
