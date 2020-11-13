#include <bits/stdc++.h>

using namespace std;

vector<int> g[200100];
int isCovered[200100] = {0};
int notCovered[200100] = {0};
bool isSelected[200100] = {false};
int parent[200100];
int inDegree[200100] = {0};

int n, m;
queue<int> q;
void dfs(int u, int p) {
    parent[u] = p;
    inDegree[p]++;

    if(g[u].size() == 1) {
        q.push(u);
        return;
    }

    for(auto v : g[u]) {
        if(v < n || v == p) // on ring or is parent
            continue;

        dfs(v, u);
    }
}

int main()
{
    memset(parent, -1, sizeof(parent));

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n + m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        dfs(i, -1);
    }

    while(q.size() > 0) {
        int u = q.front();
        int par = parent[u];
        // printf("u = %d, par %d\n", u, par);
        q.pop();

            if(isSelected[u])
                isCovered[par]++;
            else
                notCovered[par]++;
            inDegree[par]--;

            // printf("deg %d = %d\n", par, inDegree[par]);
            if(inDegree[par] == 0) {
                if(par >= n)
                    q.push(par);

                if(notCovered[par] != 0) {
                    isSelected[par] = true;
                }
            }
    }
    
    /*
    for(int i = 0; i < n + m; i++) {
        printf("%d %d %d\n", isCovered[i], notCovered[i], isSelected[i]);
    }
    */

    for(int i = 0; i < n; i++)
        if(notCovered[i] != 0)
            isSelected[i] = true;

    // add on ring
    int has = -1;
    for(int i = 0; i < n; i++) {
        if(isSelected[i]) {
            has = i;
            break;
        }
    }

    if(has == -1) {
        has = 0;
        isSelected[0] = true;
    }

    int idx = has;
    do {
        int nxt = (idx + 1) % n;
        int nxt2 = (nxt + 1) % n;

        if(isSelected[nxt] == false && isSelected[nxt2] == false)
            isSelected[nxt2] = true, idx = nxt2;
        else if(isSelected[nxt] == true)
            idx = nxt;
        else
            idx = nxt2;

        if(nxt == has || nxt2 == has)
            break;
    } while(idx != has);

    int ans = 0;
    for(int i = 0; i < n + m; i++)
        ans += isSelected[i];
    printf("%d\n", ans);

    return 0;
}
