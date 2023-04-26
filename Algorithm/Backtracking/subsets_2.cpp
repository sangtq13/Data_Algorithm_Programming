class Solution {
public:

    void backtracking(vector<int>& nums, int start, vector<int>& subsets, vector<vector<int>>& ans) {
        int pre = INT_MIN;
        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] == pre) continue;
            subsets.push_back(nums[i]);
            ans.push_back(subsets);
            backtracking(nums, i+1, subsets, ans);
            subsets.pop_back();
            pre = nums[i];
        }
    }

    // Time complexity: O(2^n)
    // Space complexity: (n)
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subsets;
        sort(nums.begin(), nums.end());
        ans.push_back({});
        backtracking(nums, 0, subsets, ans);

        return ans;
    }
};
