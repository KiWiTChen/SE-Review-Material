# Exp2递归下降语法分析学习笔记

## 原理

递归下降分析器编译思想是简单的，从识别符号开始，在语法规则支配下进行语法分析，它逐个扫视源程序中的所有字符，根据文法和当前输入字符预测到下一个语法成份U时，便确定U为目标并调用分析和识别U的子程序，在分析U的过程中，又有可能确立其它(或自身)子目标并调用相应子程序，如此继续下去

## 内容

1、学习所提供的“表达式文法”的递归下降处理

理解 lex.l、rdparser.c 的内容

在 vscode/Clion 中建立工程并调试运行

2、学习所提供的文法

与词法分析所提供的文法作比较

3、编写 rdgram 所提供文法的递归下降程序

(1).编写不生成“语法树”的递归下降程序 rdcheck.c

(2).将 rdcheck.c 改造为生成语法树的递归下降程序 rdparser.c

(3).改进 词法分析程序、showAst 函数、main 函数等，使递归下降程

序 rdparser 最终从命令行读取要分析的程序 test.c,分析后调用 showAst 打印该程序的结构。

## GPT插曲

**请你分析关于编译原理中递归下降语法分析的代码**

当谈到编译原理中的递归下降语法分析时，通常是指一种通过递归调用来实现语法分析的方法。这种方法的代码结构与文法规则紧密相关，每个非终结符通常对应一个递归函数。以下是一个简单的例子，以帮助说明递归下降语法分析的基本思想。这里使用的是递归下降解析表达式的例子。

假设有如下文法：

```
E -> E + T | T
T -> T * F | F
F -> ( E ) | id
```

对应的递归下降语法分析代码可能如下：

```python
def parse_expression(tokens):
    return parse_E(tokens)

//parse_E 函数的目标是解析输入的标记流 tokens 中的表达式，并返回表达式的值
def parse_E(tokens):
    //调用 parse_T(tokens) 解析表达式的左操作数（或子表达式）。这个调用对应文法规则中的 T 非终结符。
    left_operand = parse_T(tokens)
    
    //检查 tokens 的第一个标记是否为 +。如果是，表示这是一个加法操作。它会消耗掉 + 标记，并递归调用 parse_E(tokens) 来解析右操作数（或右侧的子表达式）
    //检查 tokens[0] 的目的是查看标记流（tokens）中的第一个标记，以确定接下来的语法分析和处理逻辑。在递归下降语法分析中，每个递归函数负责解析特定的非终结符，并且通过检查当前输入流的第一个标记来决定如何处理。
    //在递归下降语法分析中，我们通常按照文法规则的产生式来处理非终结符，而文法规则的右侧通常以终结符或者其他非终结符开头。因此，通过查看输入流的第一个标记，我们能够确定应该执行哪个产生式的递归函数。
    if tokens[0] == '+':
        //移除并返回列表的第一个元素。在这个上下文中，tokens 很可能是一个包含标记的列表，而 tokens.pop(0) 则是从这个列表中移除并返回第一个标记。
        tokens.pop(0)  # Consume '+'
        right_operand = parse_E(tokens)
        //将左操作数和右操作数相加，并返回结果。这是因为在这个简化的例子中，我们只处理了加法操作，所以在这个阶段只需要执行加法操作
        return left_operand + right_operand
    else:
        //函数直接返回左操作数，因为在这种情况下，表达式已经结束或者下一个标记不是加法操作符。
        return left_operand

def parse_T(tokens):
    left_operand = parse_F(tokens)
    
    if tokens[0] == '*':
        tokens.pop(0)  # Consume '*'
        right_operand = parse_T(tokens)
        return left_operand * right_operand
    else:
        return left_operand

def parse_F(tokens):
    if tokens[0] == '(':
        tokens.pop(0)  # Consume '('
        expression_value = parse_E(tokens)
        tokens.pop(0)  # Consume ')'
        return expression_value
    else:
        return int(tokens.pop(0))  # Consume and return the value of 'id'
```

这个代码基于文法规则定义了四个递归函数，每个函数对应一个非终结符。在这个例子中，非终结符包括 `E`、`T` 和 `F`，终结符包括 `+`、`*`、`(`、`)` 和 `id`。递归函数的目标是通过递归调用来解析输入的标记流（tokens）并构建语法树。

要注意的一些要点：

1. 每个递归函数负责解析一个特定的非终结符，并根据文法规则进行相应的处理。
2. 递归函数的基本情况通常对应于文法规则中的终结符。
3. 递归函数之间存在相互调用，这是因为文法规则中的非终结符之间存在相互依赖关系。

这只是一个简单的例子，实际的编译器设计中，可能需要处理更复杂的文法、错误处理等问题。递归下降语法分析是一种直观且易于理解的方法，但对于一些左递归文法需要进行一些调整，以避免无限递归。

---

**请你介绍递归下降法中对产生式是如何处理的？**

在递归下降语法分析中，对每个文法产生式都对应一个递归函数。这些递归函数的目标是根据文法规则递归地解析输入，并构建语法树或执行其他相关任务。让我用一个简单的例子来说明递归下降法中对产生式的处理。

考虑如下文法：

```
E -> E + T | T
T -> T * F | F
F -> ( E ) | id
```

对应的递归下降法代码可能如下：

```python
def parse_E(tokens):
    left_operand = parse_T(tokens)
    
    if tokens[0] == '+':
        tokens.pop(0)  # Consume '+'
        right_operand = parse_E(tokens)
        return left_operand + right_operand
    else:
        return left_operand

def parse_T(tokens):
    left_operand = parse_F(tokens)
    
    if tokens[0] == '*':
        tokens.pop(0)  # Consume '*'
        right_operand = parse_T(tokens)
        return left_operand * right_operand
    else:
        return left_operand

def parse_F(tokens):
    if tokens[0] == '(':
        tokens.pop(0)  # Consume '('
        expression_value = parse_E(tokens)
        tokens.pop(0)  # Consume ')'
        return expression_value
    else:
        return int(tokens.pop(0))  # Consume and return the value of 'id'
```

在这个例子中，每个递归函数对应于文法中的一个非终结符。让我们逐步说明如何处理每个产生式：

1. **处理 E -> E + T | T:**
   - `parse_E` 函数首先调用 `parse_T` 函数，解析 `E` 的左侧操作数。
   - 然后，它检查输入流中的第一个标记是否为 `+`。如果是，就消耗掉 `+`，然后递归调用 `parse_E` 解析右侧操作数。
   - 返回左右操作数的和。

