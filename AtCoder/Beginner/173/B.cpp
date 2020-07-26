#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    const char *str[] = {"AC", "WA", "TLE", "RE"};
    int cnt[4] = {0};
    for (int i = 0; i < n; i++) {
        char inp[100];
        scanf("%s", inp);

        for (int j = 0; j < 4; j++) {
            if (strcmp(inp, str[j]) == 0) {
                cnt[j]++;
                break;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("%s x %d\n", str[i], cnt[i]);
    }

    return 0;
}
