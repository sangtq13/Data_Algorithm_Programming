class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    long long pickGifts(vector<int>& gifts, int k) {
        long long ret = 0;
        priority_queue<int> pq;
        for (auto g: gifts) pq.push(g);
        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            if (k > 0) {
                pq.push(sqrt(top));
                k--;
                continue;
            }
            else {
                ret += top;
            }
        }
        return ret;
    }
};
