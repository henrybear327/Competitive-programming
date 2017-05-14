#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n;
bool solve()
{
    int inp[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &inp[i]);

    int cnt = 0;
    int nxt[n + 1];
    for (int i = 1; i <= n; i++)
        nxt[inp[i]] = i;

    for (int i = 1; i <= n; i++)
        if (inp[i] == nxt[i])
            cnt++;

    return cnt == n;
}

int main()
{
    while (scanf("%d", &n) && n != 0) {
        printf("%s\n", solve() ? "ambiguous" : "not ambiguous");
    }

    return 0;
}
