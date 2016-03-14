#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#define MIN(x, y) ((x) < (y) ? (x) : (y)
#define MAX(x, y) ((x) > (y) ? (x) : (y)

using namespace std;

int main()
{
    int total;
    scanf("%d", &total);
    int input[total], used[total + 1];
    memset(used, 0, sizeof(used));
    for (int i = 0; i < total; i++) {
        scanf("%d", &input[i]);
        if (input[i] > total)
            input[i] = -1;

        if (used[input[i]] == 0)
            used[input[i]] = 1;
        else
            input[i] = -1;
    }

    int index = 0;
    for (int i = 1; i <= total; i++) {
        if (used[i] == 0) {
            index = i;
            break;
        }
    }

    for (int i = 0; i < total && index != total + 1; i++) {
        if (input[i] == -1) {
            input[i] = index;
            for (int i = index + 1; i <= total; i++) {
                if (used[i] == 0) {
                    index = i;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < total; i++) {
        if (i != total - 1)
            printf("%d ", input[i]);
        else
            printf("%d\n", input[i]);
    }
    return 0;
}
