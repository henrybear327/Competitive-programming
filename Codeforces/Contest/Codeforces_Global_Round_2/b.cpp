#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n, h;
int inp[1000];
bool check(int mid)
{
    int tmp[mid];
    for (int i = 0; i < mid; i++)
        tmp[i] = inp[i];
    sort(tmp, tmp + mid);

    int hh = h;
	// put the largest ones in first!
    for (int i = mid - 1; i >= 0; i -= 2) {
        if (i == 0) {
            hh -= tmp[i];
        } else {
            int mx = max(tmp[i], tmp[i - 1]);
            hh -= mx;
        }

        if (hh < 0)
            return false;
    }

    return true;
}

int main()
{
    scanf("%d %d", &n, &h);

    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        // vvvvvxxxx
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    printf("%d\n", l);

    return 0;
}
