#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int a, b;
    scanf("%d %d", &a, &b);

    char ans = '=';
    if (a < b)
        ans = '<';
    else if (a > b)
        ans = '>';

    printf("%c\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();

    return 0;
}
