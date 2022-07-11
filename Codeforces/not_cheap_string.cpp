#include <bits/stdc++.h>
using namespace std;

// Using count method
// Time complexity: O(n)
// Space complexity: O(k)
string Solution(string s, int num) {
    int count[26] = {0};
    int sum = 0;
    for (auto &c : s) {
        count[c - 'a'] += 1;
        sum += (c - 'a' + 1);
    }

    int i = 25;
    while (sum > num) {
        while (i >= 0) {
            if (count[i] == 0) {
                i--;
            }
            else {
                break;
            }
        }
        sum -= (i+1);
        count[i] -= 1;
    }

    string result = "";
    for (auto &c : s) {
        if (count[c - 'a'] > 0) {
            result += c;
            count [c - 'a'] -= 1;
        }
    }

    return result;
}

// Using priority and hash map method
// Time complexity: O(n)
// Space complexity: O(n)
string Solution1(string s, int num) {
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
