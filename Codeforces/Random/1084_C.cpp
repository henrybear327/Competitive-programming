#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main()
{
    char inp[100010];
    scanf("%s", inp);
    
    // we group a into groups
    // divider is b
    vector<ll> group;
    int l = strlen(inp);
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        if (inp[i] == 'a')
            cnt++;
        else if (inp[i] == 'b') {
            if (cnt > 0) {
                group.push_back(cnt);
            }
            cnt = 0;
        }
    }

    if (cnt > 0) {
        group.push_back(cnt);
    }

    ll ans = 1;
    for (auto i : group) {
        ans = (ans * (i + 1)) % mod;
    }

    printf("%lld\n", ans - 1);

    return 0;
}
