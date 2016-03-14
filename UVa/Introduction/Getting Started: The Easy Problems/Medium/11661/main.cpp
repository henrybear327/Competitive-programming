#include <cstdio>

int main()
{
    int len;
    while (scanf("%d", &len) == 1 && len != 0) {
        char inp[len + 2];
        fgets(inp, len + 2, stdin);
        fgets(inp, len + 2, stdin);

        int prev = -1, character = -1; // curr 0 for R, 1 for D
        int min = 10000000;
        for (int i = 0; i <= len; i++) {
            if (inp[i] == 'Z') {
                min = 0;
                break;
            } else if (inp[i] == 'R' || inp[i] == 'D') {
                if (prev == -1) {
                    prev = i;
                    character = inp[i] == 'R' ? 0 : 1;
                } else {
                    if (inp[i] == 'R' && character == 0)
                        prev = i;
                    else if (inp[i] == 'R' && character == 1) {
                        min = i - prev < min ? i - prev : min;
                        prev = i;
                        character = 0;
                    } else if (inp[i] == 'D' && character == 1)
                        prev = i;
                    else {
                        min = i - prev < min ? i - prev : min;
                        prev = i;
                        character = 1;
                    }
                }
            }
        }
        printf("%d\n", min);
    }

    return 0;
}
