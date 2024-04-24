class Solution {
public:
    // Time complexity: O(logn)
    // Space complexity: O(logn)
    bool binarySearch(vector<vector<int>>& matrix, int col_start, int col_end, int row_start, int row_end, int target) {
        bool ret = false;
        if (col_start > col_end || row_start > row_end 
            || col_start < 0 || col_end < 0
            || row_start < 0 || row_end < 0) {
            return false;
        }
        //cout << col_start << col_end << row_start << row_end << endl;
        int x = (row_start + row_end) / 2;
        int y = (col_start + col_end) / 2;
        int mid = matrix[x][y];
        //cout << x << y << mid << endl;
        if (mid == target) {
            return true;
        }
        else if (mid > target) {
            ret = binarySearch(matrix, col_start, y-1, row_start, row_end, target);
            if (ret) return ret;
            ret = binarySearch(matrix, y, col_end, row_start, x-1, target);
            if (ret) return ret;
        }
        else {
            ret = binarySearch(matrix, y+1, col_end, row_start, row_end, target);
            if (ret) return ret;
            ret = binarySearch(matrix, col_start, y, x+1, row_end, target);
            if (ret) return ret;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ret = binarySearch(matrix, 0, n-1, 0, m-1, target);
        return ret;
    }
};
