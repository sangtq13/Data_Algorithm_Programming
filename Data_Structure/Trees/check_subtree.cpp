/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getLength(TreeNode* root) {
        if (!root) return 0;
        return 1 + getLength(root->left) + getLength(root->right);
    }
    
    bool compare(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return true;
        if (!r1 || !r2 || r1->val != r2->val) return false;
        return compare(r1->left, r2->left) && compare(r1->right, r2->right);
    }
    // Time complexity: O(n)
    // Space complexity: O(k)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        int subLen = getLength(subRoot);
        unordered_map<TreeNode*, int> m;
        m[nullptr] = 0;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (true) {
            if (cur) {
                if (cur->right) s.push(cur->right);
                s.push(cur);
                cur = cur->left;
            }
            else {
                if (!s.empty()) {
                    TreeNode* node = s.top();
                    s.pop();
                    if (m.find(node->left) != m.end() && m.find(node->right) != m.end()) {
                        m[node] = 1 + m[node->left] + m[node->right];
                        if (m[node] == subLen && compare(node, subRoot)) return true; 
                    }
                    if (!s.empty() && node->right && s.top() == node->right) {
                        s.pop();
                        cur = node->right;
                        s.push(node);
                    }
                }
                else {
                    break;
                }
            }
        }
        
        return false;
    }
};
