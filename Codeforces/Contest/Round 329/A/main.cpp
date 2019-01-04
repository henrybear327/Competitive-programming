#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

// I_love_Hoang_Yen

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

bool valid(char input[], char first, char second)
{
    for (int i = 0; input[i] != '\0'; i++)
        if (input[i] != first && input[i] != second) // crucial
            return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    char input[n][1010];
    for (int i = 0; i < n; i++) {
        scanf("%s", input[i]);
    }

    int ans = 0;
    for (char i = 'a'; i <= 'z'; i++) { // Great usage
        for (char j = i; j <= 'z'; j++) {
            int tmp = 0;
            for (int k = 0; k < n; k++) {
                if (valid(input[k], i, j))
                    tmp += strlen(input[k]);
                // great observation (because no partial length is allowed)
            }

            ans = max(ans, tmp);
        }
    }

    printf("%d\n", ans);

    return 0;
}
