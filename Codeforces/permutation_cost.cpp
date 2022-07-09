#include <bits/stdc++.h>
using namespace std;

void Solution(int n) {
    int d = 2;
    vector<int> ans;
    for (int i = 1; i < n+1; i+=2) {
        ans.push_back(i);
        int j = i;
        while (2*j <= n) {
            ans.push_back(2*j);
            j *= 2;
        } 
    }
    cout << d << endl;
    for (auto a: ans) cout << a << " ";
    cout << endl; 
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        Solution(num);
    }
    return 0;
}
