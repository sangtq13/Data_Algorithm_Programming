class Solution():
    def __init__(self):
        self.name = 'S->13'

    # Time complexity: O(logn)
    # Space complexity: O(logn)
    def __FixedPointHelper(self, low, high, nums):
        if low > high:
            return None
        mid = (low + high) // 2
        if nums[mid] == mid:
            minLocation = self.__FixedPointHelper(low, high-1, nums)
            if minLocation != None:
                return minLocation
            else:
                return mid
        elif nums[mid] > mid:
            return self.__FixedPointHelper(low, mid-1, nums)
        else:
            return self.__FixedPointHelper(mid+1, high, nums)

    def FixedPointRecursive(self, nums):
        return self.__FixedPointHelper(0, len(nums)-1, nums)

    # Time complexity: O(logn)
    # Space complexity: O(1)
    def FixedPoint(self, nums):
        low = 0
        high = len(nums) - 1
        minLocation = high

        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == mid:
                minLocation = mid
                high = mid - 1
            elif nums[mid] > mid:
                high = mid - 1
            else:
                low = mid + 1
        return minLocation

nums = [-5, 0 , 1, 3, 3, 4, 9]
print(Solution().FixedPoint(nums))
print(Solution().FixedPointRecursive(nums))
