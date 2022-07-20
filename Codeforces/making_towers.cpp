#include <bits/stdc++.h>
using namespace std;

// Using hashmap method
// Time complexity: O(n)
// Space complexity: O(n)
void Solution1(vector<int> test, int n) {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        m[test[i]].push_back(i);
    }
    unordered_map<int, int> max_height_colors;
    for (auto x : m) {
        int height[2] = {0};
        for (int i = 0; i < x.second.size(); ++i) {
            int j = x.second[i] % 2;
            height[j] = max(height[j], height[1-j]+1);
        }
        max_height_colors[x.first] = max(height[0], height[1]);
    }
    for (int i = 1; i < n+1; ++i) {
        if (max_height_colors.find(i) != max_height_colors.end()) {
            cout << max_height_colors[i] << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
    cout << endl;
}

// Using dp 
// Time complexity: O(n)
// Space complexity: O(n)
void Solution2(vector<int> test, int n) {
    int dp[n][2] = {0};
    for (int i = 0; i < n; ++i) {
        int j = i % 2;
        int x = test[i] - 1;
        dp[x][j] = max(dp[x][j], dp[x][1-j] + 1);
    }
    for (int i = 0; i < n; ++i) {
        cout << max(dp[i][0], dp[i][1]) << " ";
    }
    cout << endl;
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
        Solution2(test, n);
    }
    return 0;
}
