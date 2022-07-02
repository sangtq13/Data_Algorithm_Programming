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
    
    int distance(vector<int> p) {
        return p[0] * p[0] + p[1] * p[1];
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        int mid = (left + right) / 2;
        int index = left;
        swap(points[mid], points[left]);
        for (int i = left+1; i < right+1; ++i) {
            if (distance(points[i]) <= distance(points[left])) {
                index++;
                swap(points[i], points[index]);
            }
        }
        if (index < right + 1) {
            swap(points[index], points[left]);
        }
        
        return index;
    }
    // Using partition method
    // Time complexity: O(n)
    // Space complexity: O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = points.size();
        int left = 0;
        int right = l-1;
        int pivot = 0;
        vector<vector<int>> ret;
        while (pivot != k && left <= right) {
            pivot = partition(points, left, right);
            if (pivot < k) {
                left = pivot + 1;
            }
            else if (pivot > k) {
                right = pivot - 1;
            }
        }
        for (int i = 0; i < k ; ++i) {
            ret.push_back(points[i]);
        }
        return ret;
    }
};