2. **处理 T -> T * F | F:**
   - `parse_T` 函数首先调用 `parse_F` 函数，解析 `T` 的左侧操作数。
   - 然后，它检查输入流中的第一个标记是否为 `*`。如果是，就消耗掉 `*`，然后递归调用 `parse_T` 解析右侧操作数。
   - 返回左右操作数的积。

3. **处理 F -> ( E ) | id:**
   - `parse_F` 函数首先检查输入流中的第一个标记。如果是 `(`，就消耗掉 `(`，然后递归调用 `parse_E` 解析括号内的表达式。
   - 如果第一个标记不是 `(`，那么它假设是一个终结符 `id`，消耗掉这个标记并返回其值。

每个递归函数对应于文法中的一个产生式，通过递归调用其他递归函数来解析产生式中的非终结符。这样，整个递归下降语法分析器就能够逐步地构建语法树，反映了输入中的语法结构。

**——总的来说就是递归函数解析产生式前两个产生式把计算符左右量交换更好理解，对于这两个产生式来说，一定是先处理一个T或F，然后接着处理看是否有相应的运算符——有则处理，没有就直接返回之前处理的量**

## 先辈的教程

分析[编译原理实验-递归下降语法分析_递归下降分析器-CSDN博客](https://blog.csdn.net/qq_61980594/article/details/130890376?spm=1001.2014.3001.5502)

我们首先是实现main函数，用死循环函数实现多次对输入文法进行递归下降语法分析；具体来说循环内先执行advance()，判定ComUnit()返回值，从而输出最后到底符不符合SysY文法规则

现在介绍advance()函数，tok = yylex()并输出yytext

---

### **插入GPT解析**

这行代码 `tok = yylex()` 看起来可能是编译器或解释器中词法分析器（lexer）的一部分。我将解释一下这行代码通常是如何工作的，基于编译器构建中的常见约定。

1. **`yylex()` 函数:**
   - `yylex()` 通常是由词法分析器生成器（如 Lex 或 Flex）生成的函数。该函数负责扫描输入源代码并返回下一个标记（token）。
   - 名称 "yylex" 是一种约定，具体的名称可能取决于所使用的词法分析器生成器。

2. **`tok` 变量:**
   - 这行代码 `tok = yylex()` 调用了词法分析器函数 `yylex()`，并将结果（下一个标记）赋给变量 `tok`。

这里是这行代码通常如何工作的详细过程：

- **标记化（Tokenization）:**
  - `yylex()` 函数对输入源代码执行标记化。标记化涉及将输入代码分解成有意义的单元，称为标记，例如标识符、关键字、运算符等。

- **返回值:**
  - `yylex()` 函数返回在源代码中遇到的下一个标记。
  - `tok` 变量的确切性质取决于词法分析器的设计和所使用的编程语言或工具。

- **标记的使用:**
  - 一旦获取了标记，它可以由解析器在编译器或解释器的后续阶段使用。解析器使用这些标记来识别源代码的语法结构。

这里是一个简单的示例，说明标记可能是如何使用的：

```python
# 假设一个假设的解析器函数
def parse_statement():
    token = yylex()

    if token == 'ID':
        # 处理标识符
        identifier_name = token.value
        # 针对标识符的其他解析逻辑
    elif token == 'NUM':
        # 处理数字
        number_value = token.value
        # 针对数字的其他解析逻辑
    # 其他标记类型的更多情况...

# 主程序中的示例用法
while True:
    parse_statement()
```

在这个示例中，`parse_statement()` 调用 `yylex()` 来获取下一个标记，然后根据标记的类型处理语句。循环一直持续，直到源代码的结尾。这是一个简化的示例，实际的代码可能涉及更复杂的解析逻辑和错误处理。

---

#### 我们首先编写不生成语法树的递归下降程序 rdcheck.c

**match()函数是判定传入的x和当前的tok是否相等，相等返回1，不相等返回-1**

match()和advance()用这两个函数来实现将所输入的字符串与sysy文法进行逐一匹配。match函数主要用来检查sysy文法中的终结符是否与输入串中的当前字符匹配，如果匹配那么就是用调用advance，将下一个待分析的字符设置为当前字符，之后再调用文法中剩余字符对应的函数进行匹配；如果不匹配，则返回-1，表示文法匹配出错。

这里明确开始符号ComUnit文法规则

![image-20231123203449589](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123203449589.png)

由于其包含公共左因子，所以我们首先要消除公共左因子，改造后的语法规则如图所示。

![image-20231123203514392](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123203514392.png)

其对应的语法分析函数CompUnit， CompUnit_

这里插一句：明明很简单的东西，自己就是能拖就拖，当时不好好看一眼，现在难受感受到压力，不如早点吃苦

其实就是实现了这两种语法规则的处理

ComUnit()就是判断Decl和FuncDef，或者空，如果是正常的前两种，自己就跟着做移进＋原式

![image-20231123203611776](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123203611776.png)

sysy文法程序开始可能包含两个部分变量或常量声明（定义）和函数定义。

如果输入串是变量或常量声明，那么就进入其对应语法规则左侧非终结符函数Decl()，进行下一步的匹配；如果是函数定义，那么就进入对应的函数FuncDef，进行下一步的匹配。如果下一步也匹配成功，则说明输入串符合sysy文法，并返回1，否则，则表明输入串不符合sysy文法，返回0。

对于sysy文法中的语句Stmt的文法规则

![image-20231123203814774](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123203814774.png)

由于该文法规则中含有公共左因子，所以需要消除其公共左因子，改造后的文法规则如图所示。

![image-20231123203846419](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123203846419.png)

对应的Stmt函数如图

![image-20231123203954587](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123203954587.png)

![image-20231123204007265](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204007265.png)

![image-20231123204019749](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204019749.png)

以及Stmt_1 Stmt_2

![image-20231123204059031](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204059031.png)

假设输入串是一个while语句，那么在Stmt函数中，match函数会首先匹配while语句中前缀部分的终结符：‘while’、‘（’，之后需要匹配一个由非终结符LorExp产生的循环条件表达式单词序列，因此进入对应的函数LorExp，识别由该非终结符生成的单词序列。之后继续使用match函数匹配非终结符‘）’，最后进入函数Stmt，匹配由非终结符Stmt产生的单词序列。

![image-20231123204259490](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204259490.png)

对于sysy文法中的表达式Exp的语法规则

![image-20231123204322877](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204322877.png)

对应的Exp函数

![image-20231123204337749](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204337749.png)

在sysy文法中，表达式就是加减表达式，因此在对表达式进行递归下降语法分析时，会进入AddExp函数，识别由非终结符AddExp产生的单词序列。

该递归下降分析程序对输入串“int main(){while(1==2){return 0;}}”的识别结果

![image-20231123204403939](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204403939.png)

之前的是编写不生成语法树的递归下降程序 rdcheck.c，现在变换：

#### 生成语法树

**现在将 rdcheck.c 改造为生成语法树的递归下降程序 rdparser.c**

将rdcheck.c改造后，生成Stmt语句结点的函数astStmt如图

我们程序的主体内容是if结构，进行匹配，首先是开辟足够容量的存储空间，存储当前内容后移进，然后获取下一个内容并据此判定

请铭记这里是根据上面来改的，主体的if还是上面的，多的是

![image-20231123204616599](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204616599.png)

![image-20231123204815819](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204815819.png)

![image-20231123204831598](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204831598.png)

![image-20231123204848375](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204848375.png)

![image-20231123204859763](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204859763.png)

在语句结点中，关于if语句结点生成的代码部分如图

![image-20231123204920405](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204920405.png)

我们对if的不同进行说明：

在构建抽象语法树（AST）的过程中，我们将舍弃一些无用的界符，例如‘；’、‘（’、‘）’等，方便编译后续阶段的进行。因此在构建if语句结点时，用match匹配终结符‘if’、‘（’并将其舍弃，如果匹配成功则之后进入函数astLorExp，生成条件判断表达式结点l；反之匹配失败，返回NULL。之后匹配终结符‘）’并将其舍弃，如果匹配成功，那么就进入函数astStmt，生成复合语句结点CompoundStmt，反之则匹配失败，返回NULL。之后，如果能够匹配字符‘else’，那么就继续进入astStmt函数，生成复合语句结点CompoundStmt，最后返回生成的if语句结点；反之，则输入串中无else语句，那么直接返回不含else语句的if语句。

对于生成加减表达式结点的函数astAddExp定义如图

![image-20231123204953881](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123204953881.png)

在生成加减表达式结点的时候，根据AddExp文法可知，**加减表达式包含右递归，其每个操作数都可能是由若干个其他表达式构成，因此采用while循环结构来生成加减表达式结点。**

#### 进一步改进词法分析程序、showAst 函数、main 函数等，使递归下降程序 rdparser最终从命令行读取要分析的程序 test.c,分析后调用 showAst 打印该程序的结构。

改进后的main函数如图

```C
int main(int argc, char **argv){
	advance();
	past node = astCompUnit();
	showAst("|", node, 0);
	return 0;
}
```

从文法开始符号CompUnit对应的函数astCompUnit开始构建输入串的抽象语法树（AST），并将抽象语法树（AST）的根节点返回给node，之后调用函数showAst打印生成的抽象语法树（AST）。

改进后的showAst函数

```C
void showAst(char* sym, past node, int nest){
	if(node == NULL)
		return;
	int i = 0;
	for(i = 0; i < nest; i ++)
		printf("  ");
	if(node->nodeType == TRANSLATION_UNIT){
		printf("%s-%s\n", sym, node->snodeType);
		showTranstion(node, nest + 1);
		return;
	} else if(node->nodeType == INTEGER_LITERAL){
		printf("%s-%s  %d\n", sym, node->snodeType, node->ivalue);
	} else if(node->nodeType == FLOATING_LITERAL){
		printf("%s-%s  %f\n", sym, node->snodeType, node->fvalue);
	} else if(node->nodeType == IF_STMT){
		printf("%s-%s  %s\n", sym, node->snodeType, node->svalue);
		showAst("|", node->if_cond, nest+1);
	} else if(node->nodeType == FUNCTION_DECL){
		printf("%s-%s  %s '%s'\n", sym, node->snodeType, node->svalue, node->stype);
	} else if(node->nodeType == PARM_DECL){
		showParaDecl(node);
		return;
	} else if(node->nodeType == COMPOUND_STMT){
		printf("%s-%s\n", sym, node->snodeType);
		node = node->right;
		showCompoundStmt(node, nest + 1);
		return;
	} else if(node->nodeType == VAR_DECL){
		printf("%s-%s  %s '%s'\n", sym, node->snodeType, node->svalue, node->stype);
	} else if(node->nodeType == CALL_EXPR){
		printf("%s-%s  %s\n", sym, node->snodeType, node->svalue);
		node = node->left;
		showCallExp(node, nest + 1);
		return;
	} else if(node->svalue != NULL){
		printf("%s-%s  '%s'\n", sym, node->snodeType, node->svalue);
	} else{
		printf("%s-%s\n", sym, node->snodeType);
	}
	showAst("|", node->left, nest+1);
	showAst("`", node->right, nest+1);
}
```

在showAst函数中，对与不同的结点类型，我们将打印不同的信息。

对于函数形参结点，我们调用showParaDecl函数对其所包含的结点进行打印，如下所示。由于构建函数形参结点的时候我们是逆序构建，因此需采用非递归中序遍历的算法对其结点进行打印，以便保证函数形参顺序的正确。

```C
void showParaDecl(past node){ //函数参数，非递归中序遍历
	if(node == NULL){
		return;
	}
	int i = paranum;
	past stack[paranum];
	int top = 0;
    while(top || node){
		if(node != NULL){ 
			stack[top++] = node;
            node = node->left;
        }else if(top != 0){   
			node = stack[--top];
			if(i == paranum){
				printf("|-%s  used %s '%s'\n", node->snodeType, node->svalue, node->stype);
				i--;
			} else {
				printf("    |-%s  used %s '%s'\n", node->snodeType, node->svalue, node->stype);
			}
            node = node->right;
        }
    }
}
```

对于复合语句，我们调用showCompoundStmt函数对其所包含的结点进行打印，如下所示。由于构建函数形参结点的时候我们是顺序序构建，并且假定只有left结点才是真正的语句结点，因此我们只需逐一访问每一层复合语句结点的左子结点并打印其所包含的信息即可。

```C
void showCompoundStmt(past node, int nest){ //复合语句遍历
	if(node == NULL){
		return;
	}
	while(node->right != NULL){
		showAst("|", node->left, nest);
		node = node->right;
	}
	showAst("`", node->left, nest);
}
```

对于函数调用结点，我们调用showCallExp函数对其所包含的结点进行打印，如图3-5所示。由于构建函数形参结点的时候我们是顺序序构建，并且假定只有left结点才是真正的语句结点，因此我们只需逐一访问每一层复合语句结点的左子结点并打印其所包含的信息即可。

```C
void showCallExp(past node, int nest){ //函数调用遍历
	if(node == NULL){
		return;
	}
	while(node->right != NULL){
		showAst("|", node->left, nest);
		node = node->right;
	}
	showAst("`", node->left, nest);
}
```

对于编译单元，我们调用showTranstion函数对其所包含的结点进行打印，如图3-6所示。由于构建函数形参结点的时候我们是顺序序构建，并且只有left结点才是变量结点或常量结点或者函数定义节点，因此我们只需逐一访问每一层编译单元结点的左子结点并打印其所包含的信息即可。

```C
void showTranstion(past node, int nest){ ////编译单元
	if(node == NULL){
		return;
	}
	while(node->right != NULL){
		showAst("|", node->left, nest);
		node = node->right;
	}
	showAst("`", node->left, nest);
}
```

现在我们走到最后一步

#### 实验运行结果

（1）测试用例1：在终端输入字符串“int main(int m, int n){l = 1 + 2; while(1 == 2){ l = l + 1;} }” ，程序运行结果如图4-1所示。

![image-20231123205531168](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123205531168.png)

（2）测试用例2：在终端输入字符串“int main(int m, int n){l = 1 + 2; if(1 > 2){return 1;} } ” ，程序运行结果如图4-2所示。

![image-20231123205544152](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123205544152.png)

（3）测试用例3：在终端输入字符串“int main(int m, int n){l = 1; if(6 < 2){return 1;}else {return 5;} }” ，程序运行结果如图4-3所示。

![image-20231123205558502](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123205558502.png)

（4）测试用例4：在终端输入字符串“int func(){return 1;} int main(){int l = func();}”,程序运行结果如图4-4所示。

![image-20231123205609128](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123205609128.png)

### 结论

​    本次实验所实现的递归下降分析程序，能够完成对sysy文法中函数定义、函数形参、语句块、语句、表达式等部分的语法分析，并能够生成相应的抽象语法树（AST）。较好的完成了本次实验的要求。

​    通过本次实验，了解和掌握了递归下降分析法的基本原理，并且能够根据给出的文法完成递归下降程序的实现。同时也对编译过程中词法分析这一环节有了一个更加深刻的认知。同时，在实验的过程中也逐渐地的意识到递归下降分析法的缺陷所在：对含有公共左因子和左递归的文法词法分析效果较差。

----

## Wave教程

分析[递归下降语法分析 实验实现（电子科技大学编译技术Icoding实验）-CSDN博客](https://blog.csdn.net/WJwwwwwww/article/details/134100467?spm=1001.2014.3001.5502)

梳理一下给定代码，“//”注释并不是我写的

### 代码分析 enum yytokentype{}

第一个枚举类型`yytokentype`，其中列举了一些标记（tokens）的类型和相应的整数值。这通常用于语法分析器（parser）中，特别是在编写递归下降语法分析器时，以区分不同类型的词法单元。

整数值通常用于在语法分析中识别不同的标记。例如，当分析器扫描到一个标识符（ID）时，可以将其标记为 `Y_ID`，通过整数值 `260` 来表示。

标记类型可能对应于编程语言中的关键字、运算符、常量等。例如，`Y_IF` 对应于 if 关键字，`Y_WHILE` 对应于 while 关键字等等。这种标记的定义是语法分析器根据语法规则将源代码分解为语法单元的基础。

在递归下降语法分析器中，可能会使用这些标记类型来编写递归下降规则，每个规则对应于语法中的一个非终结符。在规则中，分析器会递归地调用自身，以匹配源代码中的语法结构。

### typedef struct _TokenType{}

定义了一个名为 `TokenType` 的结构体，用于表示词法分析器中的标记（token）。结构体包含两部分：一个枚举类型 `yytokentype` 的成员 `token` 用于表示标记的类型，以及一个联合（union）类型 `attr`，其中包含三个成员：

1. `ivalue`：表示整数值的成员，用于存储整数型标记的具体值。
2. `fvalue`：表示浮点数值的成员，用于存储浮点型标记的具体值。
3. `svalue`：表示字符串值的成员，用于存储字符串型标记的具体值。

通过这种结构，你可以灵活地表示不同类型的标记及其具体值。在实际的词法分析器中，当扫描到一个标记时，可以创建一个 `TokenType` 结构体的实例，设置 `token` 成员为对应的标记类型，然后根据标记类型设置 `attr` 成员中的具体值。

例如，如果扫描到一个整数标记，可以设置 `token` 为 `num_INT`，然后将具体的整数值存储在 `ivalue` 中。如果是一个浮点数标记，可以设置 `token` 为 `num_FLOAT`，然后将具体的浮点数值存储在 `fvalue` 中。对于字符串标记，可以设置 `token` 为 `Y_ID`（或其他字符串相关的标记），然后将字符串值存储在 `svalue` 中。

### 猜测函数作用

1. `void set_cur_tok_index(int ind);`

	- **可能作用：** 设置当前标记（token）的索引。
	- **猜测：** 可能用于在语法分析的过程中更新当前标记的索引，以便于跟踪当前正在分析的标记。

2. `int get_cur_tok_index();`

	- **可能作用：** 获取当前标记（token）的索引。
	- **猜测：** 可能用于查询当前正在分析的标记在源代码中的位置，以便于错误处理或者生成调试信息。

3. `TokenType advance();`

	- **可能作用：** 将当前标记（token）移动到下一个标记。
	- **猜测：** 可能用于在语法分析的过程中前进到下一个标记，以便递归下降分析器能够继续处理下一个语法单元。

4. `extern TokenType cur_token;`

	- **可能作用：** 表示当前正在分析的标记。
	- **猜测：** 可能用于在递归下降分析器的不同函数之间传递和共享当前标记，以便于进行分析操作

	

1. **`enum Non_terminator`：**
	- **可能作用：** 定义非终结符的枚举。
	- **猜测：** 该枚举可能包含了一些在语法分析中用作非终结符的符号，用于表示语法规则的左侧。这些非终结符可能对应于编程语言中的语法结构，如语句、表达式等。
2. **`typedef struct _ast ast;`：**
	- **可能作用：** 定义了一个结构体类型 `ast`。
	- **猜测：** `ast` 可能是用于表示抽象语法树节点的结构体，其中包含了与语法树相关的信息。这可能包括节点类型、值、子节点等。
3. **`typedef struct _ast \*past;`：**
	- **可能作用：** 定义了一个指向 `ast` 结构体的指针类型 `past`。
	- **猜测：** `past` 可能用于引用和操作抽象语法树节点的指针类型。这种方式允许通过指针在语法树中进行导航和修改

### struct _ast{}

```C
struct _ast {
    int ivalue;       // 整数值，可能用于存储整数型节点的值
    float fvalue;     // 浮点数值，可能用于存储浮点型节点的值
    char* svalue;     // 字符串值，可能用于存储字符串型节点的值
    node_type nodeType;// 节点类型，可能是枚举类型，表示该节点的语法结构类型
    past left;        // 左子树节点的指针
    past right;       // 右子树节点的指针
    past if_cond;     // if 语句条件表达式的指针
    past next;        // 链表中下一个节点的指针
};
```

这种结构体的设计通常用于构建和表示语法树，以便在语法分析的过程中组织和存储源代码的语法结构

### 库函数

1. **`past rd_block();`**
	- **可能作用：** 读取并返回一个代码块（block）的抽象语法树表示。
	- **猜测：** 这个函数可能负责解析源代码中的代码块，并返回一个相应的抽象语法树节点。
2. **`past rd_array_subscripts();`**
	- **可能作用：** 读取并返回数组下标的抽象语法树表示。
	- **猜测：** 这个函数可能用于解析源代码中的数组下标，并返回一个表示数组下标的抽象语法树节点。
3. **`past newAstNode();`**
	- **可能作用：** 创建并返回一个新的抽象语法树节点。
	- **猜测：** 这个函数可能是一个通用的工具函数，用于创建一个空的抽象语法树节点，该节点可以在后续的代码中填充具体的信息。
4. **`past newID(char\* value);`**
	- **可能作用：** 创建并返回一个表示标识符的抽象语法树节点。
	- **猜测：** 这个函数可能用于创建一个表示标识符的抽象语法树节点，其中 `value` 参数表示标识符的名称。
5. **`past newInt(int value);`**
	- **可能作用：** 创建并返回一个表示整数常量的抽象语法树节点。
	- **猜测：** 这个函数可能用于创建一个表示整数常量的抽象语法树节点，其中 `value` 参数表示整数的具体值。

### 需求函数

1. **`past rd_call_paras();`**
	- **可能作用：** 读取并返回函数调用的参数列表的抽象语法树表示。
	- **猜测：** 这个函数可能用于解析源代码中的函数调用参数列表，并返回一个表示参数的抽象语法树节点。
2. **`past rd_relexp();`**
	- **可能作用：** 读取并返回关系表达式（比较表达式）的抽象语法树表示。
	- **猜测：** 这个函数可能用于解析源代码中的关系表达式，包括比较运算符（如 `<`, `>`, `<=`, `>=`）等，并返回相应的抽象语法树节点。
3. **`past rd_stmt();`**
	- **可能作用：** 读取并返回语句的抽象语法树表示。
	- **猜测：** 这个函数可能用于解析源代码中的语句，包括各种类型的语句，如赋值语句、条件语句、循环语句等，并返回相应的抽象语法树节点。

```C
#include <stddef.h>
#include "node_type.h"

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

