#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int ans = 0;

    ans += (n * 2 + k - 1) / k; // 5/2 -> 3
    ans += (n * 5 + k - 1) / k; // 5/2 -> 3
    ans += (n * 8 + k - 1) / k; // 5/2 -> 3

    printf("%d\n", ans);

    return 0;
}
