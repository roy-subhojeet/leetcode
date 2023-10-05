#include <vector>
template<typename U, typename V>
class Pair {
public:
    U first;
    V second;

    Pair(U first, V second) : first(first), second(second) {}
};

class Bucket {
private:
    std::vector<Pair<int, int>> bucket;

public:
    Bucket() {}

    int get(int key) {
        for (auto& pair : bucket) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }

    void update(int key, int value) {
        bool found = false;
        for (auto& pair : bucket) {
            if (pair.first == key) {
                pair.second = value;
                found = true;
                break;
            }
        }
        if (!found) {
            bucket.push_back({key, value});
        }
    }

    void remove(int key) {
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                break;
            }
        }
    }
};

class MyHashMap {
private:
    int key_space;
    std::vector<Bucket> hash_table;

public:
    MyHashMap() : key_space(1024), hash_table(key_space) {}

    void put(int key, int value) {
        int hash_key = key % key_space;
        hash_table[hash_key].update(key, value);
    }

    int get(int key) {
        int hash_key = key % key_space;
        return hash_table[hash_key].get(key);
    }

    void remove(int key) {
        int hash_key = key % key_space;
        hash_table[hash_key].remove(key);
    }
};

// Usage:
// MyHashMap obj;
// obj.put(key, value);
// int param_2 = obj.get(key);
// obj.remove(key);
