#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inp[n];
    int total = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]), total += inp[i];

    int target = (total + 4 * m - 1) / (4 * m);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (inp[i] >= target)
            ans++;

    if (ans >= m)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
