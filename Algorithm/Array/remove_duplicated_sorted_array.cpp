class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        int n = nums.size();
        int start = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[start]) {
                if (i - start >= 2) {
                    nums[cur++] = nums[start];
                    nums[cur++] = nums[start];
                }
                else {
                    nums[cur++] = nums[start];
                }
                start = i;
            }
        }
        if (start == n-1) {
            nums[cur++] = nums[start];
        }
        else {
            nums[cur++] = nums[start];
            nums[cur++] = nums[start];
        }

        return cur;
    }
};
