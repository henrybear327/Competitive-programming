#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int N;
    while (scanf("%d", &N) == 1) {
        while (N--) {
            long long int n, m, p;
            scanf("%lld%lld%lld", &n, &m, &p);
            int a[n][m];
            int b[m][p];
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            long long int max = -1000000000;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    scanf("%d", &a[i][j]);
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < p; j++) {
                    scanf("%d", &b[i][j]);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int k = 0; k < p; k++) {
                    int tmp = 0;
                    for (int j = 0; j < m; j++) {
                        tmp += a[i][j] * b[j][k];
                    }
                    if (tmp > max)
                        max = tmp;
                }
            }

            printf("%lld\n", max);
        }
    }

    return 0;
}
