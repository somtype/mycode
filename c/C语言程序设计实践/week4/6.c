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
SomeType queuepop(Stack *S) {
    Stack tempS, *tS;
    tS = &tempS;
    initStack(tS);
    while (!isStackEmpty(S))
        push(tS, pop(S));
    SomeType x = pop(tS);
    while (!isStackEmpty(tS))
        push(S, pop(tS));
    return x;
}
int main() {
    int ope[MAXN][2];
    int i, opeNum;
    printf("input ope(end with two -1):\n");
    for (i = 0; i < MAXN; i++) {
        int operator, x;
        scanf("%d%d", &operator, & x);
        if (operator!= 1 && operator!= 2)
            break;
        ope[i][0] = operator;
        ope[i][1] = x;
    }
    opeNum = i; //记录操作数
    Stack Stack1, *S;
    S = &Stack1;
    initStack(S);
    for (i = 0; i < opeNum; i++) {
        if (ope[i][0] == 1)
            push(S, ope[i][1]);
        if (ope[i][0] == 2)
            queuepop(S);
    }
    SomeType x;
    //完成所有操作后弹出所有元素
    printf("result:\n");
    while (!isStackEmpty(S)) {
        printf("%d ", queuepop(S));
    }
    return 0;
}