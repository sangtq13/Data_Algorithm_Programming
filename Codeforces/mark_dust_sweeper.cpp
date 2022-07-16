#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
void Solution(vector<int> test) {
    int start = 0;
    bool check = false;
    long long count = 0;
    long long sum = 0;
    int n = test.size();
    for (int i = 0; i < n; ++i) {
        sum += test[i];
        if (test[i] > 0 && !check) {
            start = i;
            check = true;
        }
        if (test[i] == 0 && check) {
            test[i]++;
            test[start]--;
            count++;
            if (test[start] == 0) start++;
        }
    }
    cout << count + sum - test[n-1] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        vector<int> test;
        for (int j = 0; j < s; ++j) {
            int num;
            cin >> num;
            test.push_back(num);
        }
        Solution(test);
    }
    return 0;
}
