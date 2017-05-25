#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        int res = a - b;
        if (res % 10 == 9)
            res -= 1;
        else
            res += 1;
        printf("%d\n", res);
    }
}

int main()
{
    solve();

    return 0;
}
