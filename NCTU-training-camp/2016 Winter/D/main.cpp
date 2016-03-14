#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans_tmp;
int n, m;
vector<int> g[2 * 100000 + 100];

// void dfs(int curr, int visited[], vector<int>& g, int population[])
void dfs(int curr, int visited[], int population[])
{
    visited[curr] = true;
    ans_tmp += population[curr];

    for(int i = 0; i < (int)g[curr].size(); i++) {
        if(visited[g[curr][i]] == false) {
            dfs(g[curr][i], visited, population);
        }
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    
    while(ncase--) {
        ans_tmp = 0;
        
        scanf("%d %d", &n, &m);
        
        int population[2 * 100000 + 100];
        for(int i = 1; i <= n; i++) {
            scanf("%d", &population[i]);
            g[i].clear();
        }
        
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        int visited[2 * 100000 + 100];
        memset(visited, false, sizeof(visited));
        ll ans = LLONG_MIN;
        for(int i = 1; i <= n; i++) {
            if(visited[i] == false) {
                dfs(i, visited, population);
                ans = max(ans, ans_tmp);
                ans_tmp = 0;
            }
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}