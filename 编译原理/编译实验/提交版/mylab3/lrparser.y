%{
#include <stdio.h>
#include "ast.h"
int yylex();
void yyerror(char *);
%}

%union{
    int     iValue;
    char*   eValue;
    past    pAst;
};

%token <eValue> IDentifier
%token <iValue>	NUMBER INT VOID CONST IF ELSE WHILE BREAK CONTINUE RETURN CMP ASSIGN AND OR LESSEQ GREATEQ EQ NOTEQ
%type  <pAst>    
	Pro CompUnit Decl ConstDecl ConstDef ConstDefs ConstExps ConstInitVal VarDecl VarDef VarDefs
    InitVal InitVals ConstInitVals FuncDef FuncFParams LVal PrimaryExp
    FuncFParam Block BlockItems BlockItem Stmt Exp EqExp 
    Exps Number UnaryExp FuncRParams MulExp AddExp ConstExp Ident 
    DECL_STMT RelExp LAndExp LOrExp ArraySubscripts
%%

Pro
    : CompUnit                  { astHead = $1; }
    |                             { printf("empty\n"); }
    ;
CompUnit
    : CompUnit Decl            { $$ = newCompUnit($2, $1); }                                
    | CompUnit FuncDef         { $$ = newCompUnit($2, $1); }
    | Decl                      { $$ = newCompUnit($1, NULL); }
    | FuncDef                   { $$ = newCompUnit($1, NULL); }
    ;

Decl : ConstDecl                 { $$ = $1; }
    | VarDecl                     { $$ = $1; }
    ;

ConstDecl
    : CONST INT ConstDefs ';'            { $$ = $3; }
    ;

ConstDefs
    :ConstDef                          { $$ = newConstDefs($1,NULL); }
    |ConstDefs ',' ConstDef           { $$ = newConstDefs($3,$1); }
    ;
ConstDef
    : Ident ASSIGN ConstInitVal      { $$ = newConstDef($1, NULL, $3); }
    | Ident ConstExps ASSIGN ConstInitVal   { $$ = newConstDef($1, $2, $4); }
    ;
ConstExps
    : '[' ConstExp ']'                  { $$ = newConstExps($2, NULL); }
    | '[' ConstExp ']' ConstExps        { $$ = newConstExps($2, $4); }
    ;
ConstInitVal
    : ConstExp            { $$ = newConstInitVal($1); }
    | '{''}'    					{ $$ = newConstInitVal(NULL); }
    | '{'  ConstInitVals '}'    	{ $$ = newConstInitVal($2); }
    ;
ConstInitVals
    : ConstInitVal               { $$ = newConstInitVals($1,NULL); }
    | ConstInitVals ',' ConstInitVal  { $$ = newConstInitVals($3,$1); }
    ;
VarDecl
    : INT VarDefs  ';'             { $$ = $2; }
    ;
VarDefs
    : VarDef                        { $$ = newVarDefs($1,NULL); }
    | VarDefs ',' VarDef           { $$ = newVarDefs($3,$1); }
    ;
VarDef
    : Ident                           { $$ = newVarDef(0, $1, NULL, NULL); }
    | Ident ASSIGN InitVal           { $$ = newVarDef(1, $1, NULL, $3); }
    | Ident ConstExps                { $$ = newVarDef(2, $1, $2, NULL); }
    | Ident ConstExps ASSIGN InitVal    {  
                                            past p=$2->right;
                                            int num = p->ivalue;
                                            $$ = newVarDef(num, $1, $2, $4);              
                                        }
    ;
InitVal
    : Exp                                           { $$ = newInitVal($1); }
    | '{' '}'        								{ 
                                                        past p = newInitVal(NULL);
                                                        $$ = newInitVals(p,NULL); 
                                                    }
    | '{' InitVals '}'        				        { $$ = newInitVal($2); }
    ;
InitVals
    : InitVal                      { $$ = newInitVals($1,NULL);}
    | InitVals ',' InitVal        { $$ = newInitVals($3,$1);}
    ;
