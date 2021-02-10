

// 2021/02/10
class LRUCache {
private:
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        const auto it = m.find(key);
        if (it == m.cend()) return -1;
        
        cache.splice(cache.begin(),cache,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        const auto it = m.find(key);
    
        if (it != m.cend()) {
            
            it->second->second = value;
            
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        
        // Reached the capacity, remove the oldest entry
        if (cache.size() == capacity) {
            const auto& node = cache.back();
            m.erase(node.first);
            cache.pop_back();
        }
        
        cache.emplace_front(key, value);
        m[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
なぜその解法が思い付かなかったのか

(1)
We're asked to implement the structure which provides the following operations in \mathcal{O}(1)O(1) time :
Get the key / Check if the key exists
Put the key
Delete the first added key
The first two operations in \mathcal{O}(1)O(1) time are provided by the standard hashmap, and the last one - by linked list.

これを可能にするデータ構造を知らなかったから

(2)
cppにおけるstd::listを知らなかった（双方向連結リスト）


どういう思考が足りなかったのか
・access to a random key in O(1): hashtable
・remove the last entry in LRU cache in O(1): list
・add/move an entry to the front of LRU cache: list


もし必要とされる思考法が足りていたとしたら解法を思い付けたのか
・無理だったと思う（実装力が足りなかったと思われる９

*/
