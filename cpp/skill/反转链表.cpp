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