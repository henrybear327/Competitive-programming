#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

bool isupper(char c)
{
    return 'A' <= c && c <= 'Z';
}

bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    char inp[100];
    while (scanf("%s", inp) != EOF && strcmp(inp, "end") != 0) {
        int len = strlen(inp);
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (isupper(inp[i]))
                ans++;

            if (is_vowel(tolower(inp[i])))
                ans += 5;
            else
                ans += 2;
        }
        printf("%d\n", ans);
    }

    return 0;
}
