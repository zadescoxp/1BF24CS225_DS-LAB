struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode dummy1;         
    struct ListNode *prev1 = &dummy1;
    dummy1.next = NULL;

    struct ListNode dummy2;         
    struct ListNode *prev2 = &dummy2;
    dummy2.next = NULL;

    struct ListNode *temp = head;
