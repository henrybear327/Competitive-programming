class RandomizedSet
{
private:
    unordered_set<int> s;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val)
    {
        if (s.find(val) != s.end())
            return false;
        s.insert(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val)
    {
        if (s.find(val) != s.end()) {
            s.erase(val);
            return true;
        }

        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        auto i = s.begin();
        advance(i, rand() % s.size());

        return *i;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

class RandomizedSet
{
private:
    unordered_map<int, int> s;
    vector<int> cand;
    int sz = 0;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val)
    {
        if (s.find(val) != s.end())
            return false;

        s[val] = sz;
        if (cand.size() == sz)
            cand.push_back(val), sz++;
        else
            cand[sz++] = val;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val)
    {
        if (s.find(val) != s.end()) {
            s[cand[sz - 1]] = s[val];
            swap(cand[s[val]], cand[sz - 1]);
            sz--;
            s.erase(val);
            return true;
        }

        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int who = rand() % sz;
        return cand[who];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
