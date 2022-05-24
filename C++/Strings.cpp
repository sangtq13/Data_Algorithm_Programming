#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    
    int sa = a.size();
    int sb = b.size();
    cout << sa << " " << sb << "\n";
    cout << a+b << "\n";
    char c = *(a.begin());
    *(a.begin()) = *(b.begin());
    *(b.begin()) = c;

    cout << a << " " << b << "\n";

    return 0;
}
