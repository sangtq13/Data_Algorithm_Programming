#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Time complexity: O(n^2)
// Space complexity: O(n)
void solve(vector<int>& a, vector<int>& b, int &base) {
    int n = b.size();
    vector<int> bb(2*n, 0);
    
    // Get b*b
    for (int i = 0; i < n; ++i) {
        int carry = 0;
        int pos = i;
        for (int j = 0; j < n; ++j) {
            int value = b[i] * b[j] + bb[pos] + carry;
            bb[pos] = value % base;
            carry = value / base;
            pos++;
        }
        while (carry > 0) {
            int value = carry + bb[pos];
            bb[pos] = value % base;
            carry = value / base;
            pos++;
        }
    }
    // Add a to b*b
    int carry = 0;
    for (int i = 0; i < a.size(); ++i) {
        int value = a[i] + bb[i] + carry;
        bb[i] = value % base;
        carry = value / base;
    }
    for (int i = a.size(); i < b.size() && carry > 0; ++i) {
        int value = bb[i] + carry;
        bb[i] = value % base;
        carry = value / base;
    }
    if (bb.back() == 0) bb.pop_back();
    a = b;
    b = bb;
}

string fibonacciModified(int t1, int t2, int n) {
    vector<int> a;
    vector<int> b;
    int base = 1e4;
    string result = "";
    if (t1 == 0) {
        a.push_back(0);
    }
    else {
        while (t1 > 0) {
            a.push_back(t1 % base);
                t1 /= base;
        }
    }
    if (t2 == 0) {
        b.push_back(0);
    }
    else {
        while (t2 > 0) {
            b.push_back(t2 % base);
            t2 /= base;
        }
    }
    for (int i = 3; i <= n; ++i) {
        solve(a, b, base);
    }
    int sb = b.size();
    result += to_string(b[sb-1]);
    for (int i = sb-2; i >= 0; --i) {
        if (b[i] < 10) {
            result += "000";
        }
        else if (b[i] < 100) {
            result += "00";
        }
        else if (b[i] < 1000) {
            result += "0";
        }
        result += to_string(b[i]);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int t1 = stoi(first_multiple_input[0]);

    int t2 = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    string result = fibonacciModified(t1, t2, n);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
