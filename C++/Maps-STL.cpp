#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, int> m;
    int s;
    int type, num;
    string name;
    cin >> s;
    for (int i=0; i<s; ++i){
        cin >> type >> name;;
        if (type == 3){
            
            if (m.find(name) != m.end()) cout << m[name] << "\n";
            else cout << 0 << "\n";
        } 
        else if (type == 2){
            m.erase(name);
        }
        else if (type == 1){
            cin >> num;
            if (m.find(name) != m.end()) m[name] += num;
            else m.insert({name, num});
        }
    }
    
    return 0;
}




