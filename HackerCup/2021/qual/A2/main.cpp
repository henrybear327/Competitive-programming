#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    return false;
}

int solve()
{
    char inp[103];
    scanf("%s", inp);

    int dist[26][26];
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < 26; i++)
        dist[i][i] = 0;

    int rec;
    scanf("%d", &rec);
    for (int i = 0; i < rec; i++) {
        char edge[5];
        scanf("%s", edge);

        int u = edge[0] - 'A';
        int v = edge[1] - 'A';

        dist[u][v] = 1;
    }

    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int len = strlen(inp);
    int mn = INT_MAX;
    for (int i = 0; i < 26; i++) {
        int toChar = i;

        int t = 0;
        bool ok = true;
        for (int j = 0; j < len; j++) {
            if (inp[j] - 'A' == toChar) {
                continue;
            }

            if (dist[inp[j] - 'A'][toChar] == 0x3f3f3f3f) {
                ok = false;
                break;
            }

            t += dist[inp[j] - 'A'][toChar];
        }

        if (ok) {
            mn = min(mn, t);
        }
    }
    return mn == INT_MAX ? -1 : mn;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %d\n", i, solve());
    }

    return 0;
}
