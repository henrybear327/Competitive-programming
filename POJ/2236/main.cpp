#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct UFDS {
    int par[1111];
    void init() {
        for(int i = 0; i < 1111; i++)
            par[i] = -1;
    }

    int root(int x) {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    void merge(int x, int y) {
        x = root(x);
        y = root(y);

        if(x != y) {
            if(par[x] > par[y])
                swap(x, y);
            par[x] += par[y];
            par[y] = x;
        }
    }
};

vector< pair<int, int> > c;

int dist(pair<int, int> x, pair<int, int> y)
{
    int d1 = x.first - y.first;
    int d2 = x.second - y.second;
    return d1 * d1 + d2 * d2;
}

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);

    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        c.push_back(make_pair(x, y));
    }

    UFDS uf;
    uf.init();

    bool fixed[1111] = {false};

    char inp[100];
    int u;
    while(scanf("%s %d", inp, &u) != EOF) {
    	u--;
        if(inp[0] == 'S') {
            int v;
            scanf("%d", &v);
            v--;

            if(uf.root(v) == uf.root(u))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        } else { // O
            fixed[u] = true;
            for(int i = 0; i < n; i++) {
                if(i != u && fixed[i] == true && dist(c[i], c[u]) <= d * d) {
                	// printf("merge %d %d\n", i, u);
                    uf.merge(i, u);
                }
            }
        }
    }

    return 0;
}
