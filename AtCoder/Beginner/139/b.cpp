#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (b == 1) {
        printf("0\n");
        return 0;
    }

    for (int i = 1;; i++)
        if (a * i - (i - 1) >= b) {
            printf("%d\n", i);
            return 0;
        }

    return 0;
}
