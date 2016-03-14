#include <bits/stdc++.h>

using namespace std;

int n, ans, curr_time, root;

int dfs_timestamp[110], dfs_low[110];
int g[110][110];
bool is_articulation_point[110];
void find_articulation_point(int curr, int parent)
{
    curr_time++; // only unvisited node will be recursive-called.
    dfs_low[curr] = dfs_timestamp[curr] =
                        curr_time; // so update time here is fine.
    int child = 0;
    for (int i = 1; i <= n; i++) {
        if (g[curr][i] == 1) {
            if (dfs_timestamp[i] == 0) {
                child++;
                find_articulation_point(i, curr);

                dfs_low[curr] = min(dfs_low[curr], dfs_low[i]);

                if (dfs_low[i] >= dfs_timestamp[curr] && curr != root)
                    is_articulation_point[curr] = true;

                if (root == curr && child >= 2)
                    is_articulation_point[curr] = true;
            } else if (i != parent) {
                dfs_low[curr] = min(dfs_low[curr], dfs_timestamp[i]);
            }
        }
    }

    return;
}

int main()
{
    char inp[20000];
    while (fgets(inp, 20000, stdin) != NULL && atoi(inp) != 0) {
        memset(g, 0, sizeof(g));
        n = atoi(inp);
        for (int i = 0; i <= n; i++) { // stupid IO bug
	    /*
	    4
	    1 2
	    2 3
	    3 4
	    4 1
	    0
	    4
	    1 2
	    2 3
	    3 4
	    4 1
	    0
	    0
	    
	    ans:
	    0
	    0
	    */
            fgets(inp, 20000, stdin);

            int curr;
            char *num = strtok(inp, " \r\n");
            curr = atoi(num);
            if (curr == 0)
                break;
            while ((num = strtok(NULL, " \r\n")) != NULL) {
                g[curr][atoi(num)] = g[atoi(num)][curr] = 1;
            }
        }

        /*
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                printf("%d%c", g[i][j], j == n ? '\n' : ' ');
        */

        memset(dfs_low, 0, sizeof(dfs_low));
        memset(dfs_timestamp, 0, sizeof(dfs_timestamp));
        memset(is_articulation_point, 0, sizeof(is_articulation_point));
        for (int i = 1; i <= n; i++) {
            if (dfs_low[i] == 0) {
                curr_time = 0;
                root = i;
                find_articulation_point(i, i);
            }
        }

        ans = 0;
        for (int i = 1; i <= n; i++) {
            if (is_articulation_point[i]) {
                // printf("articulation point %d\n",i);
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
