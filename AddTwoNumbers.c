#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode tmp;
    tmp.val = 0;
    tmp.next = NULL;
    struct ListNode* curr = &tmp;
    int remain = 0, sum;

    while(l1 != NULL || l2 != NULL || remain != 0)
    {

        sum = remain + (l1==0 ? 0:l1->val) + (l2==0 ? 0:l2->val);
        remain = sum/10;
        sum %= 10;

        curr->next = malloc(sizeof(struct ListNode));
        curr->next->val = sum;
        curr->next->next = NULL;

        curr = curr->next;
        l1 = (l1==0 ?0:l1->next);
        l2 = (l2==0 ?0:l2->next);
        
    }
    return tmp.next;
}

int main(void)
{
    return 0;
}