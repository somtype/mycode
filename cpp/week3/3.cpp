#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *input() { //用于输入非负的整数
    struct ListNode *head, *p1, *p2;
    char ch;
    head = p1 = p2 = NULL;
    while (1) {
        ch = getchar();
        if (ch == ')')
            break;
        if (isdigit(ch)) {
            p2 = (ListNode *)malloc(sizeof(ListNode));
            p2->val = ch - '0';
            if (head == NULL)
                head = p2;
            else
                p1->next = p2;
            p1 = p2;
        }
    }
    p1->next = NULL;
    return head;
}
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head, *p1, *p2 /*用于创建答案链表*/, *pl1,
        *pl2; /*分别用于指向链表一和链表二*/
    int x = 0 /*用于记录进位*/
        ,
        temp;
    head = p1 = p2 = NULL;
    pl1 = l1, pl2 = l2;
    while (pl1 != NULL || pl2 != NULL) {
        p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (pl1 != NULL && pl2 != NULL) { //链表一和二都没有遍历完成
            temp = pl1->val + pl2->val + x;
            pl1 = pl1->next, pl2 = pl2->next;
        } else if (pl1 == NULL) { //链表一遍历完成，只需要引用链表二的节点
            temp = pl2->val + x;
            pl2 = pl2->next;
        } else { //链表二遍历完成，只需要引用链表一的节点
            temp = pl1->val + x;
            pl1 = pl1->next;
        }
        p2->val = temp % 10;
        x = temp / 10;
        if (head == NULL)
            head = p2;
        else
            p1->next = p2;
        p1 = p2;
    }
    p1->next = NULL;
    return head;
}
int main() {
    struct ListNode *Head1, *Head2, *Head;
    Head1 = input();
    Head2 = input();
    Head = addTwoNumbers(Head1, Head2);
    struct ListNode *p;
    int first = 1;
    for (p = Head; p != NULL; p = p->next) {
        if (first)
            first = 0;
        else
            cout << "->";
        cout << p->val;
    }
    cout << endl;
    return 0;
}