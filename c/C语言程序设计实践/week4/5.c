#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define StackSize 2
#define INITStackNum 1
#define MAXN 1010
typedef int SomeType;
typedef struct {
    SomeType (*base)[StackSize]; // SetOfStacks的底指针
    int StackNum;                //总的栈数
    int NStack;                  //指向当前为第几个栈[0,StackNum)
    int top;                     //当前栈的栈顶
} SetOfStacks;
int initSetOfStack(SetOfStacks *SS) {
    SS->base = (SomeType(*)[StackSize])calloc(
        INITStackNum,
        StackSize *
            sizeof(
                SomeType)); //申请INITStackNum个长度为INITStackSize的栈作为初始空间
    if (!SS->base) {
        printf("Initialization failed!\n");
        return -1; //初始化失败;
    }
    SS->top = SS->NStack = 0;
    SS->StackNum = INITStackNum;
    return 0; //初始化成功
}
int push(SetOfStacks *SS, SomeType x) {
    if (SS->top == StackSize) {
        //当前栈用完，用下一个栈
        SS->NStack++;
        SS->top = 0;
    }
    if (SS->NStack == SS->StackNum) {
        //所有栈已经用完
        SS->base = (SomeType(*)[StackSize])realloc(
            SS->base, (SS->StackNum + 1) * StackSize * sizeof(SomeType));
        if (!SS->base)
            return -1;
        SS->StackNum++;
    }
    SS->base[SS->NStack][SS->top++] = x;
    return 0;
}
SomeType pop(SetOfStacks *SS) {
    if (SS->top == 0) {
        //当前栈已弹空，用上一个栈
        SS->top = StackSize;
        SS->NStack--;
    }
    if (SS->NStack < 0) {
        //所有栈已弹空
        printf("Empty!\n");
        return -1;
    }
    return SS->base[SS->NStack][--SS->top];
}
int isSosEmpty(SetOfStacks *SS) {
    if (0 == SS->NStack && 0 == SS->top)
        return 1;
    else
        return 0;
}
int main() {
    int ope[MAXN][2];
    int i, opeNum;
    printf("input ope(end with two -1):\n");
    for (i = 0; i < MAXN; i++) {
        int operator, x;
        scanf("%d%d", &operator, &x);
        if (operator!= 1 && operator!= 2)
            break;
        ope[i][0] = operator;
        ope[i][1] = x;
    }
    opeNum = i; //记录操作数
    SetOfStacks MySS, *SS;
    SS = &MySS;
    initSetOfStack(SS);
    for (i = 0; i < opeNum; i++) {
        if (ope[i][0] == 1)
            push(SS, ope[i][1]);
        if (ope[i][0] == 2)
            pop(SS);
    }
    SomeType x;
    //完成所有操作后弹出所有元素
    printf("result:\n");
    while (!isSosEmpty(SS)) {
        printf("%d ", pop(SS));
    }
    return 0;
}