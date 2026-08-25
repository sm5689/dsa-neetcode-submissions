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
    void rightSideViewHelper(TreeNode* root, int level, vector<int>& rsv) {
        if (root == nullptr) return;
        if (level == rsv.size()) rsv.push_back(root->val);
        rightSideViewHelper(root->right, level+1, rsv);
        rightSideViewHelper(root->left, level+1, rsv);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rsv;
        rightSideViewHelper(root, 0, rsv);
        return rsv;
    }
};
