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
    Node* cloneGraph(Node* node) {
        
        if (node == nullptr) return nullptr;

        unordered_map<int, Node*> clones;

        queue<Node*> q;

        q.push(node);
        clones[node->val] = new Node(node->val);

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            for (auto neighbor : front->neighbors) {

                if (clones.find(neighbor->val) == clones.end()) {
                    clones[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                clones[front->val]->neighbors.push_back(clones[neighbor->val]);

            }
        }

        return clones[node->val];

    }
};
