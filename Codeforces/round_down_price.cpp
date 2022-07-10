#include <bits/stdc++.h>
using namespace std;
long Solution(long num) {
    long p = 1;
    long pre = 1;
    while (p <= num) {
        pre = p;
        p *= 10;
        if (p > num) break; 
    }

    return num - pre;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    long num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        cout << Solution(num) << endl;
    }
    return 0;
}
