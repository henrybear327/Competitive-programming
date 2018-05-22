#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int sum = 0;
    int inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        sum += inp[i];
    }

    int half = (sum + 1) / 2;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += inp[i];
        if (tmp >= half) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    printf("%d\n", n);

    return 0;
}
