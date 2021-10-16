#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INITSIZE 100
#define MAXN 1010
typedef int SomeType;
typedef struct {
    int top;        //栈顶
    SomeType *base; //栈底指针
    int stacksize;  //栈长
} Stack;
int initStack(Stack *S) {
    S->base = (SomeType *)malloc(INITSIZE * sizeof(SomeType));
    if (!S->base)
        return -1; //初始化失败
    S->top = 0;    //表示栈空
    S->stacksize = INITSIZE;
    return 0; //初始化成功
}
SomeType gettop(Stack *S) {
    if (0 == S->top) {
        printf("Stack is empty!\n");
        return -1;
    }
    return S->base[S->top - 1];
}
int push(Stack *S, SomeType x) {
    if (S->top == S->stacksize) {
        S->base = realloc(S->base, (S->stacksize + 1) * sizeof(SomeType));
        if (!S->base)
            return -1;
        S->stacksize++;
    }
    S->base[S->top++] = x;
}
SomeType pop(Stack *S) {
    if (0 == S->top) {
        printf("Stack is empty!\n");
        return -1;
    }
    return S->base[--S->top];
}
int isStackEmpty(Stack *S) {
    if (0 == S->top)
        return 1; //栈为空
    else
        return 0; //栈非空
}
int Operate(Stack *S, char val) {
    if (val >= '0' && val <= '9')
        push(S, val - '0');
    else if (val == 'C')
        pop(S);
    else if (val == 'D') {
        SomeType x = gettop(S);
        push(S, x * 2);
    } else if (val == '+') {
        SomeType x = gettop(S);
        pop(S);
        SomeType y = gettop(S);
        push(S, x);
        push(S, x + y);
    } else
        return -1; // wrong value
    return 0;
}
int main() {
    Stack Score, *S;
    S = &Score;
    //输入
    int first = 1;
    char ch, val;
    while (1) {
        if (first) {
            getchar(); //接收[
            first = 0;
        }
        getchar();       //接收"
        val = getchar(); //接收有效字符
        Operate(S, val); //对栈进行操作
        getchar();       //接收"
        ch = getchar();  //接收"或]
        if (ch == ']')
            break;
    }
    //计算最后得分
    SomeType temp = 0;
    while (!isStackEmpty(S))
        temp += pop(S);
    printf("%d\n", temp);
    return 0;
}