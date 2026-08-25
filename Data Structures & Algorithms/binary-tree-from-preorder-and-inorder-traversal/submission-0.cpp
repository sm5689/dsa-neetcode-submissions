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
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inor_mpp) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* currRoot = new TreeNode(preorder[preStart]);
        int totalLeft = inor_mpp[preorder[preStart]] - inStart;
        currRoot->left = buildTreeHelper(preorder, preStart+1, preStart+totalLeft, inorder, inStart, inor_mpp[preorder[preStart]]-1, inor_mpp);
        currRoot->right = buildTreeHelper(preorder, preStart+totalLeft+1, preEnd, inorder, inor_mpp[preorder[preStart]]+1, inEnd, inor_mpp);
        return currRoot;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inor_mpp;
        for (int i = 0; i< inorder.size(); i++) {
            inor_mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inor_mpp);
        return root;
    }
};
