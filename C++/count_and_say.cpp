class Solution {
public:
    string countSay(string n) {
        vector<pair<char, int>> v;
        v.push_back({n[0], 1});
        string ret;
        for (int i = 1; i < n.size(); ++i) {
            if (n[i] == n[i-1]) {
                v.back().second++;
            }
            else {
                v.push_back({n[i], 1});
            }
        }
        for (auto p : v) {
            string t = to_string(p.second) + p.first;
            ret += t;
        }
        
        return ret;
    }
    
    string countAndSay(int n) {
        string s = "1";
        while (n > 1) {
            string t = countSay(s);
            s = t;
            n--;
        }
        return s;
    }
};
