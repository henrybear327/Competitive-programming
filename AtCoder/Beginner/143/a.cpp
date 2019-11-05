#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = a - 2 * b;
    if (ans < 0)
        ans = 0;
    printf("%d\n", ans);

    return 0;
}
