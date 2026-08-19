/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        unordered_map<Node*, Node*> mpp;
        while (curr != nullptr) {
            Node* temp = new Node(curr->val);
            mpp[curr] = temp;
            curr = curr->next;
        }
        curr = mpp[head];
        Node* old = head;
        while (curr != nullptr) {
            curr->next = mpp[old->next];
            curr->random = mpp[old->random];
            curr = curr->next;
            old = old->next;
        }
        return mpp[head];
    }
};
