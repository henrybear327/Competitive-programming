#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    char inp[n + 3];
    scanf("%s", inp);

    if (n == 2) {
        if (inp[0] >= inp[1])
            printf("NO\n");
        else {
            printf("YES\n");
            printf("2\n%c %c\n", inp[0], inp[1]);
        }
    } else {
        printf("YES\n");
        printf("2\n");
        printf("%c %s\n", inp[0], inp + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
        solve();

    return 0;
}
