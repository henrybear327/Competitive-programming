#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int convert(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    else if ('a' <= c && c <= 'z')
        return c - 'a';
    else
        return -1;
}

int main()
{
    char target[1000];
    int cnt_target[26];
    while (scanf("%s", target) != EOF) {
        memset(cnt_target, 0, sizeof(cnt_target));

        for (int i = 0; i < (int)strlen(target); i++)
            cnt_target[convert(target[i])]++;

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            char inp[1000];
            scanf("%s", inp);

            int cnt[26] = {0};
            for (int i = 0; i < (int)strlen(inp); i++)
                cnt[convert(inp[i])]++;

            bool error = false;
            for (int i = 0; i < 26; i++)
                if (cnt[i] != cnt_target[i])
                    error = true;
            if (!error)
                printf("%s\n", inp);
        }
    }

    return 0;
}
