#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

void deleteNode(struct ListNode* node) {
// use tmp node will be faster

    Node* tmp;
    tmp = node->next;
    node->val = tmp->val;
    node->next = tmp->next;
}
