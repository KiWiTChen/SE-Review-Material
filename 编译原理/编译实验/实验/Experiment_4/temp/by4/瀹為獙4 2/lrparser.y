%{

#include <stdio.h>
#include "genllvm.h"
int yylex(void);
void yyerror(char *);
extern int type;
extern int array_size;
int count_size = 0;


%}

%union {
     int		token;
	int		int_value;
	float     float_value;
	char*	id_name;
	past		pAst;
};

%token <int_value> num_INT Y_INT Y_VOID  Y_CONST Y_IF Y_ELSE Y_WHILE Y_BREAK Y_CONTINUE Y_FLOAT Y_RETURN
%token <int_value> Y_ADD Y_COMMA Y_DIV  Y_LPAR Y_SUB Y_LSQUARE Y_MODULO Y_MUL Y_NOT Y_RPAR Y_RSQUARE Y_RBRACKET
%token <int_value> Y_LESS Y_LESSEQ Y_GREAT Y_GREATEQ Y_NOTEQ Y_EQ Y_AND Y_OR Y_ASSIGN Y_LBRACKET Y_SEMICOLON
%token <float_value> num_FLOAT
%token <id_name> Y_ID 
%type  <pAst>	program Exp AddExp MulExp UnaryExp CallParams PrimaryExp LVal ArraySubscripts
%type  <pAst>	Block BlockItem BlockItems Stmt RelExp EqExp LAndExp LOrExp  
%type  <pAst>	FuncDef FuncParam FuncParams Type 
%type  <pAst>  CompUnit Decl ConstDecl ConstDefs ConstDef ConstExps ConstInitVal ConstInitVals GlobalDecl GlobalConstDecl GlobalVarDecl
%type  <pAst>  VarDecl VarDecls VarDef InitVal InitVals ConstExp



%%
program: CompUnit {setNode($1); }
          ;

CompUnit: GlobalDecl CompUnit {past l = newCompUnit($1, NULL); l->right = $2; $$ = l;}
         | FuncDef CompUnit {past l = newCompUnit($1, NULL); l->right = $2; $$ = l;}
         | GlobalDecl  {$$ = newCompUnit($1, NULL);}
         | FuncDef {$$ = newCompUnit($1, NULL);}
         ;

GlobalDecl: GlobalConstDecl{$1->if_const += 3;$$ = $1;}
          | GlobalVarDecl{$1->if_const += 3;$$ = $1;}
          ;

GlobalConstDecl: Y_CONST Type ConstDef Y_SEMICOLON {$$ = $3; }
               | Y_CONST Type ConstDefs Y_SEMICOLON {$$ = $3; }
               ;

GlobalVarDecl:  Type VarDef Y_SEMICOLON {$$ = $2; }
               |Type VarDef VarDecls Y_SEMICOLON {$2->next = $3;$$ = $2; }
               ;

Decl: GlobalConstDecl
     | VarDecl
     ;

ConstDecl: Y_CONST Type ConstDef Y_SEMICOLON {$$ = newDeclStmt(NULL, $3);} 
          | Y_CONST Type ConstDefs Y_SEMICOLON {$$ = newDeclStmt(NULL, $3);}
          ;

ConstDefs: ConstDef Y_COMMA ConstDef {$1->next = $3,$$ = $1;}
          | ConstDefs Y_COMMA ConstDef {$3->next = $1;$$ = $3;}
          ;

ConstDef: Y_ID Y_ASSIGN ConstInitVal {$$ = newVarDecl(get_conststype(type), type, 1, $1, NULL, $3);}
         | Y_ID ConstExps Y_ASSIGN ConstInitVal {$$ = newVarDecl(get_conststype(type), type, 1, $1, NULL, newAstAny($4,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR)); }
         ; 

ConstExps: Y_LSQUARE ConstExp Y_RSQUARE {$$ = $2;array_size = $2->ivalue;}
         | Y_LSQUARE ConstExp Y_RSQUARE ConstExps {array_size = $4->ivalue;$2->next = $4,$$ = $2; }
         ;

ConstInitVal: ConstExp
             | Y_LBRACKET Y_RBRACKET {$$ = NULL; }
             | Y_LBRACKET ConstInitVal Y_RBRACKET {past node = $2;node = newAstAny(node,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR);$$ = node;count_size =0;}
             | Y_LBRACKET ConstInitVal ConstInitVals Y_RBRACKET {count_size++;past node = $2;node->next = $3;$$ = node;count_size =0; }
             ;
          
ConstExp: AddExp
          ;

ConstInitVals: Y_COMMA ConstInitVal {count_size++;past node = $2;$$ = node; }
              | Y_COMMA ConstInitVal ConstInitVals {count_size++;past node = $2;node->next = $3;$$ = node; }
              ;

