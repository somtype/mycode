#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INITSIZE 100
#define MAXN (int)1e6 + 10
#define INF 0x3f3f3f3f
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
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    Stack left, right, *pL,
        *pR; //利用双栈，光标左边的放在left，光标右边的放在right
    pL = &left;
    pR = &right;
    initStack(pL);
    initStack(pR);
    int Q, sum[MAXN], maxsum[MAXN];
    int index = 0; // index取值[1,MAXN]
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < MAXN; i++)
        maxsum[i] = -INF;
    scanf("%d", &Q);
    getchar();
    char ch;
    while (Q--) {
        ch = getchar();
        getchar();
        if (ch == 'I') {
            int temp;
            scanf("%d", &temp);
            getchar();
            push(pL, temp);
            index++;
            sum[index] = sum[index - 1] + temp;
            maxsum[index] = max(maxsum[index - 1], sum[index]);
        } else if (ch == 'D') {
            if (index != 0) {
                index--;
                pop(pL);
            }
        } else if (ch == 'L') {
            if (index != 0) {
                index--;
                int top = gettop(pL);
                pop(pL);
                push(pR, top);
            }
        } else if (ch == 'R') {
            if (!isStackEmpty(pR)) {
                index++;
                int top = gettop(pR);
                pop(pR);
                push(pL, top);
                sum[index] = sum[index - 1] + top;
                maxsum[index] = max(maxsum[index - 1], sum[index]);
            }
        } else if (ch == 'Q') {
            int x;
            scanf("%d", &x);
            getchar();
            printf("%d\n", maxsum[x]);
        }
    }
    return 0;
}