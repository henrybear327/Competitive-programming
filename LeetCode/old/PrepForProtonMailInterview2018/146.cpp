// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class LRUCache
{
private:
    int count;
    int capacity; 
public:
    LRUCache(int capacity) 
    {
        list<int> l;
        unordered_map<int, list<int>::iterator> mapping;
        count = capacity = 0;
    }

    int get(int key) 
    {
        if(mapping.find(key) == mapping.end())
            return -1;
        return *mapping[key];
    }

    void put(int key, int value) 
    {
        if(count == capacity) {
            // pop head

            // pushback
        } else {
            // if exist, move to back

            // else, pushback
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
