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
    int data[6];
    for (int i = 0; i < 6; i++)
        scanf("%d", &data[i]);

    int total = 1 + 2 * (data[0] - 1) + 2;
    int prev = total;
    // printf("%d\n", total);

    bool flag1 = true, flag2 = true;
    int R = data[1] - 1, L = data[5] - 1;
    while (1) {
        if (flag1 == false) {
            if (L == 0)
                break;
        }

        int temp = prev;
        if (L > 0 && flag1) {
            temp += 1;
            L--;
        } else if (L > 0 && flag1 == false) {
            temp -= 1;
            L--;
        } else {
            L = data[4] - 1;
            flag1 = false;
        }

        if (R > 0 && flag2) {
            temp += 1;
            R--;
        } else if (R > 0 && flag2 == false) {
            temp -= 1;
            R--;
        } else {
            R = data[2] - 1;
            flag2 = false;
        }

        total += temp;
        prev = temp;
        // printf("%d %d \n", temp, total);
    }

    printf("%d\n", total);

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
