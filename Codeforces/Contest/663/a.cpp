#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("%d%c", i + 1, i == n - 1 ? '\n' : ' ');
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--)
        solve();

    return 0;
}
