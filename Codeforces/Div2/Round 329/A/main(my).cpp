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

    char input[1100];

    int cnt[n][27];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        // printf("%s\n", input);

        for (int j = 0; input[j] != '\0'; j++) {
            if (cnt[i][input[j] - 'a'] == 0)
                cnt[i][26]++;

            cnt[i][input[j] - 'a']++;
        }

        // printf("%d %d %d %d %d\n", i, cnt[i][0], cnt[i][1], cnt[i][2], cnt[i][26]);
    }

    int ans = 0;

    // aa to zz
    for (int i = 0; i < 26; i++) {
        for (int j = i; j < 26; j++) {
            int tmp = 0;
            for (int k = 0; k < n; k++) {
		if(cnt[k][26] > 2)
		    continue;
                if (i == j) {
                    if (cnt[k][26] == 1 && cnt[k][i] != 0)
                        tmp += cnt[k][i];
                } else {
                    if ((cnt[k][26] == 1 && (cnt[k][i] != 0 || cnt[k][j] != 0))|| (cnt[k][i] != 0 && cnt[k][j] != 0))
                        tmp += cnt[k][i] + cnt[k][j];
                }
            }
            // printf("%d %d %d\n", i, j, tmp);
            ans = max(ans, tmp);
        }
    }

    printf("%d\n", ans);

    return 0;
}
