#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#define BAD_OUTPUT 0

extern FILE* yyin;
extern FILE* yyout;
extern int yyparse();

void yyerror(char const* msg, ...) {
    va_list va_args;
    va_start(va_args, msg);
    if (yyout) {
        fprintf(yyout, msg, va_args);
        return;
    }
    fprintf(yyout, msg, va_args);
    va_end(va_args);
}
int input_switcher(int argc, char** argv) {
    switch (argc) {
    case 2:
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            exit(-1);
        }
        break;
    case 3:
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            exit(-1);
        }
        if (!(yyout = fopen(argv[2], "a"))) {
            perror(argv[2]);
            printf("argv[2]:bad address\noutput to stdout\n");
            return BAD_OUTPUT;
        }
        break;
    }
}

int main(int argc, char** argv) {
    if (!input_switcher(argc, argv))
        yyout = stdout;
    yyparse();
    showAst(astHead, 0);
    return 0;
}
