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
    char input1[200010] = {'\0'};
    char input2[200010] = {'\0'};

    fgets(input1, 200010, stdin);
    fgets(input2, 200010, stdin);

    if(strlen(input1) != strlen(input2)) {
    	printf("NO\n");
    	return 0;
    }

    int len = strlen(input1) - 1;
    bool flag[4];
    for (int i = 0; i < 4; i++)
        flag[i] = true;

    if (len % 2 == 1) {
        for (int i = 0; i < len; i++) {
            if (input1[i] != input2[i]) {
                printf("NO\n");
                return 0;
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            if (flag[0] && input1[i] != input2[i]) {
                // printf("1\n");
                flag[0] = false;
            }
        }

        for (int i = 0; i < len / 2; i++) {
            if (flag[1] && input1[i] != input2[len / 2 + i]) {
                flag[1] = false;
                // printf("2\n");
            }
            if (flag[2] && input1[len / 2 + i] != input2[i]) {
                flag[2] = false;
                // printf("3\n");
            }
            if (flag[3] && input1[len / 2 + i] != input2[len / 2 + i]) {
                flag[3] = false;
                // printf("4\n");
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        // printf("%d\n", i);
        if (flag[i] == true) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

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
