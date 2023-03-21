class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long n = 0;
        for (auto c : word) {
            n = n * 10 + c - '0';
            if (n % m == 0) {
                ans.push_back(1);
            }
            else {
                ans.push_back(0);
            }
            n = n % m;
        }
        
        return ans;
    }
};
