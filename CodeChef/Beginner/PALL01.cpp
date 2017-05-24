#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    char inp[10000];
    scanf("%s", inp);

    int len = strlen(inp);
    for (int i = 0; i < len / 2; i++) {
        if (inp[i] != inp[len - i - 1]) {
            printf("losses\n");
            return;
        }
    }

    printf("wins\n");
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
