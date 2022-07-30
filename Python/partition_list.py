class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(n)
    # Space complexity: O(1)
    def PartitionList1(self, nums, k):
        less_index = 0
        greater_index = len(nums) - 1
        i = 0
        while i <= greater_index:
            if nums[i] < k:
                nums[i], nums[less_index] = nums[less_index], nums[i]
                less_index += 1
                i += 1
            if nums[i] > k:
                nums[i], nums[greater_index] = nums[greater_index], nums[i]
                greater_index -= 1
            if nums[i] == k:
                i += 1

        return nums

    # Time complexity: O(n)
    # Space complexity: O(1)
    def PartitionList2(self, nums, k):
        less_index = 0
        greater_index = len(nums) - 1
        i = 0
        while i <= greater_index:
            if nums[i] < k:
                nums[i], nums[less_index] = nums[less_index], nums[i]
                less_index += 1
                i += 1
            elif nums[i] == k:
                i += 1
            elif nums[i] > k:
                nums[i], nums[greater_index] = nums[greater_index], nums[i]
                greater_index -= 1

        return nums

    # Time complexity: O(n)
    # Space complexity: O(n)
    def PartitionList3(self, nums, k):
        a = []
        b = []
        e = []
        for num in nums:
            if num < k:
                a.append(num)
            elif num == k:
                e.append(num)
            elif num > k:
                b.append(num)
        return a + e + b


k = 3
s = Solution()
nums = [3, 8, 9, 3, 9, 3, 2, 3, 4, 1, 3, 1, 0]
# nums = [8, 9, 9, 2, 4, 1, 1, 0]
# nums = [2, 2, 2, 4, 3, 2, 4, 3, 2, 4, 3, 2, 3]
print(s.PartitionList1(nums, k))
print(s.PartitionList2(nums, k))
print(s.PartitionList3(nums, k))


