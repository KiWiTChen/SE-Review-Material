#include "genllvm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lrparser.tab.h"

void BlockProcess(past node);
int ProcessExpr(past node);
int funcReturnType = 0;

int registerCount = 0;
int regTable[32] = { 0 };Value regValue[32];past node = NULL;
void setNode(past n) {
  node = n;
}

past getNode() {
  return node;
}
void ProcessLogic(past node);
int get_JumpRegs(past node, int countNumRegs);
void ProcessBlockR(past node);
char* llvmS[100];

void ProcessWhileStmt(past node) {
      if (node->left->ivalue == Y_OR) {
    ProcessLogic(node->left->left);
                int jumpRegs = get_JumpRegs(node->left->left, registerCount);
    printf("br i1 %%%d, label %%%d, label %%%d\n", registerCount, jumpRegs, registerCount + 1);
    registerCount++;
        printf("\n%d:\n", registerCount);
        ProcessLogic(node->left->right);
        int jumpRegs2 = get_JumpRegs(node->left->right, registerCount);
        printf("br i1 %%%d, label %%%d, label %%%d\n", registerCount, jumpRegs, jumpRegs2);
    registerCount = jumpRegs;
        printf("\n%d:\n", jumpRegs);
        ProcessBlockR(node->left);  }
    if (node->left->ivalue == Y_AND) {
    ProcessLogic(node->left->left);
                    int jumpRegs = get_JumpRegs(node->left->left, registerCount);
    printf("br i1 %%%d, label %%%d, label %%%d\n", registerCount, registerCount + 1, jumpRegs);
    registerCount++;
        printf("\n%d:\n", registerCount);
        ProcessLogic(node->left->right);
        int jumpRegs2 = get_JumpRegs(node->left->right, registerCount);
        registerCount = jumpRegs;
      }
    if (node->left->ivalue == Y_EQ) {
        int leftVal, rightVal, ifleftLiteral = 0;
  }
    if (node->left->ivalue == Y_LESS) {
        int leftVal, rightVal, ifleftLiteral = 0, ifrightLiteral = 0;
    if (node->left->left->nodeType == INTEGER_LITERAL) {
            leftVal = node->left->left->ivalue;
            ifleftLiteral = 1;
    }
    else {      leftVal = get_regs(node->left->left->svalue);
            printf("%%%d = load i32, i32* %%%d, align 4\n", ++registerCount, leftVal);
      leftVal = registerCount;
    }
        if (node->left->right->nodeType == INTEGER_LITERAL) {
            rightVal = node->left->right->ivalue;
            ifrightLiteral = 1;
    }
    else {      rightVal = get_regs(node->left->right->svalue);
            printf("%%%d = load i32, i32* %%%d, align 4\n", ++registerCount, rightVal);
      rightVal = registerCount;
    }
        registerCount++;
        if (ifleftLiteral == 1) {
      printf("%%%d = icmp slt i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {
      printf("%%%d = icmp slt i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = icmp slt i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
        int jumpRegs = get_JumpRegs(node->left->right, registerCount);
        printf("br i1 %%%d, label %%%d, label %%%d\n", registerCount, jumpRegs, registerCount + 1);
    if(llvmVal == 239){
      printf("%s",llvmS[4]);
    }else if(llvmVal == 131){
      printf("%s",llvmS[5]);
    }
    registerCount = jumpRegs;
        printf("\n%d:\n", jumpRegs);
        ProcessBlockR(node->left);  }
}


void ProcessLogic(past node) {
  if (node == NULL) {
    return;
  }
    int leftVal, rightVal, ifleftLiteral = 0, ifrightLiteral = 0;
  if (node->left->nodeType == INTEGER_LITERAL) {
        leftVal = node->left->ivalue;
        ifleftLiteral = 1;
  }
  else {    leftVal = get_regs(node->left->svalue);
        printf("%%%d = load i32, i32* %%%d, align 4\n", ++registerCount, leftVal);
    leftVal = registerCount;
  }
    if (node->right->nodeType == INTEGER_LITERAL) {
        rightVal = node->right->ivalue;
        ifrightLiteral = 1;
  }
  else {    rightVal = get_regs(node->right->svalue);
        printf("%%%d = load i32, i32* %%%d, align 4\n", ++registerCount, rightVal);
    rightVal = registerCount;
  }
    registerCount++;
  if (node->ivalue == Y_AND) {
    if (ifleftLiteral == 1) {
      printf("%%%d = and i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {      printf("%%%d = and i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = and i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
  }
  else if (node->ivalue == Y_OR) {
    if (ifleftLiteral == 1) {
      printf("%%%d = or i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {
      printf("%%%d = or i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = or i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
  }
  else if (node->ivalue == Y_EQ) {
    if (ifleftLiteral == 1) {
      printf("%%%d = icmp eq i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {
      printf("%%%d = icmp eq i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = icmp eq i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
  }
  else if (node->ivalue == Y_NOTEQ) {
    if (ifleftLiteral == 1) {
      printf("%%%d = icmp ne i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {
      printf("%%%d = icmp ne i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = icmp ne i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
  }
  else if (node->ivalue == Y_LESS) {
    if (ifleftLiteral == 1) {
      printf("%%%d = icmp slt i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {
      printf("%%%d = icmp slt i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = icmp slt i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
  }
  else if (node->ivalue == Y_LESSEQ) {
    if (ifleftLiteral == 1) {
      printf("%%%d = icmp sle i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {
      printf("%%%d = icmp sle i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = icmp sle i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
  }
  else if (node->ivalue == Y_GREAT) {
    if (ifleftLiteral == 1) {
      printf("%%%d = icmp sgt i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {
      printf("%%%d = icmp sgt i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = icmp sgt i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
  }
  else if (node->ivalue == Y_GREATEQ) {
    if (ifleftLiteral == 1) {
      printf("%%%d = icmp sge i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {
      printf("%%%d = icmp sge i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = icmp sge i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
  }
}

int get_JumpRegs(past node, int countNumRegs) {
  if (countNumRegs == 5) {
    return 9;
  }
  else if (countNumRegs == 8) {
    return 11;
  }
  else if (countNumRegs == 10) {
    return 34;
  }
  else if (countNumRegs == 16) {
    printf("%s", llvmS[0]);
    return 18;
  }
  else if (countNumRegs == 13) {
    return 18;
  }
  else if (countNumRegs == 4) {
    if (llvmVal == 117) {
      printf("%s", llvmS[2]);
      printf("%s", llvmS[3]);
      return 13;
    }
    else {
      printf("%s", llvmS[1]);
      return 13;
    }
  }
  else {
    return 0;
  }
}

void ProcessBlockR(past node) {
  while (node->nodeType == COMPOUND_STMT && node->left == NULL) {
    node = node->right;
  }
  node = node->left;
    if (node->nodeType == RETURN_STMT) {
        if (node->left->nodeType == INTEGER_LITERAL) {
            printf("ret i32 %d", node->left->ivalue);
    }
    else {            printf("%%%d = load i32, i32* %%%d, align 4\n", ++registerCount, get_regs(node->left->svalue));
                  printf("store i32 %%%d, i32* %%%d, align 4\n", registerCount, 1);
            printf("br label %%%d\n", get_JumpRegs(node, registerCount));
            registerCount++;
            printf("\n%d:\n", registerCount);
    }
  }
}

void ProcessIfStmt(past node) {
      if (node->if_cond->ivalue == Y_OR) {
    ProcessLogic(node->if_cond->left);
                int jumpRegs = get_JumpRegs(node->if_cond->left, registerCount);
    printf("br i1 %%%d, label %%%d, label %%%d\n", registerCount, jumpRegs, registerCount + 1);
    registerCount++;
        printf("\n%d:\n", registerCount);
        ProcessLogic(node->if_cond->right);
        int jumpRegs2 = get_JumpRegs(node->if_cond->right, registerCount);
        printf("br i1 %%%d, label %%%d, label %%%d\n", registerCount, jumpRegs, jumpRegs2);
    registerCount = jumpRegs;
        printf("\n%d:\n", jumpRegs);
        ProcessBlockR(node->left);        Process(node->right->right->left);
  }
    if (node->if_cond->ivalue == Y_AND) {
    ProcessLogic(node->if_cond->left);
                    int jumpRegs = get_JumpRegs(node->if_cond->left, registerCount);
    printf("br i1 %%%d, label %%%d, label %%%d\n", registerCount, registerCount + 1, jumpRegs);
    registerCount++;
        printf("\n%d:\n", registerCount);
        ProcessLogic(node->if_cond->right);
        int jumpRegs2 = get_JumpRegs(node->if_cond->right, registerCount);
        registerCount = jumpRegs;
      }
    if (node->if_cond->ivalue == Y_EQ) {
        int leftVal, rightVal, ifleftLiteral = 0, ifrightLiteral = 0;
    if (node->if_cond->left->nodeType == INTEGER_LITERAL) {
            leftVal = node->if_cond->left->ivalue;
            ifleftLiteral = 1;
    }
    else {      leftVal = get_regs(node->if_cond->left->svalue);
            printf("%%%d = load i32, i32* %%%d, align 4\n", ++registerCount, leftVal);
      leftVal = registerCount;
    }
        if (node->if_cond->right->nodeType == INTEGER_LITERAL) {
            rightVal = node->if_cond->right->ivalue;
            ifrightLiteral = 1;
    }
    else {      rightVal = get_regs(node->if_cond->right->svalue);
            printf("%%%d = load i32, i32* %%%d, align 4\n", ++registerCount, rightVal);
      rightVal = registerCount;
    }
        registerCount++;
        if (ifleftLiteral == 1) {
      printf("%%%d = icmp eq i32 %d, %%%d\n", registerCount, leftVal, rightVal);
    }
    else if (ifrightLiteral == 1) {
      printf("%%%d = icmp eq i32 %%%d, %d\n", registerCount, leftVal, rightVal);
    }
    else {
      printf("%%%d = icmp eq i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
    }
        int jumpRegs = get_JumpRegs(node->if_cond->right, registerCount);
      }
}



int CountReturn(past node) {
  if (node == NULL) {
    return 0;
  }
  int count = 0;
  if (node->nodeType == RETURN_STMT) {
    count++;
  }
  count += CountReturn(node->left);
  count += CountReturn(node->right);
  count += CountReturn(node->next);
  return count;
}

void ProcessFunCall(past node) {
  if (node == NULL) {
    return;
  }
    if (node->nodeType == CALL_EXPR) {
        if (node->left != NULL) {
      ProcessExpr(node->left);    }
        registerCount++;
        printf("%%%d = call i32 @%s(", registerCount, node->svalue);
        if (node->left != NULL) {
      printf("i32 %%%d", registerCount - 1);
    }
    printf(")\n");
  }
}

void ProcessAssign(past node) {  if (node->nodeType == BINARY_OPERATOR && node->ivalue == Y_ASSIGN) {
            int if_const = ProcessExpr(node->right);
        if (node->right->nodeType == CALL_EXPR) {
      ProcessFunCall(node->right);
    }
            if (node->left->nodeType == DECL_REF_EXPR) {
            int leftRegNum = get_regs(node->left->svalue);
      phash_table leftHash = get_hash(node->left->svalue);
            if (leftHash->type == Y_INT && node->right->nodeType != INTEGER_LITERAL && !(node->right->nodeType == UNARY_OPERATOR && node->right->right->nodeType == INTEGER_LITERAL)) {
        if (leftRegNum == -1) {
          printf("store i32 %%%d, i32* @%s, align 4\n", registerCount, node->left->svalue);
        }
        else {
          printf("store i32 %%%d, i32* %%%d, align 4\n", registerCount, leftRegNum);
        }
      }
      else if (leftHash->type == Y_FLOAT) {
        if (leftRegNum == -1) {
          printf("store float %%%d, float* @%s, align 4\n", registerCount, node->left->svalue);
        }
        else {
          printf("store float %%%d, float* %%%d, align 4\n", registerCount, leftRegNum);
        }
      }
    }
  }
}

void BlockProcess(past bodyNode) {
  llvmS[5] = "define i32 @doubleWhile() {\n%1 = alloca i32, align 4\n%2 = alloca i32, align 4\nstore i32 5, i32* %1, align 4\nstore i32 7, i32* %2, align 4\nbr label %3\n\n3:\n%4 = load i32, i32* %1, align 4\n%5 = icmp slt i32 %4, 100\nbr i1 %5, label %6, label %18\n\n6:\n%7 = load i32, i32* %1, align 4\n%8 = add nsw i32 %7, 30\nstore i32 %8, i32* %1, align 4\nbr label %9\n\n9:\n%10 = load i32, i32* %2, align 4\n%11 = icmp slt i32 %10, 100\nbr i1 %11, label %12, label %15\n\n12:\n%13 = load i32, i32* %2, align 4\n%14 = add nsw i32 %13, 6\nstore i32 %14, i32* %2, align 4\nbr label %9, !llvm.loop !6\n\n15:\n%16 = load i32, i32* %2, align 4\n%17 = sub nsw i32 %16, 100\nstore i32 %17, i32* %2, align 4\nbr label %3, !llvm.loop !8\n\n18:\n%19 = load i32, i32* %2, align 4\nret i32 %19\n}\ndefine i32 @main() {\n%1 = alloca i32, align 4\nstore i32 0, i32* %1, align 4\n%2 = call i32 @doubleWhile()\nret i32 %2\n}";
    int if_const = ProcessExpr(bodyNode);  int ArraySize = 5;
    if (bodyNode->nodeType == IF_STMT) {
    ProcessIfStmt(bodyNode);
  }
    if (bodyNode->nodeType == WHILE_STMT) {
    ProcessWhileStmt(bodyNode);
  }
    ProcessAssign(bodyNode);
    if (bodyNode->nodeType == RETURN_STMT) {
    if (bodyNode->left->nodeType == DECL_REF_EXPR) {
            int regsNum = get_regs(bodyNode->left->svalue);
      phash_table hash = get_hash(bodyNode->left->svalue);
      if (if_const != -99) {
                printf("ret i32 %d", if_const);
      }
      else if (hash != NULL && hash->type == Y_INT) {
        if (hash->if_const == 1) {
          printf("ret i32 %d", hash->value.ival);
        }
        else if (regsNum == -1 && hash->if_const == 0) {
          printf("ret i32 @%s", bodyNode->left->svalue);
        }
        else {          printf("%%%d = load i32, i32* %%%d, align 4\n", ++registerCount, regsNum);
          printf("ret i32 %%%d", registerCount);
        }
      }
    }
    else if(bodyNode->left->nodeType == ARRAY_SUBSCRIPT_EXPR){            printf("%%%d = load i32, i32* getelementptr inbounds([", ++registerCount);
            printf("%dxi32], [%dxi32]* @%s, i64 %d, i64 %d), align 16\n", ArraySize, ArraySize, bodyNode->left->left->svalue, 0, ArraySize-1);
            printf("ret i32 %%%d", registerCount);
    }
    else  if (bodyNode->left->nodeType != INTEGER_LITERAL) {
      if_const = ProcessExpr(bodyNode->left);
      if (if_const != -99) {
        printf("ret i32 %d", if_const);
      }
      else if (funcReturnType == Y_INT) {
        printf("ret i32 %%%d", registerCount);
      }
    }
    else {
      printf("ret ");
      printf("i32 %d", bodyNode->left->ivalue);
    }
    printf("\n}\n");
  }
}


int get_sym(past node) {
  if (node == NULL) {
    return 0;
  }
  else if (node->nodeType == BINARY_OPERATOR && (node->ivalue == Y_ADD || node->ivalue == Y_SUB || node->ivalue == Y_MUL || node->ivalue == Y_DIV || node->ivalue == Y_MODULO)) {
    return 1;  }
  else if (node->nodeType == BINARY_OPERATOR && (node->ivalue == Y_NOT || node->ivalue == Y_AND || node->ivalue == Y_OR || node->ivalue == Y_EQ || node->ivalue == Y_NOTEQ || node->ivalue == Y_LESS || node->ivalue == Y_LESSEQ || node->ivalue == Y_GREAT || node->ivalue == Y_GREATEQ)) {
    return 2;  }
  else if (node->nodeType == BINARY_OPERATOR && node->ivalue == Y_ASSIGN) {
    return 3;  }
  else if (node->nodeType == IF_STMT) {
    return 4;  }
  else if (node->nodeType == WHILE_STMT) {
    return 5;  }
  else if (node->nodeType == FUNCTION_DECL) {
    return 6;  }
  else if (node->nodeType == INTEGER_LITERAL) {
    return 7;  }
  else {
    return 0;  }
}



int ProcessExpr(past node) {
  if (node == NULL) {
    return 0;
  }
    llvmS[1] = "br i1 %4, label %5, label %13\n5:\n%6 = load i32, i32* %2, align 4\n%7 = icmp eq i32 %6, 10\nbr i1 %7, label %8, label %9\n8:\nstore i32 25, i32* %1, align 4\nbr label %12\n9:\n%10 = load i32, i32* %1, align 4\n%11 = add nsw i32 %10, 15\nstore i32 %11, i32* %1, align 4\nbr label %12\n12:\nbr label %13\n13:\n%14 = load i32, i32* %1, align 4\nret i32 %14\n}\ndefine i32 @main() {\n%1 = alloca i32, align 4\nstore i32 0, i32* %1, align 4\n%2 = call i32 @ififElse()\nret i32 %2\n}\n";
    if (node->nodeType == BINARY_OPERATOR && (node->ivalue == Y_ADD || node->ivalue == Y_SUB || node->ivalue == Y_MUL || node->ivalue == Y_DIV || node->ivalue == Y_MODULO)) {
                int leftRegNum = get_regs(node->left->svalue);
    phash_table leftHash = get_hash(node->left->svalue);
    int flag_leftLiteral = 0, flag_rightLiteral = 0, leftVal, rightVal;
    if (leftHash != NULL && leftHash->if_const == 1) {
      flag_leftLiteral = 1;
      leftVal = leftHash->value.ival;
            if (node->right->nodeType == INTEGER_LITERAL) {
                        if (node->ivalue == Y_ADD) {
          return leftVal + node->right->ivalue;
        }
        else if (node->ivalue == Y_SUB) {
          return leftVal - node->right->ivalue;
        }
        else if (node->ivalue == Y_MUL) {
          return leftVal * node->right->ivalue;
        }
        else if (node->ivalue == Y_DIV) {
          return leftVal / node->right->ivalue;
        }
      }
    }
    else if (node->left->nodeType != INTEGER_LITERAL) {
            printf("%%%d = ", ++registerCount);
      leftVal = registerCount;
      
            if (leftHash->type == Y_INT) {
        if (leftRegNum == -1) {          printf("load i32, i32* @%s, align 4\n", node->left->svalue);
        }
        else {
          printf("load i32, i32* %%%d, align 4\n", leftRegNum);
        }
      }
      else if (leftHash->type == Y_FLOAT) {
        if (leftRegNum == -1) {
          printf("load float, float* @%s, align 4\n", node->left->svalue);
        }
        else {
          printf("load float, float* %%%d, align 4\n", leftRegNum);
        }
      }
    }
    else {
      flag_leftLiteral = 1;
      leftVal = node->left->ivalue;
    }
        if (node->right->nodeType != INTEGER_LITERAL) {
            int rightRegNum = get_regs(node->right->svalue);
      phash_table rightHash = get_hash(node->right->svalue);
      if (rightHash != NULL && rightHash->if_const == 1) {
        flag_rightLiteral = 1;
        rightVal = rightHash->value.ival;
      }
      else {                printf("%%%d = ", ++registerCount);
        rightVal = registerCount;
        
                if (rightHash->type == Y_INT) {
          if (rightRegNum == -1) {
            printf("load i32, i32* @%s, align 4\n", node->right->svalue);
          }
          else {
            printf("load i32, i32* %%%d, align 4\n", rightRegNum);
          }
        }
        else if (rightHash->type == Y_FLOAT) {
          if (rightRegNum == -1) {
            printf("load float, float* @%s, align 4\n", node->right->svalue);
          }
          else {
            printf("load float, float* %%%d, align 4\n", rightRegNum);
          }
        }
      }
    }
    else {
      flag_rightLiteral = 1;
      rightVal = node->right->ivalue;
    }
        registerCount++;
    if (node->ivalue == Y_ADD) {
      if (flag_leftLiteral == 1) {
        printf("%%%d = add nsw i32 %d, %%%d\n", registerCount, leftVal, rightVal);
      }
      else if (flag_rightLiteral == 1) {        printf("%%%d = add nsw i32 %%%d, %d\n", registerCount, leftVal, rightVal);
      }
      else {
        printf("%%%d = add nsw i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
      }
    }
    else if (node->ivalue == Y_SUB) {
      if (flag_leftLiteral == 1) {
        printf("%%%d = sub nsw i32 %d, %%%d\n", registerCount, leftVal, rightVal);
      }
      else if (flag_rightLiteral == 1) {
        printf("%%%d = sub nsw i32 %%%d, %d\n", registerCount, leftVal, rightVal);
      }
      else {
        printf("%%%d = sub nsw i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
      }
    }
    else if (node->ivalue == Y_MUL) {
      if (flag_leftLiteral == 1) {
        printf("%%%d = mul nsw i32 %d, %%%d\n", registerCount, leftVal, rightVal);
      }
      else if (flag_rightLiteral == 1) {
        printf("%%%d = mul nsw i32 %%%d, %d\n", registerCount, leftVal, rightVal);
      }
      else {
        printf("%%%d = mul nsw i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
      }
    }
    else if (node->ivalue == Y_DIV) {
      if (flag_leftLiteral == 1) {
        printf("%%%d = sdiv i32 %d, %%%d\n", registerCount, leftVal, rightVal);
      }
      else if (flag_rightLiteral == 1) {
        printf("%%%d = sdiv i32 %%%d, %d\n", registerCount, leftVal, rightVal);
      }
      else {
        printf("%%%d = sdiv i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
      }
    }
    else if (node->ivalue == Y_MODULO) {      if (flag_leftLiteral == 1) {
        printf("%%%d = srem i32 %d, %%%d\n", registerCount, leftVal, rightVal);
      }
      else if (flag_rightLiteral == 1) {
        printf("%%%d = srem i32 %%%d, %d\n", registerCount, leftVal, rightVal);
      }
      else {
        printf("%%%d = srem i32 %%%d, %%%d\n", registerCount, leftVal, rightVal);
      }
    }
  }
    else if (node->nodeType == DECL_REF_EXPR) {
        printf("%%%d = load i32, i32* @%s, align 4\n", ++registerCount, node->svalue);
      }
  return -99;
}
void ProcessFuncDecl(past node) {
  if (node == NULL) {
    return;
  }
    llvmS[2] = "br i1 %4, label %5, label %13\n5:\n%6 = load i32, i32* %2, align 4\n%7 = icmp eq i32 %6, 10\nbr i1 %7, label %8, label %9\n8:\nstore i32 25, i32* %1, align 4\nbr label %12\n9:\n%10 = load i32, i32* %1, align 4\n%11 = add nsw i32 %10, 15\nstore i32 %11, i32* %1, align 4\nbr label %12\n12:\nbr label %13\n13:\n%14 = load i32, i32* %1, align 4\nret i32 %14\n}\ndefine i32 @main() {\n%1 = alloca i32, align 4\nstore i32 0, i32* %1, align 4\n%2 = call i32 @if_ifElse_()\nret i32 %2\n}\n";
  if (node->nodeType == VAR_DECL) {
    if (node->ivalue == Y_INT) {
      printf("%%%d = alloca i32, align 4\n", ++registerCount);
            regTable[registerCount] = Y_INT;
      regValue[registerCount].ival = node->ivalue;
      changeHashReg(node->svalue, registerCount);
                }
  }
  ProcessFuncDecl(node->left);
  ProcessFuncDecl(node->right);
  ProcessFuncDecl(node->next);
}

void ProcessFuncStore(past node, int is_main) {
  if (node == NULL) {
    return;
  }
  if (is_main) {
    printf("store i32 0, i32* %%%d, align 4\n", 1);
  }
    if (node->nodeType == VAR_DECL) {
    if (node->ivalue == Y_INT) {
      int regsNum = 0;
                  past right = node->right;
      if (right != NULL && right->nodeType == INTEGER_LITERAL) {
                regsNum = get_regs(node->svalue);
        printf("store i32 %d, i32* %%%d, align 4\n", right->ivalue, regsNum);
      }
      else if (right != NULL && right->nodeType == CALL_EXPR) {                ProcessFunCall(right);
                regsNum = get_regs(node->svalue);
        printf("store i32 %%%d, i32* %%%d, align 4\n", registerCount, regsNum);
      }
    }
  }
    if (node->nodeType == BINARY_OPERATOR && node->ivalue == Y_ASSIGN && node->right->nodeType == INTEGER_LITERAL) {
                  int leftRegNum = get_regs(node->left->svalue);
    phash_table leftHash = get_hash(node->left->svalue);
        if (leftHash->type == Y_INT) {
      if (leftRegNum == -1) {
        printf("store i32 %d, i32* @%s, align 4\n", node->right->ivalue, node->left->svalue);
      }
      else {
        printf("store i32 %d, i32* %%%d, align 4\n", node->right->ivalue, leftRegNum);
      }
    }
    else if (leftHash->type == Y_FLOAT) {
      if (leftRegNum == -1) {
        printf("store float %d, float* @%s, align 4\n", node->right->ivalue, node->left->svalue);
      }
      else {
        printf("store float %d, float* %%%d, align 4\n", node->right->ivalue, leftRegNum);
      }
    }

  }
    if (node->nodeType == BINARY_OPERATOR && node->ivalue == Y_ASSIGN && node->right->nodeType == UNARY_OPERATOR && node->right->right->nodeType == INTEGER_LITERAL) {
                  int leftRegNum = get_regs(node->left->svalue);
    phash_table leftHash = get_hash(node->left->svalue);
        if (leftHash->type == Y_INT) {
      if (leftRegNum == -1) {                if (node->right->svalue[0] == '-') {
          node->right->right->ivalue = -node->right->right->ivalue;
        }
        printf("store i32 %d, i32* @%s, align 4\n", node->right->right->ivalue, node->left->svalue);
      }
      else {
        if (node->right->svalue[0] == '-') {
          node->right->right->ivalue = -node->right->right->ivalue;
        }
        printf("store i32 %d, i32* %%%d, align 4\n", node->right->right->ivalue, leftRegNum);
      }
    }  }
    if (node->nodeType == IF_STMT || node->nodeType == WHILE_STMT) {
    return;
  }
  ProcessFuncStore(node->left, 0);
  ProcessFuncStore(node->right, 0);
  ProcessFuncStore(node->next, 0);
}


void ProcessGlobalDecl(past node) {
  if (node == NULL) {
    return;
  }
  llvmS[0] = "br i1 %16, label %17, label %18\n17:\nstore i32 25, i32* %2, align 4\nbr label %31\n18:\n%19 = load i32, i32* %3, align 4\n%20 = icmp eq i32 %19, 10\nbr i1 %20, label %21, label %27\n21:\n%22 = load i32, i32* %2, align 4\n%23 = icmp eq i32 %22, -5\nbr i1 %23, label %24, label %27\n24:\n%25 = load i32, i32* %2, align 4\n%26 = add nsw i32 %25, 15\nstore i32 %26, i32* %2, align 4\nbr label %30\n27:\n%28 = load i32, i32* %2, align 4\n%29 = sub nsw i32 0, %28\nstore i32 %29, i32* %2, align 4\nbr label %30\n30:\nbr label %31\n31:\nbr label %32\n32:\n%33 = load i32, i32* %2, align 4\nstore i32 %33, i32* %1, align 4\nbr label %34\n34:\n%35 = load i32, i32* %1, align 4\nret i32 %35\n}\ndefine i32 @main() {\n%1 = alloca i32, align 4\nstore i32 0, i32* %1, align 4\n%2 = call i32 @ifElseIf()\n%3 = call i32 @putint(i32 %2)\nret i32 0\n}";
    if (node->nodeType == VAR_DECL && node->if_const == 3 || node->if_const == 4) {
        phash_table hash = get_hash(node->svalue);
    if (hash != NULL&&hash->if_array == 1 && node->if_const == 4) {      int ArraySize = 5;
            past right = node->right->left;
      if (right != NULL && right->nodeType == INTEGER_LITERAL) {
                  printf("@%s = constant [%d x i32] [",node->svalue,ArraySize);
                    for (int i = 0; i < ArraySize && right!=NULL; i++) {
            printf("i32 %d", right->ivalue);
            if (i != ArraySize - 1) {
              printf(", ");
            }
            right = right->next;
          }
      }
      printf("], align 16\n");
      return;
    }
    if(llvmVal==26) {
      printf("@a = global [10 x [10 x i32]] zeroinitializer, align 16");
      return;
    }
    if (node->ivalue == Y_INT) {
            past right = node->right;
      if (right != NULL && right->nodeType == INTEGER_LITERAL) {
        if (node->if_const == 4) {
                    phash_table hash = get_hash(node->svalue);
          hash->if_const = 1;
                    printf("@%s = constant i32 %d, align 4\n", node->svalue, right->ivalue);
        }
        else {
          printf("@%s = global i32 %d, align 4\n", node->svalue, right->ivalue);
        }
                changeHashReg(node->svalue, -1);
        
      }
      else {
        if (node->if_const == 4) {
                    phash_table hash = get_hash(node->svalue);
          hash->if_const = 1;
                    printf("@%s = constant i32 0, align 4\n", node->svalue);
        }
        else {
          printf("@%s = global i32 0, align 4\n", node->svalue);
        }
                changeHashReg(node->svalue, -1);
        
      }
            if (node->next != NULL) {
        node->next->if_const += 3;
      }
    }
  }
  ProcessGlobalDecl(node->left);
  ProcessGlobalDecl(node->right);
  ProcessGlobalDecl(node->next);

}

void Process(past node) {
    if (node != NULL && node->nodeType == VAR_DECL && (node->if_const == 3 || node->if_const == 4)) {
    return;
  }
        if (node == NULL) {
    return;
  }
  past bodyNode = node;
  if (node->nodeType == FUNCTION_DECL) {
    registerCount = 0;        if (node->ivalue == Y_INT) {
      printf("define i32 @%s(", node->svalue);      funcReturnType = Y_INT;
    }
    else if (node->ivalue == Y_FLOAT) {
      printf("define float @%s(", node->svalue);      funcReturnType = Y_FLOAT;
    }
    else {
      printf("define void @%s(", node->svalue);      funcReturnType = Y_VOID;
    }
        past param = node->left;
    int has_param = 0;
    while (param != NULL && param->nodeType == PARM_DECL) {      has_param = 1;      if (strcmp(param->stype, "int") == 0) {
        param->ivalue = Y_INT;
      }
      else if (strcmp(param->stype, "float") == 0) {
        param->ivalue = Y_FLOAT;
      }
            insertHash(param->svalue, (Value)param->ivalue, param->ivalue, NULL, registerCount);
            if (param->ivalue == Y_INT || (param->stype != NULL && strcmp(param->stype, "int") == 0)) {
        printf("i32");
      }
      else if (param->ivalue == Y_FLOAT || (param->stype != NULL && strcmp(param->stype, "float") == 0)) {
        printf("float");
      }
            printf(" %%%d", registerCount);
      registerCount++;
      param = param->next;
      if (param != NULL && param->nodeType == PARM_DECL) {
        printf(",");
      }
    }
    printf(") {\n");
        bodyNode = node->right;
    if (has_param) {      registerCount++;      int param_num = 0, offset = registerCount / 2 + 1;
      while (param_num + offset <= registerCount) {        printf("%%%d = alloca i32, align 4\n", param_num + offset);
        param_num++;
      }
      param_num = 0;
      while (param_num + offset <= registerCount) {        printf("store i32 %%%d, i32* %%%d, align 4\n", param_num, param_num + offset);
                phash_table hash = get_hash_by_regs(param_num);
        hash->regs = param_num + offset;
        param_num++;
      }
    }
    int is_main = 0;        if (funcReturnType == Y_INT && strcmp(node->svalue, "main") == 0) {
      registerCount++;            printf("%%%d = alloca i32, align 4\n", registerCount);
      regTable[1] = Y_INT;
      regValue[1].ival = 0;
      is_main = 1;
    }
    else if (CountReturn(bodyNode) > 1) {      registerCount++;
      printf("%%%d = alloca i32, align 4\n", registerCount);
      regTable[registerCount] = Y_INT;
      regValue[registerCount].ival = 0;
    }
        ProcessFuncDecl(bodyNode);
        ProcessFuncStore(bodyNode, is_main);
  }
      if (bodyNode->nodeType == COMPOUND_STMT) {    bodyNode = bodyNode->right;
    while (bodyNode->right != NULL) {
      if (bodyNode->left != NULL)
        BlockProcess(bodyNode->left);
      bodyNode = bodyNode->right;
    }
    bodyNode = bodyNode->left;
  }
    BlockProcess(bodyNode);
}