/* InitVal: Exp    { $$ = newInitVal($1); }
       | '{' '}'    { $$ = newInitVal(NULL); }
       | '{' InitVal '}'    { $$ = $2 }
       | '{' InitVal InitVals '}'   { $$ = newInitVals($2,$3);}
    ;
InitVals: ',' InitVal   { $$ = $2; }
        | ',' InitVal InitVals  { $$ = newInitVals($2,$3);}
    ; */
ArraySubscripts: Ident '[' Exp ']'    { $$ = newArraySubscript($1, $3); }
               | ArraySubscripts '[' Exp ']'  { $$ = newArraySubscript($1, $3); }
    ;
FuncDef
    : INT IDentifier '(' FuncFParams ')' Block            { $$ = newFuncDef($2, $4, $6); }
    | INT IDentifier '(' ')' Block                        { $$ = newFuncDef($2, NULL, $5); }
    | VOID IDentifier '(' FuncFParams ')' Block           { $$ = newFuncDef($2, $4, $6); }
    | VOID IDentifier '(' ')' Block                       { $$ = newFuncDef($2, NULL, $5); }
    ;
FuncFParams
    : FuncFParam                         { $$ = newFuncFParams($1, NULL); }
    | FuncFParams ',' FuncFParam       { $$ = newFuncFParams($3, $1); }
    ;
FuncFParam
    : INT Ident                          { $$ = newFuncFParam(0, $2, NULL); }
    | INT Ident '[' ']'                { $$ = newFuncFParam(1, $2, NULL); }
    | INT Ident Exps                      { $$ = newFuncFParam(2, $2, $3); }
    | INT Ident '[' ']' Exps           { $$ = newFuncFParam(3, $2, $5); }
    ;
Block    
	: '{' BlockItems '}'               	{ $$ = newBlock($2); }
    ;
BlockItems
    : BlockItem                       { $$ = newBlockItems($1, NULL); }
    | BlockItems BlockItem            { $$ = newBlockItems($2, $1); }
    ;
BlockItem : ConstDecl                 { $$ = $1; }
    | DECL_STMT                       { $$ = $1; }
    | Stmt                            { $$ = $1; }
    ;
DECL_STMT
    : VarDecl                       { $$ = newDECL_STMT($1); }
    ;
/* Stmt
    : LValStat                    	      { $$ = $1; } 
    | Block                              { $$ = $1; }
    | ExpressionStat                     { $$ = $1; }
    | IterationStat                	  { $$ = $1; }
    | SelectionStat                      { $$ = $1; }
    | ReturnStat                         { $$ = $1; }
    | BreakStat                          { $$ = $1; }
    | ContinueStat                       { $$ = $1; }
    ; */
Stmt: LVal ASSIGN Exp ';'   { $$ = lvalStmt($1,$3); }
     | ';'  { $$ = exprStmt(NULL); }
     | Exp ';'  { $$ = exprStmt($1); }
     | Block    { $$ = $1; }
     | WHILE '(' LOrExp ')' Stmt    { $$ = whileStmt($3, $5); }
     | IF '(' LOrExp ')' Stmt   { $$ = ifStmt($3, $5, NULL); }
     | IF '(' LOrExp ')' Stmt ELSE Stmt { $$ = ifStmt($3, $5, $7); }
     | BREAK ';'    { $$ = breakStmt(); }
     | CONTINUE ';' { $$ = continueStmt(); }
     | RETURN Exp ';'   { $$ = returnStmt($2); }
     | RETURN ';'   { $$ = returnStmt(NULL); }
    ;
/* SelectionStat  
    : IF '(' LOrExp ')' Stmt ElseStat       { $$ = ifStmt($3, $5, $6); }
    | IF '(' LOrExp ')' Stmt          { $$ = ifStmt($3, $5, NULL); }
    ; */
/* ElseStat
    : ELSE Stmt                       { $$ = $2; }
    ; */
/* LValStat
    : LVal ASSIGN Exp ';'            { $$ = lvalStmt($1,$3); }
    ; */
