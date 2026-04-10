# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = 0
        times = 1
        while l1 != None:
            num1 += l1.val*times
            times *= 10
            l1 = l1.next
        
        num2 =0
        times = 1
        while l2 != None:
            num2 += l2.val*times
            times *=10
            l2 = l2.next
        
        ans = num1+num2
        head = ListNode()
        node = head
        node.val = ans%10
        ans=ans//10
        node.next = None
        while ans > 0:
            temp = ListNode(ans%10, None)
            node.next = temp
            node = temp
            ans = ans//10
        return head
            

