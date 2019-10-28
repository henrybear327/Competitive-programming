#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (a < 10 && b < 10)
        printf("%d\n", a * b);
    else
        printf("-1\n");

    return 0;
}
