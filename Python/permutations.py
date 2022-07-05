class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Recursive method
    # Time complexity: O(n!)
    def permute1(self, arr):
        n = len(arr)
        if n == 1:
            return [arr]
        ret = []
        for i in range(n):
            p = self.permute1(arr[:i] + arr[i+1:])
            for j in range(len(p)):
                p[j].insert(0, arr[i])
                ret.append(p[j])
        return ret

    # __permuteHelper using backtracking method
    # Time complexity: O(n!)
    def __permuteHelper(self, arr, start=0):
        if start == len(arr)-1:
            return [arr[:]]
        n = len(arr)
        result = []
        for i in range(start, n):
            arr[i], arr[start] = arr[start], arr[i]
            result += self.__permuteHelper(arr, start+1)
            arr[i], arr[start] = arr[start], arr[i]

        return result


    def permute2(self, array):
        return self.__permuteHelper(arr)

    # permutationsIterative method
    # Time complexity: O(n!)

    def permutationsIterative(self, arr):
        n = len(arr)-1
        stack = [[arr, []]]
        result = []

        while stack:
            nums, value = stack.pop()
            if not nums:
                result.append(value)
            for i in range(len(nums)-1, -1, -1):
                stack.append([nums[:i] + nums[i+1:], value+[nums[i]]])

        return result

arr = [1,2,3,4]
s = Solution()
# arrs = s.permute1(arr)
# arrs = s.permute2(arr)
arrs = s.permutationsIterative(arr)
for a in arrs:
    print(a)
