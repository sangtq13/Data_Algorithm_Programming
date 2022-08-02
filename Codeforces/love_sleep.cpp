#include <bits/stdc++.h>
using namespace std;
void Solution(vector<pair<int, int>> test, int h, int m) {
    sort(test.begin(), test.end());
    int n = test.size();
    if ((h >= test[n-1].first && m > test[n-1].second) || h > test[n-1].first) {
        int loan = 0;
        if (m > test[0].second) {
            loan = 1;
        }
        cout << test[0].first + 24 - loan - h << " " << test[0].second + loan * 60 - m << endl;
        return;
    }
    else {
        for (auto p : test) {
            if (p.first >= h && p.second >= m) {
                cout << p.first - h << " " << p.second - m << endl;
                return;
            }
            if (p.first > h) {
                int loan = 0;
                if (m > p.second) {
                    loan = 1;
                }
                cout << p.first - h - loan << " " << p.second + loan * 60 - m << endl;
                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, h, m;
        cin >> n >> h >> m;
        vector<pair<int, int>> test;
        for (int j = 0; j < n; ++j) {
            int hour, minute;
            cin >> hour >> minute;
            pair<int, int> p = {hour, minute};
            test.push_back(p);
        }
        Solution(test, h, m);
    }
    return 0;
}
