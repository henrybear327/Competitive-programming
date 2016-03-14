#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    sort(inp, inp + n);

    // get zero
    int zero = 0;
    for (int i = 0; i < n; i++)
        if (inp[i] == 0)
            zero++;

    int capacity[100] = {0}, cnt = zero;
    for (int i = 0; i < n; i++) {
        // get min in range 0 to cnt
        int idx = -1, minn = INT_MAX;
        for (int j = 0; j < cnt; j++) {
            if (minn > capacity[j]) {
                minn = capacity[j];
                idx = j;
            }
        }

        if (inp[i] < minn) { // new pile
            capacity[cnt]++;
            cnt++;
        } else {
            capacity[idx]++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
