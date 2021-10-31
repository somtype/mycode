/*程序功能：将中缀表达式转换为后缀表达式的翻译器
  原始文法描述：
           expr --> expr + term
                  | expr - term
                  | term
           term --> term * factor
                  | term / factor
                  | factor
         factor --> ( expr )
                  | ID
                  | NUM

  消除左递归后的语法制导的翻译方案：
            expr --> term expr_rest
       expr_rest --> + term {print('+')} expr_rest
                   | - term {print('-')} expr_rest
                   | 空
            term --> factor term_rest
       term_rest --> * factor {print('*')} term_rest
                   | / factor {print('/')} term_rest
                   | 空
          factor --> ( {print('(')} expr ) {print(')')}
                   | NUM {print(value_of_token)}
                   | ID  {print(lexeme)}
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define TKN_NUM 973
#define TKN_ID 397

int numOfleft = 0; //待匹配的左括号的个数，用于匹配括号
int LookAhead;     //存放当前的词法单元的类型
int tokenval = 0;  //存放TKN_NUM的值（整数）
char lexeme[1024]; //存放TNK_ID的值（变量名）

void expr();
void expr_rest();
void term();
void term_rest();
void factor();

int GetToken() {
    int t, i;
    while (1) {
        t = getchar();
        // token是空格或制表符，忽略
        if (t == ' ' || t == '\t')
            ;

        // token是无符号整数(TKN_NUM)，获取它具体的值，然后存入tokenval
        else if (isdigit(t)) {
            tokenval = 0;
            do {
                tokenval = tokenval * 10 + t - '0';
                t = getchar();
            } while (isdigit(t));

            // 在TKN_NUM后紧跟着出现字母或者下划线'_'，则当前token为非法变量名，输出非法变量名并退出
            if (isalpha(t) || t == '_') {
                printf("出现了非法变量名\"%d", tokenval);
                do {
                    putc(t, stdout);
                    t = getchar();
                } while (isalpha(t) || t == '_');
                putc('\"', stdout);
                exit(1);
            }

            // TKN_NUM获取成功
            else {
                ungetc(t, stdin);
                return TKN_NUM;
            }
        }

        // token是变量名(TKN_ID)，获取变量名，然后存入char *lexeme
        else if (isalpha(t) || t == '_') {
            i = 0;
            do {
                lexeme[i++] = t;
                t = getchar();
            } while (isalpha(t) || isdigit(t) || t == '_');
            lexeme[i] = '\0';
            ungetc(t, stdin);
            return TKN_ID;
        }

        // token是其他值，比如'+'、'-'、'*'、'/'、'('、')'等
        else {
            tokenval = 0;
            return t;
        }
    }
}
void Match(int t) {
    //匹配成功，然后继续获取下一个token
    if (LookAhead == t)
        LookAhead = GetToken();

    //匹配失败，可能是下列原因
    else {
        if (t == ')')
            printf("\n缺少右括号\n");
        exit(1); //结束程序
    }
}
void expr() {
    // expr --> term expr_rest
    term();
    expr_rest();
}

void expr_rest() {
    switch (LookAhead) {
    // expr_rest --> + term {print('+')} expr_rest
    case '+':
        Match('+');
        term();
        printf("+ ");
        expr_rest();
        break;

    // expr_rest --> - term {print('-')} expr_rest
    case '-':
        Match('-');
        term();
        printf("- ");
        expr_rest();
        break;

    // expr_rest --> 空
    default:
        break;
    }
}

void term() {
    // term --> factor term_rest
    factor();
    term_rest();
}

void term_rest() {
    switch (LookAhead) {
    // term_rest --> * factor {print('*')} term_rest
    case '*':
        Match('*');
        factor();
        printf("* ");
        term_rest();
        break;

    // term_rest --> / factor {print('/')} term_rest
    case '/':
        Match('/');
        factor();
        printf("/ ");
        term_rest();
        break;

    // 下个token是右括号，说明在生成factor之后多出了右括号
    case ')':
        //已经没有左括号可以匹配了，这是多余的右括号
        if (numOfleft <= 0) {
            printf("\n有多余的右括号\n");
            exit(1);
        }

    // term_rest --> 空
    default:
        break;
    }
}

void factor() {
    switch (LookAhead) {
    // factor --> ( expr )
    case '(':
        Match('(');
        numOfleft++;
        printf("( ");
        expr();
        Match(')');
        numOfleft--;
        printf(") ");
        break;

    // factor --> ID
    case TKN_ID:
        printf("%s ", lexeme);
        Match(LookAhead);
        break;

    // factor --> NUM
    case TKN_NUM:
        printf("%d ", tokenval);
        Match(LookAhead);
        break;

    default:
        printf("缺少操作数");
        exit(1);
        break;
    }
}

int main() {
    printf("请输入表达式：\n");
    LookAhead = GetToken();
    printf("其后缀表达式为：\n");
    expr();
    putc('\n', stdout);
    return 0;
}
