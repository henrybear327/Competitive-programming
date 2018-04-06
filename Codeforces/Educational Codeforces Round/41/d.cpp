#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    return a == 0 ? b : gcd(b % a, a);
}

// issues on dx == 0 or dy == 0
// the sign will be messed up if not sorted properly
ii getSlope(ii a, ii b)
{
    // bullshit
    if (a.first > b.first)
        swap(a, b);
    if (a.second > b.second)
        swap(a, b);
    // end bullshit

    int dx = a.first - b.first;
    int dy = a.second - b.second;
    int g = gcd(dx, dy);
    // distinct is guaranteed
    dx /= g;
    dy /= g;

    if (dx < 0) {
        dx = -dx;
        dy = -dy;
    }

    return ii(dx, dy);
}

bool ok(int x, int y, const ii inp[], int n)
{
    // printf("x %d y %d\n", x, y);
    ii a = inp[x];
    ii b = inp[y];
    ii s = getSlope(a, b);
    // printf("%d %d %d %d\n", a.first, a.second, b.first, b.second);
    // printf("s = %d %d\n", s.first, s.second);

    bool used[n];
    memset(used, false, sizeof(used));
    used[x] = used[y] = true;
    int cnt = 2;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }

        //printf("%d: %d %d\n", i, getSlope(a, inp[i]).first,
          //     getSlope(a, inp[i]).second);
        if (s == getSlope(a, inp[i])) {
            used[i] = true;
            cnt++;
        }
    }

    //printf("cnt %d\n", cnt);
    if (n - cnt <= 2) {
        return true;
    }

    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            if (tmp == 0) {
                tmp++;
                a = inp[i];
                used[i] = true;
            } else if (tmp == 1) {
                b = inp[i];
                tmp++;
                used[i] = true;
                s = getSlope(a, b);
            } else {
                if (s != getSlope(a, inp[i])) {
                    return false;
                }
                used[i] = true;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    ii inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &inp[i].first, &inp[i].second);

    if (n <= 2 || ok(0, 1, inp, n) || ok(0, 2, inp, n) || ok(1, 2, inp, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
