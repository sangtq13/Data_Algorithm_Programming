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
    int x, a, b;
    cin >> x >> a >> b;
    int start = min(a,b);
    int end = max(a,b);
    v.erase(v.begin()+x-1);
    v.erase(v.begin()+start-1, v.begin()+end-1);
    
    cout << v.size() << "\n";
    for(auto m: v) cout << m << " ";
    
    return 0;
}

