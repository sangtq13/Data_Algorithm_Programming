class Solution {
public:
    // Time complexity: O(n^3)
    // Space complexity: O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> visited;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int first = 0; first < n-3; ++first) {
            for (int second = first+1; second < n-2; ++second) {
                int third = second + 1;
                int fourth = n-1;
                while (third < fourth) {
                    long int sum = (long int)nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (sum == target) {
                        if (visited.find({nums[first], nums[second], nums[third], nums[fourth]}) == visited.end()) {
                            ans.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                            visited.insert({nums[first], nums[second], nums[third], nums[fourth]});
                        }
                        third++;
                        fourth--;
                    }
                    else if (sum > target) {
                        fourth--;
                    }
                    else {
                        third++;
                    }
                }
            }
        }
        return ans;
    }
};
