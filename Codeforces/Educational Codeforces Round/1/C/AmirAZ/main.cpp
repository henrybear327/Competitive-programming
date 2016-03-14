#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 100;
const ld PI = M_PI;

int x[MAXN], y[MAXN], id[MAXN];
ld delta[MAXN];

bool byDelta(int a, int b)
{
    return (delta[a] < delta[b]);
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        delta[i] = atan2(y[i], x[i]) + PI;
        id[i] = i;
    }

    sort(id, id + n, byDelta);
    sort(delta, delta + n);

    ld ans = 10000;
    int id1, id2;
    for (int i = 0; i < n; i++) {
        int pre = (i - 1 + n) % n;

        ld dif = abs(delta[pre] - delta[i]);
        dif = min(dif, 2 * PI - dif);
        // cerr << dif * 180 / PI << endl;

        if (dif < ans) {
            ans = dif;
            id1 = id[i];
            id2 = id[pre];
        }
    }

    //	cerr << ans * 180 / PI << endl;;

    cout << id1 + 1 << " " << id2 + 1;
}