VarDecl: Type VarDef Y_SEMICOLON {$$ = newDeclStmt(NULL, $2);} 
        | Type VarDef VarDecls Y_SEMICOLON {$$ = newDeclStmt($2, $3);}
        ;
 
VarDecls: Y_COMMA VarDef {$$ = $2;}
         |Y_COMMA VarDef VarDecls {$2->next = $3;$$ = $2;}
         ;

VarDef: Y_ID {$$ = newVarDecl(get_stype(type), type, 0, $1, NULL, NULL);}
       | Y_ID Y_ASSIGN InitVal {$$ = newVarDecl(get_stype(type), type, 0, $1, NULL, $3);}
       | Y_ID ConstExps {$$ = newVarDecl(get_stype(type), type, 0, $1, NULL, NULL); }
       | Y_ID ConstExps Y_ASSIGN InitVal {$$ = newVarDecl(get_stype(type), type, 0, $1, NULL, newAstAny($4,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR)); }
       ; 

InitVal: Exp
        | Y_LBRACKET Y_RBRACKET {$$ = NULL;}
        | Y_LBRACKET InitVal Y_RBRACKET {past node = $2;node = newAstAny(node,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR);$$ = node;count_size =0;}
        | Y_LBRACKET InitVal InitVals Y_RBRACKET {count_size++;past node = $2;node->next = $3;if(node->nodeType!=INIT_LIST_EXPR){node = newAstAny(node,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR);node->next = $3->next;$3->next=NULL;}$$ = node;count_size =0; }
        ;

InitVals: Y_COMMA InitVal {count_size++;past node = $2;$$ = node; }
         | Y_COMMA InitVal InitVals {count_size++;past node = $2;node->next = $3;if(node->nodeType==INIT_LIST_EXPR){count_size = 0;}if(count_size>=array_size && node->nodeType!=INIT_LIST_EXPR){node = newAstAny(node,NULL,"INIT_LIST_EXPR",INIT_LIST_EXPR);node->next = $3->next;$3->next = NULL;count_size=0;}$$ = node; }
         ;


FuncDef: Type Y_ID Y_LPAR Y_RPAR Block {$$ = newFuncDecl(get_stype($1->ivalue), $1->ivalue,$2, NULL, newCompoundStmt(NULL, $5));}
        | Type Y_ID Y_LPAR FuncParams Y_RPAR Block {$$ = newFuncDecl(get_stype($1->ivalue), $1->ivalue, $2, $4, newCompoundStmt(NULL, $6));}    
        ;

FuncParams: FuncParam 
           | FuncParams Y_COMMA FuncParam {past node=$1;while(node->next!=NULL) node = node->next;node->next = $3; $$ = $1;}
           ;

FuncParam: Type Y_ID {$$ = newParaDecl(get_stype($1->ivalue), $2, NULL, NULL);}
          | Type Y_ID Y_LSQUARE Y_RSQUARE {$$ = newParaDecl(get_stype($1->ivalue), $2, NULL, NULL);}
          | Type Y_ID ArraySubscripts {$$ = newParaDecl(get_stype($1->ivalue), $2, NULL, NULL);}
          | Type Y_ID Y_LSQUARE Y_RSQUARE ArraySubscripts {$$ = newParaDecl(get_stype($1->ivalue), $2, NULL, NULL);}
          ;

Type: Y_INT {yylval.int_value = Y_INT;$$ = newType(Y_INT);}
     | Y_FLOAT {yylval.int_value = Y_FLOAT;$$ = newType(Y_FLOAT);}
     | Y_VOID {yylval.int_value = Y_VOID;$$ = newType(Y_VOID);}
     ;

Stmt: LVal Y_ASSIGN Exp Y_SEMICOLON {$$ = newBinaryOper("=", Y_ASSIGN, $1, $3);}
     | Y_SEMICOLON {$$ = NULL;}
     | Exp Y_SEMICOLON {$$ = $1;}
     | Block 
     | Y_WHILE Y_LPAR LOrExp Y_RPAR Stmt {$$ = newWhileStmt($3, newCompoundStmt(NULL,$5));}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt {$$ = newIfStmt($3, $5, NULL);}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Exp Y_SEMICOLON {$$ = newIfStmt($3,$5, $7);}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Block {$$ = newIfStmt($3,$5, $7);}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_BREAK Y_SEMICOLON {$$ = newIfStmt($3,$5, newBreakStmt());}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_CONTINUE Y_SEMICOLON {$$ = newIfStmt($3,$5,newContinueStmt());}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_RETURN Exp Y_SEMICOLON {$$ = newIfStmt($3,$5,newReturnStmt($8, NULL));}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_RETURN Y_SEMICOLON {$$ = newIfStmt($3,$5,newReturnStmt(NULL, NULL));}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE LVal Y_ASSIGN Exp Y_SEMICOLON {$$ = newIfStmt($3, $5,newBinaryOper("=", Y_ASSIGN, $7, $9));}
     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_IF Y_LPAR LOrExp Y_RPAR Stmt {$$ = newIfStmt($3,$5,newIfStmt($9,$11,NULL));}

     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Stmt {$$ = newIfStmt($3,$5,newIfStmt($9,$11,$13));}
     
     | Y_BREAK Y_SEMICOLON {$$ = newBreakStmt();}
     | Y_CONTINUE Y_SEMICOLON {$$ = newContinueStmt();}
     | Y_RETURN Exp Y_SEMICOLON {$$ = newReturnStmt($2, NULL);}
     | Y_RETURN Y_SEMICOLON {$$ = newReturnStmt(NULL, NULL);}
     ;

