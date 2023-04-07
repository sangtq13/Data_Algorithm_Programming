#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
class Solution {
public:
    void nextPosition(int&x, int&y, int cur_dir) {
        if (cur_dir == LEFT) {
            y--;
        }
        else if (cur_dir == RIGHT) {
            y++;
        }
        else if (cur_dir == UP) {
            x--;
        }
        else if (cur_dir == DOWN) {
            x++;
        }
    }

    void nextDirection(int& x, int& y, int& cur_dir, int n, vector<vector<int>>& ans) {
        if (cur_dir == LEFT) {
            if (!validPosition(x, y-1, n, ans)) {
                cur_dir = UP;
            }
        }
        else if (cur_dir == RIGHT) {
            if (!validPosition(x, y+1, n, ans)) {
                cur_dir = DOWN;
            }
        }
        else if (cur_dir == UP) {
            if (!validPosition(x-1, y, n, ans)) {
                cur_dir = RIGHT;
            }
        }
        else if (cur_dir == DOWN) {
            if (!validPosition(x+1, y, n, ans)) {
                cur_dir = LEFT;
            }
        }
    }

    bool validPosition(int x, int y, int n, vector<vector<int>>& ans) {
        if (0 <= x && x < n && 0 <= y && y < n && ans[x][y] == 0) return true;
        return false;
    }
  
    // Time complexity: O(n*n)
    // Space complexity: O(1)
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int size = n * n;
        int x = 0; 
        int y = -1;
        int cur_dir = RIGHT;
        int i = 1;
        while (i <= size) {
            nextPosition(x, y, cur_dir);
            ans[x][y] = i;
            nextDirection(x, y, cur_dir, n, ans);
            i++;
        }

        return ans;
    }
};
