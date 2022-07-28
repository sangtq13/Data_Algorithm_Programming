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
    typedef std::pair<TreeNode*, string> pp;
    
    // Time complexity: O(n)
    // Space complexity: O(n)
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        unordered_map<TreeNode*, pp> parent;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (true) {
            if (cur) {
                if (cur->right) {
                    s.push(cur->right);
                    if (parent.find(cur->right) == parent.end()) {
                        parent[cur->right] = {cur, "right"};    
                    }
                }
                s.push(cur);
                if (pre && parent.find(cur) == parent.end()) {
                    parent[cur] = {pre, "left"};
                }
                pre = cur;
                cur = cur->left;
            }
            else {
                if (!s.empty()) {
                    TreeNode* node = s.top();
                    s.pop();
                    if (!s.empty() && node->right &&node->right == s.top()) {
                        s.pop();
                        cur = node->right;
                        s.push(node);
                    }
                    else {
                        if (node->val == target && !node->left && !node->right) {
                            if (node == root) {
                                return nullptr;
                            }
                            if (parent[node].second == "left") {
                                parent[node].first->left = nullptr;
                            }
                            if (parent[node].second == "right") {
                                parent[node].first->right = nullptr;
                            }
                        }
                    }
                }
                else {
                    break;
                }
            }
        }
        return root;
    }
};
