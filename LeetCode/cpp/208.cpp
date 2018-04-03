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

class Node
{
private:
    Node *next[26];
    bool ending;

public:
    Node()
    {
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
        ending = false;
    }

    Node *go(char c, bool isEnding, int search = 0)
    {
        // search
        // 0, insert
        // 1, whole word search
        // 2, prefix search
        int val = c - 'a';
        Node *res = nullptr;

        if (next[val] == nullptr) {
            if (search != 0) // searching, don't insert
                return nullptr;
            next[val] = new Node();
        }
        res = next[val];

        if (search != 0) { // check ending
            if (search == 1 && isEnding && res->ending == false)
                return nullptr;
        } else { // inserting
            if (isEnding) {
                res->ending = true;
            }
        }

        return res;
    }
};

class Trie
{
private:
    Node *root = nullptr;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto cur = root;
        int len = (int)word.length();
        for (int i = 0; i < len; i++) {
            char c = word[i];
            cur = cur->go(c, (i == len - 1));
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto cur = root;
        int len = (int)word.length();
        for (int i = 0; i < len; i++) {
            char c = word[i];
            cur = cur->go(c, (i == len - 1), 1);

            if (cur == nullptr)
                return false;
        }

        return true;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix)
    {
        auto cur = root;
        int len = (int)prefix.length();
        for (int i = 0; i < len; i++) {
            char c = prefix[i];
            cur = cur->go(c, (i == len - 1), 2);

            if (cur == nullptr)
                return false;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

#ifdef LOCAL
int main()
{
    return 0;
}
#endif