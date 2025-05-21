#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"

void showAst(past node, int nest)
{
	if(node == NULL)
		return;

	int i = 0;
	if(strcmp(node->nodeType,"")!=0)
	{
		for(i = 0; i < nest; i ++)
		printf("  ");
		printf("%s %s\n", node->nodeType, node->ivalue);
	}else nest -- ;
	showAst(node->left, nest+1);
	showAst(node->right, nest+1);

}

 
past newAstNode(past l,past r,char * type)
{
	past node = malloc(sizeof(ast));
	if(node == NULL)
	{
		printf("run out of memory.\n");
		exit(0);
	}
	memset(node, 0, sizeof(ast));
	node->left = l;
	node->right = r;
	node->nodeType = type;
	return node;
}

past newProgram(past p1,past p2)
{
	past p = newAstNode(p1,p2,"program");
	
	return p;
 }
 
past newFunction_definition(past p1,past p2,past p3)
{
	p2->left = p3;
	past p = newAstNode(p1,p2,"function_definition");
	
	return p;
}
past newDeclaration(past p1,past p2)
{
	past p = newAstNode(p1,p2,"declaration");
	
	return p;
}

past newInit_list(past p1,past p2)
{
	past p = newAstNode(p1,p2,"init_declarator_list");
	
	return p;
}

past newInit_declarator_list(past p1,past p2,char c)
{
	past p = newAstNode(p1,p2,"init_declarator");
	p->ivalue[0] = c;
	p->ivalue[1] = '\0';
	
	return p; 
}

past newIntstr_list(past p1,past p2)
{
	past p = newAstNode(p1,p2,"intstr_list");
	
	return p;
}

past newInitializer(int f,char * s)
{
	past p;
	if(f==0)
	{
		p = newAstNode(NULL,NULL,"NUMBER");
		strcpy(p->ivalue,s);
	}
	else {
		p = newAstNode(NULL,NULL,"STRING");
		strcpy(p->ivalue,s);
	}
	return p;
}

past newDirect(int f,char * s,past p1,past p2)
{
	past p;
	if(f==0)
	{
		past p3 = newAstNode(NULL,NULL,"ID");
		strcpy(p3->ivalue,s);
		p = newAstNode(p3,p1,"direct_declarator");
	}else{
		p = newAstNode(p1,p2,"direct_declarator");
	}
	return p;
}

past newParameter_list(past p1,past p2)
{
	past p= newAstNode(p1,p2,"parameter_list");
	
	return p;
}

past newParameter(past p1,char *s)
{
	past p2 = newAstNode(NULL,NULL,"ID");
	strcpy(p2->ivalue,s);
	
	past p = newAstNode(p1,p2,"parameter_list");
	
	return p;
}

past newType(int f)
{
	past p;
	if(f == 0){
		p = newAstNode(NULL,NULL,"INT");
	}else if(f == 1){
		p = newAstNode(NULL,NULL,"STR");
	}else{
		p = newAstNode(NULL,NULL,"VOID");
	}
	
	return p;
}

past newStatement(past p1)
{
	past p = newAstNode(p1,NULL,"statement");
	
	return p;
}

past newCompound_statement(past p1)
{
	past p = newAstNode(p1,NULL,"compound_statement");
	
	return p;
}

past newStatement_list(past p1,past p2)
{
	past p = newAstNode(p1,p2,"statement_list");
	
	return p;
}

past newExpression_statement(past p1)
{
	past p = newAstNode(p1,NULL,"expression_statement");
	
	return p;
}

past newSelection_statement(past p1,past p2,past p3)
{
	past p = newAstNode(p1,p2,"IF");
	if(NULL == p3)
	{
		past p4 = newAstNode(NULL,NULL,"ELSE");
		p2->left = p4;
		p2->right = p3;
	}
	else{
		p2->left = p3;
	}
	
	return p;
}

past newIteration_statement(past p1,past p2)
{
	past p = newAstNode(p1,p2,"WHILE");
	
	return p;
}

past newJump_statement(past p1)
{
	past p = newAstNode(p1,NULL,"RETURN");
	
	return p;
}

past newPrint_statement(past p1)
{
	past p = newAstNode(p1,NULL,"PRINT");
	
	return p;
}

past newScan_statement(past p1)
{
	past p = newAstNode(p1,NULL,"SCAN");
	
	return p;
}
past newAssign_expr(int f,char * s1,char * s2,past p1,past p2)
{
	past p,p3;
	if(f==0)
	{
		p3 = newAstNode(NULL,NULL,"ASSIGN");
		strcpy(p3->ivalue,s2);
		p = newAstNode(p3,p1,"ID");
		strcpy(p->ivalue,s1);
	}else if (f == 1)
	{
		p3 = newAstNode(NULL,NULL,"=");
		p = newAstNode(p3,p1,"ID");
		strcpy(p->ivalue,s1);
	}else
	{
	    p3 = newAstNode(NULL,NULL,"=");
		p3->left = p2;
		p = newAstNode(p1,p3,"ID");
		strcpy(p->ivalue,s1);
	}
	
	return p;
}

past newCmp_expr(past p1,past p2,char *s)
{
	past p = newAstNode(p1,p2,"CMP_expr");
	strcpy(p->ivalue,s);
	
	return p;
}

past newAdd_expr(char c,past p1,past p2)
{
	past p = newAstNode(p1,p2,"ADD_expr");
	p->ivalue[0] = c;
	p->ivalue[1] = '\0';
	
	return p;
}

past newMul_expr(char c,past p1,past p2)
{
	past p = newAstNode(p1,p2,"MUL_expr");
	p->ivalue[0] = c;
	p->ivalue[1] = '\0';
	
	return p;
}

past newPrimary_expr(char *s,past p1)
{
	past p2 = newAstNode(NULL,NULL,"ID");
	strcpy(p2->ivalue,s);
	
	past p = newAstNode(p2,p1,"primary_expr");
	
	return p;
}

past newExpr_list(past p1,past p2)
{
	past p = newAstNode(p1,p2,"expr_list");
	
	return p;
}


past newId_list(char *s,past p1)
{
	past p2 = newAstNode(NULL,NULL,"ID");
	strcpy(p2->ivalue,s);
	
	past p = newAstNode(p1,p2,"id_list");

	return p;
}
