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

struct UFDS {
    int *par, n;
    void init(int _n)
    {
        n = _n;
        par = new int[n];
        for (int i = 0; i < n; i++)
            par[i] = -1;
    }
    int root(int x)
    {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }
    void merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;
        if (par[x] < par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }
} uf;

// handle special cases first
// [], "", ...
// range of input?
class Solution
{
public:
    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2,
                                vector<pair<string, string>> pairs)
    {
        if (words1.size() != words2.size())
            return false;

        unordered_map<string, int> mapping;

        // string to idx
        int idx = 0;
        for (auto i : pairs) {
            if (mapping.count(i.first) == 0)
                mapping[i.first] = idx++;
            if (mapping.count(i.second) == 0)
                mapping[i.second] = idx++;
        }

        // cal trnasitivity
        uf.init(mapping.size());
        for (auto i : pairs) {
            uf.merge(mapping[i.first], mapping[i.second]);
        }

        for (int i = 0; i < (int)words1.size(); i++) {
            if (words1[i] == words2[i])
                continue;

            if (mapping.count(words1[i]) == 0)
                return false;
            if (mapping.count(words2[i]) == 0)
                return false;

            int id1 = mapping[words1[i]];
            int id2 = mapping[words2[i]];
            if (uf.root(id1) != uf.root(id2))
                return false;
        }

        return true;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
