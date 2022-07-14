class Solution {
public:
    typedef pair<int, char> pt;
    // Time complexity: O(n)
    // Space complexity: O(n) in worst case
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for (auto task : tasks) {
            m[task]++;
        }
        priority_queue<pt> pq;
        for (auto it = m.begin(); it != m.end(); ++it) {
            pq.push({it->second, it->first});
        }
        int result = 0;
        while (!pq.empty()) {
            int k = n + 1;
            vector<pt> wait_list;
            while (k && !pq.empty()) {
                auto [count, task] = pq.top();
                result++;
                if (count > 1) {
                    wait_list.push_back({count - 1, task});
                }
                k--;
                pq.pop();
            }
            for (auto w : wait_list) {
                pq.push(w);
            }
            if (!pq.empty()) result += k;
        }
        return result;
    }
};
