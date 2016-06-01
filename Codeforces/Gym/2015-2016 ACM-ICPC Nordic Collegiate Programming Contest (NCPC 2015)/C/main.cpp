#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    char inp[1000];
    while (scanf("%s", inp) == 1) {
        int len = strlen(inp);
        int ans = 0;
        const char *str = "PER";
        for (int i = 0; i < len / 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (inp[i * 3 + j] != str[j])
                    ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
