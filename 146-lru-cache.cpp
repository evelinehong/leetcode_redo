struct node {
    int key;
    int val;
    node *prev = nullptr, *next = nullptr;
    node (int k, int v): key(k), val(v){}
};
class LRUCache {
public:
    int mcapacity;
    unordered_map <int, node*> mymap;
    node *head, *tail;
    LRUCache(int capacity):mcapacity (capacity) {}
    
    int get(int key) {
        if (mymap.find(key) != mymap.end()){
            auto cur = mymap[key];
            if (mcapacity != 1 && head->key != key){
                node *a = cur->prev;
                node *b = cur->next;
                if (cur == tail && a) tail = a;
                if (a) a->next = b;
                if (b) b->prev = a;
                cur->next = head;
                cur->prev = nullptr;
                if (head) head->prev = cur;
                head = cur;
            }            
            return cur->val;
        }
        else {
            return -1;       
        }
    }
    
    void put(int key, int value) {
        node *cur;
        if (get(key) == -1) {                  
            if (mymap.size() == mcapacity) {
                    mymap.erase(tail->key);
                    node *b = tail->prev;
                    if (b) tail = b, b->next = nullptr;
                    else head=tail=nullptr;                
            }
            cur = new node(key, value);
            if (mymap.size() == 0) tail = cur;
            else {
                cur->next = head;   
                head->prev = cur;
            }
            head = cur;
            mymap[key] = cur;
            
        }
        else {
            cur = mymap[key];
            cur->val = value;
        }
        cur->prev = nullptr;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */