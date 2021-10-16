#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *input() {
    //用于输入两个链表
    ListNode *head, *p1, *p2;
    head = p1 = p2 = NULL;
    while (1) {
        char ch;
        p2 = (ListNode *)malloc(sizeof(ListNode));
        cin >> p2->val;
        if (head == NULL)
            head = p2;
        else
            p1->next = p2;
        p1 = p2;
        ch = getchar();
        if (ch == '\n') {
            break;
        } else
            getchar();
        if (ch == ',')
            break;
    }
    p1->next = NULL;
    return head;
}
void output(ListNode *head) {
    ListNode *p;
    int first = 1;
    for (p = head; p != NULL; p = p->next) {
        if (first)
            first = 0;
        else
            cout << "->";
        cout << p->val;
    }
    cout << endl;
}
int main() {
    ListNode *head1, *head2, *p1, *p2; //用于储存两个单链表
    ListNode *head, *ph1, *ph2;        //用于创建并储存答案
    head1 = input();                   //输入链表
    head2 = input();
    p1 = head1;
    p2 = head2;
    head = ph1 = ph2 = NULL;
    while (p1 != NULL || p2 != NULL) {
        //确认新节点的值
        ph2 = (ListNode *)malloc(sizeof(ListNode));
        if (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                ph2->val = p1->val;
                p1 = p1->next;
            } else {
                ph2->val = p2->val;
                p2 = p2->next;
            }
        } else if (p1 == NULL) {
            ph2->val = p2->val;
            p2 = p2->next;
        } else {
            ph2->val = p1->val;
            p1 = p1->next;
        }
        //新节点确认，创建答案链表
        if (head == NULL)
            head = ph2;
        else
            ph1->next = ph2;
        ph1 = ph2;
    }
    ph1->next = NULL;
    output(head); //输出答案
    return 0;
}