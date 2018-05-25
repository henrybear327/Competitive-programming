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

struct UFDS {
    int par[2222];
    void init()
    {
        memset(par, -1, sizeof(par));
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

        if (par[x] > par[y])
            swap(par[x], par[y]);

        par[x] += par[y];
        par[y] = x;
    }
} uf;

class Solution
{
public:
    int numSimilarGroups(vector<string> &A)
    {
        uf.init();
        int n = A.size();
        map<string, int> has;
        for (int i = 0; i < n; i++)
            has[A[i]] = i;

        for (int i = 0; i < n; i++) {
            int len = A[i].length();
            for (int j = 0; j < len; j++)
                for (int k = j + 1; k < len; k++) {
                    swap(A[i][j], A[i][k]);
                    if (has.count(A[i]) > 0) {
                        uf.merge(i, has[A[i]]);
                    }
                    swap(A[i][j], A[i][k]);
                }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (uf.root(i) == i)
                cnt++;
        }

        return cnt;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif