#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    ll ans = 0;
    bool hasZero = false;
    int pos = 0;
    int neg = 0;
    for (int i = 0; i < n; i++) {
        if (inp[i] == 0)
            hasZero = true, ans++; // doesn't matter if we make it 1 or -1
        else if (inp[i] < 0) {
            // change neg number to -1
            ans += abs(inp[i] - -1);
            neg++;
        } else {
            // change pos number to 1
            ans += inp[i] - 1;
            pos++;
        }
    }

    if (hasZero == 0) { // if we have zero -> we can change parity without extra cost
        if (neg % 2 == 1) { // odd number of -1
            ans += 2; // make one -1 into 1
        }
    }

    printf("%lld\n", ans);

    return 0;
}