/* ExpressionStat
    : ';'                            { $$ = exprStmt(NULL); }
    | Exp ';'                       { $$ = exprStmt($1); }
    ; */

/* IterationStat
    : WHILE '(' LOrExp ')' Stmt     { $$ = whileStmt($3, $5); }
    ; */

/* ReturnStat
    : RETURN Exp ';'                 { $$ = returnStmt($2); }
    | RETURN ';'                     { $$ = returnStmt(NULL); }
    ; */
/* BreakStat
    : BREAK ';'                      { $$ = breakStmt(); }
    ; */
/* ContinueStat
    : CONTINUE ';'                   { $$ = continueStmt(); }
    ; */
Exp
    : AddExp                          { $$ = $1; }
    ; 
LVal
    : Ident                           { $$ = newLval($1, NULL); }
    | ArraySubscripts                 { $$ = newLval($1, NULL); }
    ;
Exps
    : '[' Exp ']'                		{ $$ = newExps($2, NULL); }
    | '[' Exp ']' Exps           		{ $$ = newExps($2, $4); }
    ;
PrimaryExp
    : '(' Exp ')'                     	{ $$ = newPAREN_EXPR($2); }
    | LVal                              { $$ = $1; }
    | Number                            { $$ = $1; }
    ;
Number
    : NUMBER                            { $$ = newNumber($1);  }
    ;
UnaryExp
    : PrimaryExp                        { $$ = $1; }
    | Ident '(' ')'               		{ $$ = newUnaryExp(-1, $1, NULL); }
    | Ident '(' FuncRParams ')'    	    { $$ = newUnaryExp(-1, $1, $3); }
    | '+' UnaryExp                      { $$ = newUnaryExp('+', $2, NULL); }
    | '-' UnaryExp                    	{ $$ = newUnaryExp('-', $2, NULL); }
    | '!' UnaryExp                    	{ $$ = newUnaryExp('!', $2, NULL); }
    ;
FuncRParams
    : Exp                            	{ $$ = newFuncRParams($1, NULL); }
    | FuncRParams ',' Exp             { $$ = newFuncRParams($3, $1); }
    ;
MulExp
    : UnaryExp                     		{ $$ = $1; } 
    | MulExp '*' UnaryExp        		{ $$ = newExpr('*', $1, $3); } 
    | MulExp '/' UnaryExp        		{ $$ = newExpr('/', $1, $3); } 
    | MulExp '%' UnaryExp        		{ $$ = newExpr('%', $1, $3); } 
    ;
AddExp
    : MulExp                         	{ $$ = $1; } 
    | AddExp '+' MulExp        		    { $$ = newExpr('+', $1, $3); } 
    | AddExp '-' MulExp         		{ $$ = newExpr('-', $1, $3); } 
    ;
/* EqExp
    : AddExp                         	{ $$ = $1; } 
    | EqExp CMP AddExp            		{ $$ = newExpr($2, $1, $3); }  
    ; */
RelExp: AddExp  { $$ = $1; }
      | AddExp CMP RelExp   { $$ = newExpr($2, $1, $3); }
      | AddExp LESSEQ RelExp    { $$ = newExpr($2, $1, $3); }
      | AddExp GREATEQ RelExp   { $$ = newExpr($2, $1, $3); }
    ;
EqExp: RelExp   { $$ = $1; }
     | RelExp EQ EqExp  { $$ = newExpr($2, $1, $3); }
     | RelExp NOTEQ EqExp   { $$ = newExpr($2, $1, $3); }
    ;
LAndExp: EqExp  { $$ = $1; }
        | EqExp AND LAndExp { $$ = newExpr($2, $1, $3); }
    ;
LOrExp: LAndExp { $$ = $1; }
       | LAndExp OR LOrExp  { $$ = newExpr($2, $1, $3); }
    ;
ConstExp
    : AddExp                        	{ $$ = $1; } 
    ;
Ident
    : IDentifier                   	{ $$ = newString($1); }
    ;
%%