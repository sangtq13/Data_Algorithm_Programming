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
    // Time complexity: O(n)
    // Space complexity: O(logn) to O(n) in worst case  
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int height = -1;
        priority_queue<long long> pq;
        
        while(!q.empty()) {
            pair<TreeNode*, int> node = q.front();
            q.pop();
            if (node.second > height && height != -1){
                pq.push(sum);
                sum = 0;
            }
            sum += node.first->val;
            height = node.second;
            if (node.first->left) {
                q.push({node.first->left, node.second + 1});
            }
            if (node.first->right) {
                q.push({node.first->right, node.second + 1});
            }
        }
        
        if (sum > 0) pq.push(sum);
        
        long long max_k = -1;
        if (height >= k-1) {
            while (k > 1) {
                pq.pop();
                --k;
            }
            max_k = pq.top();
        }
        
        return max_k;
    }
};
