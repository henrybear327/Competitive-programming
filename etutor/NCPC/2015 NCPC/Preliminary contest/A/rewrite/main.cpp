#include <cstdio>
#include <cstdlib>
#include <cstring>

// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

char input[1000000];

int main()
{
    int n;
    fgets(input, 1000000, stdin);
    sscanf(input, "%d", &n);
    while (n--) {
        fgets(input, 1000000, stdin);

        int idx = 0, inp[10010] = {0};
        char *num = strtok(input, " \n");
        while (num) {
            inp[idx++] = atoi(num);
            num = strtok(NULL, " \n");
        }

        int cnt[1010] = {0};
        for (int i = 0; i < idx; i++) {
            cnt[inp[i]] = i + 1;
        }

        int res = 0;
        for (int i = 0; i < 1010; i++)
            if (cnt[i])
                res += cnt[i];

        printf("%d\n", res);
    }

    return 0;
}
