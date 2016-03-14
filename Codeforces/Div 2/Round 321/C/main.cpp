#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int n, m, ans;
bool cat[100010];
vector<int> g[100010];
vector<bool> v(100010, false); // visited
vector<int> c(100010, 0);      // cat count

void dfs(int curr)
{
    v[curr] = true;

    // calculate cat
    for (int i = 0; i < (int)g[curr].size(); i++) {
        if (v[g[curr][i]] == false) {
            if (cat[curr]) {
                if (cat[g[curr][i]])
                    c[g[curr][i]] = c[curr] + 1;
                else
                    c[g[curr][i]] = 0;
            } else {
                if (cat[g[curr][i]])
                    c[g[curr][i]] = 1;
                else
                    c[g[curr][i]] = 0;
            }
        }
    }

    //early termination
    if(c[curr] > m)
	return;

    // leaf
    if (g[curr].size() == 1 && curr != 1) {
        if (c[curr] <= m)
            ans++;
        return;
    }

    for (int i = 0; i < (int)g[curr].size(); i++) {
        if (!v[g[curr][i]]) {
            dfs(g[curr][i]);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        cat[i] = tmp;
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        g[a].push_back(b);
        g[b].push_back(a);
    }

    c[1] = cat[1] ? 1 : 0;
    dfs(1);
    
    /*
    for (int i = 1; i <= n; i++) {
        printf("%d%c", c[i], i == n ? '\n' : ' ');
    }
    */

    printf("%d\n", ans);
    return 0;
}
