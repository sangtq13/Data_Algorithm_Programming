#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
vector<string> html;
vector<string> query;

void solve(string p){
    size_t l = p.find('~');
    string tag = p.substr(0,l);
    string attribute = p.substr(l+1);
    
    if (m.find(tag) == m.end()){
        cout << "Not Found!" << "\n";
        return;
    }
    
    html[m[tag]].erase(remove(html[m[tag]].begin(), html[m[tag]].end(), '>'), html[m[tag]].end());
    istringstream iss(html[m[tag]]);
    vector<string> r((istream_iterator<string>(iss)), istream_iterator<string>());
    if (r.size() == 1){
        cout << "Not Found!" << "\n";
        return;
    }
    bool found = false;
    for (int i=1; i<r.size()-2; ++i){
        if (r[i] == attribute){
            found = true;
            cout << r[i+2].substr(1, r[i+2].size()-2) << "\n";
            return;
        }
    }
    if (!found) cout << "Not Found!" << "\n";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    
    string temp;
    getline(cin, temp);
    for (int i=0; i<n; ++i){
        getline(cin, temp);
        html.push_back(temp);
    }

    for (int i=0; i<q; ++i){
        getline(cin, temp);
        query.push_back(temp);
    }
    
    vector<string> tags;
    for (int i=0; i<html.size(); ++i){
        if (html[i].find('/') != string::npos) tags.pop_back();
        else {
            string tag;
            if (html[i].find(' ') != string::npos){
                tag = html[i].substr(1, html[i].find(' ')-1);
            }
            else{
                tag = html[i].substr(1, html[i].find('>')-1);
            }
            tags.push_back(tag);
            tag.clear();
            for (int i=0; i<tags.size(); ++i) {
                tag += tags[i];
                if (i<tags.size()-1) tag += '.';
            }
            m.insert({tag, i});
        }
    }

    for (int i=0; i<q; ++i){
        solve(query[i]);
    }
    
    return 0;
}

