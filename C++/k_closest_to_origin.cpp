class Solution {
public:
    typedef pair<int, int> pp;
    // Using priority method
    // Time complexity: O(n)
    // Space complexity: O(n)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (int i = 0; i < points.size(); ++i) {
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push(make_pair(distance, i));
        }
        for (int i = 0; i < k; ++i) {
            auto top = pq.top();
            ret.push_back(points[top.second]);
            pq.pop();
        }
        return ret;
    }
};
