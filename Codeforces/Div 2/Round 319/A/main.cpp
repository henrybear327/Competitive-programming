#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);

    int i, ans = 0;
    for (i = 1; i <= n; i++) {
        if (x % i == 0 && x / i <= n) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
