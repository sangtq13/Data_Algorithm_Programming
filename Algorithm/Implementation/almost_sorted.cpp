#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
// void 
/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

#define log(x) cout<<"  [ "#x<<" = "<<x<<" ]"<<endl;

// Time complexity: O(nlogn)
// Space complexity: O(n)
void almostSorted(vector<int> arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    int count = 0;
    int s = arr.size();
    int start = -1;
    int end = -1;
    for (int j = s-1; j > 0; --j) {
        if (arr[j] != sorted[j]){
            count++;
            end = j;
            break;
        }
    }
    
    for (int i = 0; i < end; ++i) {
        if (arr[i] != sorted[i]) {
            count++;
            if (start == -1) {
                start = i;
            }
        }
    }
  
    if (count == 0) {
        cout << "yes" << endl;
        return;
    }
    if (count == 2) {
        cout << "yes" << endl;
        cout << "swap " << start+1 << " " << end+1 << endl;
        return;
    }
    
    for (int i = start; i <= (start+end)/2; ++i) {
        if (arr[i] != sorted[end-(i-start)]){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    cout << "reverse " << start+1 << " " << end+1 << endl; 
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
