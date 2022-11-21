#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
 
const int base = 10;
 
class BigInt {
public:
    static vector<int> Multiple(vector<int> a, vector<int> b) {
        int sa = a.size();
        int sb = b.size();
        vector<int> p(sa + sb, 0);
        int carry = 0;
        int start = 0; 
        for (int i = 0; i < sb; ++i) {
            for (int j = 0; j < sa; ++j) {
                int value = p[i+j] + a[j] * b[i] + carry;
                p[i+j] = value % base;
                carry = value / base;
                start = i+j+1;
            }
            while (carry > 0) {
                int value = p[start] + carry;
                p[start] = value % 10;
                carry = value / 10;
                start++;
            }
        }
        return p;
    }
};

// Time complexity: O(n*log(n!))
// Time complexity: O(log(n))
void extraLongFactorials(int n) {
    vector<int> a(1, 1);
    for (int i = 2; i <= n; ++i) {
        vector<int> b;
        int k = i;
        while (k > 0) {
            b.push_back(k%10);
            k /= 10;
        }
        vector<int> tmp = BigInt::Multiple(a, b);
        a.swap(tmp);
    }
    bool check = false;
    for (int i = a.size()-1; i >= 0; --i) {
        if (a[i] != 0) {
            check = true;
        }
        if (check) cout << a[i];
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
