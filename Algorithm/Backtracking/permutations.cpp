class Solution {
public:
    void backtracking(vector<vector<int>>& ans, vector<int>& cur,
                            unordered_map<int, bool>& seen, vector<int>& nums) 
    {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (seen[i] == false) {
                seen[i] = true;
                cur.push_back(nums[i]);
                backtracking(ans, cur, seen, nums);
                seen[i] = false;
                cur.pop_back();
            }
        }
    }

    // Time complexity: O(n!)
    // Space complexity: O(n)
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        unordered_map<int, bool> seen;
        for (int i = 0; i < nums.size(); ++i) {
            seen[i] = false;
        }

        backtracking(ans, cur, seen, nums);
        return ans;
    }
};
