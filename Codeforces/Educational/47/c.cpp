#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    long double sol = 0.0;
    
    ll oddSum = 0;
    ll evenSum = 0;
    ll sum = 0;
    for(int i = 0; i < m; i++) {
        ll x, k;
        scanf("%d %d", &x, &k);

        sum += x;
        if(k >= 0) {
            oddSum += k * (n - 1) * n;
            // printf("k >= 0 %f\n", sol);
        } else {
            bool even = n % 2 == 0;
            if(even)
                n--;
            int cnt = n / 2;
            ll inc = (k + cnt * k) * cnt;
            evenSum += inc;
            if(even)
                n++;
            cnt = n / 2;
            evenSum += (cnt * k);
            // printf("k < 0 %f\n", sol);
        }
    }

    sol += (1.0 * oddSum / 2) + (1.0 * evenSum);
    sol /= n;
    sol += sum;

    printf("%.15Lf\n", sol);

    return 0;
}
