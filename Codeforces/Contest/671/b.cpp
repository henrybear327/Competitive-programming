#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll mx = 1000000000000000000;

int main()
{
    vector<ll> pre;
    ll base = 1;
    ll acc = 1;
    for (int i = 0;; i++) {
        ll tmp = (1 + acc) / 2 * acc;
        if (tmp > mx)
            break;

        pre.push_back(tmp);

        base *= 2;
        acc += base;
    }

    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        ll _inp;
        scanf("%lld", &_inp);

        int ans = 0;
        int _sz = pre.size();
        for (int sz = _sz; sz > 0; sz--) {
            int _ans = 0;
            ll inp = _inp;
            bool used[sz] = {false};
            while (inp > 0) {
                ll tmp = -1;
                for (int i = 0; i < sz; i++) {
                    if (inp - pre[i] >= 0) {
                        if (used[i] == false) {
                            tmp = i;
                        }
                    }
                }

                if (tmp == -1)
                    break;
                _ans++;
                inp -= pre[tmp];
                used[tmp] = true;
            }

            ans = max(ans, _ans);
        }
        printf("%d\n", ans);
    }

    return 0;
}
