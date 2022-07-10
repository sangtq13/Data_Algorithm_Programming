#include <bits/stdc++.h>
using namespace std;

void Solution(vector<int> arr, vector<vector<int>> test) {
    map<int, vector<int>> m;
    for (int i = 0; i < arr.size(); ++i) {
        m[arr[i]].push_back(i);
    }
    for (auto &t : test) {
        if (m.find(t[0]) != m.end() && m.find(t[1]) != m.end() && m[t[0]][0] < m[t[1]][m[t[1]].size()-1]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    int size_arr;
    int size_test;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> size_arr;
        cin >> size_test;
        vector<int> arr;
        for (int j = 0; j < size_arr; ++j) {
            cin >> num;
            arr.push_back(num);
        }
        vector<vector<int>> test;
        for (int j = 0; j < size_test; ++j)
        {
            vector<int> tmp;
            cin >> num;
            tmp.push_back(num);
            cin >> num;
            tmp.push_back(num);
            test.push_back(tmp);
        }
        Solution(arr, test);
    }
    return 0;
}
