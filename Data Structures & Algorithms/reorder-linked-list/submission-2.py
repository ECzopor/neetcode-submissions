# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        #burte froce, bc no ideas
        #1) reverse list and count the Len 
        if head == None or head.next == None: 
            return None
        node_1= head
        prev = ListNode(node_1.val)
        length = 1
        node_1 = node_1.next
        while node_1 != None:
            curr = ListNode(node_1.val)
            length+=1
            curr.next = prev
            prev = curr
            node_1=node_1.next
        head_2 = prev

        #2)now lets merge
        length_2 = 1
        curr_1 = head
        curr_2 = head_2
        while True:
            temp = curr_1.next
            curr_1.next = curr_2
            curr_1 = curr_1.next
            length_2+=1
            if length_2 == length:
                curr_1.next = None
                break
            curr_2 = curr_2.next
            curr_1.next = temp
            curr_1 = curr_1.next
            length_2+=1
            if length_2 == length:
                curr_1.next = None
                break

            
            
            
            



