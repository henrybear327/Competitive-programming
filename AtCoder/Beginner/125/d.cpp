#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    ll zero = 0, neg = 0;
    ll mn = INT_MAX, sum = 0;
    for (int i = 0; i < n; i++) {
        ll num;
        scanf("%lld", &num);

        if (num == 0)
            zero++;
        else if (num < 0)
            neg++;

        sum += abs(num);
        mn = min(mn, abs(num));
    }

    if (zero > 0)
        printf("%lld\n", sum);
    else if (neg % 2 == 1)
        printf("%lld\n", sum - 2 * mn);
    else
        printf("%lld\n", sum);

    return 0;
}
