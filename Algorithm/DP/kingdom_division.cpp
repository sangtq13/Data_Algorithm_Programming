#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kingdomDivision' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY roads
 */
// G for good condition, B for bad condition
const int MOD = 1e9+7;

// For any node, there are two cases which are helpful to build the solution for its parent:
// (1) the node's subtree is a        good configuration, excluding its parent;
// (2) the node's subtree is a nearly good configuration, it's good when its parent is included, i.e. the direct children of the node all have the same color, which is the opposite of the node (itself is bad, rest is good); when the parent of this node has the same color, the node becomes good, therefore, this nearly good configuration becomes good.
// So we need to save above two numbers for each node.
// Denote G1r to be the number of        good configurations for node 1 when it is red, i.e. (1);
// Denote B1r to be the number of nearly good configurations for node 1 when it is red, i.e. (2);
// Obviouse by symmetry: G1r = G1b, B1r = B1b.
// Let's look at an example, we have 3 nodes: 1, 2, 3, 1 is head and the parent of 2 and 3.
// B1r = G2b * G3b: 1 is red, 2 and 3 are blue, this is by definition from (2)
// What's G1r then? Since for node 2 and 3, each has 4 numbers, let's do first attempt by naive multiplication rule:
// Version 1: G1r = (G2b + G2r + B2r + B2b) * (G3b + G3r + B3r + B3b)
// We realize: given 1 is red, B2b should be removed, because 1 being red doesn't save 2 from being a bad node, so does B3b, which gives:
// Version 2: G1r = (G2b + G2r + B2r) * (G3b + G3r + B3r)
// We then realize: G2b and G3b can not happen at the same time, otherwise 1 is connected to two blue nodes, making 1 a bad node
// Therefore, we have
// Version 3: G1r = (G2b + G2r + B2r) * (G3b + G3r + B3r) - G2b * G3

// Time complexity: O(n)
// Space complexity: O(n)

int kingdomDivision(int n, vector<vector<int>> roads) {
    // G for good condition, B for bad condition
    vector<int> graph[n+1];
    long long G[n+1];
    long long B[n+1];
    for (auto road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    function<void(int, int)> dfs = [&dfs, &graph, &G, &B] (int p, int cur) {
        bool leaf = true;
        for (auto neighbor : graph[cur]) {
            if (neighbor == p) {
                continue;
            }
            else {
                leaf = false;
                dfs(cur, neighbor);   
            }
        }
        if (leaf) {
            G[cur] = 0;
            B[cur] = 1;
            return;
        }
        B[cur] = 1;
        G[cur] = 1;
        
        for (auto neighbor : graph[cur]) {
            if (neighbor == p) continue;
            (B[cur] *= G[neighbor]) %= MOD;
            (G[cur] *= (2 * G[neighbor] + B[neighbor])) %= MOD;
        }
        G[cur] = (G[cur] - B[cur] + MOD) % MOD;
    };
    dfs(0, 1);
    return (2 * G[1]) % MOD;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> roads(n - 1);

    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(2);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int result = kingdomDivision(n, roads);

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
