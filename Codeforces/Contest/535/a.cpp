#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    ii left, right;
    scanf("%d %d %d %d", &left.first, &left.second, &right.first, &right.second);

    int a = left.first;
    int b = right.first;
    if (a == b)
        b++;

    printf("%d %d\n", a, b);
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
        solve();

    return 0;
}
