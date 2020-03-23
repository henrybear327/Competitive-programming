#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    map<int, ll> cnt;
    int inp[n];
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        cnt[num]++;

        inp[i] = num;
    }

    ll total = 0;
    for (auto i : cnt)
        total += (i.second - 1) * i.second / 2;

    for (int i = 0; i < n; i++) {
        ll c = cnt[inp[i]];
        printf("%lld\n", total - c * (c - 1) / 2 + (c - 1) * (c - 2) / 2);
    }

    return 0;
}
