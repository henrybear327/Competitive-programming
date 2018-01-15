#include <bits/stdc++.h>

using namespace std;

bool seen[55555];
int inp[55555];
void dfs(int i)
{
    if (seen[i])
        return;
    seen[i] = true;

    dfs(inp[i]);
}
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    memset(seen, false, sizeof(seen));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i] == false) {
            dfs(i);
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
