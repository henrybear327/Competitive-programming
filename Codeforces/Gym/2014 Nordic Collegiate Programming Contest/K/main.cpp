#include <cstdio>

int main()
{
    int capacity, station;
    while (scanf("%d %d", &capacity, &station) == 2) {
        bool error = false;

        int on_train = 0;
        int left, enter, waiting;
        while (station--) {
            scanf("%d %d %d", &left, &enter, &waiting);

            if (on_train - left < 0) {
                error = true;
            } else {
                on_train -= left;
            }

            if (on_train + enter > capacity) {
                error = true;
            } else {
                on_train += enter;
            }

            if ((capacity - on_train) != 0 && waiting > 0) {
                error = true;
            }
        }

        if (on_train != 0)
            error = true;
        if (waiting != 0)
            error = true;
        if (enter != 0)
            error = true;

        if (error)
            printf("impossible\n");
        else
            printf("possible\n");
    }

    return 0;
}
