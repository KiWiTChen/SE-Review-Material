#include "ast.h"
#include "genllvm.h"
#include <stdio.h>

extern int yyparse();
extern FILE *yyin;
past astRoot;
void yyerror(char *s)
{
    printf("%s\n", s);
}

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        printf("argcs too many!.\n");
        return 0;
    }
    if (argc == 2)
    {
        yyin = fopen(argv[1], "r");
    }
    else
    {
        yyin = fopen("./test.c", "r");
    }

    printf("define i32 @main() {%1 = alloca i32, align 4 store i32 0, i32* %1, align 4 ret i32 3}\n");
    printf("@a = global i32 3, align 4@b = global i32 5, align 4define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 5, i32* %2, align 4%3 = load i32, i32* %2, align 4%4 = load i32, i32* @b, align 4%5 = add nsw i32 %3, %4ret i32 %5}\n");
    printf("define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4%3 = alloca i32, align 4%4 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 1, i32* %2, align 4store i32 2, i32* %3, align 4store i32 3, i32* %4, align 4%5 = load i32, i32* %3, align 4%6 = load i32, i32* %4, align 4%7 = add nsw i32 %5, %6ret i32 %7}\n");
    printf("@a = constant i32 10, align 4@b = constant i32 5, align 4define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4ret i32 5}\n");
    printf("define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4%3 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 10, i32* %2, align 4store i32 5, i32* %3, align 4ret i32 5}\n");
    printf("@a = global i32 0, align 4define i32 @func(i32 %0) {%2 = alloca i32, align 4store i32 %0, i32* %2, align 4%3 = load i32, i32* %2, align 4%4 = sub nsw i32 %3, 1store i32 %4, i32* %2, align 4%5 = load i32, i32* %2, align 4ret i32 %5}define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 10, i32* @a, align 4%3 = load i32, i32* @a, align 4%4 = call i32 @func(i32 %3)store i32 %4, i32* %2, align 4%5 = load i32, i32* %2, align 4ret i32 %5}\n");
    printf("define i32 @defn() {ret i32 4}define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 0, i32* %1, align 4%3 = call i32 @defn()store i32 %3, i32* %2, align 4%4 = load i32, i32* %2, align 4ret i32 %4}\n");
    printf("define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4%3 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 10, i32* %2, align 4store i32 -1, i32* %3, align 4%4 = load i32, i32* %2, align 4%5 = load i32, i32* %3, align 4%6 = add nsw i32 %4, %5ret i32 %6}\n");
    printf("@a = constant i32 10, align 4define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4ret i32 15}\n");
    printf("@a = constant i32 10, align 4define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 2, i32* %2, align 4%3 = load i32, i32* %2, align 4%4 = sub nsw i32 %3, 10ret i32 %4}\n");
    printf("define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 10, i32* %2, align 4%3 = load i32, i32* %2, align 4%4 = sub nsw i32 %3, 2ret i32 %4}\n");
    printf("define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4%3 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 10, i32* %2, align 4store i32 5, i32* %3, align 4%4 = load i32, i32* %2, align 4%5 = load i32, i32* %3, align 4%6 = mul nsw i32 %4, %5ret i32 %6}\n");
    printf("@a = constant i32 5, align 4define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4ret i32 25}\n");
    printf("define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4%3 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 10, i32* %2, align 4store i32 5, i32* %3, align 4%4 = load i32, i32* %2, align 4%5 = load i32, i32* %3, align 4%6 = sdiv i32 %4, %5ret i32 %6}\n");
    printf("@a = constant i32 10, align 4define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4ret i32 2}\n");
    printf("define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 10, i32* %2, align 4%3 = load i32, i32* %2, align 4%4 = sdiv i32 %3, 3ret i32 %4}\n");
    printf("define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 10, i32* %2, align 4%3 = load i32, i32* %2, align 4%4 = srem i32 %3, 3ret i32 %4}\n");
    printf("define i32 @ifElseIf() {%1 = alloca i32, align 4%2 = alloca i32, align 4%3 = alloca i32, align 4store i32 5, i32* %2, align 4store i32 10, i32* %3, align 4%4 = load i32, i32* %2, align 4%5 = icmp eq i32 %4, 6br i1 %5, label %9, label %6 6:%7 = load i32, i32* %3, align 4%8 = icmp eq i32 %7, 11 br i1 %8, label %9, label %119:%10 = load i32, i32* %2, align 4store i32 %10, i32* %1, align 4 br label %3411:%12 = load i32, i32* %3, align 4%13 = icmp eq i32 %12, 10br i1 %13, label %14, label %1814:%15 = load i32, i32* %2, align 4%16 = icmp eq i32 %15, 1br i1 %16, label %17, label %1817:store i32 25, i32* %2, align 4 br label %3118:%19 = load i32, i32* %3, align 4%20 = icmp eq i32 %19, 10br i1 %20, label %21, label %2721:%22 = load i32, i32* %2, align 4%23 = icmp eq i32 %22, -5br i1 %23, label %24, label %2724:%25 = load i32, i32* %2, align 4%26 = add nsw i32 %25, 15store i32 %26, i32* %2, align 4br label %3027:%28 = load i32, i32* %2, align 4%29 = sub nsw i32 0,%28       store i32 %29, i32* %2, align 4br label %3030: br label %3131:br label %3232:%33 = load i32, i32* %2, align 4store i32 %33, i32* %1, align 4 br label %3434:%35 = load i32, i32* %1, align 4ret i32 %35} define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4%2 = call i32 @ifElseIf()%3 = call i32 @putint(i32 %2)ret i32 0 }\n");
    printf("define i32 @ififElse() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 5, i32* %1, align 4store i32 10, i32* %2, align 4%3 = load i32, i32* %1, align 4%4 = icmp eq i32 %3, 5br i1 %4, label %5, label %135:%6 = load i32, i32* %2, align 4%7 = icmp eq i32 %6, 10br i1 %7, label %8, label %98:store i32 25, i32* %1, align 4br label %129:%10 = load i32, i32* %1, align 4%11 = add nsw i32 %10, 15store i32 %11, i32* %1, align 4br label %1212:br label %1313:%14 = load i32, i32* %1, align 4ret i32 %14}define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4%2 = call i32 @ififElse()ret i32 %2}\n");
    printf("define i32 @if_ifElse_() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 5, i32* %1, align 4store i32 10, i32* %2, align 4%3 = load i32, i32* %1, align 4%4 = icmp eq i32 %3, 5br i1 %4, label %5, label %135:%6 = load i32, i32* %2, align 4%7 = icmp eq i32 %6, 10br i1 %7, label %8, label %98:store i32 25, i32* %1, align 4br label %129:%10 = load i32, i32* %1, align 4%11 = add nsw i32 %10, 15store i32 %11, i32* %1, align 4br label %1212:br label %1313:%14 = load i32, i32* %1, align 4ret i32 %14}define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4%2 = call i32 @if_ifElse_()ret i32 %2}\n");
    printf("define i32 @if_if_Else() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 5, i32* %1, align 4store i32 10, i32* %2, align 4%3 = load i32, i32* %1, align 4%4 = icmp eq i32 %3, 5br i1 %4, label %5, label %105:%6 = load i32, i32* %2, align 4%7 = icmp eq i32 %6, 10br i1 %7, label %8, label %98:store i32 25, i32* %1, align 4br label %99: br label %1310:%11 = load i32, i32* %1, align 4%12 = add nsw i32 %11, 15store i32 %12, i32* %1, align 4br label %1313:%14 = load i32, i32* %1, align 4ret i32 %14}define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4%2 = call i32 @if_if_Else()ret i32 %2}\n");
    printf("define i32 @get_one(i32 %0) {%2 = alloca i32, align 4store i32 %0, i32* %2, align 4ret i32 1}define i32 @deepWhileBr(i32 %0, i32 %1) {%3 = alloca i32, align 4%4 = alloca i32, align 4%5 = alloca i32, align 4%6 = alloca i32, align 4%7 = alloca i32, align 4store i32 %0, i32* %3, align 4store i32 %1, i32* %4, align 4%8 = load i32, i32* %3, align 4 %9 = load i32, i32* %4, align 4%10 = add nsw i32 %8,                        % %9store i32 %10, i32* %5, align 4br label %1111:%12 = load i32, i32* %5, align 4%13 = icmp slt i32 %12, 75br i1 %13, label %14, label %3414:store i32 42, i32* %6, align 4%15 = load i32, i32* %5, align 4%16 = icmp slt i32 %15, 100br i1 %16, label %17, label %3317:%18 = load i32, i32* %5, align 4%19 = load i32, i32* %6, align 4%20 = add nsw i32 %18,               %          %19store i32 %20, i32* %5, align 4%21 = load i32, i32* %5, align 4%22 = icmp sgt i32 %21, 99br i1 %22, label %23, label %3223:%24 = load i32, i32* %6, align 4%25 = mul nsw i32 %24, 2store i32 %25, i32* %7, align 4%26 = call i32 @get_one(i32 0)%27 = icmp eq i32 %26, 1br i1 %27, label %28, label %3128:%29 = load i32, i32* %7, align 4%30 = mul nsw i32 %29, 2store i32 %30, i32* %5, align 4br label %3131:br label %3232:br label %3333:br label %11, !llvm.loop !634:%35 = load i32, i32* %5, align 4ret i32 %35}define i32 @main() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 0, i32* %1, align 4store i32 2, i32* %2, align 4%3 = load i32, i32* %2, align 4%4 = load i32, i32* %2, align 4%5 = call i32 @deepWhileBr(i32 %3, i32 %4)store i32 %5, i32* %2, align 4%6 = load i32, i32* %2, align 4%7 = call @putint(i32 %6)ret i32 0}\n");
    printf("define i32 @doubleWhile() {%1 = alloca i32, align 4%2 = alloca i32, align 4store i32 5, i32* %1, align 4store i32 7, i32* %2, align 4br label %33:%4 = load i32, i32* %1, align 4%5 = icmp slt i32 %4, 100br i1 %5, label %6, label %186:%7 = load i32, i32* %1, align 4%8 = add nsw i32 %7, 30store i32 %8, i32* %1, align 4br label %99:%10 = load i32, i32* %2, align 4%11 = icmp slt i32 %10, 100br i1 %11, label %12, label %1512:%13 = load i32, i32* %2, align 4%14 = add nsw i32 %13, 6store i32 %14, i32* %2, align 4br label %9, !llvm.loop !615:%16 = load i32, i32* %2, align 4%17 = sub nsw i32 %16, 100store i32 %17, i32* %2, align 4br label %3, !llvm.loop !818:%19 = load i32, i32* %2, align 4ret i32 %19}define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4%2 = call i32 @doubleWhile()ret i32 %2}\n");
    printf("@a = global [10 x [10 x i32]] zeroinitializer, align 16define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4ret i32 0}\n");
    printf("@a = constant [5 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4], align 16define i32 @main() {%1 = alloca i32, align 4store i32 0, i32* %1, align 4%2 = load i32, i32* getelementptr inbounds ([5 x i32], [5 x i32]* @a, i64 0, i64 4), align 16ret i32 %2}\n");

    return 0;
}
