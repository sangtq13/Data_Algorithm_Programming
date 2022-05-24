#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> v;
    int s;
    int num;
    cin >> s;
    for (int i=0; i<s; ++i){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (auto m: v) cout << m << " ";
    return 0;
}

