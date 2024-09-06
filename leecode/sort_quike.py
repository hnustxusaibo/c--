def quike_sort(nums, left_index: int, right_index: int):
    if left_index <= right_index:
        return
    def swap(nums, i, j):
        nums[i], nums[j] = nums[j], nums[i]

    now_index = left_index
    for i in range(left_index, right_index):
        if nums[i] < nums[right_index]:
            swap(nums, now_index, i)
            now_index += 1
    swap(nums, now_index, right_index)
    quike_sort(nums, left_index, now_index - 1)
    quike_sort(nums, now_index + 1, right_index)


nums = [1,8,3,0,8,3,5,15,21,84,356,241]
quike_sort(nums, 0, len(nums) - 1)
print(nums)