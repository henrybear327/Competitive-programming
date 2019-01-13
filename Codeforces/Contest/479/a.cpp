#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    while (k > 0 && n > 0) {
        if (n % 10 == 0)
            n /= 10;
        else
            n--;

        k--;
    }
    printf("%d\n", n);

    return 0;
}
