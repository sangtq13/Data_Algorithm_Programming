class Solution {
public:
    int SearchSeparate(vector<int>& nums, int left, int right) {
        int n = nums.size();
        while(left <= right) {
            if (nums[left] < nums[right]) return left;
            int mid = (left + right) / 2;
            if (nums[mid] < nums[(mid+n-1)%n]) return mid;
            else if (nums[left] <= nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int BinarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
    
    // Time complexity: O(logn)
    // Space complexity: O(1)
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int separate_index = SearchSeparate(nums, 0, n-1);
        int left = BinarySearch(nums, 0, separate_index-1, target);
        if (left != -1) return left;
        if (separate_index == -1) separate_index = 0;

        return BinarySearch(nums, separate_index, n-1, target);
    }
};
