#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_NODE 100
vector<int> g[MAX_NODE];
vector< pair<int, int> > ans;
int dfs_time[MAX_NODE], dfs_low[MAX_NODE];

int node, timestamp = 0;
void find_bridge(int curr, int parent)
{
    timestamp++;
    dfs_low[curr] = dfs_time[curr] = timestamp;
    int child = 0;

    for(int i = 0; i < (int)g[curr].size(); i++) {
        int next = g[curr][i];
        if(dfs_time[next] == 0) {
            child++;
            find_bridge(next, curr);

            dfs_low[curr] = min(dfs_low[curr], dfs_low[next]);

            if(dfs_low[next] > dfs_time[curr])
                ans.push_back(make_pair(min(curr, next), max(curr, next)));
        } else if(next != parent) {
            dfs_low[curr] = min(dfs_low[curr], dfs_time[next]);
        }
    }
}

int main()
{
    while(scanf("%d", &node) == 1) {
        for(int i = 0; i < MAX_NODE; i++) {
            g[i].clear();
            ans.clear();
        }
        memset(dfs_time, 0, sizeof(dfs_time));
        memset(dfs_low, 0, sizeof(dfs_low));

        for(int i = 0; i < node; i++) {
            int curr, cnt;
            scanf("%d (%d)", &curr, &cnt);

            for(int i = 0; i < cnt; i++) {
                int tmp;
                scanf("%d", &tmp);
                g[curr].push_back(tmp);
            }
        }

        for(int i = 0; i < node; i++)
            if(dfs_time[i] == 0)
                find_bridge(i, i);

        sort(ans.begin(), ans.end());
        printf("%d critical links\n", (int)ans.size());
        for(int i = 0; i < (int)ans.size(); i++)
            printf("%d - %d\n", ans[i].first, ans[i].second);
        printf("\n");
    }

    return 0;
}
