#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INITSIZE 110
#define MAXN 1010
typedef char SomeType;
typedef struct {
    SomeType data[MAXN];
    int front, rear;
} Queue;
void initQueue(Queue *Q) {
    Q->front = Q->rear = 0;
}
int isQueueEmpty(Queue *Q) {
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}
int isQueueFull(Queue *Q) {
    if (Q->front == (Q->rear + 1) % MAXN)
        return 1;
    else
        return 0;
}
int ADD(Queue *Q, SomeType x) {
    if (!isQueueFull(Q)) {
        Q->rear = (Q->rear + 1) % MAXN;
        Q->data[Q->rear] = x;
    } else {
        printf("Queue is full!\n");
        return -1;
    }
}
SomeType Delete(Queue *Q) {
    if (!isQueueEmpty(Q)) {
        Q->front = (Q->front + 1) % MAXN;
        return Q->data[Q->front];
    } else {
        printf("Queue is empty!\n");
        return -1;
    }
}
SomeType getHead(Queue *Q) {
    if (!isQueueEmpty(Q))
        return Q->data[(Q->front + 1) % MAXN];
    else {
        printf("Queue is empty!\n");
        return -1;
    }
}
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
int main() {
    Queue queue1, *Q;
    Stack stack1, *S;
    Q = &queue1;
    S = &stack1;
    initQueue(Q); //初始化
    initStack(S);
    SomeType x;
    while (1) {
        //将字符串入栈和入队
        scanf("%c", &x);
        if (x != '?') {
            push(S, x);
            ADD(Q, x);
        } else {
            break;
        }
    }
    int flag;
    while (!isQueueEmpty(Q) && !isStackEmpty(S)) {
        //分别弹出栈和队列，查看是否相等
        flag = 1;
        SomeType a, b;
        a = pop(S);
        b = Delete(Q);
        if (a != b)
            flag = 0;
    }
    if (flag) {
        printf("此字符串为回文\n");
    } else {
        printf("此字符串不是回文\n");
    }
    return 0;
}