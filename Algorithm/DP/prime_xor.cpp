#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

const int MOD = 1e9 + 7;
const int MAX_XOR = (1 << 13) - 1;
/*
 * Complete the 'primeXor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
// For range of num: 3500 - 4500
// Time complexity: O(1001 * 8192)
// Space complexity: O(2 * 8192)

int primeXor(vector<int> a) {
    int count[1001] = {0};
    long long dp[2][MAX_XOR+1] = {0};
    bool primes[MAX_XOR+1];
    fill(begin(primes), end(primes), true);
    for(int i = 2; i*i <= MAX_XOR; ++i) {
        if (primes[i]) {
            for (int j = i*i; j <= MAX_XOR; j += i) {
                primes[j] = false;
            }
        }
    }
  
    for (auto num : a) count[num-3500]++;
    dp[0][0] = (count[0] / 2) + 1;
    dp[0][3500] = (count[0] + 1) / 2;
    int flag = 1;
    for (int i = 1; i < 1001; ++i) {
        for (int j = 0; j <= MAX_XOR; ++j) {
            dp[flag][j] = dp[1-flag][j] * (count[i] / 2 + 1) + dp[1-flag][j^(i+3500)] * ((count[i] + 1) / 2);
            dp[flag][j] %= MOD;
        }
        flag = 1 - flag;
    }
    
    long long ans = 0;
    for (int i = 2; i <= MAX_XOR; ++i) {
        if  (primes[i]) {
            ans += dp[1-flag][i];
            ans %= MOD; 
        }
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        int result = primeXor(a);

        fout << result << "\n";
    }

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
