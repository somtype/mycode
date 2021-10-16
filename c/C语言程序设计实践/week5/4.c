#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INITSIZE 100
#define MAXN 1010
#define INF 0x3f3f3f3f
typedef int SomeType;
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
int main() {
    Queue men, women, *pm, *pw;
    pm = &men;
    pw = &women;
    initQueue(pm);
    initQueue(pw);
    SomeType m, n, k;
    scanf("%d%d", &m, &n);
    for (SomeType i = 1; i <= m; i++)
        ADD(pm, i);
    for (SomeType j = 1; j <= n; j++)
        ADD(pw, j);
    scanf("%d", &k);
    for (SomeType i = 0; i < k; i++) {
        SomeType a, b;
        a = Delete(pm);
        b = Delete(pw);
        printf("%d %d\n", a, b);
        ADD(pm, a);
        ADD(pw, b);
    }
    return 0;
}