#
# @lc app=leetcode.cn id=567 lang=python3
#
# [567] 字符串的排列
#


# @lc code=start
class Solution:
     
     def checkInclusion(self, s1: str, s2: str) -> bool:
        from collections import Counter

        # 统计s1中字符出现的频率
        s1_count = Counter(s1)
        s1_len = len(s1)
        
        # 用于滑动窗口的计数器
        window_count = Counter()
        
        for i, char in enumerate(s2):
            # 将当前字符添加到窗口
            window_count[char] += 1
            
            # 当窗口大小超过s1长度时，移除最左边的一个字符
            if i >= s1_len:
                if window_count[s2[i - s1_len]] == 1:
                    del window_count[s2[i - s1_len]]
                else:
                    window_count[s2[i - s1_len]] -= 1
            
            # 如果窗口中的字符频率与s1相同，返回True
            if window_count == s1_count:
                return True
        
        return False


# @lc code=end
