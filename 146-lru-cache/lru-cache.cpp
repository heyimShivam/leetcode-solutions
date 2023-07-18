struct Node{
    int key;
    int val;
    Node* next = NULL;
    Node* prev = NULL;
    Node(int _key, int value){
        key = _key;
        val = value;
    }
};

class LRUCache {
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*>mp;
    int cap;
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    void deleteNode(int key){
        Node* node = mp[key];
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        mp.erase(key);
    }

    void insert(int key, int value){
        Node* temp = head->next;
        Node* newNode = new Node(key, value);
        head->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
        mp[key] = newNode;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            int value = mp[key]->val;
            deleteNode(key);
            insert(key,value);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(key);
        }

        if(mp.size() >= cap){
            deleteNode(tail->prev->key);
        }

        insert(key, value);
    }
};