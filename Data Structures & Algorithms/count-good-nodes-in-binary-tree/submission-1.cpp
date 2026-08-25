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
    void goodNodesHelper(TreeNode* root, int maxi, int& count) {
        if (root== nullptr) return;
        if (root->val >= maxi) count++;
        goodNodesHelper(root->left, max(maxi, root->val), count);
        goodNodesHelper(root->right, max(maxi, root->val), count);  
    }
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        goodNodesHelper(root, -1e8, count);
        return count;
    }
};
