#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int cmp_func(const void *a, const void *b)
{
    return *(long long int *)a - *(long long int *)b;
}

/*
WA. Consider the following case
OR all -> 0010011  (3, 16 OR => 19)

num 1  -> 0001100  (3 * 4)
num 2  -> 1000000  (16 * 4)

2 1 4 
3 16

*/

int main()
{
    long long int n, k, x;
    scanf("%lld %lld %lld", &n, &k, &x);

    long long int input[n], prev_or = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &input[i]);
        prev_or |= input[i];
    }

    qsort(input, n, sizeof(long long int), cmp_func);

    int index = 0;
    long long int tmp_prev_or = prev_or;
    bool book[100] = {false};
    while (tmp_prev_or) {
        if (tmp_prev_or & 1) {
            book[index] = true;
        }

        index++;
        tmp_prev_or >>= 1;
    }

    for (int i = 0; i < k; i++) {
        int max_diff = 0, max_diff_num = 0;
        long long int max_idx_sum = 0;
        for (int j = 0; j < n; j++) {
            long long int tmp = input[j] * x;
            long long int idx_sum = 0;
            int idx = 0, cnt = 0;
            printf("tmp %d\n", tmp);
            while (tmp) {
                if ((tmp & 1) && !book[idx]) {
                    cnt++;
                    idx_sum += (1 << idx);
                    printf("%lld\n", idx_sum);
                }
                tmp >>= 1;
                idx++;
            }

            if (cnt >= max_diff && idx_sum >= max_idx_sum) {
                max_diff = cnt;   // different pos cn t
                max_diff_num = j; // max diff idx pos
                max_idx_sum = idx_sum;
            }
        }

        prev_or = 0;
        for (int j = 0; j < n; j++) {
            if (max_diff_num == j)
                input[j] *= x;
            prev_or |= input[j];
        }
    }

    printf("%lld\n", prev_or);

    return 0;
}
