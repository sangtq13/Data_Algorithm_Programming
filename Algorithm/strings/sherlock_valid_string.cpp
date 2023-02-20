#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// Time complexity: O(n)
// Space complexity: O(n)
string isValid(string s) {
    unordered_map<char, int> m;
    for (auto c : s) {
        m[c] += 1;
    }
    
    unordered_map<int, int> m1;
    for (auto n : m) {
        m1[n.second]++;
    }
    if (m1.size() > 2) return "NO";
    if (m1.size() == 2) {
        auto one = m1.begin();
        auto two = next(one);
        if (one->second > 1 && (two->second > 1)) return "NO";
        if (one->second == 1) {
            if (one->first == 1 || one->first - two->first == 1) {
                return "YES";
            }
            else {
                return "NO";
            }
        }
        if (two->second == 1 && two->first - one->first == 1) {
            if (two->first == 1 || two->first - one->first == 1) {
                return "YES";
            }
            else {
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
