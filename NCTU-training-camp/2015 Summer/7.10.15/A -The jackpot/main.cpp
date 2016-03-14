#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

int main()
{
    int N;
    while (scanf("%d", &N) == 1 && N) {
        int temp, total = 0, max = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);
            total += temp;
            if (total < 0)
                total = 0;
            if (total > max)
                max = total;
        }
        if (max != 0)
            printf("The maximum winning streak is %d.\n", max);
        else
            printf("Losing streak.\n");
    }

    return 0;
}