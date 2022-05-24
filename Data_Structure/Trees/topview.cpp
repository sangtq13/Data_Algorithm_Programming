#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    // Using BFS with labeling node level
    void topView(Node * root) {
        map<int, int> m;
        map<int, int> ret;
        queue<Node*> q;
        q.push(root);
        m[root->data] = 0;
        
        while (!q.empty()) {
            Node *node = q.front();
            if (ret.find(m[node->data]) == ret.end()) ret[m[node->data]] = node->data;
            if (node->left) {
                m[node->left->data] = m[node->data] - 1;
                q.push(node->left);
            }
            if (node->right) {
                m[node->right->data] = m[node->data] + 1;
                q.push(node->right);
            }
            q.pop();
        }
        
        for (auto &s : ret) {
            cout << s.second << " " << s.first << endl;
        }
    }
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}

