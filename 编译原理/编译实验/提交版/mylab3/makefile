all: p clean
	
p : lrlex.c lrparser.tab.c ast.c main.c
	gcc -o p lrlex.c lrparser.tab.c ast.c main.c
lrlex.c : lrlex.l
	flex -olrlex.c lrlex.l
lrparser.tab.c : lrparser.y
	bison -d lrparser.y

clean: 
	-del /F /Q lrlex.c lrparser.tab.c lrparser.tab.h