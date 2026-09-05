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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root ==nullptr) return "#";
        string curr = to_string(root->val);
        string left = serialize(root->left);
        string right = serialize(root->right);
        return curr+","+left+","+right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialized(stringstream& s) {
        string token;
        getline(s, token, ',');
        if (token == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserialized(s);
        node->right = deserialized(s);
        return node;
    }
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return nullptr;
        stringstream s(data);
        return deserialized(s);
    }
};
