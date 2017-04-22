#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);

        int inp[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &inp[i][j]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (inp[i][j] == 1 && inp[i][k] == 1 && inp[j][k] == 1)
                        ans++;
                }
            }
        }

        printf("%d\n", ans);
    }
}