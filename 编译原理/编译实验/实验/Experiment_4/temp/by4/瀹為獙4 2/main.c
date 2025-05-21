#include<stdio.h>
#include "genllvm.h"
extern int yyparse(void);
void yyerror(char* s)
{
    printf("%s\n", s);
}

int main(void)
{
    yyparse();
    past node = getNode();
    showAst("", node, 0, 0);
    EstablishTokenTable(node);
    ProcessGlobalDecl(node);
    while (node->right != NULL) {
        //最开始处理全局变量声明：
        Process(node->left);
        node = node->right;
    }
    Process(node->left);
    return 0;
}