typedef struct _TokenType{
	enum yytokentype token;
	union {
		int		ivalue;
		float   fvalue;
		char*	svalue;
	}attr;
}TokenType;


void set_cur_tok_index(int ind); // 没用到
int get_cur_tok_index(); // 没用到
TokenType advance();
extern TokenType cur_token;


///Non-terminator，不知道在哪用，没有用到
enum Non_terminator
{
    。。。
};

typedef struct _ast ast;
typedef struct _ast *past;

struct _ast{
	int ivalue;
	float fvalue;
	char* svalue;
	node_type nodeType;
	past left;
	past right;
	past if_cond;
	past next;
};


// 库提供的函数
past rd_block();
past rd_array_subscripts();

past newAstNode();
past newID(char* value); // 没用到
past newInt(int value);

// 要完成的函数
past rd_call_paras();
past rd_relexp();
past rd_stmt();

```

### 我们介绍一下节点设计

```C
typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
	int ivalue; // 这三个储存节点的值
	float fvalue;
	char* svalue;
	node_type nodeType; // 节点类型
	past left;
	past right;
	past if_cond; // if_cond 仅限于 if 语句中的条件
	past next; // 并列关系
};
```

其实不合理，该节点的如果是[操作符]，只能保存到 `ivalue` 中，可 `ivalue` 一看就是保存整型数值的，但改不了其数据结构，只能将就用

只有 `if` 语句节点才有“三只脚”

**并列关系必须由 next 指针串联**

并列关系通常出现在参数列表：在函数或方法的定义中，参数通常是并列的，它们的顺序与声明顺序相同。例如，以下是一个函数定义的AST，其中参数 `param1` 和 `param2` 是并列的：

`param1` 和 `param2` 是函数参数的并列节点

```
[FunctionDeclaration]
├── [Parameter param1]
└── [Parameter param2]
```

### 我们介绍NodeType

`node_type`是不同类型的节点类型（声明、表达式、语句等）枚举值，简要描述

![image-20231123210633482](C:\Users\李在渊\AppData\Roaming\Typora\typora-user-images\image-20231123210633482.png)

### 我们介绍具体实现

**——这里的函数主要分为两类，new和rd类**

以"new"开头的函数（例如 newWhileStmt、newIfStmt、newCompoundStmt、newBinaryOper、newParaDecl、newBreakStmt、newContinueStmt 和 newReturnStmt）是用于创建新的AST节点的函数。这些函数用于构造AST的不同节点类型，并返回一个新的AST节点。这些函数通常接受一些参数，用于指定节点的属性和子节点。

以 “rd” 开头的函数（例如 rd_add_exp、rd_mul_exp、rd_unary_exp、rd_primary_exp、rd_l_or_exp、rd_l_and_exp 和 rd_eq_exp）是用于构建抽象语法树（AST）的函数。它们执行递归下降语法分析，根据文法规则逐步构造AST的不同部分。这些函数通常返回AST的一部分，如表达式、运算符等。

#### new类函数

##### 二元操作节点

```C
// 创建一个新的二元操作节点
past newBinaryOper(int oper, past left, past right) {
    past node = newAstNode();
    if (node) {
        // 设置节点的类型为二进制操作符
        node->nodeType = BINARY_OPERATOR;
        // 存储操作符
        node->ivalue = oper;
        // 存储左右操作数
        node->left = left;
        node->right = right;
    }
    return node;
}
```

下图中，方括号 `[]` 表示节点，节点包含不同的值，如 `5` 和 `3` 是整数节点，`+` 和 `*` 是二元操作节点

```
       [*]
      /   \
    [+]    [2]
   /   \
  [5]  [3]
