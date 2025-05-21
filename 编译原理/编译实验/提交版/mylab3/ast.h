#define log(format, ...) fprintf(yyout, format, ##__VA_ARGS__)
typedef struct _ast ast;
typedef struct _ast* past;
typedef struct _symtab symtab;
typedef struct _symtab* tab;
struct _ast {
	char* nodeType;
	int line;
	int ivalue;
	char* evalue;
	past left;
	past right;
	past next;
};
enum Token_T {
	num_INT = 258,
	num_FLOAT = 259,
	Y_ID = 260,
	Y_INT = 261,
	Y_VOID = 262,
	Y_CONST = 263,
	Y_IF = 264,
	Y_ELSE = 265,
	Y_WHILE = 266,
	Y_BREAK = 267,
	Y_CONTINUE = 268,
	Y_RETURN = 269,
	Y_ADD = 270,
	Y_SUB = 271,
	Y_MUL = 272,
	Y_DIV = 273,
	Y_MODULO = 274,
	Y_LESS = 275,
	Y_LESSEQ = 276,
	Y_GREAT = 277,
	Y_GREATEQ = 278,
	Y_NOTEQ = 279,
	Y_EQ = 280,
	Y_NOT = 281,
	Y_AND = 282,
	Y_OR = 283,
	Y_ASSIGN = 284,
	Y_LPAR = 285,
	Y_RPAR = 286,
	Y_LBRACKET = 287,
	Y_RBRACKET = 288,
	Y_LSQUARE = 289,
	Y_RSQUARE = 290,
	Y_COMMA = 291,
	Y_SEMICOLON = 292,
	Y_FLOAT = 293
};
extern past astHead;
extern int c;
past checkMalloc();
past newAstNode();
past newList(past list, past node);
past newID(char* evalue);
past newNumber(int ivalue);
past newString(char* evalue);
past newCompUnit(past left, past right);
past newConstDecl(past left, past right);
past newConstDefs(past left, past right);
past newConstDef(past left, past right, past init);
past newConstExps(past left, past right);
past newConstInitVals(past left, past right);
past newConstInitVal(past left);
past newVarDecl(past left);
past newVarDef(int x, past left, past right, past init);
past newVarDefs(past left, past right);
past newInitVals(past left, past right);
past newInitVal(past left);
past newFuncDef(char *name, past left, past right);
past newDeclarator(past left, past right);
past newFuncFParams(past left, past right);
past newFuncFParam(int x, past left, past right);
past newBlockItems(past left, past right);
past newBlock(past left);
past newStmt(past left, past right);
past continueStmt();
past breakStmt();
past returnStmt(past expr);
past ifStmt(past cond, past stmt, past elseStmt);
past lvalStmt(past left, past right);
past exprStmt(past expr);
past whileStmt(past cond, past stmt);
past newLval(past left, past right);
past newExps(past left, past right);
past newExpr(int oper, past left, past right);
past newUnaryExp(int op, past left, past right);
past newFuncRParams(past left, past right);
past newDECL_STMT(past left);
past newCALL_EXPR(past left, past right);
past newPAREN_EXPR(past left);
past newINIT_LIST_EXPR(past left, past right);
past newArraySubscript(past left, past right);
// past newArraySubscripts(past left, past right);
void showAst(past p, int nest);