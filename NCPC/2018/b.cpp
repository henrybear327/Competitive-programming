#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> candidates;

// 1:26 2WA 1AC
void init()
{
    ll two = 1, three = 1;
    for (int i = 0; i <= 32; i++) {
        if (i > 0)
            two *= 2;
        three = 1;
        for (int j = 0; j <= 32; j++) {
            if (j > 0)
                three *= 3;
            ll num = two * three;
            if (num > ll(1e10))
                break;
            candidates.push_back(num);
        }
    }

    sort(candidates.begin(), candidates.end());
}

const long double EPS = 1e-9;

void solve()
{
    ll num;
    scanf("%lld", &num);
    
    if(num == 1) {
        printf("1\n");
        return;
    }

    for (int i = 1; i < (int)candidates.size(); i++) {
        if (candidates[i - 1] <= num && num <= candidates[i]) {
            if (num * num < candidates[i - 1] * candidates[i])
                printf("%lld\n", candidates[i - 1]);
            else
                printf("%lld\n", candidates[i]);

            break;
        }
    }
}

int main()
{
    init();

    int ncase;
    scanf("%d", &ncase);

    while (ncase--)
        solve();

    return 0;
}
