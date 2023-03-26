class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low - 1;
    }
    
    // Time complexity: O(max(logn * m, nlogn))
    // Space complexity: O(n)
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> ans;
        long long dp[100001];
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1] + nums[i-1];
        }
        
        for (auto q : queries) {
            if (q <= nums[0]) {
                ans.push_back(dp[n] - (long long)q * n);
            }
            else if (q >= nums[n-1]) {
                ans.push_back((long long)q * n - dp[n]);
            }
            else {
                int index = binarySearch(nums, 0, n-1, q);
                long long count = (long long)q * (index + 1) - dp[index+1] + dp[n] - dp[index+1] - (long long)q * (n - index -1);
                ans.push_back(count);
            }
        }
        return ans;
    }
};
