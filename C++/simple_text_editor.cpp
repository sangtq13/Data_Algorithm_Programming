#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class SimpleText {
public:
    void Append(string t) {
        st.push(s);
        s += t;
    }
    
    void Delete(int k) {
        st.push(s);
        s = s.substr(0, s.size()-k);
    }
    
    void Print(int k) {
        cout << s[k-1] << endl;
    }
    
    void Undo () {
        s = st.top();
        st.pop();
    }

private:
    string s {""};
    stack<string> st;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    SimpleText st;
    int q;
    int cmd;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> cmd;
        if (cmd == 1) {
            string s;
            cin >> s;
            st.Append(s);
        }
        else if (cmd == 2) {
            int k;
            cin >> k;
            st.Delete(k);
        }
        else if (cmd == 3) {
            int k;
            cin >> k;
            st.Print(k);
        }
        else if (cmd == 4) {
            st.Undo();
        }
    }
    return 0;
}
