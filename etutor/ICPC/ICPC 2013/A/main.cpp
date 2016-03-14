#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 1000100
#define T_SIZE 100100

int inp[MAX_N], first[T_SIZE], last[T_SIZE];

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            scanf("%d", &inp[i]);

        for (int i = 0; i < T_SIZE; i++) {
            first[i] = last[i] = -1;
        }

        for (int i = 0; i < n; i++)
            if (first[inp[i]] == -1)
                first[inp[i]] = i;

        int last_number_pos = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (last[inp[i]] == -1) {
                last[inp[i]] = i;

                last_number_pos = max(last_number_pos, inp[i]);
            }
        }

        int max_idx = last[last_number_pos], ans = 0;
        for (int i = last_number_pos - 1; i >= 0; i--) {
            if (first[i] != -1 && max_idx > first[i]) {
                ans = max(max_idx - first[i], ans);
            }
            max_idx = max(last[i], max_idx);
        }

        printf("%d\n", ans);
    }

    return 0;
}
