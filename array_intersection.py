class Solution(object):
    def __int__(self):
        self.name = 'S->13'

    # Using hashmap
    # Time complexity: O(n)
    # Space complexity: O(n)
    def arrayIntersectionA(self, nums1, nums2):
        s = set(nums1)
        d = {}
        for n in nums2:
            if n in s:
                d[n] = d.get(n, 0) + 1

        return list(d.keys())

    # Using sorting and hashmap
    # Time complexity: O(nlogn)
    # Space compleity: O(n)
    def arrayIntersectionB(self, nums1, nums2):
        visited = set()
        nums1.sort()
        nums2.sort()
        i = j = 0
        l1 = len(nums1)
        l2 = len(nums2)
        ret = []
        while i < l1 and j < l2:
            if nums1[i] > nums2[j]:
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                if nums1[i] not in visited:
                    ret.append(nums1[i])
                i += 1
                j += 1

        return ret

nums1 = [4, 9, 5]
nums2 = [9, 4, 9, 8 , 4, 9, 3]
print(Solution().arrayIntersectionA(nums1, nums2))
print(Solution().arrayIntersectionB(nums1, nums2))
