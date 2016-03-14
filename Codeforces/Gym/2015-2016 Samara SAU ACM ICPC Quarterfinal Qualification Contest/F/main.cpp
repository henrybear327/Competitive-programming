#include <bits/stdc++.h>

using namespace std;

#ifdef WIN_32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    bool inp[n][m];
    char c[m + 10];
    int ans_for_1 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", c);
        for (int j = 0; j < m; j++) {
            inp[i][j] = (c[j] == '.' ? true : false);
            if (c[j] == '.')
                ans_for_1++;
        }
    }
    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d%c", inp[i][j] ? 1 : 0, j == m - 1 ? '\n' : ' ');
        }
    }
    */

    int hor[n][m];
    memset(hor, 0, sizeof(hor));

    int ver[n][m];
    memset(ver, 0, sizeof(ver));

    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = 0; j < m; j++) {
            if (inp[i][j] == true) {
                counter++;
            } else {
                counter = 0;
            }
            hor[i][j] = counter;
        }
    }
    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d%c", hor[i][j] , j == m - 1 ? '\n' : ' ');
        }
    }
    */

    for (int j = 0; j < m; j++) {
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (inp[i][j] == true) {
                counter++;
            } else {
                counter = 0;
            }
            ver[i][j] = counter;
        }
    }
    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d%c", ver[i][j] , j == m - 1 ? '\n' : ' ');
        }
    }
    */

    ll total[max(n, m) + 10];
    memset(total, 0, sizeof(total));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            total[hor[i][j]]++;
            total[ver[i][j]]++;
        }
    }

    for (int i = max(n, m); i > 1; i--) {
        total[i] = total[i + 1] + total[i];
    }

    total[1] = ans_for_1;
    for (int i = 1; i <= max(n, m); i++) {
        printf("%lld%c", total[i], i == max(n, m) ? '\n' : ' ');
    }

    return 0;
}
