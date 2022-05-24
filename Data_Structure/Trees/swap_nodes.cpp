#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */
struct Node {
    Node(int lv, int dt) : level(lv), data(dt), left(nullptr), right(nullptr) {}
    int level;
    int data;
    Node* left;
    Node* right;
};
int max_number = 1;

void create_tree(Node* root, Node* left, Node* right) {
    queue<Node*> q;
    q.push(root);
    int count = 0;
    
    while (!q.empty()) {
        Node* n = q.front();
        if (count == max_number-1) {
            n->left = left;
            n->right = right;
            if (n->left) n->left->level = n->level + 1;
            if (n->right) n->right->level = n->level + 1;
            max_number++;
            break;
        }
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
        q.pop();
        count++;
    }
}

void inorder_traversal(Node *root, vector<int>& res) {
    if (root == nullptr) return;
    if (root->left) {
        inorder_traversal(root->left, res);
    }
    cout << root->data << " ";
    res.push_back(root->data);
    if (root->right) {
        inorder_traversal(root->right, res);
    }
}

void swap(Node* root, int level) {
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* n = q.front();
        if (n->level % level == 0) {
            Node* tmp = n->left;
            n->left = n->right;
            n->right = tmp;
        }
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
        q.pop();
    }
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> ret;
    Node* root = new Node(1, 1);
    
    for (int i=0; i<indexes.size(); ++i) {
        Node* left = nullptr;
        Node* right = nullptr;
        if (indexes[i][0] != -1) {
            left = new Node(INFINITY, indexes[i][0]);
        }
        if (indexes[i][1] != -1) {
            right = new Node(INFINITY, indexes[i][1]);
        }
        create_tree(root, left, right);
    }
    
    for (auto &q : queries) {
        swap(root, q);
        vector<int> res;
        inorder_traversal(root, res);
        ret.push_back(res);
        cout << "\n";
    }
    
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

