#include <cstdio>
#include <cstring>

int main()
{
    int appliance, operation, fuse;
    int index = 1;
    while (scanf("%d %d %d", &appliance, &operation, &fuse) == 3 &&
           appliance != 0 && operation != 0 && fuse != 0) {

        int consumption[appliance];
        memset(consumption, 0, sizeof(consumption));
        for (int i = 0; i < appliance; i++)
            scanf("%d", &consumption[i]);

        int max = -1, ampere = 0;
        int state[appliance];
        memset(state, 0, sizeof(state));
        for (int i = 0; i < operation; i++) {
            int curr;
            scanf("%d", &curr);
            curr--;

            if (state[curr] == 0) {
                ampere += consumption[curr];
                state[curr] = 1;
                max = max > ampere ? max : ampere;
            } else {
                ampere -= consumption[curr];
                state[curr] = 0;
            }
        }

        printf("Sequence %d\n", index++);
        if (max > fuse)
            printf("Fuse was blown.\n\n");
        else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n", max);
        }
    }

    return 0;
}
