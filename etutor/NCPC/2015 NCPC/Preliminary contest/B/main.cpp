#include <bits/stdc++.h>

using namespace std;

int g[40][40];
int money_node[40];

int node, start, money;
int v[40];
int v_money[40];
bool flag = false;
void dfs(int curr, int money)
{
    v[curr] = 1;
    money += money_node[curr];
    v_money[curr] = money;
    for(int i = 1; i <= node; i++) {
        if(v[i] == 0 && g[curr][i] != 0 && money >= g[curr][i]) {
            dfs(i, money - g[curr][i]);
        } else if(v[i] == 1 && g[curr][i] != 0 && money - g[curr][i] + money_node[i] > v_money[i]) {
            flag = true;
        }
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while(cases--) {
        scanf("%d %d %d", &node, &start, &money);
        int edge;
        scanf("%d", &edge);

        memset(g, 0, sizeof(g));

        bool ggg[40] = {0};
        for(int i = 0; i < edge; i++) {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);

            g[x][y] = g[y][x] = c;
            ggg[x] = ggg[y] = 1;
        }

        memset(money_node, 0, sizeof(money_node));
        int m_node;
        scanf("%d", &m_node);
        for(int i = 0; i < m_node; i++) {
            int x, c;
            scanf("%d %d", &x, &c);
            money_node[x] = c;
        }

        //dfs
        memset(v, 0, sizeof(v));
        memset(v_money, 0, sizeof(v_money));
        flag = false;
        dfs(start, money);

        int ans = 0;
        for(int i = 1; i <= node; i++) {
            if(v[i] == 0)
                ans++;
        }

        int cnt = 0;
        if(flag) {
            for(int i = 1; i <= node; i++) {
                if(ggg[i] == 0)
                    cnt++;
            }
        }
        printf("%d\n", flag ? cnt : ans);

    }

    return 0;
}
