#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num >= k)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
