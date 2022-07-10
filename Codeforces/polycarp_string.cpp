#include <bits/stdc++.h>
using namespace std;

int Solution(string s) {
    int days = 0;
    map<char, bool> m;
    for (auto &c : s) {
        if (m.size() < 3) {
            m[c] = true;
        }
        else {
            if (m.find(c) == m.end()) {
                m.clear();
                m[c] = true;
                days += 1;
            }
        }
    }
   
    return days + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        cout << Solution(s) << endl;
    }
    return 0;
}
