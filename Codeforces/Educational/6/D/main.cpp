#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

/*
10
87 -92 -67 -100 -88 80 -82 -59 81 -72
10
-50 30 30 77 65 92 -60 -76 -29 -15
*/

using namespace std;

pair<int, int> aa, bb;
void check(ll *ans, ll left, ll right, int a, int b, int c, int d)
{
    if(*ans > llabs(left - right)) {
        // printf("%lld %lld %d %d %d %d\n", left, right, a, b, c, d);
        *ans = llabs(left - right);
        aa = make_pair(c + 1, a + 1);
        bb = make_pair(d + 1, b + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    ll sa = 0LL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sa += a[i];
    }

    int m;
    scanf("%d", &m);
    int b[m];
    ll sb = 0LL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        sb += b[i];
    }


    ll ans = llabs(sa - sb);
    int idxa, idxb;
    // zero/one swap
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if (ans > llabs((sa - a[i] + b[j]) - (sb - b[j] + a[i]))) {
                ans =  llabs((sa - a[i] + b[j]) - (sb - b[j] + a[i]));
                idxa = i + 1;
                idxb = j + 1;
            }

    if(ans == llabs(sa - sb))
        printf("%lld\n0\n", ans);
    else {
        ll one_ans = ans;

        vector< pair<ll, pair<int, int> > > asum;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                asum.push_back(make_pair(2LL * (a[i] + a[j]), make_pair(i, j)));
        sort(asum.begin(), asum.end());

        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++)  {
                ll left = sa - sb + 2LL * (b[i] + b[j]);
                auto lower = lower_bound(asum.begin(), asum.end(), make_pair(left, make_pair(0, 0)));

                if(lower != asum.end())
                    check(&ans, left, lower->first, i, j, lower->second.first, lower->second.second);
                if(lower != asum.begin()) {
                    lower--;
                    check(&ans, left, lower->first, i, j, lower->second.first, lower->second.second);
                }
            }
        }

        if(ans == one_ans)
            printf("%lld\n1\n%d %d\n", one_ans, idxa, idxb);
        else
            printf("%lld\n2\n%d %d\n%d %d\n", ans, aa.first, aa.second, bb.first, bb.second);
    }

    return 0;
}
