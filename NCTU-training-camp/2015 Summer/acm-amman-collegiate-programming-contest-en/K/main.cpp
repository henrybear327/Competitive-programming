#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX
#include <cmath>

using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int exist[100001] = {0};
        int N, target;
        scanf("%d %d", &N, &target);

        int temp;
        while (N--) {
            scanf("%d", &temp);
            exist[temp]++;
        }

        int i;
        for (i = 1; i <= 100000 && i * i <= target; i++) {
            if (exist[i] > 0 && target % i == 0 && exist[target / i] > 0) {
                if (target / i == i && exist[i] != 1) {
                    printf("%d %d\n", i, target / i);
                    break;
                } else if (target / i == i && exist[i] == 1) {
                    continue;
                }
                printf("%d %d\n", i, target / i);
                break;
            }
        }
        if (i == 100001 || i * i > target)
            printf("-1\n");
    }

    return 0;
}
/*
2 1
1 1
*/

//.bashrc
// getchar() for scanf("") and fgets!
// len for strlen
// scanf == 1, 2, 3...
// i, j, k !! don't mess them up!
// look out for memset that sort of thing! Don't forget to initialize whenever
// needed
// scanf != EOF or == 1 may fail!!