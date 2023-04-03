class Solution {
public:
    void backtracking(vector<vector<int>>& ans, vector<int>& cur, unordered_map<int, int>& count, int n) {
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second != 0) {
                it->second--;
                cur.push_back(it->first);
                backtracking(ans, cur, count, n);
                it->second++;
                cur.pop_back();
            } 
        }
    }

    // Time complexity: O(n*n!)
    // Space complexity: O(n)
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        unordered_map<int, int> count;
        int n = nums.size();
        for (auto n : nums) count[n]++;
        backtracking(ans, cur, count, n);

        return ans;
    }
};
