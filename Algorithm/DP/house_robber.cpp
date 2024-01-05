class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int rob(vector<int>& nums) {
        int n = nums.size();
        int first = 0;
        int second = nums[0];
        for (int i = 1; i < n; ++i) {
            int first_tmp = first;
            first = max(first, second);
            second = first_tmp + nums[i];
        }
        return max(first, second);
    }
};
