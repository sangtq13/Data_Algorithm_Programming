class Solution {
public:
    bool existsInFirst(vector<int>& nums, int start, int element) {
        return nums[start] <= element;
    }
    // Time complexity: O(n) in worst case or O(logn) in normal case
    // Space complexity: O(1)
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;

        while(start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[start]) {
                start++;
                continue;
            }
            bool midInFirst = existsInFirst(nums, start, nums[mid]);
            bool targetInFirst = existsInFirst(nums, start, target);
            if (midInFirst && !targetInFirst) {
                start = mid + 1;
            }
            else if (!midInFirst && targetInFirst) {
                end = mid - 1;
            }
            else {
                if (target >= nums[mid]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }

        }
        return false;
    }
};
