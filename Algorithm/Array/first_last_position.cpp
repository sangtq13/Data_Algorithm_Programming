class Solution {
public:
  // Recursive method 
  // Time complexity: O(logn)
  // Space complexity: O(logn) for stack usage
  void binarySearch(vector<int>& nums, int low, int high, int target, int& left_most, int& right_most) 
  {
    if (low > high) return; 
    int mid = (low + high) / 2;
    if (nums[mid] == target) {
      if (left_most == -1 && right_most == -1) {
        left_most = mid;
        right_most = mid;
      }
      else if (mid < left_most) {
        left_most = mid;
        this->binarySearch(nums, low, mid-1, target, left_most, right_most);
        return;
      }
      else if (mid > right_most) {
        right_most = mid;
        this->binarySearch(nums, mid+1, high, target, left_most, right_most);
        return;
      }
    }
    this->binarySearch(nums, low, mid-1, target, left_most, right_most);
    this->binarySearch(nums, mid+1, high, target, left_most, right_most);
  } 

  vector<int> searchRange(vector<int>& nums, int target) {
    int left_most = -1;
    int right_most = -1;
    int n = nums.size();
    this->binarySearch(nums, 0, n-1, target, left_most, right_most);
    return {left_most, right_most};
  }
};