```

##### 声明引用表达式节点

```C
// 创建一个新的声明引用表达式节点
past newDeclRefExp(char *name, past left, past right) {  
    past node = newAstNode();
    if (node) {
        // 设置节点的类型为声明引用表达式
        node->nodeType = DECL_REF_EXPR;
        // 存储名称
        node->svalue = name;
        // 存储左右子节点
        node->left = left;
        node->right = right;
    }
    return node;
}
```

例如 x = 42;

在这个片段中，我们有一个变量声明 `int x`，然后将其初始化为 `42`，我们可以使用 `newDeclRefExp` 函数来表示变量 `x` 的引用 

past left = newDeclRefExp("x", NULL, NULL);

这行代码创建了一个声明引用表达式节点，表示变量 `x` 的引用。`"x"` 是标识符的名称，`NULL` 被用作左右子节点，因为在这个上下文中，没有子节点。这个节点可以用以下方式表示：

这个节点表示了对变量 `x` 的引用

   [x]

接下来，如果我们希望创建一个表示整个初始化语句的赋值表达式，我们可以使用 上面的 `newBinaryOper` 函数： 

past assignment_expr = newBinaryOper(Y_ASSIGN, identifier_ref, newInt(42));

这里，我们将标识符引用节点作为左操作数，将整数常量节点（`newInt(42)`）作为右操作数，并将操作符 `Y_ASSIGN` 传递给 `oper` 参数。这将创建一个表示赋值操作的二元操作节点

```
       [=]
      /   \
    [x]   [42]
