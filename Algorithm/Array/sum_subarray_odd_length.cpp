class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int sumOddLengthSubarrays(vector<int>& arr) {
        int s = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            s += (((i+1) * (n-i) + 1) / 2) * arr[i];
        }
        return s;
    }
};
