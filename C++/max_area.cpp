class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int m = 0;
        while (i < j) {
            int s = (j-i) * min(height[i], height[j]);
            if (s > m) m = s;
            if (height[i] <= height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return m;
    }
};
