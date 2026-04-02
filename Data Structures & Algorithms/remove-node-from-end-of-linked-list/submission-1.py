# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head == None: return head
        if head.next == None:
            head = None
            return head
        
        node = head
        length =0
        while node != None:
            length +=1
            node= node.next
        
        target = length - n

        prev = None
        node = head
        itr = 0
        while node != None:
            if target == itr:
                if prev == None:
                    head = head.next
                else:
                    prev.next = node.next
                return head
            itr+=1
            prev = node
            node = node.next
