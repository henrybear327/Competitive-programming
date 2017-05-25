#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    bool done[n];
    memset(done, 0, sizeof(done));
    for (int i = 0; i < m; i++) {
        int tmp;
        scanf("%d", &tmp);
        tmp--;

        done[tmp] = true;
    }

    vector<int> ans[2];
    int turn = 0;
    for (int i = 0; i < n; i++) {
        if (done[i] == false) {
            ans[turn].push_back(i);
            turn ^= 1;
        }
    }

    int len = ans[0].size();
    if (len == 0)
        printf("\n");
    for (int i = 0; i < len; i++)
        printf("%d%c", ans[0][i] + 1, i == len - 1 ? '\n' : ' ');

    len = ans[1].size();
    if (len == 0)
        printf("\n");
    for (int i = 0; i < len; i++)
        printf("%d%c", ans[1][i] + 1, i == len - 1 ? '\n' : ' ');
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
