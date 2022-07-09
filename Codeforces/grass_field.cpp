#include <bits/stdc++.h>
using namespace std;

int Solution(vector<vector<int>> a) {
    if (a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 0) return 0;
    if (a[0][0] == 1 && a[0][1] == 1 && a[1][0] == 1 && a[1][1] == 1) return 2;
    return 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; ++i) {
        vector<vector<int>> test;
        for (int k = 0; k < 2; ++k) {
            vector<int> tmp;
            for (int j = 0; j < 2; ++j) {
                cin >> num;
                tmp.push_back(num);
            }
            test.push_back(tmp);
        }
        cout << Solution(test) << "\n";
    }
    return 0;
}
