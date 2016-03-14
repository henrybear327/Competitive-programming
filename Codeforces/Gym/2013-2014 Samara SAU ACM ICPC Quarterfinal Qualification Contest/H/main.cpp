#include <cstdio>

int main()
{
    int len;
    while (scanf("%d", &len) == 1) {
        char input[len + 10], input2[len + 10]; //be aware of the overflow problem!!
        fgets(input, len + 10, stdin);

        fgets(input, len + 10, stdin);
        fgets(input2, len + 10, stdin);

        bool consecutive = false;
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (input[i] != input2[i]) {
                if (!consecutive) {
                    consecutive = !consecutive;
                    cnt++;
                }
            } else {
                if (consecutive)
                    consecutive = !consecutive;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
