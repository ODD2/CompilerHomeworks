all: lex.yy.o  y.tab.o
	g++ -o compiler -std=c11 lex.yy.o y.tab.o -ll
	cat test.modula.txt | ./compiler
scanner: lex.yy.o y.tab.o
	g++ -o scanner lex.yy.o -ll
lex.yy.o: lex.l y.tab.h
	lex lex.l
	gcc -c -g lex.yy.c
y.tab.o: y.tab.h y.tab.c
	g++ -c  y.tab.c -std=c++11
y.tab.h y.tab.c: hw2.yacc
	yacc -d -v hw2.yacc
clean:
	rm -f *.o lex.yy.c
