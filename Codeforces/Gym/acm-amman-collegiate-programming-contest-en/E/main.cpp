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

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        int students;
        scanf("%d", &students);
        int data[students];
        for (int i = 0; i < students; i++)
            scanf("%d", &data[i]);

        qsort(data, students, sizeof(int), cmp);
        int max = data[students - 1];
        int ans = 0, range = 100 - max;
        for (int i = 0; i < students; i++) {
            if (data[i] + range >= 50)
                ans++;
        }
        printf("%d\n", ans);
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