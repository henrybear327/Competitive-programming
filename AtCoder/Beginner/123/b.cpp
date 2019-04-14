#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int inp[5];
    for (int i = 0; i < 5; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + 5);

    int mn = INT_MAX, sum = 0;
    // 29 20 7 35 120
    do {
        sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += inp[i];
            if (i < 4 && sum % 10 > 0)
                sum += 10 - sum % 10;

            // printf("sum %d\n", sum);
        }
        mn = min(mn, sum);
    } while (next_permutation(inp, inp + 5));

    printf("%d\n", mn);

    return 0;
}
