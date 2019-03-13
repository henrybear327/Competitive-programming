class LRUCache
{
private:
    int sz;
    unordered_map<int, list<pair<int, int>>::iterator> mapping;
    list<pair<int, int>> q;

public:
    LRUCache(int capacity)
    {
        sz = capacity;
    }

    int get(int key)
    {
        // cout << "get " << key << endl;
        if (mapping.find(key) != mapping.end()) {
            auto it = mapping[key];
            int value = it->second;
            mapping.erase(it->first);
            q.erase(it);
            q.push_back(pair<int, int> {key, value});
            mapping[key] = prev(q.end());

            return mapping[key]->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // cout << "key " << key << " value " << value << endl;

        auto newData = pair<int, int> {key, value};
        if (mapping.find(key) != mapping.end()) {
            auto del = mapping[key];
            mapping.erase(del->first);
            q.erase(del);
        }

        if (sz == q.size()) {
            list<pair<int, int>>::iterator kick = q.begin();
            mapping.erase(kick->first);
            q.pop_front();
        }

        q.push_back(newData);
        mapping[key] = prev(q.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
