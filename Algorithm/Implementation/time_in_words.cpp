#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */
string num_to_strings[21] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
string timeInWords(int h, int m) {
    string connect;
    string prefix;
    string suffix;
    
    if (m == 0) return num_to_strings[h] + " " + "o' clock"; 
    if (m == 30) return string("half past") + " " + num_to_strings[h];
    if (m > 30) {
        connect = "to";
        m = 60 - m;
        h = h + 1;
    }
    else {
        connect = "past";
    }
    prefix = m > 20 ? num_to_strings[20] + " " + num_to_strings[m-20] : num_to_strings[m];
        suffix = num_to_strings[h];
    if (m == 1) {
        return prefix + " " + "minute" + " " + connect + " " + suffix;
    }
    else if (m == 15) {
        return prefix + " " + connect + " " + suffix;
    }
    return prefix + " " + "minutes" + " " + connect + " " + suffix;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
