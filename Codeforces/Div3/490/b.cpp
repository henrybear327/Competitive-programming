#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[111];
    scanf("%s", inp);

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            reverse(inp, inp + i);
        }
    }

    printf("%s\n", inp);

    return 0;
}
