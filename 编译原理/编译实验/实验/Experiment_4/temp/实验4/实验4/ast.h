#include <stdbool.h>
#ifndef COMPILER_LAB_NODE_TYPE_H
#define COMPILER_LAB_NODE_TYPE_H

enum _node_type{

	// A declaration whose specific kind is not exposed via this interface
	//

	// A C or C++ struct
	STRUCT_DECL = 2,

	// A C or C++ union
	UNION_DECL = 3,

	// An enumeration
	ENUM_DECL = 5,

	// A field in C, or non-static data member in C++, in a struct, union, or C++
	// class
	FIELD_DECL = 6,

	// An enumerator constant
	ENUM_CONSTANT_DECL = 7,

	// A function
	FUNCTION_DECL = 8,

	// A variable
	VAR_DECL = 9,

	// A function or method parameter
	PARM_DECL = 10,


	// A typedef
	TYPEDEF_DECL = 20,

	// A Type alias decl
	TYPE_ALIAS_DECL = 36,


	// A reference to a member of a struct, union, or class that occurs in
	// some non-expression context, eg, a designated initializer
	MEMBER_REF = 47,

	// A reference to a labeled statement
	LABEL_REF = 48,

	// A reference to a set of overloaded functions or function templates
	// that has not yet been resolved to a specific function or function template
	OVERLOADED_DECL_REF = 49,

	// A reference to a variable that occurs in some non-expression
	// context, eg, a C++ lambda capture list
	VARIABLE_REF = 50,


	//////
	// Invalid/Error Kinds

	INVALID_FILE = 70,
	NO_DECL_FOUND = 71,
	NOT_IMPLEMENTED = 72,
	INVALID_CODE = 73,
	

	//////
	// Expression Kinds

	// An expression whose specific kind is not exposed via this interface
	//
	// Unexposed expressions have the same operations as any other kind of
	// expression; one can extract their location information, spelling, children,
	// etc However, the specific kind of the expression is not reported
	UNEXPOSED_EXPR = 100,

	// An expression that refers to some value declaration, such as a function,
	// variable, or enumerator
	DECL_REF_EXPR = 101,

	// An expression that refers to a member of a struct, union, class, Objective-C
	// class, etc
	MEMBER_REF_EXPR = 102,

	// An expression that calls a function
	CALL_EXPR = 103,


	// An expression that represents a block literal
	BLOCK_EXPR = 105,

	// An integer literal
	INTEGER_LITERAL = 106,

	// A floating point number literal
	FLOATING_LITERAL = 107,

	// An imaginary number literal
	IMAGINARY_LITERAL = 108,

	// A string literal
	STRING_LITERAL = 109,

	// A character literal
	CHARACTER_LITERAL = 110,

	// A parenthesized expression, eg "1,"
	//
	// This AST node is only formed if full location information is requested
	PAREN_EXPR = 111,

	// This represents the unary-expression's except sizeof and
	// alignof,
	UNARY_OPERATOR = 112,

	// [C99 6521] Array Subscripting
	ARRAY_SUBSCRIPT_EXPR = 113,

	// A builtin binary operation expression such as "x + y" or
	// "x <= y"
	BINARY_OPERATOR = 114,

	// Compound assignment such as "+="
	COMPOUND_ASSIGNMENT_OPERATOR = 115,

	// The ?: ternary operator
	CONDITIONAL_OPERATOR = 116,

	// An explicit cast in C C99 654, or a C-style cast in C++
	// C++ [exprcast],, which uses the syntax Type,expr
	//
	// For example: int,f
	CSTYLE_CAST_EXPR = 117,

	// [C99 6525]
	COMPOUND_LITERAL_EXPR = 118,

	// Describes an C or C++ initializer list
	INIT_LIST_EXPR = 119,

	// The GNU address of label extension, representing &&label
	ADDR_LABEL_EXPR = 120,



	// A statement whose specific kind is not exposed via this interface
	//
	// Unexposed statements have the same operations as any other kind of statement;
	// one can extract their location information, spelling, children, etc However,
	// the specific kind of the statement is not reported
	UNEXPOSED_STMT = 200,

	// A labelled statement in a function
	LABEL_STMT = 201,

	// A compound statement
	COMPOUND_STMT = 202,

	// A case statement
	CASE_STMT = 203,

	// A default statement
	DEFAULT_STMT = 204,

