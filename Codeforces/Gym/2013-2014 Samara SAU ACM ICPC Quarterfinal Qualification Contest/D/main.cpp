#include <cstdio>

int main()
{
    int len;
    while (scanf("%d", &len) == 1) {
        char inp[3][len + 10];
        fgets(inp[0], len + 10, stdin);

        for (int i = 0; i < 3; i++) {
            fgets(inp[i], len + 10, stdin);
        }

        for (int i = 0; i < len; i++) {
            int cnt[26] = {0};
            int ans = -1, ans_cnt = 0;
            for (int j = 0; j < 3; j++) {
                cnt[inp[j][i] - 'a']++;
                if (cnt[inp[j][i] - 'a'] > ans_cnt) {
                    ans = inp[j][i] - 'a';
                    ans_cnt = cnt[inp[j][i] - 'a'];
                }
            }
            printf("%c", ans + 'a');
        }
        printf("\n");
    }

    return 0;
}
