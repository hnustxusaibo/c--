def merge_sort(nums, left_index: int, right_index: int):
    if left_index < right_index:
        mid_index = (left_index + right_index) // 2
        merge_sort(nums, left_index, mid_index)
        merge_sort(nums, mid_index + 1, right_index)
        merge_in_place(nums, left_index, mid_index, right_index)

def merge_in_place(nums, left_index: int, mid_index: int, right_index: int):
    start1 = left_index
    start2 = mid_index + 1

    while start1 <= mid_index and start2 <= right_index:
        if nums[start1] <= nums[start2]:
            start1 += 1
        else:
            value = nums[start2]
            index = start2

            while index != start1:
                nums[index] = nums[index - 1]
                index -= 1

            nums[start1] = value

            start1 += 1
            mid_index += 1
            start2 += 1

nums = [1,8,3,0,8,3,5,15,21,84,356,241]
merge_sort(nums, 0, len(nums) - 1)
print(nums)