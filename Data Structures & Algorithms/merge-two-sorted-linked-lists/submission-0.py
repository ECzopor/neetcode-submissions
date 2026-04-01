# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None and list2 is None:
            return list1
        if list1 is None:
            return list2
        if list2 is None:
            return list1


        new = ListNode()
        new.next = None
        if list1.val > list2.val:
            new = list2
            list2=list2.next
        else:
            new = list1
            list1=list1.next

        placeholder = new
        

        while list1 != None and list2 !=None:
            print("list1.val: ", list1.val, "list2.val: ", list2.val)
            if list1.val > list2.val:
                new.next =list2
                list2=list2.next
            else:
                new.next = list1
                list1=list1.next
            new = new.next
        
        if list1 is None:
            new.next = list2
        else:
            new.next = list1
        
        return placeholder

