class Solution {
public:
  // Time complexity: O(n)
  // Space complexity: O(1)
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n-1;
    for (; i > 0; --i) {
      if (nums[i-1] < nums[i]) break;
    }
    int left = i-1;
    if (left == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }

    for (i = n-1; i > left; --i) {
      if (nums[i] > nums[left]) break;
    }

    swap(nums[left], nums[i]);
    for (i = 0; i <= (n-left-2)/2; ++i) {
      swap(nums[left+1+i], nums[n-1-i]);
    }
  }
};
