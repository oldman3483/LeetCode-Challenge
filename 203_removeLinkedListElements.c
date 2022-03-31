#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode* removeElements(struct ListNode* head, int val){
    Node* prev, *curr, *sentinel;
    curr = head;
    prev = head;
    if(curr == NULL)
    {
        return NULL;
    }
    while (curr != NULL)
    {
        if(curr->val == val)
        {
            prev->next = curr->next;
        }
        else
        {
            prev = curr;

        }
        curr = curr->next;
    }
    if(head->val==val){
        head=head->next;
    }


    return head;
}