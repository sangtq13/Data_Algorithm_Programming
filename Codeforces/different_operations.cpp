#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
void Solution(vector<int> test) {
    if (test[0] == 0) {
        for (auto t : test) {
            if (t != 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    else {
        for (auto t : test) {
            if (t % test[0] != 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> test;
        int s;
        cin >> s;
        for (int j = 0; j < s; ++j) {
            int num;
            cin >> num;
            test.push_back(num);
        }
        Solution(test);
    }
    return 0;
}
