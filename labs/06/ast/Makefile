all:
	flex lex-analizer.l
	yacc analyzer.y -d
	gcc lex.yy.c y.tab.c y.tab.h -o compiler

clean:
	rm y.tab.h
	rm y.tab.c
	rm lex.yy.c