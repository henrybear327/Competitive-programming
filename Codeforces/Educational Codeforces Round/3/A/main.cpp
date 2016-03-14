#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int size;
    scanf("%d", &size);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n);

    int sum = 0, cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += inp[i];
        cnt++;
        if (sum >= size)
            break;
    }

    printf("%d\n", cnt);
    return 0;
}
