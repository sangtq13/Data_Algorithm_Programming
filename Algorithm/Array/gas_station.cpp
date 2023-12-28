class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int neg = 0;
        int start_pos = 0;
        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += (gas[i] - cost[i]);
            if (total < 0) {
                neg += total;
                total = 0;
                start_pos = i + 1;
            }
        }
        return (total + neg >= 0) ? start_pos : -1;
    }
};
