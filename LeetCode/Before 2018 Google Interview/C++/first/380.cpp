#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?

class RandomizedSet
{
private:
    unordered_set<int> s;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        s.clear();
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val)
    {
        if (s.count(val) == 1)
            return false;
        s.insert(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val)
    {
        auto it = s.find(val);
        if (it == s.end())
            return false;
        s.erase(it);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int sz = s.size();
        int r = rand() % sz;

        return *next(s.begin(), r);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

#ifdef LOCAL
int main()
{
    return 0;
}
#endif