struct Node {
    int key;
    int value;
    
    Node *prev =NULL;
    Node *next =NULL;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
    }
};

class LRUCache {
public:
    int cap = 0;
    unordered_map<int, Node*> mp;

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(int key) {
        Node *del = mp[key];
        Node* prevNode = del->prev;
        Node* nextNode = del->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        mp.erase(key);
        delete del;
    }

    void insert(int key, int value) {
       Node *newNode = new Node(key, value);
       
       newNode->next = head->next;
       head->next = newNode;
       newNode->prev = head;
       newNode->next->prev = newNode;
       mp[key] = newNode;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()) {
            int value = mp[key]->value;

            deleteNode(key);
            insert(key,value);
            
            return value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            deleteNode(key);
        }

        if(mp.size() >= cap) {
            deleteNode(tail->prev->key);
        }

        insert(key, value);
    }
};
