class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    vector<int> leftRigthDifference(vector<int>& nums) {
        int dp[1001] = {0};
        int n = nums.size();
        vector<int> ans;
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1] + nums[i-1];
        }
        for (int i = 1; i <= n; ++i) {
            ans.push_back(abs(dp[i] + dp[i-1] - dp[n]));
        }
        return ans;
    }
};
