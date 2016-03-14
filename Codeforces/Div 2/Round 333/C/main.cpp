#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int node, n;
int g[410][410];

//Another tricky problem where the restriction is ... never mind
int bfs(int type)
{
    queue<int> q;
    q.push(0);
    int visited[node];

    memset(visited, -1, sizeof(visited));
    visited[0] = 0;

    while(!q.empty()) {
        int curr= q.front();
        if(curr == node - 1)
            break;
        q.pop();
        for(int i= 0; i < node; i++) {
            if(visited[i] == -1 && g[i][curr] == type) {
                q.push(i);
                visited[i] = visited[curr] + 1;
            }
        }
    }

    return visited[node - 1];
}

#define RAIL 1
#define ROAD 2

int main()
{
    scanf("%d %d", &node, &n);
    for(int i = 0; i < node; i++)
        fill(g[i], g[i] + node, ROAD);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d",&a, &b);
        a--; // come on~~ off-by-one
        b--;
        g[a][b] = g[b][a] = RAIL;
    }
    //bfs search the route(weight 1), use dijkstra is faster
    int d1 = bfs(RAIL), d2 = bfs(ROAD);
    // printf("%d %d\n", d1, d2);
    int ans = max(bfs(RAIL), bfs(ROAD));
    if(d1 == -1 || d2 == -1)
        ans = -1;
    printf("%d\n", ans);

    return 0;
}
