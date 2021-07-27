#include <stdio.h>
#include <stdlib.h>

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
    struct ListNode a1, b1, c1;
    struct ListNode a2, b2, c2; 
    struct ListNode *l1 = &a1; 
    struct ListNode *l2 = &a2;


    // l1=582 l2=123
    a1.val = 5;
    a1.next = &b1;
    b1.val = 6;
    b1.next = &c1;
    c1.val = 2;
    c1.next = NULL;

    a2.val = 3;
    a2.next = &b2;
    b2.val = 2;
    b2.next = &c2;
    c2.val = 1;
    c2.next = NULL;

    struct ListNode *ans = addTwoNumbers(l1, l2);
    while(ans!=NULL){
        printf("address=%p, ",ans); 
        printf("data=%d ",ans->val);  
        printf("next=%p\n",ans->next); 
        ans=ans->next;  
    } 

    return 0;
}