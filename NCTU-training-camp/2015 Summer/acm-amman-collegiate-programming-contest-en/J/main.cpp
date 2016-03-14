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
        int N, M;
        scanf("%d %d", &N, &M);

        int age[16] = {0};
        int candies[51] = {0};

        while (N--) {
            int temp;
            scanf("%d", &temp);
            age[temp]++;
        }
        while (M--) {
            int temp;
            scanf("%d", &temp);
            candies[temp]++;
        }

        int j = 1;
        bool flag = true;
        for (int i = 5; i <= 15 && flag; i++) {
            while (age[i] != 0) {
                for (; j <= 50; j++) {
                    if (candies[j] >= age[i]) {
                        j++;
                        age[i] = 0;
                        break;
                    }
                }
                if (age[i] != 0 && j == 51) {
                    printf("NO\n");
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
            printf("YES\n");
    }

    return 0;
}

//.bashrc
// getchar() for scanf("") and fgets!
// len for strlen
// scanf == 1, 2, 3...
// i, j, k !! don't mess them up!
// look out for memset that sort of thing! Don't forget to initialize whenever
// needed
// scanf != EOF or == 1 may fail!!
// put break while necessary!

// try cases containing 0, 1, or repeat, eveb reverse
//estimate big-O!! 2^10is small!!