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

struct size {
    int l, h;
};

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    struct size x[4];
    for (int i = 0; i < 4; i += 2) {
        scanf("%d %d", &x[i].l, &x[i].h);
        x[i + 1].h = x[i].l;
        x[i + 1].l = x[i].h;
    }
    int q, r;
    // 0 2
    q = x[0].l + x[2].l;
    r = MAX(x[0].h, x[2].h);
    if ((q <= a && r <= b) || (r <= a && q <= b)) {
        printf("YES\n");
        return 0;
    }
    // 0 3
    q = x[0].l + x[3].l;
    r = MAX(x[0].h, x[3].h);
    if ((q <= a && r <= b) || (r <= a && q <= b)) {
        printf("YES\n");
        return 0;
    }
    // 1 2
    q = x[1].l + x[2].l;
    r = MAX(x[1].h, x[2].h);
    if ((q <= a && r <= b) || (r <= a && q <= b)) {
        printf("YES\n");
        return 0;
    }
    // 1 3
    q = x[1].l + x[3].l;
    r = MAX(x[1].h, x[3].h);
    if ((q <= a && r <= b) || (r <= a && q <= b)) {
        printf("YES\n");
        return 0;
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