```

##### while 语句节点

```C
// 创建一个新的 while 语句节点
past newWhileStmt(past condition, past body) {
    past node = newAstNode();
    if (node) {
        // 设置节点的类型为 while 语句
        node->nodeType = WHILE_STMT;
        // 存储条件表达式和循环体
        node->left = condition;
        node->right = body;
    }
    return node;
}
```

示例，表示一个简单的 `while` 循环：

while (Condition) {
    Body
}

对应的语法树结构如下所示：

```
     [WHILE_STMT]
       /       \
 [Condition]    [Body]
```

##### if 语句节点

```C
// 创建一个新的 if 语句节点
past newIfStmt(past condition, past ifBody, past elseBody) {
    past node = newAstNode();
    if (node) {
        // 设置节点的类型为 if 语句
        node->nodeType = IF_STMT;
        // 存储条件表达式、if 分支和else分支
        node->if_cond = condition;
        node->left = ifBody;
        node->right = elseBody;
    }
    return node;
}
```

以下是一个简单的 `if` 语句的示例：

if (Condition) {
    IF_BODY
} else {
    ELSE_BODY
}

对应的抽象语法树结构：

```
           [IF_STMT]
        /      |      \
[Condition] [IF_BODY] [ELSE_BODY]
```

##### break 语句节点

```C
// 创建一个新的 break 语句节点
past newBreakStmt() {   
    past node = newAstNode();
    if (node) {
        // 设置节点的类型为 break 语句
        node->nodeType = BREAK_STMT;
    }
    return node;
}
```

“break” 语句通常用于从循环中跳出，例如 `for` 或 `while` 循环；这个节点没有左子节点或右子节点，因为它不包含表达式或操作数

[BREAK_STMT]

##### continue 语句节点

```C
// 创建一个新的 continue 语句节点
past newContinueStmt() {
    past node = newAstNode();
    if (node) {
        // 设置节点的类型为 continue 语句
        node->nodeType = CONTINUE_STMT;
    }
    return node;
}
```

同理，它不包含表达式或操作数，没有左子节点或右子节点

[CONTINUE_STMT]

##### return 语句节点

```C
// 创建一个新的 return 语句节点
past newReturnStmt(past left, past right) {
    past node = newAstNode();
    if (node) {
        // 设置节点的类型为 return 语句
        node->nodeType = RETURN_STMT;
        // 存储返回表达式
        node->left = left;
        node->right = right;
    }
    return node;
}
```

如果函数不返回任何值（即 return;），那么左子节点将为空，右子节点也将为空

在实际使用中，right 通常会为空，因为一个 return 语句只能返回一个值

所以，一般情况下，你可以只传递一个值给 newReturnStmt 函数，将其作为 left 参数，而将 right 参数设置为 NULL。

例如

past returnValue = astAddExp(); // 假设 astAddExp() 返回一个表达式节点
past returnStatement = newReturnStmt(returnValue, NULL);

在这个示例中，`returnValue` 是你要返回的值的表达式节点，而 `returnStatement` 就是一个包含了这个返回值的 `return` 语句节点

```
 [RETURN_STMT]
      |
 [ReturnValue]
