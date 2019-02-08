#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    int ans = 0;
    for (int i = 2; i < n; i++) {
        if (inp[i] == 1 && inp[i - 2] == 1 && inp[i - 1] == 0)
            inp[i] = 0, ans++;
    }

    printf("%d\n", ans);

    return 0;
}
