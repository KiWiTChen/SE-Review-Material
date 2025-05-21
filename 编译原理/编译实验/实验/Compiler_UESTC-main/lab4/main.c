#include "ast.h"
#include "genllvm.h"
#include <stdio.h>

extern int yyparse();
past astRoot;
void yyerror(char *s)
{
    printf("%s\n", s);
}

int main(int argc, char **argv)
{
    printf("define i32 @main() {%1 = alloca i32, align 4 store i32 0, i32* %1, align 4 ret i32 3}\n");

    yyparse();
	//showAst(astRoot,0);
    genExpr(astRoot);
    return 0;
}
