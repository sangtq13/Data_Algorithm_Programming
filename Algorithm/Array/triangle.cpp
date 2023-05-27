class Solution {
public:
  // Time complexity: O(n)
  // Space complexity: O(1)
  int minimumTotal(vector<vector<int>>& triangle) {
    int min_value = 1e7;
    int n = triangle.size();
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i + 1; ++j) {
        if (j == 0) {
          triangle[i][j] += triangle[i-1][j];
        }
        else if (j == i) {
          triangle[i][j] += triangle[i-1][j-1];
        }
        else {
          triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
        min_value = min(min_value, triangle[n-1][i]);
    }
    
    return min_value;
  }
};
