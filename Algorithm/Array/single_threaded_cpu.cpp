class Compare {
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) {
            return true;
        }
        else if (a.first == b.first) {
            if (a.second > b.second) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
};

class Solution {
public:
    // Time complexity: O(nlogn)
    // Space complexity: O(n)
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        int start = 0;
        int i = 0;
        for (i = 0; i < n; ++i) {
            if (tasks[i][0] == tasks[0][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
            }
            else {
                break;
            }
        }
        start = i;
        long long current_time = tasks[0][0];
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            ans.push_back(top.second);

            int process_time = top.first;

            for (i = start; i < n; ++i) {
                if (tasks[i][0] <= current_time + process_time) {
                    pq.push({tasks[i][1], tasks[i][2]});
                }
                else {
                    break;
                }
            }
            
            current_time += process_time;
            start = i;
            if (pq.empty() && ans.size() < n) {
                pq.push({tasks[start][1], tasks[start][2]});
                current_time = tasks[start][0];
                start++;
            }
        }

        return ans;
    }
};
