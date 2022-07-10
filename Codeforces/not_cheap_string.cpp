#include <bits/stdc++.h>
using namespace std;

string Solution(string s, int num) {
    string result = "";
    priority_queue<char> pq;
    unordered_map<char, int> m;
    int sum = 0;
    for (auto &c : s) {
        sum += (c - '`');
        if (m.find(c) == m.end()) {
            m[c] = 1;        
        }
        else {
            m[c] += 1;
        }
        pq.push(c);
    }
    while(sum > num) {
        char top = pq.top();
        m[top] -= 1;
        sum -= (top - '`');
        pq.pop();
    }
    for (auto &c : s) {
        if (m[c] > 0) {
            result += c;
            m[c] -= 1;
        }
    }

    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    string s;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        cin >> num;
        cout << Solution(s, num) << endl;
    }
    return 0;
}
