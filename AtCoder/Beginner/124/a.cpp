#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d\n", max({2 * n - 1, 2 * m - 1, m + n}));

    return 0;
}
