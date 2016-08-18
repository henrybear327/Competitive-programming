#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define EPS 1e-9
double dist(ii a, ii b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return sqrt(double(dx * dx + dy * dy));
}

#define N 555
struct UFDS {
    int par[N];
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
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }
} ufds;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int s, p;
        scanf("%d %d", &s, &p);

        vector<ii> inp;
        for (int i = 0; i < p; i++) {
            ii tmp;
            scanf("%d %d", &tmp.first, &tmp.second);

            inp.push_back(tmp);
        }

        // get distance
        vector<pair<double, ii>> pt;
        for (int i = 0; i < (int)inp.size(); i++)
            for (int j = i + 1; j < (int)inp.size(); j++)
                pt.push_back(make_pair(dist(inp[i], inp[j]), ii(i, j)));
        sort(pt.begin(), pt.end());

        // get MST
        ufds.init();
        vector<pair<double, ii>> ans;
        double res = 0;
        int cnt = 0;
        for (int i = 0; i < (int)pt.size(); i++) {
            int u = pt[i].second.first;
            int v = pt[i].second.second;
            double w = pt[i].first;
            if (ufds.root(u) == ufds.root(v))
                continue;

            ufds.merge(u, v);
            res = w;

            cnt++;

            // cnt -> how many edges in MST now
            // S satellites can save S - 1 edges!
            // so: if ( p - 1 (total edges in MST) - cnt = edges left to be connected
            // ) == s - 1 (edges that can be saved)
            // we are done
            if (p - 1 - cnt == s - 1)
                break;
        }
        printf("%.2f\n", res);

        // printf("%.2f\n", ans[p - s - 1].first); // not an obvious conclusion
    }

    return 0;
}
