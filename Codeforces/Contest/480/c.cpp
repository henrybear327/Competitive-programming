#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

// idea
// from left to right, process the number one by one
// if it wasn't marked in a group yet, extend towards 0 till next group is met or 0
// if the next group is met, then try to extent that group!

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }

    int arrangement[256];
    memset(arrangement, -1, sizeof(arrangement));
    for (int i = 0; i < n; i++) {
        if (arrangement[inp[i]] == -1) {
            int mn = inp[i];
            int r = k;
            for (int j = inp[i]; j >= 0 && arrangement[j] == -1 && r > 0; j--) {
                mn = min(mn, j);
                r--;
            }

            bool skip = false;
            if (r > 0 && mn - 1 >= 0 && arrangement[mn - 1] != -1) {
                int used = mn - arrangement[mn - 1];
                if (used + (k - r) <= k) {
                    skip = true;
                    for (int j = mn; j <= inp[i]; j++) {
                        arrangement[j] = arrangement[mn - 1];
                    }
                }
            }
            if (skip == false) {
                for (int j = mn; j <= inp[i]; j++) {
                    arrangement[j] = mn;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arrangement[inp[i]]);

    return 0;
}
