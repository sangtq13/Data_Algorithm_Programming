#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER rq
 *  4. INTEGER cq
 *  5. 2D_INTEGER_ARRAY obstacles
 */
#define DIAGONAL_UP 1
#define HORIZONTAL 2
#define DIAGONAL_DOWN 3
#define VERTICAL 4
using pp = pair<int, int>;

// Time complexity: O(n)
// Space complexity: O(1)
int queensAttack(int n, int k, int rq, int cq, vector<vector<int>> obstacles) {
    int ans = 0;
    unordered_map<int, pp[2]> m;
    int m1 = min(rq, cq);
    int m2 = min(n-rq, n-cq)+1;
    int m3 = min(n-rq, cq-1)+1;
    int m4 = min(rq-1, n-cq)+1;
    m[DIAGONAL_UP][0] = {rq-m1, cq-m1};
    m[DIAGONAL_UP][1] = {rq+m2, cq+m2};
    m[HORIZONTAL][0] = {rq, 0};
    m[HORIZONTAL][1] = {rq, n+1};
    m[DIAGONAL_DOWN][0] = {rq+m3, cq-m3};
    m[DIAGONAL_DOWN][1] = {rq-m4, cq+m4};
    m[VERTICAL][0] = {0, cq};
    m[VERTICAL][1] = {n+1, cq};
    
    for (auto ob : obstacles) {
        int diff_r = ob[0] - rq;
        int diff_c = ob[1] - cq;
        if (diff_r < 0 && diff_c < 0 && diff_r == diff_c) {
            if(ob[0] > m[DIAGONAL_UP][0].first) {
                m[DIAGONAL_UP][0].first = ob[0];
                m[DIAGONAL_UP][0].second = ob[1];
            }
        }
        
        if (diff_r > 0 && diff_c > 0 && diff_r == diff_c) {
            if(ob[0] < m[DIAGONAL_UP][1].first) {
                m[DIAGONAL_UP][1].first = ob[0];
                m[DIAGONAL_UP][1].second = ob[1];
            }
        }
        
        if (diff_r == 0 && diff_c < 0) {
            if (ob[1] > m[HORIZONTAL][0].second) {
                m[HORIZONTAL][0].second = ob[1];
            }
        }
        
        if (diff_r == 0 && diff_c > 0) {
            if (ob[1] < m[HORIZONTAL][1].second) {
                m[HORIZONTAL][1].second = ob[1];
            }
        }
        
        if (diff_r > 0 && diff_c < 0 && diff_r == -diff_c) {
            if(ob[0] < m[DIAGONAL_DOWN][0].first) {
                m[DIAGONAL_DOWN][0].first = ob[0];
                m[DIAGONAL_DOWN][0].second = ob[1];
            }
        }
        
        if (diff_r < 0 && diff_c > 0 && diff_r == -diff_c) {
            if(ob[0] > m[DIAGONAL_DOWN][1].first) {
                m[DIAGONAL_DOWN][1].first = ob[0];
                m[DIAGONAL_DOWN][1].second = ob[1];
            }
        }
        
        if (diff_r < 0 && diff_c == 0) {
            if (ob[0] > m[VERTICAL][0].first) {
                m[VERTICAL][0].first = ob[0];
            }
        }
        
        if (diff_r > 0 && diff_c == 0) {
            if (ob[0] < m[VERTICAL][1].first) {
                m[VERTICAL][1].first = ob[0];
            }
        }
    }
    ans += (m[DIAGONAL_UP][1].first - m[DIAGONAL_UP][0].first) - 2;
    ans += (m[HORIZONTAL][1].second - m[HORIZONTAL][0].second) - 2;
    ans += (m[DIAGONAL_DOWN][0].first - m[DIAGONAL_DOWN][1].first) - 2;
    ans += (m[VERTICAL][1].first - m[VERTICAL][0].first) - 2;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

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
