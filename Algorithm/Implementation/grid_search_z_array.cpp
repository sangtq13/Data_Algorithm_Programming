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

// Construct Z array of string
// For a string str[0..n-1], Z array is of same length as string. An element Z[i] of Z 
// array stores length of the longest substring starting from str[i] which is also a 
// prefix of str[0..n-1]. The first entry of Z array is meaning less as complete string is // always prefix of itself.
// Example
// str = "aabaacd"
// Z[] = {x, 1, 0, 2, 1, 0, 0}
// str = "abababab"
// Z[] = {x, 0, 6, 0, 4, 0, 2, 0}
void GetZArray(string s, int z_arr[]) {
    int l = 0;
    int r = 0;
    int sz = s.size();
    for (int i = 1; i < sz; ++i) {
        if (i > r) {
            l = i;
            r = i;
            while (r < sz && s[r-l] == s[r]) {
                r++;
            }
            z_arr[i] = r - l;
            r--;
        }
        else {
            int k = i - l;
            if (z_arr[k] < r - i + 1) {
                z_arr[i] = z_arr[k];
            }
            else {
                l = i;
                while (r < sz && s[r-l] == s[r]) {
                    r++;
                }
                z_arr[i] = r - l;
                r--;
            }
        }
    }
}

// This function uses to get index of all matching pattern
vector<int> Search(string s, string p) {
    string str = p + "$" + s;
    int l = str.size();
    int z_arr[l];
    int ps = p.size();
    vector<int> ans;
    GetZArray(str, z_arr);
    for (int i = ps+1; i < l; ++i) {
        if (z_arr[i] == ps){
            ans.push_back(i - ps - 1);    
        }
    }
    return ans;
}

// This solution uses Z algorithm (Linear time pattern searching Algorithm)
// Time complexity: O(rowG * (colG+colP))
// Space complexity: O(colG + colP)
string gridSearch(vector<string> G, vector<string> P) {
    int lp = P.size();
    int lg = G.size();
    int l_pattern = P[0].size();
    int lps[l_pattern];
    
    for (int i = 0; i <= lg - lp; ++i) {
        vector<int> ids = Search(G[i], P[0]);
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
