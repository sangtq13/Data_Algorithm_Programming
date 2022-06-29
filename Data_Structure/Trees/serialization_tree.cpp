/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    vector<string> split(string s, string demiliter) {
        int start_pos = 0;
        int end_pos = 0;
        int ld = demiliter.size();
        vector<string> ret;
        while ((end_pos = s.find(demiliter, start_pos)) != string::npos) {
            ret.push_back(s.substr(start_pos, end_pos-start_pos));
            start_pos = end_pos + ld;
        }
        ret.push_back (s.substr(start_pos));
        
        return ret;
    }
    string serialize(TreeNode* root) {
        if (root == nullptr) return "*";
        
        return to_string(root->val) + "." + serialize(root->left) + "." + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> list = split(data, ".");
        if (list[0] == "*") return nullptr;
        TreeNode* root = new TreeNode(stoi(list[0]));
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int i = 1;
        while (true) {
            if (cur) {
                s.push(cur);
                if (list[i] != "*") {
                    cur->left = new TreeNode(stoi(list[i]));
                }
                cur = cur->left;
                
            }
            else {
                if (!s.empty()) {
                    TreeNode* node = s.top();
                    s.pop();
                    if (list[i] != "*") {
                        node->right = new TreeNode(stoi(list[i]));
                        cur = node->right;
                    }
                }
                else {
                    break;
                }
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
