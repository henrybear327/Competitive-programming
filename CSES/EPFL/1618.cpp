#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    1. 2*5 = 10 -> makes 1 zero
    2. Even numbers will have >=1 2 in the decomposition, 5 is more scarce

    Thus, count for 5
    */

    int n;
    scanf("%d", &n);

    // naive
    int ans = 0;
    /*
    for (int i = 5; i <= n; i += 5) {
        int cand = i;
        while (cand % 5 == 0) {
            cand /= 5;
            ans++;
        }
    }
    */

    // efficient

    // 5 10 15 20 25 30 35 40 45 50...
    // 1 1  1  1  2  1  1  1  1  1 (count of 5 in the decomposition)
    // n /= 5 you basically remove one 5 from all the decomposition
    // and then you count again
    while (n > 0) {
        ans += n / 5;
        n /= 5;
    }

    printf("%d\n", ans);

    return 0;
}
