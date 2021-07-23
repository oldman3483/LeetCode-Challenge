class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next
        return 
    
    def has_value(self, value):
        if self.data == value:
            return True
        else:
            return False


class SingleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        return
    
    def add_list_item(self, item):
        ## put the item to the end of the original list
        if not isinstance(item, ListNode):
            item = ListNode(item)
        
        if self.head is None:
            self.head = item
        else:
            self.tail.next = item
        
        self.tail = item
        return
    
    def list_length(self):
        ## returns the number of list items
        cnt = 0
        cur_node = self.head
        
        while cur_node is not None:
            cnt += 1
            cur_node = cur_node.next
        
        return cnt
    
    def output_list(self):
        ## outputs the list (the value of the node, actually)
        cur_node = self.head
        res = []

        while cur_node is not None:
            res.append(cur_node.data)
            cur_node = cur_node.next

        print (res)
        return

    def unordered_search(self, value):
        ## search which node has this value in the linked list for the node
        cur_node = self.head
        node_id = 1
        res_pos = []

        while cur_node is not None:
            if cur_node.data == value:
                res_pos.append(node_id)
            cur_node = cur_node.next
            node_id+=1
        
        return res_pos

    def remove_list_item_by_id(self, id):
        ## remove the list item with the item id
        cur_node = self.head
        cur_node_id = 1
        prev_node = None

        while cur_node is not None:
            if cur_node_id == id:
                if prev_node is not None:
                    prev_node.next = cur_node.next
                else: ## means delete the head 
                    self.head = cur_node.next 
            prev_node = cur_node
            cur_node = cur_node.next
            cur_node_id += 1
        return

    def reverse(self):

        ## reverse the order of the list
        cur_node = self.head
        prev_node = None
        next_node = cur_node.next

        while next_node is not None:
            #next_node = cur_node.next
            cur_node.next = prev_node
            prev_node = cur_node
            cur_node = next_node
            next_node = next_node.next
        cur_node.next = prev_node
        self.head = cur_node
        return
        ## tutorial: https://www.youtube.com/watch?v=O0By4Zq0OFc&t=128s

    def remove_value(self, value):
        ## remove the first item in the list with this value

        cur_node = self.head
        prev_node = None

        while cur_node is not None:
            if cur_node.data == value:
                prev_node.next = cur_node.next
                return
            prev_node = cur_node
            cur_node = cur_node.next
        
        return

if __name__ == "__main__":
    node1 = ListNode(15)  
    list1 = SingleLinkedList()
    list1.add_list_item(node1)
    list1.add_list_item('12')
    list1.add_list_item(15)
    list1.add_list_item(17)
    list1.remove_list_item_by_id(3)
    list1.reverse()
    list1.remove_value(15)
    list1.output_list()



