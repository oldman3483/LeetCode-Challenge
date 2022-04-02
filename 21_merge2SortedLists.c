#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    Node *cur_l1, *cur_l2, res;
    Node *pickup = &res;
    cur_l1 = list1;
    cur_l2 = list2;
    if((cur_l1 == NULL) && (cur_l2 == NULL))
        return NULL;

    while ((cur_l1 != NULL) && (cur_l2 != NULL))
    {
        if(cur_l1->val <= cur_l2->val)
        {
            pickup->next = cur_l1;
            cur_l1 = cur_l1->next;
        }
        else
        {
            pickup->next = cur_l2;
            cur_l2 = cur_l2->next;
        }
        pickup = pickup->next;
    }

    if(cur_l1)
    {
        pickup->next = cur_l1;

    }
    if(cur_l2)
    {
        pickup->next = cur_l2;
    }

    return res.next;

}
