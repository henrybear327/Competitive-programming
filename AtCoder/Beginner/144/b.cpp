#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    bool ok = false;
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++)
            if (i * j == n)
                ok = true;

    printf("%s\n", ok ? "Yes" : "No");

    return 0;
}
