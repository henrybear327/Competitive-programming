#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    char input[1000];
    while (scanf("%s", input) != EOF) {
        int ans = 0, len = strlen(input);
        for (int i = 0; i < len; i++) {
            ans *= 26;
            ans += (input[i] - 'A' + 1);
        }

        printf("%d\n", ans);
    }

    return 0;
}
