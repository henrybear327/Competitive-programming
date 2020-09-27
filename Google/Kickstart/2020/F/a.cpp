#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x;
    scanf("%d %d", &n, &x);

    map<int, vector<int>> ans;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        ans[(num - 1) / x].push_back(i + 1);
    }

    for (auto i : ans)
        for (auto j : i.second) {
            printf("%d ", j);
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

    return 0;
}
