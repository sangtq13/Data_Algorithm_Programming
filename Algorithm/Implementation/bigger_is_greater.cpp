#include <bits/stdc++.h>

using namespace std;

#define log(x) cout<<"  [ "#x <<" = "<< x << " ]" << endl;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

// Time complexity: O(n)
// Space complexity: O(1)
string biggerIsGreater(string w) {
    int s = w.size();
    int i = s-1;
    
    // Find the longest non-decreasing suffix
    while(i > 0 && w[i] <= w[i-1]) {
        i--;
    }
    if (i == 0) return "no answer";
    
    // Let w[i-1] be the pivot
    // Find rightmost element greater than the pivot
    int j = s-1;
    while(w[i-1] >= w[j]) {
        j--;
    }
  
    // Swap the pivot with j
    swap(w[i-1], w[j]);
  
    // Reverse the suffix
    j = s-1;
    while(i < j) {
        swap(w[i], w[j]);
        i++;
        j--;
    }
    
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

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
