#
# @lc app=leetcode.cn id=2065 lang=python3
#
# [2065] 最大化一张图中的路径价值
#
from typing import List
# @lc code=start


def dfs_state(state_fs: frozenset, target_node, state_map, node_map, max_time):
    state = (state_fs, target_node)
    if state in state_map and state_map[state] > max_time:
        return
    state_map[state] = max_time
    print(f"state_fs={state_fs}, target_node={target_node}, max_time={max_time}")
    for new_target_node, edge_len in node_map[target_node]:
        new_state_fs = state_fs.union([new_target_node])
        new_max_time = max_time - edge_len
        if new_max_time < 0:
            continue
        dfs_state(state_fs=new_state_fs,
                  target_node=new_target_node,
                  state_map=state_map,
                  node_map=node_map,
                  max_time=new_max_time)


def calculate_ans(state_fs, values):
    ans = 0
    for node in state_fs:
        ans += values[node]
    return ans


class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        node_size = len(values)
        node_map = [[] for _ in range(node_size)]
        state_map = {}
        for edge in edges:
            node_map[edge[0]].append((edge[1], edge[2]))
            node_map[edge[1]].append((edge[0], edge[2]))

        state_fs = frozenset([0])
        target_node = 0
        dfs_state(state_fs=state_fs,
                  target_node=target_node,
                  state_map=state_map,
                  node_map=node_map,
                  max_time=maxTime)
        ans = 0
        for (state_fs, target_node) in state_map.keys():
            if target_node == 0:
                ans = max(ans, calculate_ans(state_fs, values))
        return ans
# @lc code=end