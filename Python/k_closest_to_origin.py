import heapq
class Solution(object):
    def __init__(self):
        self.name = 'S->13'

    # Using sorting method:
    # Time complexity: O(nlogn)
    # Space complexity: O(logn) to O(n) in worst case
    def kClosestA(self, points, k):
        points.sort(key=lambda x: x[0] ** 2 + x[1] ** 2)
        return points[:k]

    # Using min heap method
    # Time complexity: O(n)
    # Space complexity: O(n)
    def kClosestB(self, points, k):
        heap = []
        ret = []
        for p in points:
            distance = p[0] ** 2 + p[1] ** 2
            heapq.heappush(heap, [distance, p[0], p[1]])
        for _ in range(k):
            smallest = heapq.heappop(heap)
            ret.append([smallest[1], smallest[2]])
        return ret

    def __distance(self, p):
        return p[0] ** p[0] + p[1] ** p[1]

    # def __patition(self, points, left, right):
    #     mid = (left + right) // 2
    #     points[left], points[mid] = points[mid], points[left]
    #     index = left
    #     for i in range(left+1, right+1):
    #         if (self.__distance(points[i]) <= self.__distance(points[left])):
    #             index += 1
    #             points[i], points[index] = points[index], points[i]
    #     if index < right + 1:
    #         points[index], points[left] = points[left], points[index]
    #     return index

    # def __patition(self, points, left, right):
    #     mid = (left + right) // 2
    #     pivot = self.__distance(points[mid])
    #     while left < right:
    #         while left <= right and self.__distance(points[left]) < pivot:
    #             left += 1
    #         while self.__distance(points[right]) > pivot:
    #             right -= 1
    #         if left < right:
    #             points[left], points[right] = points[right], points[left]
    #             left += 1
    #             right -= 1
    #     return left

    def __patition(self, points, left, right):
        mid = (left + right) // 2
        pivot = self.__distance(points[mid])
        while left < right:
            if self.__distance(points[left]) >= pivot:
                points[left], points[right] = points[right], points[left]
                right -= 1
            else:
                left += 1
        if self.__distance(points[left]) < pivot:
            left += 1
        return left

    def kClosestC(self, points, k):
        left = 0
        right = len(points) - 1
        pivot = len(points)
        while pivot != k:
            pivot = self.__patition(points, left, right)
            if pivot < k:
                left = pivot
            elif pivot > k:
                right = pivot - 1

        return points[:k]


# points = [[1, 1], [3, 3], [2, 2], [4, 4], [-1, -1]]
# k = 2
# print(Solution().kClosestA(points, k))
# print(Solution().kClosestB(points, k))
print(Solution().kClosestC([[0,1],[1,0]], 2))
# print(Solution().kClosestC([[1, 1], [3, 3], [2, 2], [4, 4], [-1, -1]], 2))
# print(Solution().kClosestC([[1,3],[-2,2]], 1))
# print(Solution().kClosestC([[1,3],[-2,2],[2,-2]], 2))
