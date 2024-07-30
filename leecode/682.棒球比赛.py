#
# @lc app=leetcode.cn id=682 lang=python3
#
# [682] 棒球比赛
#

# @lc code=start
class Solution:
    def calPoints(self, operations: List[str]) -> int:
        ans_list = []
        for operation in operations:
            if operation == 'C':
                del ans_list[-1]
                pass
            elif operation == 'D':
                ans_list.append(ans_list[-1] * 2)
                pass
            elif operation == '+':
                ans_list.append(ans_list[-1] + ans_list[-2])
                pass
            else:
                ans_list.append(int(operation))
        return sum(ans_list)
# @lc code=end

