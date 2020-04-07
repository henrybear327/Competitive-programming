#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void gen(vector<ll> &tb, int digit, int starting, int mxDigit)
{
    if (digit > mxDigit)
        return;

    int mx = tb.size();
    for (int i = starting; i < mx; i++) {
        ll d = tb[i] % 10;
        if (d > 0)
            tb.push_back(tb[i] * 10 + d - 1);
        tb.push_back(tb[i] * 10 + d);
        if (d < 9)
            tb.push_back(tb[i] * 10 + d + 1);
    }

    gen(tb, digit + 1, mx, mxDigit);
}

int main()
{
    vector<ll> tb;
    for (int i = 1; i <= 9; i++)
        tb.push_back(i);
    gen(tb, 2, 0, 10);

    //    printf("%d\n", tb.size());
    sort(tb.begin(), tb.end());

    // for (int i = 0; i < tb.size(); i++)
    //  printf("%d\n", tb[i]);

    int k;
    scanf("%d", &k);

    printf("%lld\n", tb[k - 1]);

    return 0;
}
