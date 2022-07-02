class Solution {
public:
    typedef pair<int, int> pp;
    // Using priority method using min heap
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
    
    // Using priority method using max heap
    // Time complexity: O(n)
    // Space complexity: O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;
        priority_queue<pp> pq;
        for (int i = 0; i < points.size(); ++i) {
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(i < k) {
                pq.push(make_pair(distance, i));
            }
            else if (distance < pq.top().first){
                pq.pop();
                pq.push(make_pair(distance, i));
            }
        }
        for (int i = 0; i < k; ++i) {
            auto top = pq.top();
            ret.push_back(points[top.second]);
            pq.pop();
        }
        return ret;
    }
};
