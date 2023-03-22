class Solution {
public:
    // Time complexity: O(nlogn)
    // Space complexity: O(1)
    int maxScore(vector<int>& nums) {
        long long sum = 0;
        int count = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for (auto& num : nums) {
            sum += num;
            if (sum > 0) count++;
        }
        return count;
    }
};
