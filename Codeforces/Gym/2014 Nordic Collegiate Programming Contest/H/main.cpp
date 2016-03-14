/*
Pure KMP problem
*/
#include <bits/stdc++.h>

using namespace std;

int f[200100];
int n;

int clock1[200100], clock2[200100];
int diff1[200100], diff2[400100];

int plen, slen;

void fail_function()
{
    memset(f, 0, sizeof(f));
    plen = n;

    int i = 0, j = 1;
    while (j < plen) {
        if (diff1[i] == diff1[j]) {
            f[j] = i + 1;
            i++;
            j++;
        } else {
            if (i != 0) {
                i = f[i - 1];
            } else {
                f[j] = 0;
                j++;
            }
        }
    }
}

int KMP()
{
    int cnt = 0;

    int pidx = 0;
    for (int i = 0; i < n * 2; i++) {
        int skip = 0;
        while (diff1[pidx] == diff2[i] && i < n * 2) {
            if (pidx == plen - 1) {
                cnt++;
                pidx = f[pidx];
                skip = 1;
                break;
            }
            pidx++;
            i++;
        }

        if (pidx != 0 && skip == 0) {
            pidx = f[pidx - 1];
            i--;
        }
    }

    return cnt;
}

inline int get_degree(int deg)
{
    if (deg == 360000)
        return 0;

    if (deg < 0)
        return deg + 360000;
    return deg;
}

int main()
{
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%d", &clock1[i]);

        for (int i = 0; i < n; i++)
            scanf("%d", &clock2[i]);

        sort(clock1, clock1 + n);
        sort(clock2, clock2 + n);

        for (int i = 1; i < n; i++) {
            diff1[i] = get_degree(clock1[i] - clock1[i - 1]);
            diff2[i] = get_degree(clock2[i] - clock2[i - 1]);
        }

        diff1[0] = get_degree(clock1[0] - clock1[n - 1]); // A
        diff2[0] = get_degree(clock2[0] - clock2[n - 1]); // BB

        for (int i = n; i < 2 * n; i++) {
            diff2[i] = diff2[i - n];
        }

        /*
        for(int i = 0; i< n; i++) {
            printf("%d ", diff1[i]);
        }
        printf("\n");

        for(int i = 0; i < 2 * n; i++) {
            printf("%d ", diff2[i]);
        }
        printf("\n");
        */

        fail_function();

        /*
        for(int i = 0; i < n; i++)
            printf("%d ", f[i]);
        printf("\n");
        */

        if (KMP() >= 1)
            printf("possible\n");
        else
            printf("impossible\n");
    }

    return 0;
}
