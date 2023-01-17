#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'larrysArray' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY A as parameter.
 */

// This is a type of invariant problem.
// Let's call the number of inversions is the number of pairs (x, y) where 1 <= x < y <= N
// We will have 2 types of permutation: ABC -> BCA or ABC -> CAB.
// We can see that after any type permutation, the number inversions of A
// can increase 2, increase 0 or decrease 2.
// For example: 4 2 6 -> 2 6 4 or 4 2 6 -> 6 4 2
// inversions.    1.  ->   1        1.  ->   3
// Prove that we can always get the permutation [1, 2, 3, ..., n-2, n-1, n] (Form 1)
// or [1, 2, 3, ..., n-2, n, n-1] (Form 2). Note the reversal of the last two elements.
// Form 1 and Form 2 can be done by using our operation ABC -> BCA (B and C will move to left by one).
// In this way we can move 1 into the first place, 2 into the second place and so on through .
// The sum of the inversions will be 0 when A is in Form 1 or 1 when A is in Form 2.
// So if the original inversions of A is even, A can be fully sorted after a couple of times permutation
// and vice verse.
 
// Time complexity: O(nˆ2)
// Space complexity: O(1)
string larrysArray(vector<int> A) {
    int count = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        for (int j = i + 1; j < A.size(); j++) {
            if (A[i] > A[j]) {
                count += 1;
            }
        }
    }

    return count % 2 == 0 ? "YES" : "NO";
}

// Time complexity: O(n^2)
// Space complexity: O(1)
string larrysArray1(vector<int> A) {
    int n = A.size();
    int i = 0;
    while (i < n-1) {
        int loc = std::find (A.begin(), A.end(), i+1) - A.begin();
        int diff = loc - i;
        if (A[i] == i+1) 
        {
            i++;
            continue;
        }
        if (diff == 1) {
            if (i+2 > n-1) {
                return "NO";
            }
            int tmp = A[i];
            A.erase(A.begin()+i);
            A.insert(A.begin()+loc+1, tmp);
        }
        else if (diff % 2 == 0) {
            int tmp = A[loc];
            A.erase(A.begin()+loc);
            A.insert(A.begin()+i, tmp);
        }
        else if (diff % 2 == 1) {
            if (i+2 > n-1)
            {
                return "NO";
            }
            int tmp = A[loc];
            swap(A[i], A[i+1]);
            A.erase(A.begin()+loc);
            A.insert(A.begin()+i, tmp);
        }
        i++;
    }

    return "YES";
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split(rtrim(A_temp_temp));

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

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
