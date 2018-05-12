#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int dp[1111][1111];
int main()
{
    // empty string......... WTF scanf won't work
    char str1[1111], str2[1111];
    while (fgets(str1 + 1, 1110, stdin) != NULL) {
        if (str1[strlen(str1 + 1)] == '\n')
            str1[strlen(str1 + 1)] = '\0';
        fgets(str2 + 1, 1110, stdin);
        if (str2[strlen(str2 + 1)] == '\n')
            str2[strlen(str2 + 1)] = '\0';

        int len1 = strlen(str1 + 1);
        int len2 = strlen(str2 + 1);

        for (int i = 0; i < 1111; i++)
            dp[i][0] = dp[0][i] = 0;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // for (int i = 0; i <= len1; i++)
        //     for (int j = 0; j <= len2; j++)
        //         printf("%d%c", dp[i][j], j == len2 ? '\n' : ' ');

        printf("%d\n", dp[len1][len2]);
    }

    return 0;
}
