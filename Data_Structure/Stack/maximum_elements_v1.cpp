#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> getMax(vector<string> operations) {
    vector<int> ret;
    stack<int> s;
    map<int, int> m;
    for (auto &o : operations) {
        string t = o.substr(0, 1);
        if (t == "1") {
            int num = stoi(o.substr(2));
            s.push(num);
            if (m.find(num) == m.end()) {
                m[num] = 1;
            }
            else {
                m[num] += 1;
            }
        }
        if (t == "2") {
            int num = s.top();
            m[num] = m[num] - 1;
            if (m[num] == 0) {
                m.erase(num);
            }
            s.pop();
        }
        if (t == "3") {
            ret.push_back(m.rbegin()->first);
        }
        
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

