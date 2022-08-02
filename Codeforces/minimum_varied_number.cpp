#include <bits/stdc++.h>
using namespace std;
void Solution(int n) {
    int i = 9;
    int ans = 0;
    int p = 1;
    while (i >= 1 && n >= i) {
        ans += i * p;
        p *= 10;
        n -= i;
        i--;
    }
    if (n > 0) ans += n * p;
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
        Solution(n);
    }
    return 0;
}
