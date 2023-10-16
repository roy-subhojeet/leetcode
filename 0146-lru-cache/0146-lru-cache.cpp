#include <unordered_map>

class LRUCache
{
public:
    struct ListNode
    {
        ListNode* next;
        ListNode* prev;
        int key;
        int val;
        ListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };

    LRUCache(int capacity)
    {
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    ~LRUCache() {
        while (head) {
            ListNode* next = head->next;
            delete head;
            head = next;
        }
    }

    int get(int key)
    {
        if(mp.find(key) == mp.end()) return -1;
        detachNode(mp[key]);  // Detach but don't delete
        addNode(mp[key]);
        return mp[key]->val;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end())
        {
            detachNode(mp[key]);
            deleteNode(mp[key]);  // Delete after detaching
            mp.erase(key);
        }
        
        ListNode *newNode = new ListNode(key, value);
        addNode(newNode);
        mp[key] = newNode;

        if(mp.size() > capacity)
        {
            ListNode *toRemove = head->next;
            detachNode(toRemove); 
            mp.erase(toRemove->key);
            deleteNode(toRemove);  // Delete after detaching
        }
    }

private:

    int capacity;
    std::unordered_map<int, ListNode*> mp;
    ListNode* head = new ListNode(-1, -1);
    ListNode* tail = new ListNode(-1, -1);

    void addNode(ListNode* node)
    {
        ListNode *last = tail->prev;
        last->next = node;
        node->next = tail;
        node->prev = last;
        tail->prev = node;   
    }

    // Detaches the node from the list but doesn't delete it
    void detachNode(ListNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Deletes the node
    void deleteNode(ListNode* node)
    {
        delete node;
    }
};
