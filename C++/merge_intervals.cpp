class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (auto& i : intervals) {
            if (i[0] > end) {
                ret.push_back({start, end});
                start = i[0];
                end = i[1];
            }
            else {
                start = min(start, i[0]);
                end = max(end, i[1]);
            }
        }
        ret.push_back({start, end});
        
        return ret;
    }
};
