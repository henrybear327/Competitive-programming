#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int inp[3];
    for (int i = 0; i < 3; i++)
        scanf("%d", inp + i);

    sort(inp, inp + 3);

    printf("%d\n", inp[1]);
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