	// An if statement
	IF_STMT = 205,

	// A switch statement
	SWITCH_STMT = 206,

	// A while statement
	WHILE_STMT = 207,

	// A do statement
	DO_STMT = 208,

	// A for statement
	FOR_STMT = 209,

	// A goto statement
	GOTO_STMT = 210,

	// An indirect goto statement
	INDIRECT_GOTO_STMT = 211,

	// A continue statement
	CONTINUE_STMT = 212,

	// A break statement
	BREAK_STMT = 213,

	// A return statement
	RETURN_STMT = 214,


	// The null statement
	NULL_STMT = 230,

	// Adaptor class for mixing declarations with statements and expressions
	DECL_STMT = 231,


	//////
	// Other Kinds

	// Cursor that represents the translation unit itself
	//
	// The translation unit cursor exists primarily to act as the root cursor for
	// traversing the contents of a translation unit
	TRANSLATION_UNIT = 300,
};

typedef enum _node_type node_type;
extern int type;
#endif
#ifndef COMPILER_LAB_AST_H
#define COMPILER_LAB_AST_H
//全局变量~
extern int yylex();
extern char* yytext;
extern int yyleng;
extern int tok;

//结点声明
typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
	char* stype;
	int ivalue;
	float fvalue;
	char* svalue;
	node_type nodeType;
	char* snodeType;
	int if_const;
	past left;
	past right;
	past if_cond;
	past next;
};
//函数声明

//返回ast结点函数
past newAstNode();
//显示ast
void showAst(char* sym, past node, int nest,bool use_blank);
void showParaDecl(past node,int nest);
void showCompoundStmt(past node, int nest,bool use_blank);
void showCallExp(past node, int nest,bool use_blank);
void showTranstion(past node, int nest,bool use_blank);

char* get_id(char* yytext);
char* get_stype(int type);
char* get_conststype(int type);

past newDeclStmt(past left, past right);
past newCompUnit(past left, past right);
past newDeclRefExp(char* name, past left, past right);
past newFuncDecl(char* stype, int type,char* svalue, past left, past right);
past newBinaryOper(char* soper, int oper, past left, past right);
past newArraySubscriptsExp(past left, past right);
past newCallExp(char* stype, int type, char* name, past left, past right);
past newParaDecl(char* stype, char* name, past left, past right);
past newCompoundStmt(past left, past right);
past newIntVal(int ival);
past newFloatVal(float fval);
past newVarDecl(char* stype, int type, int if_cond, char* s, past left, past right);
past newIfStmt(past if_cond, past left, past right);
past newWhileStmt(past left, past right);
past newContinueStmt();
past newBreakStmt();
past newReturnStmt(past left, past right);
past newType(int oper);
past newUnaryOper(char* soper, int oper, past left, past right);
past newAstAny(past left, past right, char* snodeType, node_type nodeType);

typedef struct _scope scope;
typedef struct _scope *pscope;
struct _scope{
	char* func; //是表明函数名称,全局变量此值为NULL
	node_type nodeType;//表明是在if语句中还是在while语句中或者是在函数中
	pscope child;//指向子作用域,一个变量的作用域是一直到它的子作用域为NULL的位置才是他的作用域
};
typedef union Value {
  int ival;
  float fval;
} Value;
extern int hash(char* name);//hash函数,根据变量名字来计算hash值

typedef struct _hash_table hash_table;
typedef struct _hash_table *phash_table;
struct _hash_table{
	char* name;//变量名字
	Value value;//变量值
	int type;//变量类型,有Y_INT,Y_FLOAT
	int regs;//变量寄存器号
	int if_const;//是否是常量,1表示是常量,0表示不是常量
	pscope scope;//变量作用域
	phash_table next;//指向下一个hash表元素
	int if_array;//是否是数组,1表示是数组,0表示不是数组
};
extern phash_table My_hash_table[1000];//hash表,里面元素是hash_table结构体的指针
extern void insertHash(char* name, Value value, int type, pscope scope,int regs);//插入hash表
extern void changeHashReg(char* name,int regs);//修改hash表,将变量的寄存器号修改为regs
extern int get_regs(char* name);//根据变量名字获取变量的寄存器号
extern phash_table get_hash(char* name);//根据变量名字获取hash表元素
extern phash_table get_hash_by_regs(int regs);//根据寄存器号获取hash表元素
extern void EstablishTokenTable(past node);
 
#endif