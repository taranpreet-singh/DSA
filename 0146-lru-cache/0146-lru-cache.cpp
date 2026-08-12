class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* curAfterHead = head->next;
        head->next = node;
        node->next = curAfterHead;
        node->prev = head;
        curAfterHead->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;
        Node* node = cache[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            if (cache.size() == capacity) {
                Node* lruNode = tail->prev;
                cache.erase(lruNode->key);
                deleteNode(lruNode);
            }
            Node* node = new Node(key, value);
            insertAfterHead(node);
            cache[key] = node;
        } else {
            Node* node = cache[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */