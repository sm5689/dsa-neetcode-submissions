class Node {
    public:
        Node* prev;
        Node* next;
        int key;
        int val;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
};

class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    int capacity_;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity_ = capacity;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }
        Node* found = mpp[key];
        deleteNode(found);
        addAfterHead(found);
        return mpp[key]->val;
    }
    
    void put(int key, int value) {
        Node* newNode = new Node(key, value);
        if (mpp.find(key) == mpp.end()) {
            if (mpp.size() < capacity_) {
                addAfterHead(newNode);
            }
            else {
                mpp.erase(tail->prev->key);
                deleteNode(tail->prev);
                addAfterHead(newNode);
            }
            mpp[key] = newNode;
        }
        else {
            deleteNode(mpp[key]);
            addAfterHead(newNode);
            mpp[key] = newNode;
        }  
    }

    void deleteNode(Node* tbd) {
        tbd->next->prev = tbd->prev;
        tbd->prev->next = tbd->next;
    }

    void addAfterHead(Node* tba) {
        tba->next = head->next;
        head->next->prev = tba;
        head->next = tba;
        tba->prev = head;
    }
};
