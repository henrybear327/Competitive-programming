#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    char inp[1111];
    scanf("%s", inp);

    bool hasDiff = false;
    int n = strlen(inp);
    for (int i = 1; i < n; i++)
        if (inp[i] != inp[i - 1]) {
            hasDiff = true;
            break;
        }

    if (hasDiff) {
        sort(inp, inp + n);
        printf("%s\n", inp);
    } else
        printf("-1\n");
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
        solve();

    return 0;
}
