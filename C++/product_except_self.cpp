class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        ans[0] = 1;
        int p = 1;
        for (int i = n-2; i >= 0; --i) {
            p *= nums[i+1];
            ans[i] = p;
        }
        p = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] *= p;
            p *= nums[i];
        }
        return ans;
    }
};
