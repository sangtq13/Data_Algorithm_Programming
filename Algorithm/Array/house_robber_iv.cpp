class Solution {
public:
    bool helper(vector<int>&nums, int k, int mid) {
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] <= mid) {
                k--;
                if (k == 0) {
                    return true;
                }
                i+=2;
            }
            else {
                i++;
            }
        }
        return k == 0;
    }

    // Time complexity: o(nlogn)
    // Space complexity: O(1)
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 1, high = 1e9+1;
        int ans = INT_MAX;
      
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (helper(nums, k, mid)) {
                ans = min(ans, mid);
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
      
        return ans;
    }
};
