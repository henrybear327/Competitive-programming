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
    int size;
    scanf("%d", &size);
    int sum = 0, input[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &input[i]);
        sum += input[i];
    }
    /*
        int data[sum + 1];
        for (int i = 0; i < sum + 1; i++)
            data[i] = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 1; j * input[i] <= sum; j++) {
                data[j * input[i]] = 1;
            }
        }

        int i;
        for (i = 1; i <= sum; i++) {
            if (data[i] == 0) {
                printf("%d\n", i);
                return 0;
            }
        }
    */
    int i;
    for (i = 0; i < size; i++) {
        if (input[i] == 1) {
            printf("-1\n");
            return 0;
        }
    }

    if (i == size)
        printf("1\n");

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

// read problem state,ent carefully! Word by word!

// try cases containing 0, 1, or repeat, eveb reverse
// estimate big-O!! 2^10is small!!

// try to find cycle first!!!
