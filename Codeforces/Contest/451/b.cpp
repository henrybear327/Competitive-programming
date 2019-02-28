#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    for (int i = 0; i * a <= n; i++) {
        int j = n - a * i;
        if (j >= 0 && j % b == 0) {
            printf("YES\n");
            printf("%d %d\n", i, j / b);
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}
