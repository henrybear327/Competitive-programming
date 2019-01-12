#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    int sum = 0;
    int target = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        sum += inp[i];
        target += i % 2 == 0 ? 5 : 4;
    }
    sort(inp, inp + n);

    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (sum < target) {
            sum += 5 - inp[i];
            diff++;
        }
    }

    printf("%d\n", diff);
    return 0;
}
