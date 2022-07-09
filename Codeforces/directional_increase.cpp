#include <bits/stdc++.h>
using namespace std;

bool Solution(vector<int> a) {
    long long sum = 0;
    int s = a.size();
    for (auto& m : a) {
        sum += m;
    }
    if (sum != 0) return false;
    vector<long long> plus;
    plus.push_back(a[0]);
    for (int i = 1; i < s; ++i) {
        plus.push_back(plus[i-1] + a[i]);
    };
    
    bool check_zero = false;
    for (int i = 0; i < s; ++i) {
        if (plus[i] < 0) {
            return false;
        }
        if (check_zero && plus[i] != 0) {
            return false;
        }
        if (plus[i] == 0) check_zero = true;
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        vector<int> test;
        int num;
        for (int j = 0; j < size; ++j) {
            cin >> num;
            test.push_back(num);
        }
        if (Solution(test)) {
            std::cout << "Yes" << std::endl;
        }
        else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
