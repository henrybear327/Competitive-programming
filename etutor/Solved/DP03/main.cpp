#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct data {
    int w, val;
};

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        data inp[n];
        for (int i = 0; i < n; i++)
            scanf("%d %d", &inp[i].w, &inp[i].val);

        int max_weight;
        scanf("%d", &max_weight);

        int T[n + 1][max_weight + 1];
        memset(T, 0, sizeof(T));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= max_weight; j++) {
                if (j < inp[i - 1].w)
                    T[i][j] = T[i - 1][j];
                else {
                    T[i][j] =
                        max(T[i - 1][j], T[i - 1][j - inp[i - 1].w] + inp[i - 1].val);
                }
            }
        }
        printf("%d\n", T[n][max_weight]);
    }

    return 0;
}
