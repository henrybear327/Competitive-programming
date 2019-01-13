#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    char inp[n + 3];
    scanf("%s", inp);

    int l = 1, r = 1;
    for (int i = 1; i < n; i++) {
        if (inp[i - 1] == inp[i])
            continue;
        l = i;
        break;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (inp[i + 1] == inp[i])
            continue;
        r = (n - 1) - i;
        break;
    }

    if (inp[0] != inp[n - 1])
        printf("%d\n", l + r + 1);
    else {
        printf("%lld\n", ll(l + 1) * ll(r + 1) % 998244353);
    }

    return 0;
}
