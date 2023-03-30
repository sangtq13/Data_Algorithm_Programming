class Solution {
public:
    void backtracking(map<int, int>& m, vector<vector<int>>& ans, vector<int>& cur, 
            int& target, map<int, int>::iterator& cur_group) {
        if (0 == target) ans.push_back(cur);
        if (cur_group == m.end() || target <= 0) {
            return;
        }
        for (int i = 0; i <= cur_group->second; ++i) {
            if (i > 0) {
                target -= cur_group->first;
                cur.push_back(cur_group->first);
            }

            cur_group++;
            
            backtracking(m, ans, cur, target, cur_group);
            cur_group--;

            if (i == cur_group->second) {
                target += cur_group->first * i;
                for (int j = 0; j < cur_group->second; ++j) cur.pop_back();
            }
        }
    }

    // Time complexity: O(2^n)
    // Space complexity: O(n)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        int cur_sum = 0;
        map<int, int> m;
        for (auto c : candidates) {
            m[c]++;
        }


        auto cur_group = m.begin();
        backtracking(m, ans, cur, target, cur_group);

        return ans;
    }
};
