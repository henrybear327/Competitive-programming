#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    char inp[1000];
    scanf("%s", inp);

    int f[26] = {0};
    int len = strlen(inp);
    for (int i = 0; i < len / 2; i++)
        f[inp[i] - 'a']++;

    int f2[26] = {0};
    for (int i = (len + 1) / 2; i < len; i++)
        f2[inp[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        if (f[i] != f2[i]) {
            printf("NO\n");
            return;
        }

    printf("YES\n");
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
