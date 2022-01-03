#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

struct Data {
    int l, r, c;
};

void solve()
{
    int n;
    scanf("%d", &n);

    Data lb = {INT_MAX, INT_MAX, INT_MAX};
    Data rb = {INT_MIN, INT_MIN, INT_MAX};

    Data lb2 = {INT_MAX, INT_MAX, INT_MAX};
    Data rb2 = {INT_MIN, INT_MIN, INT_MAX};
    for (int i = 0; i < n; i++) {
        Data data;
        scanf("%d %d %d", &data.l, &data.r, &data.c);

        if (data.l < lb.l) {
            lb = data;
            lb2 = data;
        } else if (data.l == lb.l) {
            if (data.c < lb.c) {
                lb = data;
            }

            if (data.r == lb2.r && data.c < lb2.c) {
                lb2 = data;
            } else if (data.r > lb2.r) {
                lb2 = data;
            }
        }

        if (data.r > rb.r) {
            rb = data;
            rb2 = data;
        } else if (data.r == rb.r) {
            if (data.c < rb.c) {
                rb = data;
            }

            if (data.l == rb2.l && data.c < rb2.c) {
                rb2 = data;
            } else if (data.l < rb2.l) {
                rb2 = data;
            }
        }

        int ret = INT_MAX;

        ret = min(ret, lb.c + rb.c);
        if (lb2.r >= rb.r) {
            ret = min(ret, lb2.c);
        }

        if (rb2.l <= lb.l) {
            ret = min(ret, rb2.c);
        }

        printf("%d\n", ret);
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--)
        solve();

    return 0;
}