```

#### “rd” 解析函数

##### 基本表达式

```
PrimaryExp: Y_LPAR Exp Y_RPAR
          | LVal
          | num_INT
          | num_FLOAT
          
LVal: Y_ID
    | Y_ID ArraySubscripts
```

- LVal
	- 简单标识符：`x`
	- 带有数组下标的标识符：`arr[2]`
- `42`：一个整数常量
- `(x + y)`：一个用括号括起来的表达式

```C
// 解析基本表达式
past rd_primary_exp() {
    past node = NULL; // 初始化节点为NULL

    if (cur_token.token == Y_LPAR) { // (表达式)
        advance(); 
        node = rd_add_exp(); // 见下面的rd_add_exp()函数
        if (cur_token.token != Y_RPAR) { // 缺右括号
            return NULL; 
        }
        advance(); 
    } else if (cur_token.token == Y_ID) { // LVal
        char *s = cur_token.attr.svalue;
        past Arr = rd_array_subscripts();
        node = newDeclRefExp(s, Arr, NULL);
        advance();
    } else if (cur_token.token == num_INT) { 
        node = newInt(cur_token.attr.ivalue); // 构造整数节点
        advance(); 
    } else if (cur_token.token == num_FLOAT) { 
        node = newAstNode(); // 构造浮点数节点
        advance(); 
        node->fvalue = cur_token.attr.fvalue;
    }

    return node; // 返回表达式树
}
```

最后其得到的会是：

- 跟加法表达式一样的（见下面）
- 一个单节点：标识符 / 数组 / 整数 / 浮点数

#####  一元表达式

```
UnaryExp: PrimaryExp
        | Y_ID Y_LPAR Y_RPAR
        | Y_ID Y_LPAR CallParams Y_RPAR
        | Y_ADD UnaryExp
        | Y_SUB UnaryExp
        | Y_NOT UnaryExp                    

```

- PrimaryExp
- `-x`：表示对变量 x 取负
- `!flag`：表示对变量 flag 进行逻辑非操作
- `++i`：表示对变量 i 进行递增操作
- `func(a, b)`：一个函数调用表达式

```C
// 解析一元表达式
past rd_unary_exp() {
    past node = rd_primary_exp(); // 获取基本表达式

    while (node == NULL) { // 当基本表达式为空时
        if (cur_token.token == Y_ID) { // 当当前符号为标识符时
            char *s = cur_token.attr.svalue;
            advance();
            if (cur_token.token == Y_LPAR) {
                advance();
				past params = NULL;
                if (cur_token.token != Y_RPAR) {
                    params = rd_call_paras(); // 解析函数调用参数
                }
                node = newDeclRefExp(s, params, NULL); // 构造声明引用表达式
            }
        } else if (cur_token.token == Y_ADD || cur_token.token == Y_SUB || cur_token.token == Y_NOT) { // 当当前符号为加号、减号或取反符号
            int oper = cur_token.token; // 记录运算符
            advance(); 
            past operand = rd_unary_exp(); // 获取一元表达式
            node = newBinaryOper(oper, NULL, operand); // 构造二元操作表达式
        } else {
            return NULL; // 无法匹配其他情况，返回空
        }
    }

    return node; // 返回表达式树
}

