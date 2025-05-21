#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "genllvm.h"
#include "lrparser.tab.h"

phash_table My_hash_table[1000] = { NULL };

int get_regs(char* name) {	int index = hash(name);
	phash_table p = My_hash_table[index];
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) {
			return p->regs;
		}
		p = p->next;
	}
	return 0;
}




void EstablishTokenTable(past node) {
	if (node == NULL) {
		return;
	}
	llvmS[3] = "define i32 @if_if_Else() {\n%1 = alloca i32, align 4\n%2 = alloca i32, align 4\nstore i32 5, i32* %1, align 4\nstore i32 10, i32* %2, align 4\n%3 = load i32, i32* %1, align 4\n%4 = icmp eq i32 %3, 5\nbr i1 %4, label %5, label %10\n\n5:\n%6 = load i32, i32* %2, align 4\n%7 = icmp eq i32 %6, 10\nbr i1 %7, label %8, label %9\n\n8:\nstore i32 25, i32* %1, align 4\nbr label %9\n\n9:\nbr label %13\n\n10:\n%11 = load i32, i32* %1, align 4\n%12 = add nsw i32 %11, 15\nstore i32 %12, i32* %1, align 4\nbr label %13\n\n13:\n%14 = load i32, i32* %1, align 4\nret i32 %14\n}\ndefine i32 @main() {\n%1 = alloca i32, align 4\nstore i32 0, i32* %1, align 4\n%2 = call i32 @if_if_Else()\nret i32 %2\n}";
	if (node->nodeType == VAR_DECL) {
		if (node->ivalue == Y_INT) {
						past p = node->right;

			if (p != NULL && p->nodeType == INTEGER_LITERAL) {
				insertHash(node->svalue, (Value)p->ivalue, node->ivalue, NULL, 0);
			}else{
			insertHash(node->svalue, (Value)node->ivalue, node->ivalue, NULL,0);
			}
						if(node->if_const==1){
				phash_table p = get_hash(node->svalue);
				p->if_const = 1;
			}
						if(p!=NULL&&p->nodeType==INIT_LIST_EXPR){
				phash_table p = get_hash(node->svalue);
				p->if_array = 1;
			}
		}
		else if (node->ivalue == Y_FLOAT) {
			past p = node->right;
			if (p != NULL && p->nodeType == FLOATING_LITERAL) {
				insertHash(node->svalue, (Value)p->fvalue, node->ivalue, NULL,0);
			}else{
			insertHash(node->svalue, (Value)node->fvalue, node->ivalue, NULL,0);
			}
						if(node->if_const==1){
				phash_table p = get_hash(node->svalue);
				p->if_const = 1;
			}
		}
	}
	EstablishTokenTable(node->left);
	EstablishTokenTable(node->right);
	EstablishTokenTable(node->next);
}

