# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def print_nodes(self):
        '''
        if not self.head:
            print(self.head)
        node = self.head
        '''
        node = self
        while node:
            end = " -> " if node.next else "\n"
            print(node.val, end=end)
            node = node.next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l3 = ListNode()
        l3_head = l3

        while l2 or l1:
            if l1:
                l3.val += l1.val
                if l1.next:
                    l3.next = ListNode(0)
                l1 = l1.next
            
            if l2:
                l3.val += l2.val
                if l2.next:
                    l3.next = ListNode(0)
                l2 = l2.next

            if l3.val >= 10:
                l3.val = l3.val%10
                l3.next = ListNode(1)
            l3 = l3.next
        return l3_head



if __name__ == "__main__":
    input1 = [2, 4, 3]
    input2 = [5, 6, 4]
    
    l3= ListNode()
    l2= ListNode()
    l1= ListNode()
    l2_h = l2
    l2.val = input1[0]
    l2.next = ListNode()
    l2 = l2.next
    l2.val = input1[1]
    l2.next = ListNode()
    l2 = l2.next
    l2.val = input1[2]
    l2.next = ListNode()
    l2 = l2.next
    l1_h = l1
    l1.val = input2[0]
    l1.next = ListNode()
    l1 = l1.next
    l1.val = input2[1]
    l1.next = ListNode()
    l1 = l1.next
    l1.val = input2[2]
    l1.next = ListNode()
    l1 = l1.next
    l3_h= Solution.addTwoNumbers(l3, l2_h, l1_h)
    

    l3_h.print_nodes()
    l1_h.print_nodes()
    l2_h.print_nodes()
    
    
        