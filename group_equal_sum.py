# Give n*n array and a target number. Find in each row a column
# that differs from other and total sum is target

class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Using backtracking
    # Time complexity: O(n!)
    def __groupEqualSumHelper(self, arr, target, sum=0, start=0, visit=[]):
        n = len(arr)-1
        result = []
        if start == n+1 and sum == target:
            return [visit[:]]
        if (start == n+1 and sum != target) or (sum >= target and start < n):
            return []

        for i in range(len(arr[start])):
            newVisit = visit[:]
            newSum = sum
            if i not in newVisit:
                newVisit.append(i)
                newSum += arr[start][i]
                result += self.__groupEqualSumHelper(arr, target, newSum, start+1, newVisit)

        return result

    def groupEqualSum(self, arr, target):
        return self.__groupEqualSumHelper(arr, target)

    # Using non-recursive method
    def groupEqualSumIterative(self, arr, target):
        n = len(arr)-1
        stack = [[[], 0, -1]]
        result = []
        while stack:
            visit, sum, start = stack.pop()
            if start == n and sum == target:
                result.append(visit)
            if (start == n and sum != target) or (sum >= target and start < n):
                continue
            for i in range(len(arr[start])):
                newVisit = visit[:]
                if i not in newVisit:
                    newVisit.append(i)
                    new_sum = sum + arr[start][i]
                    stack.append([newVisit, new_sum, start+1])

        return result

arr = [[1,2,3,4,5,6], [5,6,7,8,9,10], [9,10,11,12,13,14], [13,14,15,16,17,18], [17,18,19,20,21,60], [21,33,45,50,90,100]]
target = 81
s = Solution()
# print(s.groupEqualSum(arr, target))
print(s.groupEqualSumIterative(arr, target))
