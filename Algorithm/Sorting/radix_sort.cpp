class Solution {
public:
    void countingSort(vector<int>& nums, int exp) {
        int count[10] = {0};
        int n = nums.size();
        vector<int> output(n);

        for (int i = 0; i < n; ++i) {
            count[(nums[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; ++i) {
            count[i] += count[i-1];
        }

        for (int i = n-1; i >= 0; --i) {
            output[count[(nums[i] / exp) % 10] - 1] = nums[i];
            count[(nums[i] / exp) % 10]--;
        }
        nums.swap(output);
    }

    void radixSort(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        for (int exp = 1; m / exp > 0; exp *= 10) {
            countingSort(nums, exp);
        }
    }

    // Time complexity: O(n)
    // Space complexity: O(n)
    int maximumGap(vector<int>& nums) {
        int max_gap = 0;
        radixSort(nums);
        for (int i = 1; i < nums.size(); ++i) {
            max_gap = max(max_gap, nums[i] - nums[i-1]);
        }
        return max_gap;
    }
};
