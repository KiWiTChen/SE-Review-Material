#include<stdio.h>
#include "genllvm.h"
extern int yyparse(void);
// 错误输出
void yyerror(char* s)
{
    printf("%s\n", s);
}

int main(void)
{
    yyparse();
    // 获取根节点
    past node = getNode();
    showAst("", node, 0, 0);
    EstablishTokenTable(node);
    ProcessGlobalDecl(node);
    // 每个结点进行处理
    while (node->right != NULL) {
        //最开始处理全局变量声明：
        Process(node->left);
        node = node->right;
    }
    Process(node->left);
    return 0;
}
