#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Edge {
    ll u, v, w;
};

vector<Edge> inp;
vector<Edge> res;

int n, m;
struct UFDS {   
    int val[10010];
    void init() {
        memset(val, -1, sizeof(val));
    }

    int find(int x) {
        if(val[x] < 0)
            return x;
        return val[x] = find(val[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if(x == y)
            return;

        if(val[x] > val[y])
            swap(x, y);
        val[x] += val[y];
        val[y] = x;
    }
} uf;

bool check(int mid) {
    uf.init();
    res.clear();
    for(const auto &i : inp) {
        if((int)res.size() == n - 1)
            break;

        if(i.w < mid)
            continue;

        if(uf.find(i.u) == uf.find(i.v))
            continue;

        res.push_back(i);
        uf.merge(i.u, i.v);
    }

    return (int)res.size() == n - 1; 
}

vector<ii> g[10010];
bool seen[10010];

void dfs(int u, int mn, ll &ans) {
    if(seen[u])
        return;
    seen[u] = true;

    for(const auto &v: g[u]) {
        if(seen[v.first] == false) {
            ans += min(mn, v.second);
            // printf("%d %d %d\n", u, v.first, min(mn, v.second));
            dfs(v.first, min(mn, v.second), ans);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;

        inp.push_back({u, v, w});
    }

    sort(inp.begin(), inp.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    // vvvxxxxx
    int l = 0, r = 0x3f3f3f3f;
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }

    // l
    // printf("l = %d\n", l);
    check(l);
    for(const auto &i : res) {
        g[i.u].push_back({i.v, i.w});
        g[i.v].push_back({i.u, i.w});
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        memset(seen, false, sizeof(seen));
        dfs(i, INT_MAX, ans); 
    }
    // printf("AC: %lld\n", ans / 2);
    printf("%lld\n", ans / 2);
    
    /*
    ll ans2 = 0;
    ll cnt = n - 1;
    for(const auto &i : res) {
        // printf("%lld %lld %lld\n", i.u, i.v, i.w);
        ans2 += cnt * i.w; 
        cnt--;
    }
    printf("WA: %lld\n", ans2);
    */

	return 0;
}
