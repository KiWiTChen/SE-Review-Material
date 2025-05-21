#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _ast ast;
typedef struct _ast *past;

struct _ast{
	char ivalue[20];
	char* nodeType;
	past left;
	past right;
};

void showAst(past node, int nest);
past newProgram(past p1, past p2);
past newAstNode(past l, past r, char * type);
past newFunction_definition(past p1, past p2, past p3);
past newDeclaration(past p1, past p2);
past newInit_list(past p1, past p2);
past newInit_declarator_list(past p1, past p2, char c);
past newIntstr_list(past p1, past p2);
past newInitializer(int f, char * s);
past newDirect(int f, char * s, past p1, past p2);
past newParameter_list(past p1, past p2);
past newParameter(past p1, char *s);
past newType(int f);
past newStatement(past p1);
past newCompound_statement(past p1);
past newStatement_list(past p1, past p2);
past newExpression_statement(past p1);
past newSelection_statement(past p1, past p2, past p3);
past newIteration_statement(past p1, past p2);
past newJump_statement(past p1);
past newPrint_statement(past p1);
past newScan_statement(past p1);
past newAssign_expr(int f, char * s1, char * s2, past p1, past p2);
past newCmp_expr(past p1, past p2, char *s);
past newAdd_expr(char c, past p1, past p2);
past newMul_expr(char c, past p1, past p2);
past newPrimary_expr(char *s, past p1);
past newExpr_list(past p1, past p2);
past newId_list(char *s, past p1);

