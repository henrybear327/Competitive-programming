#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int mx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (mx <= num)
            ans++;
        mx = max(mx, num);
    }
    printf("%d\n", ans);

    return 0;
}
