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
    Queue desk, *pd;
    pd = &desk;
    initQueue(pd);
    SomeType n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    char name[MAXN][MAXN];
    memset(name, 0, sizeof(name));
    for (SomeType i = 0; i < n; i++) {
        ADD(pd, i);
        scanf("%s", name[i]);
    }
    for (SomeType i = 1; i < m; i++) {
        SomeType x = Delete(pd);
        ADD(pd, x);
    }
    SomeType count = t;
    char a[MAXN];
    while (!isQueueEmpty(pd)) {
        SomeType index = Delete(pd);
        count++;
        if (count % 7 == 0)
            memcpy(a, name[index], sizeof(name[index]));
        else
            ADD(pd, index);
    }
    printf("result:\n%s\n", a);
    return 0;
}