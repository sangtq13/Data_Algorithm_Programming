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
        this->binarySearch(nums, low, mid-1, target, left_most, right_most);
        this->binarySearch(nums, mid+1, high, target, left_most, right_most);
      }
      else if (mid < left_most) {
        left_most = mid;
        this->binarySearch(nums, low, mid-1, target, left_most, right_most);
      }
      else if (mid > right_most) {
        right_most = mid;
        this->binarySearch(nums, mid+1, high, target, left_most, right_most);
      }
    }
    else if (nums[mid] > target) {
      this->binarySearch(nums, low, mid-1, target, left_most, right_most);
    }
    else {
      this->binarySearch(nums, mid+1, high, target, left_most, right_most);
    }
  } 

  // 
  vector<int> searchRange(vector<int>& nums, int target) {
    int left_most = -1;
    int right_most = -1;
    int n = nums.size();
    this->binarySearch(nums, 0, n-1, target, left_most, right_most);
    return {left_most, right_most};
  }
  
  int iterativeSearch(vector<int>& nums, int low, int high, int target, bool left_most = false) 
  {
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        if (left_most) {
          if (mid == 0 || nums[mid-1] < nums[mid]) {
            return mid;
          }
          high = mid - 1;
        }
        else {
          if (mid == nums.size()-1 || nums[mid] < nums[mid+1]) {
            return mid;
          }
          low = mid + 1;
        }
      }
      else if (nums[mid] > target) {
        high = mid -1;
      }
      else {
        low = mid + 1;
      }
    }
    return -1;
  } 
  // Iterative method
  // Time complexity: O(logn)
  // Space complexity: O(1)
  vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int left_most = iterativeSearch(nums, 0, n-1, target, true);
    int right_most = iterativeSearch(nums, 0, n-1, target, false);
    return {left_most, right_most};
  }
};
