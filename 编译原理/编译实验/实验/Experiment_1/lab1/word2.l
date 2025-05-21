%{
// 单词类别
enum yytokentype {
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
    int ivalue;
    float fvalue;
    char* idname;
%}
HEX    0[xX][0-9a-fA-F]+
%%
"int" { return Y_INT;}
"void" {return Y_VOID;}
"const" {return Y_CONST;}
"if" {return Y_IF;}
"else" {return Y_ELSE;}
"while" {return Y_WHILE;}
"break" {return Y_BREAK;}
"continue" {return Y_CONTINUE;}
"return" {return Y_RETURN;}

"float" {return Y_FLOAT;}

([1-9][0-9]*\.[0-9]*|0\.[0-9]*) {fvalue=atof(yytext);return num_FLOAT;}
{HEX}   {sscanf(yytext,"%x",&ivalue);return num_INT;}
[1-9][0-9]*|0 { ivalue=atoi(yytext);return num_INT;}
[a-zA-Z\_][0-9a-zA-Z\_]* {idname=yytext;return Y_ID; }

"+" { return Y_ADD; }
"-" { return Y_SUB; }
"*"	{ return Y_MUL; }
"/"	{ return Y_DIV; }
"%" { return Y_MODULO; }
"<" { return Y_LESS; }
"<=" { return Y_LESSEQ; }
">" { return Y_GREAT; }
">=" { return Y_GREATEQ; }
"!=" { return Y_NOTEQ; }
"==" { return Y_EQ; }
"!" { return Y_NOT; }
"&&" { return Y_AND; }
"||" {return Y_OR; }
"=" { return Y_ASSIGN; }

"(" { return Y_LPAR;}
")" {return Y_RPAR;}
"{" {return Y_LBRACKET;}
"}" {return Y_RBRACKET;}
"[" {return Y_LSQUARE;}
"]" {return Y_RSQUARE;}
"," {return Y_COMMA;}
";" { return Y_SEMICOLON;}

"//".* {} 
[ \t] { /* ignore whitespace */ }
\n  {}
%%
int main(int argc, char **argv)
    {
FILE *file;
char filname[100];
char ch;

file = fopen("51_short_circuit3.sy","r");

if(file ==NULL){
printf("ERROR");
return 1;
}
yyin = file;
        int token;
        while(token = yylex()) 
        {
            printf("<%d, ",token);
            switch (token)
            {
            case num_INT:
                printf("%d>\n",ivalue);
                break;
            case num_FLOAT:
                printf("%f>\n",fvalue);
                break;
            case Y_ID:
                printf("%s>\n",idname);
                break;
            case Y_FLOAT:
                printf("KEYWORD>\n");
                break;
            default:
                if(token>=Y_INT&&token<=Y_RETURN)
                {
                    printf("KEYWORD>\n");
                }
                else if(token>=Y_ADD&&token<=Y_ASSIGN)
                {
                    printf("OPERATOR>\n");
                }
                else if(token>=Y_LPAR&&token<=Y_SEMICOLON)
                {
                    printf("SYMBOL>\n");
                }
                break;
            }
        }fclose(file);
    }


int yywrap() {
	return 1;
}
