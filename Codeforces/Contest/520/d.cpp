#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    ll sum = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; i * j <= n; j++) {
            sum += j * 4;
        }
    }

    printf("%lld\n", sum);

    return 0;
}
