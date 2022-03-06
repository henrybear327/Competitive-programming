#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    bool has[n] = {false};
    for (int i = 0; i < n - 1; i++) {
        int tmp;
        scanf("%d", &tmp);

        has[tmp - 1] = true;
    }

    for (int i = 0; i < n; i++)
        if (has[i] == false)
            printf("%d\n", i + 1);

    return 0;
}
