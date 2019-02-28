#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    if (n % 10 <= 5)
        printf("%d\n", n - n % 10);
    else
        printf("%d\n", n + (10 - n % 10));

    return 0;
}
