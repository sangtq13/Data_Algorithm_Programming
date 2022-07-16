#include <bits/stdc++.h>
using namespace std;

// Using sorting method
// Time complexity: O(n)
// Space complexity: O(logn) to O(n) depends on sort on C++
void Solution1(vector<int> test, int x) {
    int n = test.size() / 2;
    sort(test.begin(), test.end());
    for (int i = 0; i < n; ++i) {
        if (test[i + n] - test[i] < x) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

// Using priority queue method
// Time complexity: O(n)
// Space complexity: O(n)
void Solution2(vector<int> test, int x) {
    int n = test.size() / 2;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto t : test) {
        pq.push(t);
    }
    int tmp[n];
    int i = 0;
    while (i < 2*n) {
        int top = pq.top();
        if (i < n) {
            tmp[i] = top;
        }
        else {
            if (top - tmp[i%n] < x) {
                cout << "NO" << endl;
                return;
            }
        }
        pq.pop();
        i++;
    }
    cout << "YES" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, x;
        cin >> n >> x;
        vector<int> test;
        for (int j = 0; j < 2 * n; ++j) {
            int num;
            cin >> num;
            test.push_back(num);
        }
        //Solution1(test, x);
        Solution2(test, x);
    }
    return 0;
}
