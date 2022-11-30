#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// Time complexity: O(n)
// Space complexity: O(n)
string encryption(string str) {
    string t;
    string ans;
    for (auto c : str) {
        if (c != ' ') t += c;
    }
    int s = t.size();
    int row = floor(sqrt(s));
    int col = ceil(sqrt(s));
    if (row * col < s) row++;
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            if (j * col + (i+1) <= s) {
                ans += t[j*col+i];
            }
        }
        ans += " ";
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
