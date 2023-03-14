class Solution(object):
    def alertNames(self, keyName, keyTime):
        """
        :type keyName: List[str]
        :type keyTime: List[str]
        :rtype: List[str]
        """
        name_map = {}
        for i in range(0, len(keyName)):
            _l = name_map.get(keyName[i], [])
            hour, minute = int(keyTime[i][:2]), int(keyTime[i][3:])
            _l.append(hour * 60 + minute)
            name_map[keyName[i]] = _l

        _set = set()
        for i in range(0, len(keyName)):
            time_list = name_map.get(keyName[i], [])
            time_list.sort()
            for j in range(0, len(time_list) - 2):
                if time_list[j + 2] - time_list[j] <= 60:
                    _set.add(keyName[i])
                    break
        ans = list(_set)
        ans.sort()
        return ans


if __name__ == '__main__':
    l1 = ["daniel", "daniel", "daniel", "luis", "luis", "luis", "luis"]
    l2 = ["10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00"]
    print(str(Solution.alertNames(self=None, keyName=l1, keyTime=l2)))
