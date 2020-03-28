#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int ans = 0;
    if (n / 500 > 0) {
        ans += n / 500 * 1000;
        n -= 500 * (n / 500);
    }

    if (n / 5 > 0) {
        ans += n / 5 * 5;
        n -= 5 * (n / 5);
    }

    printf("%d\n", ans);

    return 0;
}
