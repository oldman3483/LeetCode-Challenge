#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct node ListNode;


bool hasCycle(struct ListNode *head){

    //ptr1 run 2X of  the ptr2;

    if (!head || !(head->next))
        return false;
    
    struct ListNode *ptr1 = head->next;
    struct ListNode *ptr2 = head;
    while ((ptr1 != NULL) && (ptr2 != NULL) && (ptr1->next != NULL)) 
    {
        if(ptr1 == ptr2)
            return true;
        ptr1 = ptr1->next->next;
        ptr2 = ptr2->next;
    }
    return false;
}