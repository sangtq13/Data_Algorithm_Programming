#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts fointowing parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */
 
const int base = 256;
const int mod = 1e9 + 7;

// This solution uses Rabin-Karp Algorithm for Pattern Searching
// Time complexity: O(rowG * colG)
// Space complexity: O(1)
vector<int> Search(string s, string p, int hp, int pow_p)
{
    int lp = p.size();
    int ls = s.size();
    int hs = 0;
    vector<int> ans;
    
    for (int i = 0; i < lp; ++i) {
        hs = (hs * base + s[i]) % mod;
    }
    for (int i = 0; i <= ls - lp; ++i) {
        if (hs == hp) {
            bool check = true;
            for (int j = i; j < i + lp; ++j) {
                if (s[j] != p[j-i]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ans.push_back(i);            
            }
        }
        if (i + lp < ls) {
            hs = ((hs - s[i] * pow_p) * base + s[i+lp]) % mod;
            if (hs < 0) hs += mod;
        }
    }
    
    return ans;
}

string gridSearch(vector<string> G, vector<string> P) {
    int lp = P.size();
    int lg = G.size();
    int l_pattern = P[0].size();
    int pow_p = 1;
    int hp = 0;
    
    for (int i = 0; i < l_pattern-1; ++i) {
        pow_p = (base * pow_p) % mod;
    }
    
    for (int i = 0; i < l_pattern; ++i) {
        hp = (hp * base + P[0][i]) % mod;
    }
    
    for (int i = 0; i <= lg - lp; ++i) {
        vector<int> ids = Search(G[i], P[0], hp, pow_p);
        if (ids.size() > 0) {
            for (auto index : ids) {
                bool check = true;
                for (int j = 1; j < lp; ++j) {
                    if (G[i+j].substr(index, l_pattern) != P[j]) {
                        check = false;
                        break;
                    }
                }
                if (check) return "YES";
            }
        }
    }
    
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int R = stoi(first_multiple_input[0]);

        int C = stoi(first_multiple_input[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int r = stoi(second_multiple_input[0]);

        int c = stoi(second_multiple_input[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

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
