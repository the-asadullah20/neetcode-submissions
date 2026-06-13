# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseLL(self,head:Optional[ListNode])->Optional[ListNode]:
        fut=None
        curr=head
        prev=None
        while(curr):
            fut=curr.next
            curr.next=prev
            prev=curr
            curr=fut
        return prev

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        return self.reverseLL(head)





