#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
};
ListNode *reverseList(ListNode *head) {
    //反转函数
    ListNode *newhead = NULL, *p;
    while (head != NULL) {
        p = head;
        head = head->next;
        p->next = newhead;
        newhead = p;
    }
    return newhead;
}
ListNode *cpyList(ListNode *head) {
    ListNode *newHead, *p1, *p2, *p;
    newHead = p1 = p2 = NULL;
    for (p = head; p != NULL; p = p->next) {
        p2 = (ListNode *)malloc(sizeof(ListNode));
        p2->val = p->val;
        if (newHead == NULL)
            newHead = p2;
        else
            p1->next = p2;
        p1 = p2;
    }
    p1->next = NULL;
    return newHead;
}
ListNode *input() {
    //输入函数
    ListNode *head, *p1, *p2;
    head = p1 = p2 = NULL;
    int first = 1;
    while (1) {
        p2 = (ListNode *)malloc(sizeof(ListNode));
        if (first)
            first = 0;
        else {
            char ch = getchar();
            if (ch == '\n')
                break;
            getchar();
        }
        scanf("%d", &p2->val);
        if (head == NULL)
            head = p2;
        else
            p1->next = p2;
        p1 = p2;
    }
    p1->next = NULL;
    return head;
}
int isPalindrome(ListNode *head) {
    ListNode *Head, *rHead;
    Head = cpyList(head);      //复制链表
    rHead = reverseList(head); //反转链表
    ListNode *p, *rp;
    int a = 1;
    for (p = Head, rp = rHead; p != NULL && rp != NULL;
         p = p->next, rp = rp->next) {
        //判断两个链表是否相等
        if (p->val != rp->val)
            a = 0;
    }
    return a;
}
int main() {
    ListNode *head;
    head = input();
    if (isPalindrome(head)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}