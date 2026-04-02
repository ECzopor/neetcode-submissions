# Definition for singly-linked list.
# class ListNode:
from os import curdir
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head == None or head.next == None or head.next.next == None:
            return None

        slow = head
        fast = head.next
        while fast != None and fast.next !=None:
            slow = slow.next
            if fast.next.next == None:
                fast = fast.next
            else:
                fast = fast.next.next

        head2 = slow.next
        slow.next = None
        
        prev = None
        curr = head2
        while curr !=None:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        curr1 = head
        curr2 = prev
        
        while curr1 != None and curr2 != None:
            
            temp = curr1.next
            temp2 = curr2.next
            curr1.next = curr2
            curr1=curr1.next
            curr1.next = temp
            curr2= temp2
            curr1 = curr1.next


