#
# @lc app=leetcode.cn id=86 lang=python3
#
# [86] 分隔链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        ma_head = ListNode()
        ma_head_p = ma_head
        mi_head = ListNode()
        mi_head_p = mi_head


        while head:
            if head.val < x:
                mi_head_p.next = head
                mi_head_p = head
            else:
                ma_head_p.next = head
                ma_head_p = head
            head = head.next
            
        ma_head_p.next = None
        mi_head_p.next = ma_head.next
        return mi_head.next


# @lc code=end

