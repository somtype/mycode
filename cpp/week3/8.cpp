#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};
ListNode *input() {
    //输入函数
    ListNode *head, *p1, *p2;
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
void output(ListNode *head) {
    //输出函数
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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    //低位在前的加和函数
    ListNode *head, *p1, *p2; //用于创建答案链表
    ListNode *pl1, *pl2;      //分别用于指向链表一和链表二
    int x = 0                 //用于记录进位
        ,
        temp;
    head = p1 = p2 = NULL;
    pl1 = l1, pl2 = l2;
    while (pl1 != NULL || pl2 != NULL) {
        p2 = (ListNode *)malloc(sizeof(ListNode));
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
        //创建答案链表
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
    ListNode *head1, *head2, *head;
    head1 = input();                    //输入链表1
    head2 = input();                    //输入链表2
    head1 = reverseList(head1);         //反转链表1
    head2 = reverseList(head2);         //反转链表2
    head = addTwoNumbers(head1, head2); //加和存入答案链表
    head = reverseList(head);           //反转答案链表
    output(head);                       //输出答案
    return 0;
}