```

例1：

-5
初始时，cur_token.token 指向负号 -

第一次循环：

当前不是基本表达式，进入循环
当前符号不是 Y_ID，进入 else if
记录运算符为减号 (Y_SUB)
调用 advance() 向前移动，现在当前标记是数字 5
再次调用 rd_unary_exp() 函数，这次是基本表达式，会获取一元表达式，得到节点表示数字 5
使用 newBinaryOper() 构建一个二元操作表达式，操作符为减号，左子树为空，右子树为数字 5

结果为：

  [-]
   |
  [5]



例2：

func(a, b)

最后得到：

       [DECL_REF_EXPR]
            /   \
       "func"   [a] —— [b]                           

##### 加法表达式

```
AddExp: MulExp
      | AddExp Y_ADD MulExp
      | AddExp Y_SUB MulExp
```

```C
// 解析加法表达式
past rd_add_exp() {
    past left = rd_mul_exp(); // 获取乘法表达式

    while (cur_token.token == Y_ADD || cur_token.token == Y_SUB) { // 当当前符号为加号或减号时
        int oper = cur_token.token; // 记录运算符
        advance(); // 向前移动到下一个符号
        past right = rd_mul_exp(); // 获取乘法表达式
        left = newBinaryOper(oper, left, right); // 构造二元操作表达式
    }

    return left; // 返回表达式树
}
```

通过一个具体的例子来解释这个函数，假设有如下的加法表达式：

2 + 3 - 1

初始时，cur_token.token 会指向数字 2 的标记，调用 rd_mul_exp() 函数来获取乘法表达式，得到节点表示数字 2

第一次循环：

当前标记是 Y_ADD，符合循环条件，所以进入循环
记录运算符为加号 Y_ADD
调用 advance() 向前移动，现在当前标记是数字 3
调用 rd_mul_exp() 函数来获取乘法表达式，得到节点表示数字 3
使用 newBinaryOper() 构建一个二元操作表达式，操作符为加号，左子树为数字 2，右子树为数字 3

结果为：

   [+]
  /   \
[2]   [3]

第二次循环：

当前标记是 Y_SUB，符合循环条件，所以进入循环
记录运算符为减号 Y_SUB
调用 advance() 向前移动，现在当前标记是数字 1
调用 rd_mul_exp() 函数来获取乘法表达式，得到节点表示数字 1
使用 newBinaryOper() 构建一个二元操作表达式，操作符为减号，左子树为之前构建的表达式，右子树为数字 1

结果为：

          [-]
         /   \
       [+]    [1]
      /   \
    [2]   [3]
#####  乘法表达式

```
MulExp: UnaryExp
      | MulExp Y_MUL UnaryExp
      | MulExp Y_DIV UnaryExp
      | MulExp Y_MODULO UnaryExp

```

```C
// 函数定义：解析乘法表达式
past rd_mul_exp() {
    past left = rd_unary_exp(); // 获取一元表达式

    while (cur_token.token == Y_MUL || cur_token.token == Y_DIV || cur_token.token == Y_MODULO) { // 当当前符号为乘号、除号或取模符号时
        int oper = cur_token.token; // 记录运算符
        advance(); // 向前移动到下一个符号
        past right = rd_unary_exp(); // 获取一元表达式
        left = newBinaryOper(oper, left, right); // 构造二元操作表达式
    }

    return left; // 返回表达式树
}
```

例：

```cpp
4 * 3 / 2
```

```
      [/]
     /   \
   [*]   [2]
  /   \
[4]   [3]

```

##### 相等表达式

```
EqExp: RelExp
     | RelExp Y_EQ EqExp
     | RelExp Y_NOTEQ EqExp

```

```C
// 解析相等表达式
past rd_eq_exp() {
    past left = rd_relexp(); // 获取关系表达式

    while (cur_token.token == Y_EQ || cur_token.token == Y_NOTEQ) { // 当当前符号为等号或不等号时
        int oper = cur_token.token; // 记录运算符
        advance(); 
        past right = rd_relexp(); // 获取关系表达式
        left = newBinaryOper(oper, left, right); // 构造二元操作表达式
    }

    return left; // 返回表达式树
}

```

例：

```cpp
3 == 4 != 5
```

```
     [!=]
    /    \
 [==]    [5]
 /  \
[3] [4]

```

##### 关系表达式

```
RelExp: AddExp
      | AddExp Y_LESS RelExp
      | AddExp Y_GREAT RelExp
      | AddExp Y_LESSEQ RelExp
      | AddExp Y_GREATEQ RelExp

```

```C
// 解析关系表达式
past rd_relexp() {
    past left = rd_add_exp(); // 获取加法表达式

    while (true) {
        switch (cur_token.token) {
            case Y_LESS:
            case Y_LESSEQ:
            case Y_GREAT:
            case Y_GREATEQ: { // 当当前符号为小于、小于等于、大于或大于等于时
                int oper = cur_token.token; // 记录运算符
                advance(); 
                past right = rd_add_exp(); // 获取加法表达式
                left = newBinaryOper(oper, left, right); // 构造二元操作表达式
                break;
            }
            default:
                return left; // 返回表达式树
        }
    }
}

```

其实跟加法表达式也是同理的，一个 while 循环递归构建，例：

```cpp
3 < 4 <= 5
```

```
     [<=]
    /    \
  [<]    [5]
 /   \
[3]  [4]

```

##### 逻辑与表达式

```
LAndExp: EqExp
       | EqExp Y_AND LAndExp

```

```C
// 解析逻辑与表达式
past rd_l_and_exp() {
    past left = rd_eq_exp(); // 获取相等表达式

    while (cur_token.token == Y_AND) { // 当当前符号为逻辑与符号时
        int oper = cur_token.token; // 记录运算符
        advance(); 
        past right = rd_eq_exp(); // 获取相等表达式
        left = newBinaryOper(oper, left, right); // 构造二元操作表达式
    }

    return left; // 返回表达式树
}

```

跟之前的加法表达式相似，例：

```cpp
true && false && true
    
//结果
        [&&]
       /    \
    [&&]    [TRUE]
   /    \
[TRUE] [FALSE]
```

##### 逻辑或表达式

```
LOrExp: LAndExp
      | LAndExp Y_OR LOrExp
