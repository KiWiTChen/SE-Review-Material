%{
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "lrparser.tab.h"
void yyerror(char *);

%}


%%
\n	{/* ignore */}
[ \t] { /* ignore whitespace */ }

"int" {yylval.sValue=strdup(yytext); return INT;}
"str" {yylval.sValue=strdup(yytext); return STR;}
"void" {yylval.sValue=strdup(yytext); return VOID;}
"if" {yylval.sValue=strdup(yytext); return IF;}
"else" {yylval.sValue=strdup(yytext); return ELSE;}
"while" {yylval.sValue=strdup(yytext); return WHILE;}
"return" {yylval.sValue=strdup(yytext); return RETURN;}
"print" {yylval.sValue=strdup(yytext); return PRINT;}
"scan" {yylval.sValue=strdup(yytext); return SCAN;}

"+"|"-"|"*"|"/"|"%" {return yytext[0]; }
","|"("|")"|"["|"]"|"{"|"}"|";"|"q"|"="      {return yytext[0]; }

"/*".*"*/"  {/* ignore annotation */}
"//".*\n  	{/* ignore annotation */}
"\""[^"]*"\"" {yylval.sValue=strdup(yytext); return STRING;}

[0-9]+ { yylval.sValue=strdup(yytext); return NUMBER; }

[_a-zA-Z][_a-zA-Z0-9]*		{yylval.sValue=strdup(yytext); return ID;}

"+=" |"-=" |"*=" |"/=" {yylval.sValue=strdup(yytext);return ASSIGN;}
">"|"<"|">="|"<="|"=="  {yylval.sValue=strdup(yytext);return CMP;}

. 	{ printf("Mystery character %c\n", *yytext); }



%%



int yywrap()
{
	return 1;
}
