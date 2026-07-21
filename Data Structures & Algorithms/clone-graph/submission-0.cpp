/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, unordered_map<Node*, Node*> &oldToNew) {
        // If node itself is NULL, return nullptr directly.
        if (node == nullptr) {
            return nullptr;
        }

        // Check if a pair already exists for the current node in the map, if yes, then return that.
        if (oldToNew.count(node) > 0) {
            return oldToNew[node];
        }

        // If it does not exist already in the map, 
        // We create a new copy of that specific node
        // and insert it in the map as a pair with the old node.
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;
        
        // Now, recursively copy each and every neighbor 
        // For the copy node as well and place it exactly the same 
        // As the structure of the original Node.
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor, oldToNew));
        }

        // return a copy of the originally created Node.
        return copy;
    }

    Node* cloneGraph(Node* node) {
        // Create a map to store the old node and the new created copies of each nodes and their neighbors.
        unordered_map<Node*, Node*> oldToNew;

        // Finally, return the output from the function which was just created to
        // recursively handle creating the copies for each and every nodes.
        return dfs(node, oldToNew);
    }
};
