class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int lower_bound = newInterval[0];
        int upper_bound = newInterval[1];
        
        for (; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
                continue;
            }
            if (intervals[i][0] > newInterval[1]) break;
            lower_bound = min(lower_bound, intervals[i][0]);
            upper_bound = max(upper_bound, intervals[i][1]);
        }
        ans.push_back({lower_bound, upper_bound});
        for (; i < intervals.size(); ++i) {
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
