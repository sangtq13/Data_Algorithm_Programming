#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'fairCut' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */
#define ll long long
const ll max_value = 1e17;

// Time complexity: O(k*n)
// Space complexity: O(k*n)
ll fairCut(ll k, vector<int> arr) {
    int n = arr.size();
    if (k > n-k) k = n - k;
    sort(arr.begin(), arr.end());
    vector<vector<ll>> dp(n+1 , vector<ll> (k+2, max_value));
    dp[0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= min(i, k); ++j) {
            ll to_i, to_j;
            // Put arr[i] to I, it will have (i-j) number less than arr[i] in set J and 
            // (n-k-(i-j)) number greater than arr[i] in set J for future calculation 
            to_i = dp[i][j] + (i-j) * arr[i] - (n-k-(i-j)) * arr[i];
            // Put arr[i] to J, it will have (j) number less than arr[i] in set I and 
            // (k-j)) number greater than arr[i] in set I for future calculation 
            to_j = dp[i][j] + j * arr[i] - (k - j) * arr[i];
            if (dp[i+1][j+1] > to_i) {
                dp[i+1][j+1] = to_i;
            }
            if (dp[i+1][j] > to_j) {
                dp[i+1][j] = to_j;
            }
        }
    }

    return dp[n][k];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    ll k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    ll result = fairCut(k, arr);

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
