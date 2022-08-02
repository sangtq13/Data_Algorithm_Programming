#include <bits/stdc++.h>
using namespace std;
void Solution(vector<int> test) {
    map<int, int> m;
    int ans = 0;
    for (int i = 0; i < test.size(); ++i) {
        if (m.find(test[i]) != m.end()) {
            for (int j = ans; j < m[test[i]]; ++j) {
                m.erase(test[j]);
            }
            ans = m[test[i]] + 1;
        }
        m[test[i]] = i;
    }

    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> test;
        for (int j = 0; j < n; ++j) {
            int num;
            cin >> num;
            test.push_back(num);
        }
        Solution(test);
    }
    return 0;
}
