#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */
 
// This function uses to the longest prefix which is also a proper suffix
// For the pattern "AAAA", lps[] is [0, 1, 2, 3]
// For the pattern "ABCDE", lps[] is [0, 0, 0, 0, 0]
// For the pattern "AABAACAABAA", lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5
void ComputeLPS(string pattern, int* lps) {
    int s = pattern.size();
    int len = 0;
    int i = 1;
    
    lps[0] = 0;
    
    while (i < s) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> Search(string s, string p, int* lps) {
    vector<int> ans;
    int ls = s.size();
    int lp = p.size();
    
    int i = 0; 
    int j = 0;
    while (i < ls && j < lp) {
        if (s[i] == p[j]) {
            i++;
            j++;
            if (j == lp) {
                ans.push_back(i-j);
                j = lps[j-1];
            }
        }
        else {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }
    return ans;
}

// This solution uses KMP (Knuth Morris Pratt) algorithm for pattern searching
// Time complexity: O(rowG * colG)
// Space complexity: O(colP)
string gridSearch(vector<string> G, vector<string> P) {
    int lp = P.size();
    int lg = G.size();
    int l_pattern = P[0].size();
    int lps[l_pattern];
    
    ComputeLPS(P[0], (int*)(&lps));
    
    for (int i = 0; i <= lg - lp; ++i) {
        vector<int> ids = Search(G[i], P[0], (int*)(&lps));
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
