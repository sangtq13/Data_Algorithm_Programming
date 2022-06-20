class Solution(object):
    def __init__(self):
        self.name = 'S->13'
    
    # This method uses in the case that we don't sort the list
    # Time complexity: O(n^2)
    # Space complexity: O(n)
    def threeSumA(self, nums):
        l = len(nums)
        i = 0
        j = l-1
        index = 0
        result = []
        while index <= j:
            if nums[index] < 0:
                nums[index], nums[i] = nums[i], nums[index]
                i += 1
                index += 1
            elif nums[index] == 0:
                index += 1
            elif nums[index] > 0:
                nums[j], nums[index] = nums[index], nums[j]
                j -= 1
        nums[:i] = sorted(nums[:i])
        nums[index:] = sorted(nums[index:])
        if j-i > 1:
            result.append([0, 0, 0])

        s1 = set()
        for m in nums[index:]:
            s1.add(m)

        for x in range(index-1):
            for y in range(x+1, index):
                temp = -(nums[x] + nums[y])
                if temp in s1 and [nums[x], nums[y], temp] not in result:
                    result.append([nums[x], nums[y], temp])
        s2 = set()
        for m in nums[:i]:
            s2.add(m)
        for x in range(index, l-1):
            for y in range(x+1, l):
                temp = -(nums[x] + nums[y])
                if temp in s2 and [temp, nums[x], nums[y]] not in result:
                    result.append([temp, nums[x], nums[y]])
        return result

    def __twoSum(self, nums, start, result):
        target = -nums[start]
        value = {}
        l = len(nums)
        for i in range(start+1, l):
            diff = target - nums[i]
            if diff in value and [nums[start], diff, nums[i]] not in result:
                result.append([nums[start], diff, nums[i]])
            else:
                value[nums[i]] = 1

    # Using hashmap with twosum algorithm for sorted list
    # We can parition negative number to left, zero in middle and
    # non-negative number in the right and sort each part instead of
    # using sorting for all list
    # Time complexity: O(n^2)
    # Space complexity: O(n^2)
    def threeSumHashmap(self, nums):
        # nums.sort()
        l = len(nums)
        i = 0
        j = l - 1
        index = 0
        while index <= j:
            if nums[index] < 0:
                nums[index], nums[i] = nums[i], nums[index]
                i += 1
                index += 1
            elif nums[index] == 0:
                index += 1
            elif nums[index] > 0:
                nums[j], nums[index] = nums[index], nums[j]
                j -= 1
        nums[:i] = sorted(nums[:i])
        nums[index:] = sorted(nums[index:])
        result = []
        for i in range(l):
            self.__twoSum(nums, i, result)
        result.sort()
        return result

    def __twoSumIndices(self, nums, start, result):
        i = start+1
        j = len(nums)-1
        target = -nums[start]
        while i < j:
            if nums[i] + nums[j] < target:
                i += 1
            elif nums[i] + nums[j] > target:
                j -= 1
            else:
                if [nums[start], nums[i], nums[j]] not in result:
                    result.append([nums[start], nums[i], nums[j]])
                i += 1
                j -= 1

    # Using indices for sorting list
    # Time complexity: O(n^2)
    # Space complexity: O(k)
    def threeSumIndices(self, nums):
        l = len(nums)
        i = 0
        j = l-1
        index = 0
        result = []
        while index <= j:
            if nums[index] < 0:
                nums[index], nums[i] = nums[i], nums[index]
                i += 1
                index += 1
            elif nums[index] == 0:
                index += 1
            elif nums[index] > 0:
                nums[j], nums[index] = nums[index], nums[j]
                j -= 1
        nums[:i] = sorted(nums[:i])
        nums[index:] = sorted(nums[index:])
        for i in range(l):
            self.__twoSumIndices(nums, i, result)

        return result

nums = [-1,0,1,2,-1,-4,-2,-3,3,0,4]
#[[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]
s = Solution()
# print(s.threeSum(nums))
# print(s.threeSumHashmap(nums))
print(s.threeSumIndices(nums))

