#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};


struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !(head->next))
        return NULL;
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while ((fast != NULL) && (slow != NULL) && (fast->next != NULL)) 
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            struct ListNode *entry = head;
            while (slow != entry)
            {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
        
    }
    return NULL;
}