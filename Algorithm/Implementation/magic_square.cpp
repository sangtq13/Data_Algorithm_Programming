#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */
#define VERTICAL 1
#define HORIZONTAL 2
#define pp pair<int, int>

vector<pp> GetAllPosition(int x9, int y9, int x8, int y8, int relative_pos) {
    vector<pp> ret(10);
    ret[9].first = x9;
    ret[9].second = y9;
    ret[8].first = x8;
    ret[8].second = y8;
    ret[5].first = 1;
    ret[5].second = 1;
    ret[2].first = 2 - x8;
    ret[2].second = 2 - y8;
    if (relative_pos == VERTICAL) {
        ret[1].first = x9;
        ret[1].second = 2 - y9;
        ret[4].first =  x8;
        ret[4].second = 2 - y8;
        ret[3].first = x8;
        ret[3].second = 1;
        ret[6].first = 2 - x8;
        ret[6].second = y8;
        ret[7].first = 2 - x8;
        ret[7].second = 1; 
    }
    else if (relative_pos == HORIZONTAL) {
        ret[1].first = 2 - x9;
        ret[1].second = y9;
        ret[4].first =  2 - x8;
        ret[4].second = y8;
        ret[3].first = 1;
        ret[3].second = y8;
        ret[6].first = x8;
        ret[6].second = 2 - y8;
        ret[7].first = 1;
        ret[7].second = 2 - y8; 
    }
    return ret;
}
 
vector<pp> GetEightPosition (int x9, int y9, int relative_pos) {
    vector<pp> ret;
    if (relative_pos == VERTICAL) {
        ret.push_back({x9-1, 2-y9});
        ret.push_back({x9+1, 2-y9});
    }
    
    if (relative_pos == HORIZONTAL) {
        ret.push_back({2-x9, y9-1});
        ret.push_back({2-x9, y9+1});
    }
    return ret;
}

// Time complexity: O(n)
// Space complexity: O(n)
int formingMagicSquare(vector<vector<int>> s) {
    int min_cost = 1000;
    unordered_map<int, vector<pp>> nine_map;
    nine_map[VERTICAL] = {{1, 0}, {1, 2}};
    nine_map[HORIZONTAL] = {{0, 1}, {2, 1}};
    for (auto p : nine_map) {
        int relative_pos = p.first;
        for (auto nine_pos : p.second) {
            vector<pp> eight_pos = GetEightPosition(nine_pos.first, nine_pos.second, relative_pos);
            for (auto ep : eight_pos) {
                vector<pp> all_pos = GetAllPosition(nine_pos.first, nine_pos.second, ep.first, ep.second, relative_pos);
                int cost = 0;
                for (int i = 1; i < all_pos.size(); ++i) {
                    cost += abs(s[all_pos[i].first][all_pos[i].second] - i);
                }
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
        }
    }
    return min_cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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
