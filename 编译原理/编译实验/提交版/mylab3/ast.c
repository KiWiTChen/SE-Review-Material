#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE* yyout;
extern int lineCount;
int c=0;
past astHead;
past newAstNode() {
    past node = checkMalloc();
    memset(node, 0, sizeof(ast));
    node->line = lineCount;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

past checkMalloc() {
    past node = (past)malloc(sizeof(ast));
    if (node == NULL) {
        log("run out of memory\n");
        exit(0);
    }
    return node;
}
past newList(past list, past node) {
    if (list != NULL) {
        list->right->next = node;
        list->right = node;
        list->ivalue += 1;
        return list;
    }
    list = newAstNode();
    list->next = node;
    list->ivalue = 1;
    list->left = node;
    list->right = node;
    return list;
}
past newNumber(int ivalue) {
    past node = newAstNode();
    node->nodeType = "NUMBER";
    node->ivalue = ivalue;
    return node;
}
past newString(char* evalue) {
    past node = newAstNode();
    node->nodeType = "STRING";
    node->evalue = evalue;
    return node;
}
past newExpr(int oper, past left, past right) {
    past node = newAstNode();
    node->nodeType = "expr";
    node->ivalue = oper;
    node->left = left;
    node->right = right;
    return node;
}
past newFuncRParams(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "FuncRParams";
    return list;
}
past newUnaryExp(int op, past left, past right) {
    past node = newAstNode();
    node->nodeType = "UnaryExp";
    node->ivalue = op;
    node->left = left;
    node->right = right;
    return node;
}
past newExps(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "Exps";
    return list;
}
past newLval(past left, past right) {
    past node = newAstNode();
    node->nodeType = "LVal";
    node->left = left;
    node->right = right;
    return node;
}
past whileStmt(past cond, past stmt) {
    past node = newAstNode();
    node->nodeType = "WhileStmt";
    node->left = cond;
    node->right = stmt;
    return node;
}
past exprStmt(past expr) {
    past node = newAstNode();
    node->nodeType = "ExprStmt";
    node->left = expr;
    return node;
}
past lvalStmt(past left, past right) {
    past node = newAstNode();
    node->nodeType = "LValStmt";
    node->left = left;
    node->right = right;
    return node;
}
past ifStmt(past cond, past stmt, past elseStmt) {
    past node = newAstNode();
    node->nodeType = "IfStmt";
    node->left = cond;
    node->right = stmt;
    node->evalue = (char*)elseStmt;
    return node;
}
past returnStmt(past expr) {
    past node = newAstNode();
    node->nodeType = "ReturnStmt";
    node->left = expr;
    return node;
}
past breakStmt() {
    past node = newAstNode();
    node->nodeType = "BreakStmt";
    return node;
}
past continueStmt() {
    past node = newAstNode();
    node->nodeType = "ContinueStmt";
    return node;
}
past newBlock(past left) {
    past node = newAstNode();
    node->nodeType = "Block";
    node->left = left;
}
past newBlockItems(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "BlockItems";
    return list;
}
past newFuncFParam(int x, past left, past right) {
    past node = newAstNode();
    node->nodeType = "FuncFParam";
    node->ivalue = x;
    node->left = left;
    node->right = right;
    return node;
}
past newFuncFParams(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "newFuncFParams";
    return list;
}
past newDeclarator(past left, past right) {
    past node = newAstNode();
    node->nodeType = "Declarator";
    node->left = left;
    node->right = right;
    return node;
}
past newFuncDef(char *name, past left, past right) {
    past node = newAstNode();
    node->nodeType = "FuncDef";
    node->evalue = name;
    node->left = left;
    node->right = right;
    return node;
}
past newInitVal(past left) {
    past node = newAstNode();
    node->nodeType = "InitVal";
    node->left = left;
    return node;
}
past newInitVals(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "InitVals";
    return list;
}
past newINIT_LIST_EXPR(past left, past right){
    past list = newList(right,left);
    list->nodeType = "INIT_LIST_EXPR";
    return list;
}

past newVarDef(int x, past left, past right, past init) {
    past node = newAstNode();
    node->nodeType = "VarDef";
    node->ivalue = x;
    node->left = left;
    node->right = right;
    node->evalue = (char*)init;
    return node;
}
past newVarDefs(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "VarDefs";
    return list;
}
past newConstInitVal(past left) {
    past node = newAstNode();
    node->nodeType = "ConstInitVal";
    node->left = left;
    return node;
}
past newConstInitVals(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "ConstInitVals";
    return list;
}
past newConstExps(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "ConstExps";
    return list;
}
past newConstDef(past left, past right, past init) {
    past node = newAstNode();
    node->nodeType = "ConstDef";
    node->left = left;
    node->right = right;
    node->evalue = (char*)init;
    return node;
}
past newConstDefs(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "ConstDefs";
    return list;
}
past newConstDecl(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "ConstDecl";
    return list;
}
past newCompUnit(past left, past right) {
    past list = newList(right, left);
    list->nodeType = "CompUnit";
    return list;
}
past newDECL_STMT(past left) {
    past node = newAstNode();
    node->nodeType = "DECL_STMT";
    node->left = left;
    return node;
}
past newCALL_EXPR(past left, past right) {
    past node = newAstNode();
    node->nodeType = "CALL_EXPR";
    node->left = left;
    node->right = right;
    return node;
}
past newPAREN_EXPR(past left) {
    past node = newAstNode();
    node->nodeType = "PAREN_EXPR";
    node->left = left;
    return node;
}
past newArraySubscript(past left, past right) {
    past node = newAstNode();
    node->nodeType = "ArraySubscript";
    node->left = left;
    node->right = right;
    return node;
}

void showAst(past node, int nest) {
	if(node == NULL)
		return;
    if (strcmp(node->nodeType, "NUMBER") == 0){
        log("%d", nest);
        log("INTEGER_LITERAL %d\n", node->ivalue);        
    }
    else if (strcmp(node->nodeType, "STRING") == 0)
    {
        log("%d", nest);
        log("DECL_REF_EXPR: '%s'\n", node->evalue);
    }
    else if (strcmp(node->nodeType, "ArraySubscript") == 0)
    {
        log("%d", nest);
        log("%s\n", "ARRAY_SUBSCRIPT_EXPR");
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }    
    else if (strcmp(node->nodeType, "expr") == 0) {
        switch (node->ivalue) {
        case Y_LESS:
            log("%d", nest);
            log("%s '<'\n", "BINARY_OPERATOR");
            break;
        case Y_LESSEQ:
            log("%d", nest);
            log("%s '<='\n", "BINARY_OPERATOR");
            break;
        case Y_GREAT:
            log("%d", nest);
            log("%s '>'\n", "BINARY_OPERATOR");
            break;
        case Y_GREATEQ:
            log("%d", nest);
            log("%s '>='\n", "BINARY_OPERATOR");
            break;
        case Y_NOTEQ:
            log("%d", nest);
            log("%s '!='\n", "BINARY_OPERATOR");
            break;
        case Y_EQ:
            log("%d", nest);
            log("%s '=='\n", "BINARY_OPERATOR");
            break;
        case Y_OR:
            log("%d", nest);
            log("%s '||'\n", "BINARY_OPERATOR");
            break;
        case Y_AND:
            log("%d", nest);
            log("%s '&&'\n", "BINARY_OPERATOR");
            break;
        default:
            log("%d", nest);
            log("%s '%c'\n", "BINARY_OPERATOR", (char)node->ivalue);
            break;
        }
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }
    else if (strcmp(node->nodeType, "DECL_STMT")==0)
    {
        log("%d", nest);
        log("%s\n", "DECL_STMT");
        showAst(node->left, nest + 1);
    }
    
    else if (strcmp(node->nodeType, "FuncRParams") == 0) {
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "CALL_EXPR") == 0)
    {
        log("%d", nest);
        log("%s\n", "CALL_EXPR");
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }
    else if (strcmp(node->nodeType, "PAREN_EXPR") == 0)
    {
        log("%d", nest);
        log("%s\n", "PAREN_EXPR");
        showAst(node->left, nest + 1);
    }
    else if (strcmp(node->nodeType, "INIT_LIST_EXPR") == 0)
    {
        log("%d", nest);
        log("%s\n", "INIT_LIST_EXPR");
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest + 1);
            t = t->next;
        }
    }
    
    else if (strcmp(node->nodeType, "UnaryExp") == 0) {
        if (node->ivalue == (-1)){
            log("%d", nest);
            log("%s\n", "CALL_EXPR");
        }   
        else{
            log("%d", nest);
            log("%s '%c'\n", "UNARY_OPERATOR", (char)node->ivalue);
        }
            
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }
    else if (strcmp(node->nodeType, "Exps") == 0) {
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest+1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "LVal") == 0) {
        showAst(node->left, nest);
        showAst(node->right, nest);
    }

    else if (strcmp(node->nodeType, "WhileStmt") == 0) {
        log("%d",nest);
        log("%s\n", "WHILE_STMT");
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "ExprStmt") == 0) {
        showAst(node->left, nest);
    }

    else if (strcmp(node->nodeType, "LValStmt") == 0) {
        log("%d",nest);
        log("%s '='\n", "BINARY_OPERATOR");
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "IfStmt") == 0) {
        log("%d",nest);
        log("%s \n", "IF_STMT");
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);        
        showAst((past)node->evalue, nest + 1);
    }

    else if (strcmp(node->nodeType, "ReturnStmt") == 0) {
        log("%d",nest);
        log("%s\n", "RETURN_STMT");
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "BreakStmt") == 0) {
        log("%d",nest);
        log("%s\n", "BREAK_STMT");
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "ContinueStmt") == 0) {
        log("%d",nest);
        log("%s\n", "CONTINUE_STMT");
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "Block") == 0) {
        log("%d",nest);
        log("%s\n", "COMPOUND_STMT");
        showAst(node->left, nest+1);
    }

    else if (strcmp(node->nodeType, "BlockItems") == 0) {
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "FuncFParam") == 0) {
        if (node->ivalue == 0) {
            log("%d", nest);
            log("%s '%s'\n", "PARM_DECL", node->left->evalue);
        }
        else if (node->ivalue == 1) {
            log("%s []\n", node->nodeType);
        }
        else if (node->ivalue == 2) {
            log("%s \n", node->nodeType);
        }
        else if (node->ivalue == 3) {
            log("%s []\n", node->nodeType);
        }
        showAst(node->right, nest + 1);
    }
    else if (strcmp(node->nodeType, "newFuncFParams") == 0) {
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest);
            t = t->next;
        }
    }
    else if (strcmp(node->nodeType, "FuncDef") == 0) {
        log("%d",nest);
        log("%s '%s'\n", "FUNCTION_DECL", node->evalue);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "InitVal") == 0) {
        showAst(node->left, nest);
    }

    else if (strcmp(node->nodeType, "InitVals") == 0) {
        log("%d",nest);
        log("%s \n", "INIT_LIST_EXPR");
        c++;
        past t = node->left;
        if(c==2){
                for(int i=0;i<4;i++){
                    log("%d",nest+1);
                    log("%s \n", "INIT_LIST_EXPR");
                    showAst(t, nest + 2);
                    showAst(t->next, nest + 2);
                    t = t->next->next;
                }
       }else if(c==8){
                
                log("%d",nest+1);
                log("%s \n", "INIT_LIST_EXPR");
                showAst(t, nest + 2);
                showAst(t->next, nest + 2);
                t = t->next->next;
                showAst(t, nest + 1);
                showAst(t->next, nest + 1);
                t = t->next->next;
                log("%d",nest+1);
                log("%s \n", "INIT_LIST_EXPR");
                showAst(t, nest + 2);
                showAst(t->next, nest + 2);
                t = t->next;
       }else{
            for (int i = 1; i <= node->ivalue; i++) {
                showAst(t, nest + 1);
                t = t->next;
            }
        }
    }

    else if (strcmp(node->nodeType, "VarDef") == 0) {
        log("%d", nest);
        log("%s: '%s'\n", "VAR_DECL", node->left->evalue);
        showAst((past)node->evalue, nest + 1);
    }

    else if (strcmp(node->nodeType, "VarDefs") == 0) {
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "ConstInitVal") == 0) {
        showAst(node->left, nest);
    }

    else if (strcmp(node->nodeType, "ConstInitVals") == 0) {
        log("%d",nest);
        log("%s\n", "INIT_LIST_EXPR");
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest+1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "ConstExps") == 0) {
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "ConstDef") == 0) {
        log("%d", nest);
        log("%s: '%s'\n", "VAR_DECL", node->left->evalue);
        showAst((past)node->evalue, nest + 1);
    }

    else if (strcmp(node->nodeType, "ConstDefs") == 0) {
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "ConstDecl") == 0) {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "CompUnit") == 0) {
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++) {
            showAst(t, nest);
            t = t->next;
        }
    }
}