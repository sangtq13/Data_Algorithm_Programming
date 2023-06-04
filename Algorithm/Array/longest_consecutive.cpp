class Solution {
public:
  // Time complexity: O(n)
  // Space complexity: O(n)
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;

    for (auto& n : s) {
      if (s.find(n-1) == s.end()) {
        int j = n;
        while (s.find(j) != s.end()) {
          j++;
        }
        longest = max(longest, j - n);
      }
    }

    return longest;
  }
};
