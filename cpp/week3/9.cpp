#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
};
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
ListNode *deleteDuplicates(ListNode *head) {
    ListNode *pre, *cur; //指向前一个节点和当前节点
    ListNode *beforeHead;
    pre = (ListNode *)malloc(sizeof(ListNode));
    pre->next = head;
    beforeHead = pre;
    cur = head;
    int count = 0; //记录需要删除的某一种节点的个数
    while (cur->next != NULL) {
        if (cur->next->val == cur->val) {
            //下一个节点与当前节点相同，需要删除
            cur->next = cur->next->next;
            count++;
        } else {
            //下一个节点与当前节点不同
            if (count > 0) {
                //之前已经删除了与当前节点相同的节点，当前节点需要删除
                pre->next = cur->next;
                count = 0;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
    }
    if (count > 0) {
        //判断最后一个节点是否需要删除
        pre->next = cur->next;
    }
    return beforeHead->next;
}
int main() {
    ListNode *head1;
    ListNode *head;  //用于记录答案
    head1 = input(); //输入链表
    head = deleteDuplicates(head1);
    output(head); //输出答案
    return 0;
}