#include <cstdio>

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int command, init = 0;
        scanf("%d", &command);
        getchar();

        int save[command];
        for (int i = 0; i < command; i++) {
            char input[100];
            fgets(input, 100, stdin);

            if (input[0] == 'L')
                save[i] = -1;
            else if (input[0] == 'R')
                save[i] = 1;
            else {
                char garbage[100];
                sscanf(input, "%s %s %d", garbage, garbage, &save[i]);
                // printf("save %d\n", save[i]);
                save[i] = save[save[i] - 1];
            }

            init += save[i];
        }

        printf("%d\n", init);
    }

    return 0;
}
