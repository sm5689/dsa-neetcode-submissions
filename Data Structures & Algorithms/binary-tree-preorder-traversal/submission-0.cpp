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
    void traverse(TreeNode* root, vector<int>& values) {
        if (root == nullptr) return;
        values.push_back(root->val);
        traverse(root->left, values);
        traverse(root->right, values);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        traverse(root, values);
        return values;
    }
};