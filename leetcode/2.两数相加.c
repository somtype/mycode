/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (37.53%)
 * Likes:    4445
 * Dislikes: 0
 * Total Accepted:    444.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start
/*#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};*/
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int x = 0;
    struct ListNode *Head, *p11, *p12, *p1, *p2;
    Head = p11 = p12 = NULL;
    p1 = l1;
    p2 = l2;
    while (p1 != NULL || p2 != NULL)
    {
        p12 = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (p1 == NULL)
        {
            x = p2->val + x;
            p2 = p2->next;
        }
        else if (p2 == NULL)
        {
            x = p1->val + x;
            p1 = p1->next;
        }
        else
        {
            x = p1->val + p2->val + x;
            p1 = p1->next;
            p2 = p2->next;
        }
        p12->val = x % 10;
        x /= 10;
        if (Head == NULL)
            Head = p12;
        else
            p11->next = p12;
        p11 = p12;
    }
    if (x != 0)
    {
        p12 = (struct ListNode *)malloc(sizeof(struct ListNode));
        p12->val = x;
        p11->next = p12;
        p11 = p12;
    }
    p11->next = NULL;
    return Head;
    
}

// @lc code=end
