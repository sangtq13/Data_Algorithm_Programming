#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */
 
void changeState(vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<pair<int, int>> coords = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    unordered_map<int, bool> m;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'O') {
                grid[i][j] = '.';
                for (auto c : coords) {
                    int x = i + c.first;
                    int y = j + c.second;
                    if (0 <= x && x < rows && 0 <= y 
                    && y < cols && (grid[x][y] != 'O' 
                    || (grid[x][y] == 'O' && m.find(x*cols+y) != m.end()))) {
                        grid[x][y] = '.';
                        m[x*cols+y] = true;
                    }
                }
            }
            else {
                if (m.find(i*cols+j) == m.end()) {
                    grid[i][j] = 'O';
                    m[i*cols+j] = true;
                }
            }           
        }
    }
}

// Time complexity: O(rows * cols)
// Space complexity: O(1)
vector<string> bomberMan(int n, vector<string> grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    if (n % 2 == 0) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '.') {
                    grid[i][j] = 'O';
                }
            }
        }
        return grid;
    }
    if (n == 1) return grid;
    changeState(grid);
    if (n % 4 > 1) return grid;
    changeState(grid);
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
