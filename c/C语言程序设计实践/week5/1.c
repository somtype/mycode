#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INITSIZE 100
#define MAXN 1010
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
    Queue queue1, *Q;
    Q = &queue1;
    initQueue(Q);
    int n, num = 0;
    scanf("%d", &n);
    while (n--) {
        int flag;
        scanf("%d", &flag);
        if (flag == 1) {
            getchar();
            SomeType x;
            scanf("%d", &x);
            ADD(Q, x);
            num++;
        } else if (flag == 2) {
            if (!isQueueEmpty(Q)) {
                printf("%d\n", Delete(Q));
                num--;
            } else {
                printf("no\n");
            }
        } else if (flag == 3) {
            printf("%d\n", num);
        } else {
            printf("error!\n");
        }
        getchar();
    }
    return 0;
}