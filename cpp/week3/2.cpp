#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};
int main() {
    char hash[1010] = {0};
    struct ListNode *Head, *p1, *p2, *p;
    Head = p1 = p2 = NULL;
    cout << "输入0-1000的数字：\n";
    p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    cin >> p2->val;
    while (p2->val >= 0) {
        if (Head == NULL)
            Head = p2;
        else
            p1->next = p2;
        p1 = p2;
        p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        cin >> p2->val;
    }
    p1->next = NULL;
    hash[Head->val]++;
    p1 = Head;
    p2 = p1->next;
    while (p2 != NULL) {
        if (hash[p2->val]) {
            p1->next = p2->next;
        } else {
            hash[p2->val]++;
            p1 = p1->next;
        }
        p2 = p2->next;
    }
    for (p = Head; p != NULL; p = p->next)
        cout << p->val << ' ';
    cout << endl;
    return 0;
}