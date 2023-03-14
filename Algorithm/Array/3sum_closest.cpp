class Solution {
public:
  // Time complexity: O(n^2)
  // Space complexity: O(1)
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n-2; ++i) {
      if(i > 0 && nums[i] == nums[i-1]) continue;
      int second = i + 1;
      int third = n - 1;
      while (second < third) {
        int sum = nums[i] + nums[second] + nums[third];
        if (sum == target) return target;
        if (abs(sum-target) < abs(closest-target)) {
          closest = sum;
        }
        if (sum < target) {
          second++;
        }
        else if (sum > target) {
          third--;
        }
      }
    }

    return closest;
  }
};
