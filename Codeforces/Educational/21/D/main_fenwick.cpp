#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100100;

#define LSB(x) (x & (-x))
typedef long long ll;
struct Fenwick {
    ll data[MAX_N];
    int n;

    void init(int n)
    {
        this->n = n;
        memset(data, 0, sizeof(ll) * (n + 1));
    }

    ll query(int idx)
    {
        idx++;
        ll ret = 0;
        while (idx > 0) {
            ret += data[idx];
            idx -= LSB(idx);
        }
        return ret;
    }

    void add(int idx, ll val)
    {
        idx++;
        while (idx <= n) {
            data[idx] += val;
            idx += LSB(idx);
        }
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    Fenwick fw;
    fw.init(n);

    ll inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &inp[i]);

        fw.add(i, inp[i]);
    }

    ll half = fw.query(n - 1) / 2;
    if ((fw.query(n - 1) % 2 == 1) || (n == 1)) {
        printf("NO\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fw.add(i, -inp[i]);

        {
            int l = -1, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;

                if (fw.query(mid) <= half - inp[i]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }

            ll tmp = fw.query(l);
            if (l != -1 && tmp + inp[i] == half) {
                printf("YES\n");
                return 0;
            }
        }

        {
            int l = -1, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;

                if (fw.query(mid) <= half) {
                    l = mid;
                } else {
                    r = mid;
                }
            }

            ll tmp = fw.query(l);
            if (l != -1 && tmp == half) {
                printf("YES\n");
                return 0;
            }
        }

        fw.add(i, inp[i]);
    }

    printf("NO\n");

    return 0;
}
