#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */
// Time complexity: O(m*n)
// Space complexity: O(m*n)
string abbreviation(string a, string b) {
    int m = a.size();
    int n = b.size();
    bool dp[n][m] = {false};
    int upper = 0;
    
    for (int i = 0; i < m; ++i) {
        if (islower(a[i])) {
            if (toupper(a[i]) == b[0] && upper == 0) {
                dp[0][i] = true;
            }
            else {
                dp[0][i] = dp[0][i-1];
            }
        }
        else {
            if (a[i] == b[0] && upper == 0) {
                dp[0][i] = true;
            }
            upper++;
        }
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (islower(a[j])) {
                if (toupper(a[j]) == b[i]) {
                    dp[i][j] = dp[i-1][j-1] | dp[i][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
            else {
                if (a[j] != b[i]) {
                    dp[i][j] = false;
                }
                else {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
    }
    if (dp[n-1][m-1]) return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

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
