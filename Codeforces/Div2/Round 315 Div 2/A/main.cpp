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
    float T, S, q;
    scanf("%f %f %f", &T, &S, &q);

    int count = 0;

    while (S < T) {
        S *= q;
        count++;
    }
    printf("%d\n", count);
    return 0;
}
