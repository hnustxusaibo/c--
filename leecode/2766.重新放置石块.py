#
# @lc app=leetcode.cn id=2766 lang=python3
#
# [2766] 重新放置石块
#

# @lc code=start
class Solution:
    def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
        _map = {}
        for num in nums:
            _map[num] = True
        for i in range(len(moveFrom)):
            _form = moveFrom[i]
            _to = moveTo[i]
            _map[_form] = False
            _map[_to] = True
        ans = []
        for k,v in _map.items():
            if v :
                ans.append(k)
        return sorted(ans)
# @lc code=end

