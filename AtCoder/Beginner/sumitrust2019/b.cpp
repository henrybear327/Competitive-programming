#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= 50000; i++) {
        int x = i * 108 / 100;
        if (x == n) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf(":(\n");

    return 0;
}
