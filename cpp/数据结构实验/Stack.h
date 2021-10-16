#include "stdio.h"
#include "stdlib.h"
#define INITSIZE 100
#define INCREMENT 10
typedef int SomeType;
typedef struct {
    SomeType *base; //栈底指针
    SomeType *top;  //栈顶指针
    int size;       //栈长
} Stack;
int initStack(Stack &S) {
    S.base = (SomeType *)malloc(INITSIZE * sizeof(SomeType));
    if (!S.base)
        return -1;  //初始化失败
    S.top = S.base; //表示栈空
    S.size = INITSIZE;
    return 0; //初始化成功
}
int gettop(Stack &S, SomeType &e) {
    if (S.base == S.top) {
        printf("Stack is empty!\n");
        return -1;
    }
    e = *(S.top - 1);
    return 0;
}
int push(Stack &S, SomeType e) {
    if (S.top - S.base >= S.size) {
        S.base = (SomeType *)realloc(S.base,
                                     (S.size + INCREMENT) * sizeof(SomeType));
        if (!S.base)
            return -1;
        S.top = S.base + S.size;
        S.size += INCREMENT;
    }
    *(S.top++) = e;
    return 0;
}
int pop(Stack &S, SomeType &e) {
    if (S.base == S.top)
        return -1;
    e = *(--S.top);
    return 0;
}
int StackEmpty(Stack &S) {
    if (S.base == S.top)
        return 1; //栈为空
    else
        return 0; //栈非空
}