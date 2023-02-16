#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

pair<int, int> nextPosition(pair<int, int> curPos, int curDir)
{
    if (curDir == LEFT) {
        return {curPos.first, curPos.second - 1};
    }
    else if (curDir == RIGHT) {
        return {curPos.first, curPos.second + 1};
    }
    else if (curDir == UP) {
        return {curPos.first - 1, curPos.second};
    }
    else {
        return {curPos.first + 1, curPos.second};
    }
}

int nexDirection(int& curDir) {
    if (curDir == LEFT) {
        return DOWN;
    }
    else if (curDir == RIGHT) {
        return UP;
    }
    else if (curDir == UP) {
        return LEFT;
    }
    else {
        return RIGHT;
    }
}

bool validPos(int rows, int cols, pair<int, int> curPos, int currentLevel) {
    if ((currentLevel <= curPos.first && curPos.first < rows - currentLevel)
     && (currentLevel <= curPos.second && curPos.second < cols - currentLevel))
    {
        return true;
    }
    return false;
}

void nextValidPos(int rows, int cols, pair<int, int>& curPos, int& curDir, int currentLevel)
{
    pair<int, int> nextPos = nextPosition(curPos, curDir);
    if (validPos(rows, cols, nextPos, currentLevel)) {
        curPos.first = nextPos.first;
        curPos.second = nextPos.second;
    }
    else {
        curDir = nexDirection(curDir);
        pair<int, int> nextPos = nextPosition(curPos, curDir);
        curPos.first = nextPos.first;
        curPos.second = nextPos.second;
    }
}

void Print(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " \n"[j==cols-1];
        }
    }
}

// Time complexity: O(n)
// Space complexity: O(n)
void matrixRotation(vector<vector<int>> matrix, int r) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> ans(rows , vector<int>(cols, 0));
    
    for (int i = 0; i < min(rows, cols)/2; ++i) {
        int modulo = 2 * (rows + cols - 4 * i) - 4;
        int rotate = r % modulo;

        pair<int, int> startPos = {i, i};
        int startDir = LEFT;
        pair<int, int> rotatePos = {i, i};
        int rotateDir = LEFT;
        for (int j = 0; j < rotate; ++j) {
            nextValidPos(rows, cols, rotatePos, rotateDir, i);
        }
        int tmp = matrix[rotatePos.first][rotatePos.second];
        while (modulo) {
            ans[rotatePos.first][rotatePos.second] = matrix[startPos.first][startPos.second];
            nextValidPos(rows, cols, startPos, startDir, i);
            nextValidPos(rows, cols, rotatePos, rotateDir, i);
            modulo--;
        }
    }
    Print(ans);
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
