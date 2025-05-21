#ifndef GENLLVM_H

#define GENLLVM_H

#include "ast.h"

extern void setNode(past node);
extern past getNode();

extern void Process(past node);
extern void ProcessGlobalDecl(past node);

extern int llvmVal;
extern char* llvmS[100];

#endif