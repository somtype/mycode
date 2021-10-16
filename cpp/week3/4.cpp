#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};
int main() {
    struct ListNode *head, *p1, *p2, *p, *l1 /*记录奇数节点*/,
        *l2 /*记录偶数节点*/, *pl1, *pl2;
    head = p1 = p2 = NULL;
    while (1) { //输入单链表
        char ch;
        p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        cin >> p2->val;
        if (head == NULL)
            head = p2;
        else
            p1->next = p2;
        p1 = p2;
        getchar(); //用于接收“->”符号
        getchar();
        ch = getchar();
        if (isdigit(ch))
            ungetc(ch, stdin);
        else
            break;
    }
    p1->next = NULL;
    int i = 1;
    l1 = l2 = pl1 = pl2 = NULL;
    for (p = head; p != NULL; p = p->next, i++) {
        p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        p2->val = p->val;
        if (i % 2 != 0) { //奇数节点
            if (l1 == NULL)
                l1 = p2;
            else
                pl1->next = p2;
            pl1 = p2;
        } else { //偶数节点
            if (l2 == NULL)
                l2 = p2;
            else
                pl2->next = p2;
            pl2 = p2;
        }
    }
    pl1->next = pl2->next = NULL;
    p = l1;
    while (p->next != NULL) //连接两个链表
        p = p->next;
    p->next = l2;
    for (pl1 = l1; pl1 != NULL; pl1 = pl1->next) { //输出答案
        cout << pl1->val << "->";
    }
    cout << "NULL" << endl;
    return 0;
}