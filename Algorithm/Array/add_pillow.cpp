class Solution {
public:
    // Time complexity: O(1)
    // Space complexity: O(1)
    int passThePillow(int n, int time) {
        int d = time / (n-1);
        int m = time % (n-1);
        return d % 2 == 0 ? m + 1 : n - m; 
        
    }
};
