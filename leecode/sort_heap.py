def heap_sort(nums):
    def heap_format(nums, root, heap_size):
        max_index = root
        l_index = max_index * 2 + 1
        r_index = max_index * 2 + 2
        if l_index < heap_size and nums[l_index] > nums[max_index]:
            max_index = l_index
        if r_index < heap_size and nums[r_index] > nums[max_index]:
            max_index = r_index
        if max_index != root:
            nums[max_index], nums[root] = nums[root], nums[max_index]
            heap_format(nums, max_index, heap_size)
    nums_size = len(nums)
    max_noleaf_root = nums_size // 2 - 1 
    for i in range(max_noleaf_root , -1 , -1):
        heap_format(nums, i , nums_size)
    # print(nums)
    for i in range(nums_size - 1, 0 , -1):
        nums[i], nums[0] = nums[0], nums[i]
        heap_format(nums, 0 , i)
        # print(nums)

nums = [1,8,3,0,8,3,5,15,21,84,356,241]
heap_sort(nums)
print(nums)