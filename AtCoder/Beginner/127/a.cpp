#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (a <= 5)
        printf("0\n");
    else if (6 <= a && a <= 12)
        printf("%d\n", b / 2);
    else
        printf("%d\n", b);

    return 0;
}
