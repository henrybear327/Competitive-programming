#include <cstdio>
#include <cstring>

int main()
{
    int cases;
    scanf("%d", &cases);
    char input[100];
    fgets(input, 100, stdin);

    int ans = 0;
    while (cases--) {
        fgets(input, 100, stdin);

        if (input[0] == 'd') {
            int dollar;
            char tmp[100];
            sscanf(input, "%s %d", tmp, &dollar);
            ans += dollar;
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
