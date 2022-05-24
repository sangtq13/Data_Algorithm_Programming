#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int s, num;
    vector<int> v;
    cin >> s;
    for (int i=0; i<s; ++i){
        cin >> num;
        v.push_back(num);
    }
    int q;
    cin >> q;
    for (int i=0; i<q; ++i){
        cin >> num;
        auto low = lower_bound(v.begin(), v.end(), num);
        if (*low == num) cout << "Yes " << low-v.begin()+1 << "\n";
        else cout << "No " << low-v.begin()+1 << "\n";
    }
    return 0;
}

