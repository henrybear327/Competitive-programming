#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a + b + c == 180 && (a && b && c))
        printf("YES\n");
    else
        printf("NO\n");
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
