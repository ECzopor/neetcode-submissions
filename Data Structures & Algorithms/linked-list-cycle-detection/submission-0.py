# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        #brute force for now:
        if head == None:
            return False
        
        list_of_ptr = list([])
        while head != None:
            if head.next in list_of_ptr:
                return True;
            list_of_ptr.append(head.next)
            head = head.next
        return False
    