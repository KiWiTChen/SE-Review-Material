%{
#include <stdlib.h>
#include "ast.h"
#include "lrparser.tab.h"
void yyerror(char const* msg, ...);
int lineCount = 1;
%}

%%
"/*"([^\*]|(\*)+[^/])*"*/"	{ /* 忽略多行注释 */ }
"//".*		{ /* 忽略单行注释 */ }
"int"		{ yylval.iValue = Y_INT; return INT;}
"const"		{ yylval.iValue = Y_CONST; return CONST;}
"void"		{ yylval.iValue = Y_VOID; return VOID;}
"if"			{ return IF;}
"else"		{ return ELSE;}
"while"		{ return WHILE;}
"break"		{ return BREAK;}
"continue"	{ return CONTINUE;}
"return"	{ return RETURN;}

"+"|"-"|"*"|"/"|"%"|"&"|""|"!"      { return yytext[0]; }
"{"|"}"|"["|"]"         	{ return yytext[0]; }
","|";"                 	{ return yytext[0]; }
"("|")"                 	{ return yytext[0]; }

"<"			{ yylval.iValue = Y_LESS; return CMP;}
">"			{ yylval.iValue = Y_GREAT; return CMP;}
"<="		{ yylval.iValue = Y_LESSEQ; return LESSEQ;}
">="		{ yylval.iValue = Y_GREATEQ; return GREATEQ;}
"=="		{ yylval.iValue = Y_EQ; return EQ;}
"!="		{ yylval.iValue = Y_NOTEQ; return NOTEQ;}
"&&"		{ yylval.iValue = Y_AND; return AND;}
"||"		{ yylval.iValue = Y_OR; return OR;}
"="			{ yylval.iValue = Y_ASSIGN; return ASSIGN;}
\n			{ ++lineCount; }
[ \t]		{ /* 忽略空格 */ }
[1-9][0-9]*|[0] 		{ yylval.iValue = atoi(yytext); return NUMBER;}
[0][Xx]([1-9a-fA-F][0-9a-fA-F]*|[0]) 		{ yylval.iValue = strtol(yytext, NULL, 16); return NUMBER;}
[0][0-7]* 		{ yylval.iValue = strtol(yytext, NULL, 8); return NUMBER;}
[a-zA-Z_][a-zA-Z_0-9]*		{ yylval.eValue = strdup(yytext); return IDentifier;}
.     { yyerror("line:%d unknown character %s", lineCount, yytext); }
%%
int yywrap() {
	return 1;
}