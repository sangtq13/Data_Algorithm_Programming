class Solution {
public:
    void backtracking(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> cur, int& cur_sum, int start = 0) {
        if (cur_sum == target) {
            ans.push_back(cur);
        }
        if (cur_sum >= target) return;
        for (int i = start; i < candidates.size(); ++i) {
            bool check = false;
            if (cur_sum + candidates[i] <= target) {
                cur.push_back(candidates[i]);
                check = true;
                cur_sum += candidates[i];
                backtracking(candidates, target, ans, cur, cur_sum, i);
            }
            if (check == true) {
                cur.pop_back();
                cur_sum -= candidates[i];
            }
        }
    }
    
    // Time complexity: O(2ˆn)
    // Space complexity: O(2ˆn)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        int cur_sum = 0;

        backtracking(candidates, target, ans, cur, cur_sum);
        return ans;
    }
};
