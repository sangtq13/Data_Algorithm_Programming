class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int solve(vector<int>& nums, int start, int end) {
        int first = 0;
        int second = nums[start];
        for (int i = start+1; i <= end; ++i) {
            int tmp = first;
            first = max(first, second);
            second = tmp + nums[i];
        }
        return max(first, second);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int ret = solve(nums, 0, n-2);  
        ret = max(ret, solve(nums, 1, n-1));
        return ret;
    }
};
