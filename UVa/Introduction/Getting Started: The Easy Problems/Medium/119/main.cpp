#include <cstdio>
#include <cstring>

int main()
{
    int people;
    bool first_time = true;
    while (scanf("%d", &people) == 1) {
        if (first_time)
            first_time = false;
        else
            printf("\n");

        char name[people][100];
        for (int i = 0; i < people; i++) {
            scanf("%s", name[i]);
        }
        getchar();

        int money[people];
        memset(money, 0, sizeof(money));

        for (int i = 0; i < people; i++) {
            char input[1000], curr_name[100];
            fgets(input, 1000, stdin);
            int spent, to_count;
            sscanf(input, "%s %d %d", curr_name, &spent, &to_count);

            for (int j = 0; j < people; j++) {
                if (strcmp(curr_name, name[j]) == 0) {
                    int spent_per_person = 0;
                    if (to_count != 0) {
                        money[j] += spent - to_count * (spent / to_count);
                        money[j] -= spent;
                        spent_per_person = spent / to_count;
                    }

                    for (int k = 0; k < 3; k++) {
                        if (k == 0)
                            char *token = strtok(input, " \n");
                        else
                            char *token = strtok(NULL, " \n");
                    }

                    for (int k = 0; k < to_count; k++) {
                        char *token = strtok(NULL, " \n");
                        for (int l = 0; l < people; l++) {
                            if (strcmp(token, name[l]) == 0) {
                                money[l] += spent_per_person;
                                break;
                            }
                        }
                    }

                    break;
                }
            }
        }

        for (int i = 0; i < people; i++) {
            printf("%s %d\n", name[i], money[i]);
        }
    }
    return 0;
}