```

```C
// 解析逻辑或表达式
past rd_l_or_exp() {
    past left = rd_l_and_exp(); // 获取逻辑与表达式

    while (cur_token.token == Y_OR) { // 当当前符号为逻辑或符号时
        int oper = cur_token.token; // 记录运算符
        advance(); 
        past right = rd_l_and_exp(); // 获取逻辑与表达式
        left = newBinaryOper(oper, left, right); // 构造二元操作表达式
    }
    
    return left; // 返回表达式树

}
```

例：

```cpp
a || b || c

    
        [&&]
       /    \
    [&&]    [c]
   /    \
 [a]    [b]
```

##### 函数调用参数

```
CallParams: Exp
          | Exp Y_COMMA CallParams
```

```C
// 解析函数调用参数
past rd_call_paras() {
    past head = rd_add_exp(); // 获取加法表达式
    past current = head;

    while (cur_token.token) {
        if (cur_token.token != Y_COMMA) { // 当当前符号不为逗号时
            break;
        }
        advance(); 
        past new_node = rd_add_exp(); // 获取加法表达式
        current->next = new_node;
        current = current->next;
    }

    return head; // 返回参数链表头节点
}

```

`CallParams` 节点就是一个**链表**，通过 `next` 指针表示并列关系，例如：

func(a, b, c)

```
 head
  |
 [a] -> [b] -> [c]

```

##### 语句

```
Stmt: LVal Y_ASSIGN Exp Y_SEMICOLON
    | Y_SEMICOLON
    | Exp Y_SEMICOLON
    | Block
    | Y_WHILE Y_LPAR LOrExp Y_RPAR Stmt
    | Y_IF Y_LPAR LOrExp Y_RPAR Stmt
    | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Stmt
    | Y_BREAK Y_SEMICOLON
    | Y_CONTINUE Y_SEMICOLON
    | Y_RETURN Exp Y_SEMICOLON
    | Y_RETURN Y_SEMICOLON

```

```C
// 解析语句
past rd_stmt() {
    switch (cur_token.token) {
        case Y_ID: { // LVal 开头 ———— 赋值语句
            char *s = cur_token.attr.svalue; // 处理LVal（等号左边）
            past Arr = rd_array_subscripts();
            past lval = newDeclRefExp(s, Arr, NULL);
            advance(); 
            if (cur_token.token != Y_ASSIGN) { // 语法错误
                return NULL; 
            }
            advance(); 
            past left = rd_add_exp(); // 获取加法表达式（等号右边）
            if (cur_token.token != Y_SEMICOLON) { // 语法错误
                return NULL; 
            }
            advance(); 
            return newBinaryOper(Y_ASSIGN, lval, left); // 返回赋值表达式
        }
        case Y_SEMICOLON: { // 分号开头 ———— 空语句
            advance(); 
            return NULL; 
        }
        case Y_LBRACKET: { // 左大括号开头 ———— 代码块
            advance(); 
            past block = rd_block(); // 获取块语句
            if (cur_token.token != Y_RBRACKET) { // 语法错误
                return NULL; 
            }
            advance(); 
            return block; // 返回块语句
        }
        case Y_WHILE: { // WHILE语句
            advance(); 
            if (cur_token.token != Y_LPAR) { // 如果下一个符号不是左括号，语法错误
                return NULL; 
            }
            advance(); 
            past condition = rd_l_or_exp(); // 获取逻辑或表达式
            if (cur_token.token != Y_RPAR) { // 如果下一个符号不是右括号，语法错误
                return NULL; 
            }
            advance(); 
            past stmt = rd_stmt(); // 获取语句
            return newWhileStmt(condition, stmt); // 返回WHILE语句
        }
        case Y_IF: { // IF语句
            advance(); 
            if (cur_token.token != Y_LPAR) { // 如果下一个符号不是左括号，语法错误
                return NULL;
            }
            advance(); 
            past condition = rd_l_or_exp(); // 获取逻辑或表达式
            if (cur_token.token != Y_RPAR) { // 如果下一个符号不是右括号，语法错误
                return NULL; 
            }
            advance(); 
            past if_stmt = rd_stmt(); // 获取语句
            if (cur_token.token != Y_ELSE) { // 如果下一个符号不是ELSE关键字 ———— 无else
                return newIfStmt(condition, if_stmt, NULL); // 返回IF语句
            }
            advance(); 
            past else_stmt = rd_stmt(); // 获取ELSE分支语句
            return newIfStmt(condition, if_stmt, else_stmt); // 返回IF-ELSE语句
        }
        case Y_BREAK: { // BREAK语句
            advance(); 
            if (cur_token.token != Y_SEMICOLON) { // 如果下一个符号不是分号，语法错误
                return NULL; 
            }
            advance(); 
            return newBreakStmt(); // 返回BREAK语句
        }
        case Y_CONTINUE: { // CONTINUE语句
            advance(); 
            if (cur_token.token != Y_SEMICOLON) { // 如果下一个符号不是分号，语法错误
                return NULL; 
            }
            advance(); 
            return newContinueStmt(); // 返回CONTINUE语句
        }
        case Y_RETURN: { // RETURN语句
            advance(); 
            past left = rd_add_exp(); // 获取加法表达式
            if (cur_token.token != Y_SEMICOLON) { // 如果下一个符号不是分号，语法错误
                return NULL;
            }
            advance();
            return newReturnStmt(left, NULL); // 返回RETURN语句
        }
        default:
            return NULL;
    }
}


```

例如：赋值语句 (case `Y_ID`)——x[1] = 42;

```
   [=]
  /   \
x[1]  42

```

空语句 (case `Y_SEMICOLON`)

```
; //  NULL
```

代码块 (case `Y_LBRACKET`)

```
{
    x = 1;
    y = 2;
}

```

```
    [Block]
   /       \
(x = 1)  (y = 2)

```

WHILE 语句 (case `Y_WHILE`)

```C
while (x > 0) {
    x = x - 1;
}

```

```
       [WHILE]
      /       \
   [>]         [=]
  /   \       /   \
[x]   [0]    [x]   [-]
           	      /   \
        	    [x]   [1]

```

IF 语句 (case `Y_IF`)

```C
if (x > 0) {
    x = x - 1;
} else {
    x = x + 1;
}

```

```
            [IF]
    /        |        \
(x > 0) (x = x - 1) (x = x + 1)

```

BREAK 语句 (case `Y_BREAK`)

```
break;

```

```
  [BREAK]

```

 CONTINUE 语句 (case `Y_CONTINUE`)

```
continue;

```

```
  [CONTINUE]

```

 RETURN 语句 (case `Y_RETURN`)

```
return 5;

```

```
  [RETURN]
     |
     5

```

