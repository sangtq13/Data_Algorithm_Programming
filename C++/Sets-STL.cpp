#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int> s;
    int l;
    int type, num;
    cin >> l;
    for (int i=0; i<l; ++i){
        cin >> type >> num;
        if (type == 3){
            if (s.find(num) != s.end()) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
        else if (type == 2){
            s.erase(num);
        }
        else {
            s.insert(num);
        }    
    }
    return 0;
}




