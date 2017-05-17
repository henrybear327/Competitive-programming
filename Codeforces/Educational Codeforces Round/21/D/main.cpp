#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100100;

typedef long long ll;

ll inp[MAX_N];
int n;
ll sum = 0;

bool ok;
void go()
{
    ll prefixSum = 0;

    set<ll> in;
    for (int i = 0; i < n; i++) {
        prefixSum += inp[i];

        in.insert(inp[i]);
        if (prefixSum < sum / 2)
            continue;

        ll diff = (prefixSum - sum / 2);

        if (in.find(diff) != in.end()) {
            ok = true;
            return;
        }
    }
}

int main()
{
    scanf("%d", &n);

    sum = 0;
    ok = false;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &inp[i]);

        sum += inp[i];
    }

    if (sum % 2 == 1) {
        ok = false;
    } else {
        go();
        reverse(inp, inp + n);
        go();
    }

    if (ok)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
