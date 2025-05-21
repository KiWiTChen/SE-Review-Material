#ifndef GENLLVM_H

#define GENLLVM_H

#include "ast.h"
// 添加 CountReturn 函数的声明
int CountReturn(past node);


extern void setNode(past node);
extern past getNode();

extern void Process(past node);
extern void ProcessGlobalDecl(past node);

extern int llvmVal;
extern char* llvmS[100];

#endif
