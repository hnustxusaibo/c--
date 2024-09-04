#
# @lc app=leetcode.cn id=676 lang=python3
#
# [676] 实现一个魔法字典
#

# @lc code=start
class MagicDictionary:
    dict_map = {}
    def __init__(self):
        self.dict_map = {}
        pass
    

    def buildDict(self, dictionary: List[str]) -> None:
        def insert(str,dict_map_node):
            if len(str) == 0:
                return None
            dict_map_node.get()
        for _str in dictionary:
            insert(_str)
    def deep_search(self, searchWord: str,falg):
        pass
    def search(self, searchWord: str) -> bool:
        pass



# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)
# @lc code=end

