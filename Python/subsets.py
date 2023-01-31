import copy
class Solution(object):
  # Time complexity: O(n*2^n)
  # Space complexity: O(n*2^n)
  # Cascading solution
  def subsets1(self, nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    ans = [[]]

    for num in nums:
      tmp = copy.deepcopy(ans)
      for t in tmp:
          t.append(num)
      ans.extend(tmp)

    return ans
  
  # Time complexity: O(n*2^n)
  # Space complexity: O(n)
  #  Backtracking solution
  def subsets2(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first = 0, curr = []):
            # if the combination is done
            if len(curr) == k:  
                output.append(curr[:])
                return
            for i in range(first, n):
                curr.append(nums[i])
                backtrack(i + 1, curr)
                curr.pop()
        
        output = []
        n = len(nums)
        for k in range(n + 1):
            backtrack()
        return output
