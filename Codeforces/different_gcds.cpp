#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)
void Solution1(int n, int l, int r) {
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int d = l - l % (i+1);
        if (d == l) {
            ans.push_back(d);
        }
        else if (d + i + 1 <= r)
        {
            ans.push_back(d + i + 1);
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto a : ans) cout << a << " ";
    cout << endl;
}

// Time complexity: O(n)
// Space complexity: O(n)
void Solution2(int n, int l, int r) {
    int a[n];
    for (int i = 1; i < n+1; ++i) {
        bool check = false;
        for (int j = l/i + (l%i!=0); j <= r/i; ++j) {
            a[i-1] = i * j;
            check = true;
        }
        if (check == false) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
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
        int n, l, r;
        cin >> n >> l >> r;
        Solution2(n, l, r);
    }
    return 0;
}
