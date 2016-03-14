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
    int number;
    scanf("%d", &number);

    int data[number];
    for (int i = 0; i < number; i++) {
        scanf("%d", &data[i]);
    }

    int begin = 0, end = 0, ans = 0;
    for (int i = 1; i < number; i++) {
        if (data[i] >= data[i - 1]) {
            end = i;
        } else {
            ans = max(i - 1 - begin + 1, ans);
            begin = i;
            end = i;
        }
    }
    ans = max(number - 1 - begin + 1, ans);

    printf("%d\n", ans);

    return 0;
}
