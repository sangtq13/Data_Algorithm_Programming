class Solution {
public:
    void backtrack(int k, int n, unordered_set<int>& existed, vector<int>& valid_com, vector<vector<int>>& result) {
        if (k == 0 && n == 0) {
            result.push_back(valid_com);
        }
        if (k < 0 || n < 0) return;
        for (int i = 1; i < 10; ++i) {
            bool check_increase = valid_com.empty() ? true : i > valid_com.back();
            if (existed.find(i) == existed.end() && check_increase) {
                existed.insert(i);
                valid_com.push_back(i);
                backtrack(k - 1, n - i, existed, valid_com, result);
                existed.erase(i);
                valid_com.pop_back();
            }
        }
    }

    // Time complexity: (9-k)!
    // Space complexity: O(1)
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> valid_com;
        unordered_set<int> existed;
        backtrack(k, n, existed, valid_com, result);
        return result;
    }
};
