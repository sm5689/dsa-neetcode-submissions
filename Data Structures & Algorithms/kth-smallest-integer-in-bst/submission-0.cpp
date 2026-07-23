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
    void bstArray(TreeNode* root, vector<int>& bstArr) {
        if (root == nullptr) return;
        bstArray(root->left, bstArr);
        bstArr.push_back(root->val);
        bstArray(root->right, bstArr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> bstArr;
        bstArray(root, bstArr);
        int n = bstArr.size();
        return bstArr[k-1];
    }
};
