class Solution {
public:
    // Time complexity: O(nlogn in worst case)
    // Space complexity: O(k) 
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int max_reward = 0;
        int n = reward1.size() - 1;
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            max_reward += reward1[i];
            pq.push(reward2[i] - reward1[i]);
        }
        
        for (int i = k; i <= n; ++i) {
            if (pq.empty()) {
                max_reward += reward2[i];
            }
            else {
                int diff = reward2[i] - reward1[i];
                if (diff >= pq.top()) {
                    max_reward += reward2[i];
                }
                else {
                    max_reward += pq.top() + reward1[i];
                    pq.pop();
                    pq.push(diff);
                }   
            }
        }

        return max_reward;
    }
};
