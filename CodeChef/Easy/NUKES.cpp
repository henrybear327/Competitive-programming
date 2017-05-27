#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, n, k;
    scanf("%d %d %d", &a, &n, &k);
    for (int i = 0; i < k; i++) {
        printf("%d%c", a % (n + 1), i == k - 1 ? '\n' : ' ');
        a /= (n + 1);
    }

    return 0;
}
