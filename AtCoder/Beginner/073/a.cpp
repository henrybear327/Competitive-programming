#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    bool ok = false;
    while (n) {
        if (n % 10 == 9)
            ok = true;
        n /= 10;
    }

    printf("%s\n", ok ? "Yes" : "No");
    return 0;
}
