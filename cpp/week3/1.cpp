#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *newhead = NULL, *p;
    while (head != NULL) {
        p = head;
        head = head->next;
        p->next = newhead;
        newhead = p;
    }
    return newhead;
}
int main() {
    struct ListNode *head, *p1, *p2, *p;
    head = p1 = p2 = NULL;
    p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    cin >> p2->val;
    while (p2->val != 0) {
        if (head == NULL)
            head = p2;
        else
            p1->next = p2;
        p1 = p2;
        p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        cin >> p2->val;
    }
    p1->next = NULL;
    head = reverseList(head);
    for (p = head; p != NULL; p = p->next)
        cout << p->val << ' ';
    cout << endl;
    return 0;
}