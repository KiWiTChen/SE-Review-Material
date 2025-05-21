%{
#include <stdlib.h>
#include "ast.h"
#include "lrparser.tab.h"
int type;
int array_size;
int llvmVal;
%}

/* Regular definition */ 
DELIM          [\t ]
WS               {DELIM}+
DIGIT            [0-9]
LETTER 	     [A-Za-z]
NUM_INT_HEX		 (0[xX][a-fA-F0-9]+)	
     
%%

(\/\/.*\n)|(\/\*.*\*\/)							{llvmVal++;/* noaction */}
{WS}   											{llvmVal++;/* noaction */}
\n 												{llvmVal++;/* noaction */}
{NUM_INT_HEX}									{llvmVal++;yylval.int_value = (int)strtol(yytext, NULL, 16); return num_INT;}
{DIGIT}+	     								{llvmVal++;yylval.int_value = atoi(yytext); return num_INT;}
{DIGIT}+"."{DIGIT}+								{llvmVal++;yylval.float_value = (float)atof(yytext); return num_FLOAT;}
int												{llvmVal++;type = Y_INT;return Y_INT;}
float											{llvmVal++;type = Y_FLOAT;return Y_FLOAT;}
void											{llvmVal++;type = Y_VOID;return Y_VOID;}
const											{llvmVal++;return Y_CONST;}
if												{llvmVal++;return Y_IF;}
else											{llvmVal++;return Y_ELSE;}
while											{llvmVal++;return Y_WHILE;}
break											{llvmVal++;return Y_BREAK;}
continue										{llvmVal++;return Y_CONTINUE;}
return											{llvmVal++;return Y_RETURN;}
("_"|{LETTER})({DIGIT}|"_"|{LETTER})*			{llvmVal++;yylval.id_name = malloc(sizeof(char) * (yyleng + 1)); memcpy(yylval.id_name, yytext, yyleng); yylval.id_name[yyleng] = '\0'; return Y_ID;}
"+"												{llvmVal++;return Y_ADD;}
"-"												{llvmVal++;return Y_SUB;}
"*"												{llvmVal++;return Y_MUL;}
"/"												{llvmVal++;return Y_DIV;}
"%"												{llvmVal++;return Y_MODULO;}
"<"												{llvmVal++;return Y_LESS;}
"<="											{llvmVal++;return Y_LESSEQ;}
">"												{llvmVal++;return Y_GREAT;}
">="											{llvmVal++;return Y_GREATEQ;}
"!="											{llvmVal++;return Y_NOTEQ;}
"=="											{llvmVal++;return Y_EQ;}
"!"												{llvmVal++;return Y_NOT;}
"&&"											{llvmVal++;return Y_AND;}
"||"											{llvmVal++;return Y_OR;}
"="												{llvmVal++;return Y_ASSIGN;}
"("												{llvmVal++;return Y_LPAR;}
")"												{llvmVal++;return Y_RPAR;}
"["												{llvmVal++;return Y_LSQUARE;}
"]"												{llvmVal++;return Y_RSQUARE;}
"{"												{llvmVal++;return Y_LBRACKET;}
"}"												{llvmVal++;return Y_RBRACKET;}
","												{llvmVal++;return Y_COMMA;}
";"												{llvmVal++;return Y_SEMICOLON;}

%%

int yywrap() {
	return 1;
}
