class LRUCache {
private:

    /* Data Structures, Private member variables */
    struct ListNode
    {
        ListNode * next;
        ListNode * prev;
        int val;
        int key;
        ListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr){}
    };

    ListNode* head = new ListNode(-1, -1);
    ListNode* tail = new ListNode(-1, -1);
    int capacity;
    unordered_map<int, ListNode*> mp;

    /* Methods*/

    void addNode(ListNode *node)
    {
        ListNode *secondLast = tail->prev;
        secondLast->next = node;
        node->next = tail;
        node->prev = secondLast;
        tail->prev = node;
    }

    void removeNode(ListNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        ListNode* current = head;
        while (current) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }
    
    int get(int key) {

        if(mp.find(key) == mp.end()) return -1;
        removeNode(mp[key]);
        addNode(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            removeNode(mp[key]);
            delete mp[key];  // Don't forget to deallocate the memory
        }
        mp[key] = new ListNode(key, value);
        addNode(mp[key]);
        if(mp.size() > capacity)
        {
            ListNode *toDelete = head->next;
            removeNode(toDelete);
            mp.erase(toDelete->key);
            delete toDelete;  // free the memory
        }
    }
};


/* My Sol 14/22 - also correcting it would give TLE

class LRUCache {

private:
unordered_map<int, int> p;
queue<int> st;
int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        if(p.find(key) == p.end()) return -1;
        if(st.front() == key) st.pop();
        st.push(key);
        return p[key];
    }
    
    void put(int key, int value) {
        //cout << p.size() << " "<< capacity<< endl;
        p[key] = value;
        if(p.size() > capacity && !st.empty()) 
        {
            int i = st.front();
            p.erase(i);
            st.pop();
            //return;
        }
        if(st.front() == key) st.pop();
        st.push(key);
        
    }
};
*/
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */