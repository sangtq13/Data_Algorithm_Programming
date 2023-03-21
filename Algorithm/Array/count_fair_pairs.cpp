class Solution {
public:
    
    // Time complexity: O(nlogn)
    // Space complexity: O(1)
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        long long count = 0;
        while (left < right) {
            long long total = (long long)nums[left] + nums[right];
            if (total < lower) {
                left++;
            }
            else if (total > upper) {
                right--;
            }
            else {
                count++;
                int low = left + 1;
                int high = right - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if ((long long)nums[mid] + nums[right] <= upper) {
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
                count += (low - left - 1);
                low = left + 1;
                high = right - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if ((long long)nums[mid] + nums[left] >= lower) {
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }
                count += (right - high - 1);
                left++;
                right--;
            }
        }
        return count;
    }
};
