#
# @lc app=leetcode.cn id=721 lang=python3
#
# [721] 账户合并
#

# @lc code=start
from typing import List


class Solution:
    
    def find_bin(self, x, bin):
        if bin[x] == x:
            return x
        return self.find_bin(bin[x], bin)

    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        accounts_map = {}
        for account in accounts:
            accounts_map.setdefault(account[0], []).append(account[1:])
        ans_list = []
        for account_name, account_list in accounts_map.items():
            size = len(account_list)
            bin = list(range(size))
            for i in range(size):
                for j in range(i + 1, size):
                    if set(account_list[i]) & set(account_list[j]):
                        rooti =  self.find_bin(i, bin)
                        rootj =  self.find_bin(j, bin)
                        bin[rootj] = bin[rooti]
            for i in range(size):
                rooti =  self.find_bin(i, bin)
                account_list[rooti] += account_list[i]
            for i in range(size):
                if bin[i] == i:
                    ans_list.append([account_name] + sorted(list(set(account_list[i]))))
        
        return ans_list

# if __name__ == "__main__":
#     _list = [["Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"],["Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"],["Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"],["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"],["Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"]]
#     s = Solution()
#     s.accountsMerge(_list)

# @lc code=end

