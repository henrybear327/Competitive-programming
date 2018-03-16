#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    unordered_map<string, int> idx;
    unordered_map<int, string> ridx;
    int cnt = 0;
    int deg[n * 2];
    memset(deg, 0, sizeof(deg));
    int nxt[n * 2];
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; i++) {
        char from[100], to[100];
        scanf("%s %s", from, to);

        int f, t;
        if (idx.find(from) != idx.end())
            f = idx[from];
        else {
            idx[from] = cnt++;
            f = idx[from];
            ridx[f] = from;
        }

        if (idx.find(to) != idx.end())
            t = idx[to];
        else {
            idx[to] = cnt++;
            t = idx[to];
            ridx[t] = to;
        }

        nxt[f] = t;
        deg[t]++;
    }

    for (int i = 0; i < cnt; i++)
        if (deg[i] == 0) {
            while (nxt[i] != -1) {
                printf("%s-%s ", ridx[i].c_str(), ridx[nxt[i]].c_str());
                i = nxt[i];
            }

            break;
        }
    printf("\n");
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
