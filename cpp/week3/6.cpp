#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *input() {
    //输入单链表
    struct ListNode *head, *p1, *p2;
    head = p1 = p2 = NULL;
    char s[10];         //用于接收多余的字符
    fgets(s, 9, stdin); //用于接收“head = [”
    while (1) {
        char ch;
        p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        cin >> p2->val;
        if (head == NULL)
            head = p2;
        else
            p1->next = p2;
        p1 = p2;
        ch = getchar();
        if (ch == ']')
            break;
    }
    p1->next = NULL;
    return head;
}
struct ListNode *removeZeroSumSublists(struct ListNode *head) {
    //暴力破解
    struct ListNode *beforeHead =
        (struct ListNode *)malloc(sizeof(struct ListNode));
    beforeHead->val = 0;
    beforeHead->next = head;
    struct ListNode *p = beforeHead;
    while (p != NULL) {
        int sum = 0;
        struct ListNode *q = p->next;
        while (q != NULL) {
            sum += q->val;
            if (sum == 0) {
                p->next = q->next;
            }
            q = q->next;
        }
        p = p->next;
    }
    return beforeHead->next;
}
int main() {
    struct ListNode *head, *p;
    head = input(); //输入单链表
    int first = 1;
    head = removeZeroSumSublists(head);
    cout << '[';
    for (p = head; p != NULL; p = p->next) { //输出答案
        if (first)
            first = 0;
        else
            cout << ',';
        cout << p->val;
    }
    cout << ']' << endl;
    return 0;
}