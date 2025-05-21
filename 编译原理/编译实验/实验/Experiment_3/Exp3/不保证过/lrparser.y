%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);
past rr;
%}
%union {
	
	char 	    *sValue;
	past		pAst;
};
  
%token <sValue> ID NUMBER STRING ASSIGN CMP SCAN PRINT WHILE RETURN IF ELSE  STR VOID MUL INT EOL
%type <pAst>  program external_declaration function_definition declaration init_declarator_list init_declarator intstr_list initializer declarator direct_declarator parameter_list parameter type statement compound_statement begin_scope end_scope statement_list expression_statement selection_statement iteration_statement jump_statement print_statement scan_statement expr assign_expr cmp_expr add_expr mul_expr primary_expr expr_list id_list



%%






program: external_declaration{ $$ = newProgram($1, NULL); rr = $$; }
| program external_declaration{ $$ = newProgram($1, $2); rr = $$; }
;

external_declaration: function_definition{ $$ = $1; }
| declaration{ $$ = $1; }
;
function_definition: type declarator compound_statement{ $$ = newFunction_definition($1, $2, $3); }
;
declaration: type init_declarator_list ';' {$$ = newDeclaration($1, $2); }
					 ;
init_declarator_list: init_declarator{ $$ = $1; }
							  | init_declarator_list ',' init_declarator{ $$ = newIntstr_list($1, $3); }
init_declarator: declarator{ $$ = $1; }
							  | declarator '=' add_expr{ $$ = newInit_declarator_list($1, $3, '='); }
							  | declarator '=' '{' intstr_list '}' {$$ = newInit_declarator_list($1, $4, '='); }
							  ;
intstr_list: initializer{ $$ = $1; }
							  | intstr_list ',' initializer{ $$ = newIntstr_list($1, $3); }
							  ;
initializer: NUMBER{ $$ = newInitializer(0, $1); }
							  | STRING{ $$ = newInitializer(1, $1); }
							  ;
declarator: direct_declarator{ $$ = $1; }
							  ;
direct_declarator: ID{ $$ = newDirect(0, $1, NULL, NULL); }
									  | direct_declarator '(' parameter_list ')'{$$ = newDirect(1, "", $1, $3); }
									  | direct_declarator '(' ')' {$$ = newDirect(1, "", $1, NULL); }
									  | ID '[' expr ']'  {$$ = newDirect(0, $1, $3, NULL); }
									  | ID '[' ']' {$$ = newDirect(0, $1, NULL, NULL); }
									  ;
parameter_list: parameter{ $$ = $1; }
									  | parameter_list ',' parameter{ $$ = newParameter_list($1, $3); }
									  ;
parameter: type ID{ $$ = newParameter($1, $2); }
									  ;
type: INT{ $$ = newType(0); }
											 | STR{ $$ = newType(1); }
											 | VOID{ $$ = newType(2); }
											 ;
statement: compound_statement{ $$ = newStatement($1); }
											 | expression_statement{ $$ = newStatement($1); }
											 | selection_statement{ $$ = newStatement($1); }
											 | iteration_statement{ $$ = newStatement($1); }
											 | jump_statement{ $$ = newStatement($1); }
											 | print_statement{ $$ = newStatement($1); }
											 | scan_statement{ $$ = newStatement($1); }
											 | declaration{ $$ = newStatement($1); }
											 ;
compound_statement: begin_scope end_scope{}
											 | begin_scope statement_list end_scope{ $$ = newCompound_statement($2); }
											 ;

begin_scope: '{' {}

end_scope: '}'  {}

statement_list: statement{ $$ = newStatement_list($1, NULL); }
											 | statement_list statement{ $$ = newStatement_list($1, $2); }
											 ;
expression_statement: ';'  {$$ = NULL; }
											 | expr ';'  {$$ = newExpression_statement($1); }
											 ;
selection_statement: IF '(' expr ')' statement{ $$ = newSelection_statement($3, $5, NULL); }
											 | IF '(' expr ')' statement ELSE statement{ $$ = newSelection_statement($3, $5, $7); }
											 ;
iteration_statement: WHILE '(' expr ')' statement{ $$ = newIteration_statement($3, $5); }
											 ;
jump_statement: RETURN ';' {$$ = newJump_statement(NULL);}
              | RETURN expr ';' {$$ = newJump_statement($2);}
			;
print_statement: PRINT ';'  {$$ = newPrint_statement(NULL); }
															  | PRINT expr_list ';' {$$ = newPrint_statement($2); }
															  ;
scan_statement: SCAN id_list ';' {$$ = newScan_statement($2); }
															  ;
expr: assign_expr{ $$ = $1; }
																		  ;
assign_expr: cmp_expr{ $$ = $1; }
							| ID ASSIGN assign_expr{ $$ = newAssign_expr(0, $1, $2, $3, NULL); }
							| ID '=' assign_expr{ $$ = newAssign_expr(1, $1, "", $3, NULL); }
							| ID '[' expr ']' '=' assign_expr{ $$ = newAssign_expr(2, $1, "", $3, $6); }
							;
cmp_expr: add_expr{ $$ = $1; }
																			| cmp_expr CMP add_expr{ $$ = newCmp_expr($1, $3, $2); }
																			;

add_expr: mul_expr{ $$ = $1; }
																			| add_expr '+' mul_expr{ $$ = newAdd_expr('+', $1, $3); }
																			| add_expr '-' mul_expr{ $$ = newAdd_expr('-', $1, $3); }
																			;

mul_expr: primary_expr{ $$ = $1; }
																			| mul_expr '*' primary_expr{ $$ = newMul_expr('*', $1, $3); }
																			| mul_expr '/' primary_expr{ $$ = newMul_expr('/', $1, $3); }
																			| mul_expr '%' primary_expr{ $$ = newMul_expr('%', $1, $3); }
																			| '-' primary_expr{ $$ = newMul_expr('-', $2, NULL); }
																			;

primary_expr: ID '(' expr_list ')' {$$ = newPrimary_expr($1, $3); }
																			| ID '(' ')'    {$$ = newPrimary_expr($1, NULL); }
																			| '(' expr ')'  {$$ = $2; }
																			| ID{ $$ = newPrimary_expr($1, NULL); }
																			| initializer{ $$ = $1;}
																			| ID '[' expr ']' {$$ = newPrimary_expr($1, $3); }
																			;

expr_list: expr{ $$ = $1; }
																			| expr_list ',' expr{ $$ = newExpr_list($1, $3); }
																			;

id_list: ID{ $$ = newId_list($1, NULL); }
																			| id_list ',' ID{ $$ = newId_list($3, $1); }
																			;
%%