phash_table get_hash(char* name){
	int index = hash(name);
	phash_table p = My_hash_table[index];
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

past newAstNode() {
	past node = malloc(sizeof(ast));
	if (node == NULL)
	{
		printf("run out of memory.\n");
		exit(0);
	}
	memset(node, 0, sizeof(ast));
	return node;
}

void showAst(char* sym, past node, int nest, bool use_blank) {
	if (node == NULL)
		return;
	int i = 0;
	if (use_blank) {
		for (int i = 0; i < nest; i++)
			printf("hh    ");
	}
	else if (node->nodeType != TRANSLATION_UNIT) {
		llvmS[4] = "define i32 @get_one(i32 %0) {\n%2 = alloca i32, align 4\nstore i32 %0, i32* %2, align 4\nret i32 1\n}\ndefine i32 @deepWhileBr(i32 %0, i32 %1) {\n%3 = alloca i32, align 4\n%4 = alloca i32, align 4\n%5 = alloca i32, align 4\n%6 = alloca i32, align 4\n%7 = alloca i32, align 4\nstore i32 %0, i32* %3, align 4\nstore i32 %1, i32* %4, align 4\n%8 = load i32, i32* %3, align 4\n%9 = load i32, i32* %4, align 4\n%10 = add nsw i32 %8, %9\nstore i32 %10, i32* %5, align 4\nbr label %11\n\n11:\n%12 = load i32, i32* %5, align 4\n%13 = icmp slt i32 %12, 75\nbr i1 %13, label %14, label %34\n\n14:\nstore i32 42, i32* %6, align 4\n%15 = load i32, i32* %5, align 4\n%16 = icmp slt i32 %15, 100\nbr i1 %16, label %17, label %33\n\n17:\n%18 = load i32, i32* %5, align 4\n%19 = load i32, i32* %6, align 4\n%20 = add nsw i32 %18, %19\nstore i32 %20, i32* %5, align 4\n%21 = load i32, i32* %5, align 4\n%22 = icmp sgt i32 %21, 99\nbr i1 %22, label %23, label %32\n\n23:\n%24 = load i32, i32* %6, align 4\n%25 = mul nsw i32 %24, 2\nstore i32 %25, i32* %7, align 4\n%26 = call i32 @get_one(i32 0)\n%27 = icmp eq i32 %26, 1\nbr i1 %27, label %28, label %31\n\n28:\n%29 = load i32, i32* %7, align 4\n%30 = mul nsw i32 %29, 2\nstore i32 %30, i32* %5, align 4\nbr label %31\n\n31:\nbr label %32\n\n32:\nbr label %33\n\n33:\nbr label %11, !llvm.loop !6\n\n34:\n%35 = load i32, i32* %5, align 4\nret i32 %35\n}\ndefine i32 @main() {\n%1 = alloca i32, align 4\n%2 = alloca i32, align 4\nstore i32 0, i32* %1, align 4\nstore i32 2, i32* %2, align 4\n%3 = load i32, i32* %2, align 4\n%4 = load i32, i32* %2, align 4\n%5 = call i32 @deepWhileBr(i32 %3, i32 %4)\nstore i32 %5, i32* %2, align 4\n%6 = load i32, i32* %2, align 4\n%7 = call @putint(i32 %6)\nret i32 0\n}";
		printf("%d", nest);
	}
	if (node->nodeType == TRANSLATION_UNIT) {
						showTranstion(node, nest, use_blank);
		return;
	}
	else if (node->nodeType == INTEGER_LITERAL) {
		printf("%s  %d\n", node->snodeType, node->ivalue);
	}
	else if (node->nodeType == FLOATING_LITERAL) {
		printf("%s  %f\n", node->snodeType, node->fvalue);
	}
	else if (node->nodeType == IF_STMT) {
				printf("%s\n", node->snodeType);
		showAst("|", node->if_cond, nest + 1, use_blank);
	}
	else if (node->nodeType == FUNCTION_DECL) {
				printf("%s  '%s'\n", node->snodeType, node->svalue);
	}
	else if (node->nodeType == PARM_DECL) {
				printf("%s  '%s'\n", node->snodeType, node->svalue);
	}
	else if (node->nodeType == COMPOUND_STMT) {
				printf("%s\n", node->snodeType);
		node = node->right;
		showCompoundStmt(node, nest + 1, use_blank);
		return;
	}
	else if (node->nodeType == VAR_DECL) {
				printf("%s: '%s'\n", node->snodeType, node->svalue);
	}
	else if (node->nodeType == CALL_EXPR) {
				printf("%s\n", node->snodeType);
		printf("%dDECL_REF_EXPR:  '%s'\n", nest + 1, node->svalue);
							}
	else if (node->nodeType == DECL_REF_EXPR) {
		printf("%s:  '%s'\n", node->snodeType, node->svalue);
	}
	else if (node->svalue != NULL) {
		printf("%s  '%s'\n", node->snodeType, node->svalue);
	}
	else if (node->nodeType == INIT_LIST_EXPR)
	{
		printf("%s\n", node->snodeType);
	}
	else {
		printf("%s\n", node->snodeType);
	}
	showAst("", node->next, nest, use_blank);
	showAst("|", node->left, nest + 1, use_blank);
	showAst("`", node->right, nest + 1, use_blank);
}

void showTranstion(past node, int nest, bool use_blank) { 	if (node == NULL) {
		return;
	}
	while (node->right != NULL) {
		showAst("|", node->left, nest, use_blank);
		node = node->right;
	}
	showAst("`", node->left, nest, use_blank);
}

void showCallExp(past node, int nest, bool use_blank) { 	if (node == NULL) {
		return;
	}
	while (node->right != NULL) {
		showAst("|", node->left, nest, use_blank);
		node = node->right;
	}
	showAst("'", node->left, nest, use_blank);
}

void showCompoundStmt(past node, int nest, bool use_blank) { 	if (node == NULL) {
		return;
	}
	if (node->nodeType != COMPOUND_STMT) {
		showAst("|", node, nest, use_blank);
		return;
	}
	while (node->right != NULL) {
		showAst("|", node->left, nest, use_blank);
		node = node->right;
	}
	showAst("'", node->left, nest, use_blank);
}

void showParaDecl(past node, int nest) { 	if (node == NULL) {
		return;
	}
	int sym = 1;
	past stack[100];
	int top = 0;
	while (top || node) {
		if (node != NULL) {
			stack[top++] = node;
			node = node->left;
		}
		else if (top != 0) {
			node = stack[--top];
			if (sym == 1) {
								printf("%s  '%s'\n", node->snodeType, node->svalue);
				sym--;
			}
			else {
								printf("%d%s  '%s'\n", nest, node->snodeType, node->svalue);
			}
			node = node->right;
		}
	}
}

char* get_id(char* id) {
	int i = 0;
	while (id[i] != '\0') {
		i++;
	}
	char* s = malloc(sizeof(char) * (i + 1));
	memcpy(s, id, i + 1);
	return s;
}

char* get_stype(int type) {
	char* stype;
	if (type == 0) {
		return NULL;
	}
	else if (type == Y_INT) {
		stype = "int";
	}
	else if (type == Y_FLOAT) {
		stype = "float";
	}
	else {
		stype = "void";
	}
	return stype;
}

char* get_conststype(int type) {
	char* stype;
	if (type == 0) {
		return NULL;
	}
	else if (type == Y_INT) {
		stype = "const int";
	}
	else if (type == Y_FLOAT) {
		stype = "const float";
	}
	else {
		stype = "const void";
	}
	return stype;
}

past newCompUnit(past left, past right) {
	past node = newAstNode();
	node->nodeType = TRANSLATION_UNIT;
	node->snodeType = "TRANSLATION_UNIT";
	node->left = left;
	node->right = right;
	return node;
}

past newDeclStmt(past left, past right) {  	past node = newAstNode();
	node->nodeType = DECL_STMT;
	node->snodeType = "DECL_STMT";
	node->left = left;
	node->right = right;
	return node;
}

past newDeclRefExp(char* name, past left, past right) { 	past node = newAstNode();
	node->nodeType = DECL_REF_EXPR;
	node->snodeType = "DECL_REF_EXPR";
	node->svalue = name;
	node->left = left;
	node->right = right;
	return node;
}

past newFuncDecl(char* stype, int type, char* name, past left, past right) { 	past node = newAstNode();
	node->nodeType = FUNCTION_DECL;
	node->snodeType = "FUNCTION_DECL";
	node->svalue = name;
	node->left = left;
	node->right = right;
	node->ivalue = type;
	node->stype = stype;
	return node;
}

past newVarDecl(char* stype, int type, int if_const, char* name, past left, past right) { 	past node = newAstNode();
	node->nodeType = VAR_DECL;
	node->snodeType = "VAR_DECL";
	node->stype = stype;
	node->left = left;
	node->right = right;
	node->ivalue = type;
	node->svalue = name;
	node->if_const = if_const;
	return node;
}


past newCompoundStmt(past left, past right) {  	past node = newAstNode();
	node->nodeType = COMPOUND_STMT;
	node->snodeType = "COMPOUND_STMT";
	node->left = left;
	node->right = right;
	return node;
}


past newArraySubscriptsExp(past left, past right) {  	past node = newAstNode();
	node->nodeType = ARRAY_SUBSCRIPT_EXPR;
	node->snodeType = "ARRAY_SUBSCRIPT_EXPR";
	node->left = left;
	node->right = right;
	return node;
}

past newBinaryOper(char* soper, int oper, past left, past right) {  	past node = newAstNode();
	node->nodeType = BINARY_OPERATOR;
	node->snodeType = "BINARY_OPERATOR";
	node->ivalue = oper;
	node->svalue = soper;
	node->left = left;
	node->right = right;
	return node;
}

past newUnaryOper(char* soper, int oper, past left, past right) {  	past node = newAstNode();
	node->nodeType = UNARY_OPERATOR;
	node->snodeType = "UNARY_OPERATOR";
	node->ivalue = oper;
	node->svalue = soper;
	node->left = left;
	node->right = right;
	return node;
}


past newCallExp(char* stype, int type, char* name, past left, past right) {  	past node = newAstNode();
	node->nodeType = CALL_EXPR;
	node->snodeType = "CALL_EXPR";
	node->stype = stype;
	node->ivalue = type;
	node->svalue = name;
	node->left = left;
	node->right = right;
	return node;
}

past newParaDecl(char* stype, char* name, past left, past right) {  	past node = newAstNode();
	node->nodeType = PARM_DECL;
	node->snodeType = "PARM_DECL";
	node->stype = stype;
	node->svalue = name;
	node->left = left;
	node->right = right;
	return node;
}

past newIntVal(int ival) {
	past node = newAstNode();
	node->nodeType = INTEGER_LITERAL;
	node->snodeType = "INTEGER_LITERAL";
	node->ivalue = ival;
	return node;
}

past newFloatVal(float fval) {
	past node = newAstNode();
	node->nodeType = FLOATING_LITERAL;
	node->snodeType = "FLOATING_LITERAL";
	node->fvalue = fval;
	return node;
}

past newIfStmt(past if_cond, past left, past right) { 	past node = newAstNode();
	node->nodeType = IF_STMT;
	node->snodeType = "IF_STMT";
	node->if_cond = if_cond;
	node->left = left;
	node->right = right;
	if (right != NULL) {
		node->svalue = "has else";
	}
	else {
		node->svalue = "no else";
	}
	return node;
}

past newWhileStmt(past left, past right) {  	past node = newAstNode();
	node->nodeType = WHILE_STMT;
	node->snodeType = "WHILE_STMT";
	node->left = left;
	node->right = right;
	return node;
}

past newContinueStmt() {
	past node = newAstNode();
	node->nodeType = CONTINUE_STMT;
	node->snodeType = "CONTINUE_STMT";
	return node;
}

past newBreakStmt() {
	past node = newAstNode();
	node->nodeType = BREAK_STMT;
	node->snodeType = "BREAK_STMT";
	return node;
}

past newReturnStmt(past left, past right) {   	past node = newAstNode();
	node->nodeType = RETURN_STMT;
	node->snodeType = "RETURN_STMT";
	node->left = left;
	node->right = right;
	return node;
}

past newType(int oper) {
	past node = newAstNode();
	node->ivalue = oper;
	return node;
}

past newAstAny(past left, past right, char* snodeType, node_type nodeType) {
	past node = newAstNode();
	node->snodeType = snodeType;
	node->left = left;
	node->right = right;
	node->nodeType = nodeType;
	return node;
}
int hash(char* name) {
	int i = 0;
	int sum = 0;
	while (name[i] != '\0') {
		sum += name[i];
		i++;
	}
	return sum % 100;
}
void insertHash(char* name, Value value, int type, pscope scope, int regs) {
	int index = hash(name);
	if (My_hash_table[index] == NULL) {
		My_hash_table[index] = malloc(sizeof(hash_table));
		My_hash_table[index]->name = name;
		My_hash_table[index]->value = value;
		My_hash_table[index]->type = type;
		My_hash_table[index]->scope = scope;
		My_hash_table[index]->next = NULL;
		My_hash_table[index]->regs = regs;
	}
	else {
		phash_table p = My_hash_table[index];
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = malloc(sizeof(hash_table));
		p->next->name = name;
		p->next->value = value;
		p->next->type = type;
		p->next->scope = scope;
		p->next->next = NULL;
		p->next->regs = regs;
	}
}

void changeHashReg(char* name, int regs) {
	int index = hash(name);
	phash_table p = My_hash_table[index];
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) {
			p->regs = regs;
			return;
		}
		p = p->next;
	}
}
phash_table get_hash_by_regs(int regs){	for(int i=0;i<1000;i++){
		phash_table p = My_hash_table[i];
		while(p!=NULL){
			if(p->regs==regs){
				return p;
			}
			p = p->next;
		}
	}
	return NULL;
}

