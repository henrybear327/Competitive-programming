#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);

    int sum = a + b - c;
    if (sum >= 0 && n - sum >= 1 && a >= c && b >= c)
        printf("%d\n", n - sum);
    else
        printf("-1\n");

    return 0;
}