Block: Y_LBRACKET BlockItems Y_RBRACKET {$$ = newCompoundStmt(NULL,$2);}
      | Y_LBRACKET Y_RBRACKET {$$ = NULL;}
      ;

BlockItems: BlockItem {$$ = newCompoundStmt($1, NULL);}
           | BlockItem BlockItems {past l = newCompoundStmt($1, NULL); l->right = $2; $$ = l;}
           ;

BlockItem: Decl
          | Stmt 
          ;

RelExp: AddExp
       | AddExp Y_LESS RelExp {$$ = newBinaryOper("<", Y_LESS, $1, $3);}
       | AddExp Y_GREAT RelExp {$$ = newBinaryOper(">", Y_GREAT, $1, $3);}
       | AddExp Y_LESSEQ RelExp {$$ = newBinaryOper("<=", Y_LESSEQ, $1, $3);}
       | AddExp Y_GREATEQ RelExp {$$ = newBinaryOper(">=", Y_GREATEQ, $1, $3);}
       ;

EqExp: RelExp
      | RelExp Y_EQ EqExp {$$ = newBinaryOper("==", Y_EQ, $1, $3);}
      | RelExp Y_NOTEQ EqExp {$$ = newBinaryOper("!=", Y_NOTEQ, $1, $3);}
      ;

LAndExp: EqExp 
        | EqExp Y_AND LAndExp {$$ = newBinaryOper("&&", Y_AND, $1, $3);}
        ;

LOrExp: LAndExp
       | LAndExp Y_OR LOrExp {$$ = newBinaryOper("||", Y_OR, $1, $3);}
       ;

Exp: AddExp  
     ;


AddExp: MulExp
     | AddExp Y_ADD MulExp {$$ = newBinaryOper("+", Y_ADD, $1, $3);}
     | AddExp Y_SUB MulExp {$$ = newBinaryOper("-", Y_SUB, $1, $3);}
     ;

MulExp: UnaryExp
     | MulExp Y_MUL UnaryExp {$$ = newBinaryOper("*", Y_MUL, $1, $3);}
     | MulExp Y_DIV UnaryExp {$$ = newBinaryOper("/", Y_DIV, $1, $3);}
     | MulExp Y_MODULO UnaryExp {$$ = newBinaryOper("%", Y_MODULO, $1, $3);}
     ;

UnaryExp: PrimaryExp
     | Y_ID Y_LPAR Y_RPAR {$$ = newCallExp(NULL, 0, $1, NULL, NULL);}
     | Y_ID Y_LPAR CallParams Y_RPAR {$$ = newCallExp(NULL, 0, $1, $3, NULL);}
     | Y_ADD UnaryExp {$$ = newUnaryOper("+", Y_ADD, NULL, $2);}
     | Y_SUB UnaryExp {$$ = newUnaryOper("-", Y_SUB, NULL, $2);}
     | Y_NOT UnaryExp {$$ = newUnaryOper("!", Y_NOT, NULL, $2);}
     ;

CallParams: Exp
     | Exp Y_COMMA CallParams {$1->next = $3;$$ = $1 ;}
     ;

PrimaryExp: Y_LPAR Exp Y_RPAR {past node = newAstAny($2,NULL,"PAREN_EXPR",INIT_LIST_EXPR);$$ = node;}
     | LVal 
     | num_INT {$$ = newIntVal($1);}
     | num_FLOAT {$$ = newFloatVal($1);}
     ;

LVal: Y_ID {$$ = newDeclRefExp($1, NULL, NULL);}
    | Y_ID ArraySubscripts {past node = newDeclRefExp($1,NULL,NULL);past node2 = $2;while(node2->left!=NULL) node2 = node2->left;node2->left = node;$$ = $2;}
    ;

ArraySubscripts: Y_LSQUARE Exp Y_RSQUARE {$$ = newArraySubscriptsExp(NULL,$2);}
               |ArraySubscripts Y_LSQUARE Exp Y_RSQUARE  {$$ = newArraySubscriptsExp($1, $3);}
               ;

%%
