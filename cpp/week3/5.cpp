#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};
int main() {
    struct ListNode *head, *p1, *p2, *p, *l1 /*用于记录小于x的节点*/,
        *l2 /*用于记录大于等于x的节点*/, *pl1, *pl2;
    int x;
    head = p1 = p2 = l1 = l2 = pl1 = pl2 = NULL;
    char s[10];         //用于接收多余的字符
    fgets(s, 8, stdin); //用于接收“head = ”
    while (1) {         //输入单链表
        char ch;
        p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        cin >> p2->val;
        if (head == NULL)
            head = p2;
        else
            p1->next = p2;
        p1 = p2;
        getchar(); //用于接收“->”
        getchar();
        ch = getchar();
        if (isdigit(ch))
            ungetc(ch, stdin);
        else {
            fgets(s, 4, stdin); //用于接收“ = ”
            cin >> x;
            break;
        }
    }
    p1->next = NULL;
    for (p = head; p != NULL; p = p->next) {
        p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        p2->val = p->val;
        if (p->val < x) { //小于x的节点
            if (l1 == NULL)
                l1 = p2;
            else
                pl1->next = p2;
            pl1 = p2;
        } else { //大于等于x的节点
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
    int first = 1;
    for (pl1 = l1; pl1 != NULL; pl1 = pl1->next) { //输出答案
        if (first)
            first = 0;
        else
            cout << "->";
        cout << pl1->val;
    }
    return 0;
}