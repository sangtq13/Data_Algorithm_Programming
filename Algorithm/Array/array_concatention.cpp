class Solution {
public:
  // Time complexity: O(n)
  // Space complexity: O(1)
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        long long ret = 0;
        for (int i = 0; i < n/2; ++i) {
            string s = to_string(nums[i]) + to_string(nums[n-1-i]);
            ret += stoi(s);
        }
        if (n%2 == 1) ret += nums[n/2];
        return ret;
    }
};
